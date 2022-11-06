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
            FVasyaAndArray solver = new FVasyaAndArray();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FVasyaAndArray {
        Modular mod = new Modular(998244353);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();
            int len = in.readInt();
            int[][] dp = new int[n][k + 1];
            int[] sum = new int[n];

            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = in.readInt();
            }

            if (len == 1) {
                out.println(0);
                return;
            }

            if (s[0] == -1) {
                for (int i = 1; i <= k; i++) {
                    dp[0][i] = 1;
                }
            } else {
                dp[0][s[0]] = 1;
            }

            int[] lastDifference = new int[n];
            for (int i = 0; i < n; i++) {
                if (s[i] == -1) {
                    if (i == 0) {
                        lastDifference[i] = -1;
                    } else if (s[i - 1] == -1) {
                        lastDifference[i] = lastDifference[i - 1];
                    } else {
                        lastDifference[i] = i - 1;
                    }
                    continue;
                }
                int j = i - 1;
                while (j >= 0 && s[j] == -1) {
                    j--;
                }
                if (j >= 0) {
                    lastDifference[i] = s[i] == s[j] ? lastDifference[j] : j;
                } else {
                    lastDifference[i] = -1;
                }
            }

            sum[0] = sumOf(dp[0], 1, k);
            for (int i = 1; i < n; i++) {
                for (int j = 1; j <= k; j++) {
                    if (s[i] == -1 || s[i] == j) {
                        dp[i][j] = sum[i - 1];
                        if (i >= len - 1 && (i - lastDifference[i] >= len || s[lastDifference[i]] == j &&
                                i - lastDifference[lastDifference[i]] >= len)) {
                            if (i == len - 1) {
                                dp[i][j] = mod.subtract(dp[i][j], 1);
                            } else {
                                dp[i][j] = mod.subtract(dp[i][j], mod.subtract(sum[i - len], dp[i - len][j]));
                            }
                        }
                    }
                }
                sum[i] = sumOf(dp[i], 1, k);
            }

            int ans = sumOf(dp[n - 1], 1, k);
            out.println(ans);
        }

        public int sumOf(int[] x, int l, int r) {
            long ans = 0;
            for (int i = l; i <= r; i++) {
                ans += x[i];
            }
            return mod.valueOf(ans);
        }

    }

    static class Modular {
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

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public int subtract(int x, int y) {
            return valueOf(x - y);
        }

        public String toString() {
            return "mod " + m;
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