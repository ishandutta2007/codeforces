import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.function.IntBinaryOperator;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
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
            GChattering solver = new GChattering();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GChattering {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[] rs = new int[n];
            for (int i = 0; i < n; i++) {
                rs[i] = in.readInt();
            }

            if (n == 1) {
                out.println(0);
                return;
            }

            int[] leftTo = new int[3 * n];
            int[] rightTo = new int[3 * n];
            for (int i = 0; i < 3 * n; i++) {
                leftTo[i] = Math.max(0, i - rs[i % n]);
                rightTo[i] = Math.min(3 * n - 1, i + rs[i % n]);
            }

            int[] indexes = new int[3 * n];
            for (int i = 0; i < 3 * n; i++) {
                indexes[i] = i;
            }

            IntegerSparseTable leftST = new IntegerSparseTable(indexes, indexes.length, (a, b) -> leftTo[a] <= leftTo[b] ? a : b);
            IntegerSparseTable rightST = new IntegerSparseTable(indexes, indexes.length, (a, b) -> rightTo[a] >= rightTo[b] ? a : b);

            int[][] dpL = new int[20][3 * n];
            int[][] dpR = new int[20][3 * n];
            dpL[0] = leftTo;
            dpR[0] = rightTo;

            for (int i = 1; i < 20; i++) {
                for (int j = n; j < n * 2; j++) {
                    int l = dpL[i - 1][j];
                    int r = dpR[i - 1][j];
                    int lIndex = leftST.query(l, r);
                    int rIndex = rightST.query(l, r);
                    l = Math.min(l, dpL[i - 1][lIndex]);
                    l = Math.min(l, dpL[i - 1][rIndex]);
                    r = Math.max(r, dpR[i - 1][lIndex]);
                    r = Math.max(r, dpR[i - 1][rIndex]);
                    dpL[i][j] = l;
                    dpR[i][j] = r;
                }
                for (int j = 0; j < n; j++) {
                    dpL[i][j] = Math.max(0, dpL[i][j + n] - n);
                    dpR[i][j] = dpR[i][j + n] - n;
                }
                for (int j = 2 * n; j < 3 * n; j++) {
                    dpL[i][j] = dpL[i][j - n] + n;
                    dpR[i][j] = Math.min(3 * n - 1, dpR[i][j - n] + n);
                }
            }

            //System.err.println(Arrays.deepToString(dpL));
            // System.err.println(Arrays.deepToString(dpR));

            for (int i = n; i < 2 * n; i++) {
                int mask = 0;
                int ll = i;
                int rr = i;
                for (int j = 20 - 1; j >= 0; j--) {
                    int l = ll;
                    int r = rr;
                    int lIndex = leftST.query(l, r);
                    int rIndex = rightST.query(l, r);
                    l = Math.min(l, dpL[j][lIndex]);
                    l = Math.min(l, dpL[j][rIndex]);
                    r = Math.max(r, dpR[j][lIndex]);
                    r = Math.max(r, dpR[j][rIndex]);

                    if (r - l + 1 < n) {
                        mask = Bits.setBit(mask, j, true);
                        ll = l;
                        rr = r;
                    }
                }

                out.println(mask + 1);
            }
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

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class Bits {
        private Bits() {
        }

        public static int setBit(int x, int i, boolean v) {
            if (v) {
                x |= 1 << i;
            } else {
                x &= ~(1 << i);
            }
            return x;
        }

    }

    static class IntegerSparseTable {
        private int[][] st;
        private IntBinaryOperator merger;

        public IntegerSparseTable(int[] data, int length, IntBinaryOperator merger) {
            int m = CachedLog2.floorLog(length);
            st = new int[m + 1][length];
            this.merger = merger;
            for (int i = 0; i < length; i++) {
                st[0][i] = data[i];
            }
            for (int i = 0; i < m; i++) {
                int interval = 1 << i;
                for (int j = 0; j < length; j++) {
                    if (j + interval < length) {
                        st[i + 1][j] = merge(st[i][j], st[i][j + interval]);
                    } else {
                        st[i + 1][j] = st[i][j];
                    }
                }
            }
        }

        private int merge(int a, int b) {
            return merger.applyAsInt(a, b);
        }

        public int query(int left, int right) {
            int queryLen = right - left + 1;
            int bit = CachedLog2.floorLog(queryLen);
            // x + 2^bit == right + 1
            // So x should be right + 1 - 2^bit - left=queryLen - 2^bit
            return merge(st[bit][left], st[bit][right + 1 - (1 << bit)]);
        }

        public String toString() {
            return Arrays.toString(st[0]);
        }

    }

    static class CachedLog2 {
        private static final int BITS = 16;
        private static final int LIMIT = 1 << BITS;
        private static final byte[] CACHE = new byte[LIMIT];

        static {
            int b = 0;
            for (int i = 0; i < LIMIT; i++) {
                while ((1 << (b + 1)) <= i) {
                    b++;
                }
                CACHE[i] = (byte) b;
            }
        }

        public static int floorLog(int x) {
            return x < LIMIT ? CACHE[x] : (BITS + CACHE[x >>> BITS]);
        }

    }
}