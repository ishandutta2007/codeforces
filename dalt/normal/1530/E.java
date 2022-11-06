import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
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
            EMinimax solver = new EMinimax();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class EMinimax {
        char[] s = new char[(int) 2e5];
        int[] ans;
        int wpos;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.rs(s);
            int charset = 'z' - 'a' + 1;
            int[] cnts = new int[charset];
            for (int i = 0; i < n; i++) {
                cnts[s[i] - 'a']++;
            }
            int oneOccur = -1;
            for (int i = 0; i < charset; i++) {
                if (cnts[i] == 1) {
                    oneOccur = i;
                    break;
                }
            }
            if (oneOccur != -1) {
                out.append((char) (oneOccur + 'a'));
                for (int i = 0; i < charset; i++) {
                    if (i == oneOccur) {
                        continue;
                    }
                    for (int j = 0; j < cnts[i]; j++) {
                        out.append((char) (i + 'a'));
                    }
                }
                out.println();
                return;
            }
            Deque<Item> dq = new ArrayDeque<>(charset);
            for (int i = 0; i < charset; i++) {
                if (cnts[i] > 0) {
                    dq.addLast(new Item(i, cnts[i]));
                }
            }
            if (dq.size() == 1) {
                for (int i = 0; i < n; i++) {
                    out.append(s[i]);
                }
                out.println();
                return;
            }

            Item first = dq.removeFirst();
            ans = new int[n];
            wpos = 0;
            int consume = 2 + (n - first.cnt) >= first.cnt ? 2 : 1;
            consume = Math.min(consume, first.cnt);
            for (int i = 0; i < consume; i++) {
                add(first);
            }
            if (first.cnt == 0) {
                while (!dq.isEmpty()) {
                    Item head = dq.removeFirst();
                    addAll(head);
                }
            } else if (consume == 2) {
                while (first.cnt > 0) {
                    Item cur = dq.peekFirst();
                    if (cur.cnt == 0) {
                        dq.removeFirst();
                        continue;
                    }
                    add(cur);
                    add(first);
                }
                while (!dq.isEmpty()) {
                    Item head = dq.removeFirst();
                    addAll(head);
                }
            } else {
                if (dq.size() == 1) {
                    Item head = dq.removeFirst();
                    addAll(head);
                    addAll(first);
                } else {
                    Item second = dq.removeFirst();
                    add(second);
                    addAll(first);
                    add(dq.peekFirst());
                    dq.addFirst(second);
                    while (!dq.isEmpty()) {
                        Item head = dq.removeFirst();
                        addAll(head);
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                out.append((char) (ans[i] + 'a'));
            }
            out.println();
        }

        void add(Item item) {
            ans[wpos++] = item.c;
            item.cnt--;
        }

        void addAll(Item item) {
            while (item.cnt > 0) {
                add(item);
            }
        }

    }

    static class Item {
        int c;
        int cnt;

        public Item(int c, int cnt) {
            this.c = c;
            this.cnt = cnt;
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public String next() {
            return readString();
        }

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
        }

        public int rs(char[] data, int offset) {
            return readString(data, offset);
        }

        public int rs(char[] data) {
            return rs(data, 0);
        }

        public int readString(char[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
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

        public FastOutput println() {
            return append('\n');
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
}