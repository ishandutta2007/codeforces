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
            EVasyaAndBinaryString solver = new EVasyaAndBinaryString();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EVasyaAndBinaryString {
        long[][][] dp;
        long[] profits;
        int[] flags;
        int n;
        long inf = (long) 1e18;
        PreSum ps;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            flags = new int[n];
            for (int i = 0; i < n; i++) {
                flags[i] = in.readChar() - '0';
            }
            ps = new PreSum(flags);

            profits = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                profits[i] = in.readInt();
            }

            dp = new long[n][n][n + 1];
            SequenceUtils.deepFill(dp, -1L);

            long ans = dp(0, n - 1, 0);
            out.println(ans);
        }

        public long dp(int l, int r, int remain) {
            if (l > r) {
                return remain == 0 ? 0 : -inf;
            }
            if (dp[l][r][remain] == -1) {
                dp[l][r][remain] = -inf;
                for (int i = n; i > remain; i--) {
                    dp[l][r][remain] = Math.max(dp[l][r][remain],
                            dp(l, r, i) + profits[i - remain]);
                }
                if (remain == 0) {
                    return dp[l][r][remain];
                }
                if (l == r) {
                    dp[l][r][remain] = remain == 1 ? 0 : -inf;
                    return dp[l][r][remain];
                }
                if (remain == 1) {
                    dp[l][r][remain] = Math.max(dp[l][r][remain],
                            dp(l, l, 1) + dp(l + 1, r, 0));
                }
                for (int i = l + 1; i <= r; i++) {
                    if (flags[i] != flags[l]) {
                        continue;
                    }
                    dp[l][r][remain] = Math.max(dp[l][r][remain],
                            dp(l, i - 1, 0) +
                                    dp(i, r, remain));
                    dp[l][r][remain] = Math.max(dp[l][r][remain],
                            dp(l, i - 1, 1) +
                                    dp(i, r, remain - 1));
                }
            }
            return dp[l][r][remain];
        }

    }

    static class SequenceUtils {
        public static void deepFill(Object array, long val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof long[]) {
                long[] longArray = (long[]) array;
                Arrays.fill(longArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
            }
        }

    }

    static class PreSum {
        private long[] pre;

        public PreSum(long[] a) {
            int n = a.length;
            pre = new long[n];
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a[i];
            }
        }

        public PreSum(int[] a) {
            int n = a.length;
            pre = new long[n];
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a[i];
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
}