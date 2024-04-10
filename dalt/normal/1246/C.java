import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
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
            TaskC solver = new TaskC();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskC {
        int n;
        int m;
        int[][] left;
        int[][] top;
        int[][] h;
        int[][] v;
        int[][] hs;
        int[][] vs;
        NumberTheory.Modular mod = new NumberTheory.Modular(1e9 + 7);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            m = in.readInt();
            char[][] grids = new char[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                in.readString(grids[i], 1);
            }
            if (n == 1 && m == 1) {
                out.println(1);
                return;
            }

            left = new int[n + 1][m + 1];
            top = new int[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    left[i][j] = left[i][j - 1] + (grids[i][j] == 'R' ? 1 : 0);
                }
            }
            for (int j = 1; j <= m; j++) {
                for (int i = 1; i <= n; i++) {
                    top[i][j] = top[i - 1][j] + (grids[i][j] == 'R' ? 1 : 0);
                }
            }

            h = new int[n + 1][m + 1];
            v = new int[n + 1][m + 1];
            hs = new int[n + 1][m + 1];
            vs = new int[n + 1][m + 1];

            ArrayUtils.fill(h, -1);
            ArrayUtils.fill(v, -1);
            ArrayUtils.fill(hs, -1);
            ArrayUtils.fill(vs, -1);
            h[n][m] = v[n][m] = 1;

            //h(2, 2);
            int ans1 = h(1, 1);
            int ans2 = v(1, 1);
            int ans = mod.plus(ans1, ans2);
            out.println(ans);
        }

        public int h(int i, int j) {
            if (h[i][j] == -1) {
                int stoneInRight = left[i][m] - left[i][j];
                int maxTo = m - stoneInRight;
                h[i][j] = mod.subtract(vs(i, j + 1), vs(i, maxTo + 1));
            }
            return h[i][j];
        }

        public int v(int i, int j) {
            if (v[i][j] == -1) {
                int stoneInBottom = top[n][j] - top[i][j];
                int maxTo = n - stoneInBottom;
                v[i][j] = mod.subtract(hs(i + 1, j), hs(maxTo + 1, j));
            }
            return v[i][j];
        }

        public int hs(int i, int j) {
            if (i > n) {
                return 0;
            }
            if (hs[i][j] == -1) {
                hs[i][j] = mod.plus(hs(i + 1, j), h(i, j));
            }
            return hs[i][j];
        }

        public int vs(int i, int j) {
            if (j > m) {
                return 0;
            }
            if (vs[i][j] == -1) {
                vs[i][j] = mod.plus(vs(i, j + 1), v(i, j));
            }
            return vs[i][j];
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
                    throw new RuntimeException(e);
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

    static class NumberTheory {
        public static class Modular {
            int m;

            public Modular(int m) {
                this.m = m;
            }

            public Modular(long m) {
                this.m = (int) m;
                if (this.m != m) {
                    throw new IllegalArgumentException();
                }
            }

            public Modular(double m) {
                this.m = (int) m;
                if (this.m != m) {
                    throw new IllegalArgumentException();
                }
            }

            public int valueOf(int x) {
                x %= m;
                if (x < 0) {
                    x += m;
                }
                return x;
            }

            public int plus(int x, int y) {
                return valueOf(x + y);
            }

            public int subtract(int x, int y) {
                return valueOf(x - y);
            }

            public String toString() {
                return "mod " + m;
            }

        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(int c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
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

    }

    static class ArrayUtils {
        public static void fill(int[][] x, int val) {
            for (int[] v : x) {
                Arrays.fill(v, val);
            }
        }

    }
}