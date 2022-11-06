import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.stream.IntStream;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
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
            ABook solver = new ABook();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class ABook {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            List<DirectedEdge>[] g = Graph.createGraph(n);
            int[] deg = new int[n];
            for (int i = 0; i < n; i++) {
                int k = in.ri();
                deg[i] = k;
                for (int j = 0; j < k; j++) {
                    Graph.addEdge(g, in.ri() - 1, i);
                }
            }
            RangeTree rt = new RangeTree(n);
            for (int i = 0; i < n; i++) {
                if (deg[i] == 0) {
                    rt.add(i);
                }
            }
            int time = 0;
            while (rt.size() > 0) {
                time++;
                for (int iter = rt.first(); iter != -1; iter = rt.ceil(iter)) {
                    rt.remove(iter);
                    for (DirectedEdge e : g[iter]) {
                        deg[e.to]--;
                        if (deg[e.to] == 0) {
                            rt.add(e.to);
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (deg[i] > 0) {
                    out.println(-1);
                    return;
                }
            }
            out.println(time);
        }

    }

    static class Bits {
        private Bits() {
        }

        public static long set(long x, int i) {
            return x | (1L << i);
        }

        public static long clear(long x, int i) {
            return x & (~(1L << i));
        }

        public static int lowestOneBitOffset(long x) {
            return Long.numberOfTrailingZeros(x & -x);
        }

        public static long tailLongMask(int n) {
            if (n == 0) {
                return 0;
            }
            return -1L << (64 - n);
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

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

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

        public FastOutput println(int c) {
            return append(c).println();
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

    static class Graph {
        public static DirectedEdge addEdge(List<DirectedEdge>[] g, int s, int t) {
            DirectedEdge e = new DirectedEdge(t);
            g[s].add(e);
            return e;
        }

        public static List[] createGraph(int n) {
            return IntStream.range(0, n).mapToObj(i -> new ArrayList<>()).toArray(i -> new List[i]);
        }

    }

    static class DirectedEdge {
        public int to;

        public DirectedEdge(int to) {
            this.to = to;
        }

        public String toString() {
            return "->" + to;
        }

    }

    static class RangeTree {
        private long[][] data;
        private static int bitShift = 6;
        private static int bitShiftValue = 1 << bitShift;
        private static int bitShiftValueMask = bitShiftValue - 1;
        private int size;
        private int n;

        private int calcLevel(int n) {
            int level = 0;
            while (n > 64) {
                level++;
                n = (n + 63) / 64;
            }
            level++;
            return level;
        }

        public RangeTree(int n) {
            this.n = n;
            int level = calcLevel(n);
            data = new long[level][];
            for (int i = 0, m = (n + 63) / 64; i < level; i++, m = (m + 63) / 64) {
                data[i] = new long[m];
            }
        }

        public boolean contains(int x) {
            return ((data[0][x >> bitShift] >>> (x & bitShiftValueMask)) & 1) == 1;
        }

        public int size() {
            return size;
        }

        public void add(int x) {
            if (contains(x)) {
                return;
            }
            size++;
            for (int i = 0; i < data.length; i++) {
                int offset = x & bitShiftValueMask;
                x >>= bitShift;
                data[i][x] = Bits.set(data[i][x], offset);
            }
        }

        public void remove(int x) {
            if (!contains(x)) {
                return;
            }
            size--;
            long lastValue = 0;
            for (int i = 0; i < data.length && lastValue == 0; i++) {
                int offset = x & bitShiftValueMask;
                x >>= bitShift;
                lastValue = data[i][x] = Bits.clear(data[i][x], offset);
            }
        }

        private int firstSet(int i, int x) {
            assert i < 0 || data[i][x] != 0;
            for (; i >= 0; i--) {
                int offset = Bits.lowestOneBitOffset(data[i][x]);
                x = (x << bitShift) | offset;
            }
            return x;
        }

        public int ceil(int x) {
            if (x >= n) {
                return -1;
            }
            if (contains(x)) {
                return x;
            }
            for (int i = 0, y = x; i < data.length; i++) {
                int offset = y & bitShiftValueMask;
                y = y >>> bitShift;
                long tailMask = Bits.tailLongMask(63 - offset);
                if ((data[i][y] & tailMask) != 0) {
                    return firstSet(i - 1, (y << bitShift) | Bits.lowestOneBitOffset(data[i][y] & tailMask));
                }
            }
            return -1;
        }

        public int first() {
            if (size == 0) {
                return -1;
            }
            return firstSet(data.length - 1, 0);
        }

        public IntegerIterator iterator() {
            return iterator(0, n - 1);
        }

        public IntegerIterator iterator(int l, int r) {
            return new IntegerIterator() {
                int cur = ceil(l);


                public boolean hasNext() {
                    return cur <= r && cur != -1;
                }


                public int next() {
                    int ans = cur;
                    if (cur == r) {
                        cur = -1;
                    } else {
                        cur = ceil(cur + 1);
                    }
                    assert cur == -1 || cur > ans;
                    return ans;
                }
            };
        }

        public String toString() {
            IntegerIterator iterator = iterator();
            List<Integer> list = new ArrayList<>(n);
            for (; iterator.hasNext(); ) {
                list.add(iterator.next());
            }
            return list.toString();
        }

    }
}