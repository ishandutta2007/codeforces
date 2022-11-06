import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
            TaskE solver = new TaskE();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskE {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int q = in.readInt();
            int[][] mat = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = in.readChar() - '0';
                }
            }

            MatrixMachine machine = new MatrixMachine(mat);
            for (int i = 0; i < q; i++) {
                int t = in.readInt();
                int l = in.readInt();
                int b = in.readInt();
                int r = in.readInt();
                long ans = machine.query(l, r, t, b);
                out.println(ans);
            }
        }

    }

    static class Log2 {
        public int floorLog(long x) {
            return 63 - Long.numberOfLeadingZeros(x);
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

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
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

        public FastOutput println(long c) {
            cache.append(c).append('\n');
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

    static class MatrixMachine {
        int[][] mat;
        int[][] preSum;
        int n;
        int m;
        Log2 log2 = new Log2();

        public MatrixMachine(int[][] mat) {
            this.mat = mat;
            this.n = mat.length;
            this.m = mat[0].length;
            preSum = new int[n * 2][m * 2];
            for (int i = 0; i < n * 2; i++) {
                for (int j = 0; j < m * 2; j++) {
                    int v = mat[i % n][j % m];
                    if (i >= n) {
                        v = 1 - v;
                    }
                    if (j >= m) {
                        v = 1 - v;
                    }
                    preSum[i][j] = v;
                    if (j > 0) {
                        preSum[i][j] += preSum[i][j - 1];
                    }
                }
                if (i > 0) {
                    for (int j = 0; j < m * 2; j++) {
                        preSum[i][j] += preSum[i - 1][j];
                    }
                }
            }
        }

        private long queryZero(long r, long b) {
            return r * b - query(r, b);
        }

        private long query(long r, long b) {
            if (r <= 2 * m && b <= 2 * n) {
                if (r == 0 || b == 0) {
                    return 0;
                }
                return preSum[(int) (b - 1)][(int) (r - 1)];
            }
            if (b > 2 * n) {
                long time = (b / (2 * n));
                int floorLog = log2.floorLog(time);
                long ans = (1L << floorLog) * n * r;
                b -= 2 * n * (1L << floorLog);
                ans += queryZero(r, b);
                return ans;
            }
            long time = (r / (2 * m));
            int floorLog = log2.floorLog(time);
            long ans = (1L << floorLog) * m * b;
            r -= 2 * m * (1L << floorLog);
            ans += queryZero(r, b);
            return ans;
        }

        public long query(int l, int r, int t, int b) {
            long ans = query(r, b);
            if (t > 1) {
                ans -= query(r, t - 1);
            }
            if (l > 1) {
                ans -= query(l - 1, b);
            }
            if (l > 1 && t > 1) {
                ans += query(l - 1, t - 1);
            }
            return ans;
        }

    }
}