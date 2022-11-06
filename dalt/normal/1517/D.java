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
            DExplorerSpace solver = new DExplorerSpace();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DExplorerSpace {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            int k = in.ri();
            int[][] lr = new int[n][m - 1];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m - 1; j++) {
                    lr[i][j] = in.ri();
                }
            }
            int[][] ud = new int[n - 1][m];
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m; j++) {
                    ud[i][j] = in.ri();
                }
            }

            if (k % 2 == 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        out.append(-1).append(' ');
                    }
                    out.println();
                }
                return;
            }

            k /= 2;
            int inf = (int) 1e9;
            int[][][] dp = new int[k + 1][n][m];
            for (int i = 1; i <= k; i++) {
                for (int j = 0; j < n; j++) {
                    for (int t = 0; t < m; t++) {
                        dp[i][j][t] = inf;
                        //left
                        if (t > 0) {
                            dp[i][j][t] = Math.min(dp[i][j][t], dp[i - 1][j][t - 1] + lr[j][t - 1]);
                        }
                        //right
                        if (t + 1 < m) {
                            dp[i][j][t] = Math.min(dp[i][j][t], dp[i - 1][j][t + 1] + lr[j][t]);
                        }
                        //bot
                        if (j + 1 < n) {
                            dp[i][j][t] = Math.min(dp[i][j][t], dp[i - 1][j + 1][t] + ud[j][t]);
                        }
                        //top
                        if (j > 0) {
                            dp[i][j][t] = Math.min(dp[i][j][t], dp[i - 1][j - 1][t] + ud[j - 1][t]);
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    out.append(dp[k][i][j] * 2).append(' ');
                }
                out.println();
            }
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private final Writer os;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);

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

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
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

        public FastOutput println() {
            return append('\n');
        }

        public FastOutput flush() {
            try {
//            boolean success = false;
//            if (stringBuilderValueField != null) {
//                try {
//                    char[] value = (char[]) stringBuilderValueField.get(cache);
//                    os.write(value, 0, cache.length());
//                    success = true;
//                } catch (Exception e) {
//                }
//            }
//            if (!success) {
                os.append(cache);
//            }
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
}