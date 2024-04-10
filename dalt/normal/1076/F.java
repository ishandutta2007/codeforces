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
            FSummerPracticeReport solver = new FSummerPracticeReport();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FSummerPracticeReport {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();
            int[] x = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                x[i] = in.readInt();
            }
            int[] y = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                y[i] = in.readInt();
            }

            int inf = k + 1;
            int[][] dp = new int[n + 1][2];
            for (int i = 1; i <= n; i++) {
                int[] ab = new int[]{x[i], y[i]};
                dp[i][0] = inf;
                dp[i][1] = inf;
                for (int j = 0; j < 2; j++) {
                    for (int t = 0; t < 2; t++) {
                        if (dp[i - 1][t] > k) {
                            continue;
                        }
                        long atLeast;
                        long atMost;
                        if (j == t && ab[1 - j] == 0) {
                            if (ab[j] + dp[i - 1][t] > k) {
                                continue;
                            }
                            dp[i][j] = Math.min(dp[i][j], dp[i - 1][t] + ab[j]);
                            continue;
                        }

                        if (j == t) {
                            atLeast = DigitUtils.ceilDiv(ab[1 - j], k) - 1;
                            atMost = k - dp[i - 1][t] + (long) (ab[1 - j] - 1) * k;
                        } else {
                            if (k - dp[i - 1][t] >= ab[1 - j]) {
                                atLeast = 0;
                            } else {
                                atLeast = DigitUtils.ceilDiv(ab[1 - j] - (k - dp[i - 1][t]), k);
                            }
                            atMost = (long) ab[1 - j] * k;
                        }
                        if (atLeast + 1 > ab[j]) {
                            continue;
                        }
                        long remain = Math.max(1, ab[j] - atMost);
                        dp[i][j] = (int) Math.min(remain, dp[i][j]);
                    }
                }
            }

            //System.err.println(Arrays.deepToString(dp));
            if (dp[n][0] <= k || dp[n][1] <= k) {
                out.println("YES");
            } else {
                out.println("NO");
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

        public FastOutput println(String c) {
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

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorDiv(int a, int b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static int ceilDiv(int a, int b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            int c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
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
}