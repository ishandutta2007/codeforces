import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.lang.reflect.Field;
import java.util.Deque;
import java.util.function.Supplier;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.util.function.Consumer;
import java.io.Closeable;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            HXORAndDistance solver = new HXORAndDistance();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class HXORAndDistance {
        Item[] items;
        int inf = (int) 1e9;
        int k;
        Buffer<Item> buffer;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            k = in.ri();
            items = new Item[1 << k];
            buffer = new Buffer<>(Item::new, x -> {
                x.l = x.r = x.nearest = 0;
            }, 2 << k);
            for (int i = 0; i < n; i++) {
                int a = in.ri();
                Item item = buffer.alloc();
                item.l = item.r = a;
                item.nearest = inf;
                items[a] = item;
            }
            dac(0, items.length - 1, k - 1);
            for (Item item : items) {
                out.append(item.nearest).append(' ');
            }
        }

        public void dac(int l, int r, int k) {
            if (l >= r) {
                return;
            }
            int m = (l + r) / 2;
            dac(l, m, k - 1);
            dac(m + 1, r, k - 1);
            for (int i = l; i <= m; i++) {
                int mirror = m + 1 + (i - l);
                Item a = items[i];
                Item b = items[mirror];
                items[i] = add(a, b, 0);
                items[mirror] = add(b, a, 1 << k);
                buffer.release(a, b);
            }
        }

        public Item add(Item a, Item b, int xor) {
            if (a == null && b == null) {
                return null;
            }
            Item res = buffer.alloc();
            if (a == null || b == null) {
                Item c = a == null ? b : a;
                res.l = c.l ^ xor;
                res.r = c.r ^ xor;
                res.nearest = c.nearest;
                return res;
            }
            res.nearest = Math.min(a.nearest, b.nearest);
            assert (b.l ^ xor) - (a.r ^ xor) >= 0;
            res.nearest = Math.min(res.nearest, (b.l ^ xor) - (a.r ^ xor));
            res.l = a.l ^ xor;
            res.r = b.r ^ xor;
            return res;
        }

    }

    static class Item {
        int l;
        int r;
        int nearest;

        public String toString() {
            return "Item{" +
                    "l=" + l +
                    ", r=" + r +
                    ", nearest=" + nearest +
                    '}';
        }

    }

    static class Buffer<T> {
        private Deque<T> deque;
        private Supplier<T> supplier;
        private Consumer<T> cleaner;
        private int allocTime;
        private int releaseTime;

        public Buffer(Supplier<T> supplier) {
            this(supplier, (x) -> {
            });
        }

        public Buffer(Supplier<T> supplier, Consumer<T> cleaner) {
            this(supplier, cleaner, 0);
        }

        public Buffer(Supplier<T> supplier, Consumer<T> cleaner, int exp) {
            this.supplier = supplier;
            this.cleaner = cleaner;
            deque = new ArrayDeque<>(exp);
        }

        public T alloc() {
            allocTime++;
            T res;
            if (deque.isEmpty()) {
                res = supplier.get();
                cleaner.accept(res);
            } else {
                res = deque.removeFirst();
            }
            return res;
        }

        public void release(T e) {
            if (e == null) {
                return;
            }
            releaseTime++;
            cleaner.accept(e);
            deque.addLast(e);
        }

        public void release(T a, T b) {
            release(a);
            release(b);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private OutputStream writer;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);
        private static Field stringBuilderValueField;
        private char[] charBuf = new char[THRESHOLD * 2];
        private byte[] byteBuf = new byte[THRESHOLD * 2];

        static {
            try {
                stringBuilderValueField = StringBuilder.class.getSuperclass().getDeclaredField("value");
                stringBuilderValueField.setAccessible(true);
            } catch (Exception e) {
                stringBuilderValueField = null;
            }
            stringBuilderValueField = null;
        }

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < THRESHOLD) {
                return;
            }
            flush();
        }

        public FastOutput(OutputStream writer) {
            this.writer = writer;
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput flush() {
            try {
                if (stringBuilderValueField != null) {
                    try {
                        byte[] value = (byte[]) stringBuilderValueField.get(cache);
                        writer.write(value, 0, cache.length());
                    } catch (Exception e) {
                        stringBuilderValueField = null;
                    }
                }
                if (stringBuilderValueField == null) {
                    int n = cache.length();
                    if (n > byteBuf.length) {
                        //slow
                        writer.write(cache.toString().getBytes(StandardCharsets.UTF_8));
//                writer.append(cache);
                    } else {
                        cache.getChars(0, n, charBuf, 0);
                        for (int i = 0; i < n; i++) {
                            byteBuf[i] = (byte) charBuf[i];
                        }
                        writer.write(byteBuf, 0, n);
                    }
                }
                writer.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                writer.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public int ri() {
            return readInt();
        }

        public int readInt() {
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
        }

    }
}