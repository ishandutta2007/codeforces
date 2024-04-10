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
            EKuroAndTopologicalParity solver = new EKuroAndTopologicalParity();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EKuroAndTopologicalParity {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int p = in.readInt();

            Modular mod = new Modular(1e9 + 7);
            CachedPow pow = new CachedPow(2, n, mod);

            int[][][][] dp = new int[n + 1][2][2][2];
            dp[0][0][0][0] = 1;

            for (int i = 1; i <= n; i++) {
                int c = in.readInt();

                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        for (int t = 0; t < 2; t++) {
                            int cnt = i - 2 >= 0 ? pow.pow(i - 2) : 1;
                            if (c != 1) {
                                if (t == 1) {
                                    //pick odd
                                    dp[i][j][k][t] = mod.plus(dp[i][j][k][t], mod.mul(dp[i - 1][j][k][t], cnt));
                                    if (k == 1) {
                                        //pick even
                                        dp[i][j][k][t] = mod.plus(dp[i][j][k][t], mod.mul(mod.plus(dp[i - 1][1 - j][1][t], dp[i - 1][1 - j][0][t]), cnt));
                                    }
                                } else {
                                    if (k == 1) {
                                        dp[i][j][k][t] = mod.plus(dp[i][j][k][t], mod.mul(mod.plus(dp[i - 1][1 - j][0][t], dp[i - 1][1 - j][1][t]), pow.pow(i - 1)));
                                    }
                                }
                            }
                            if (c != 0) {
                                //pick odd
                                if (k == 1) {
                                    dp[i][j][k][t] = mod.plus(dp[i][j][k][t], mod.mul(dp[i - 1][j][k][t], cnt));
                                    if (t == 1) {
                                        //pick even
                                        dp[i][j][k][t] = mod.plus(dp[i][j][k][t], mod.mul(mod.plus(dp[i - 1][1 - j][k][1], dp[i - 1][1 - j][k][0]), cnt));
                                    }
                                } else {
                                    if (t == 1) {
                                        //pick even
                                        dp[i][j][k][t] = mod.plus(dp[i][j][k][t], mod.mul(mod.plus(dp[i - 1][1 - j][k][1], dp[i - 1][1 - j][k][0]), pow.pow(i - 1)));
                                    }
                                }

                            }
                        }
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    ans = mod.plus(dp[n][p][i][j], ans);
                }
            }

            out.println(ans);
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

    static class Modular {
        int m;

        public int getMod() {
            return m;
        }

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

        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public Modular getModularForPowerComputation() {
            return new Modular(m - 1);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long round(double x) {
            if (x >= 0) {
                return (long) (x + 0.5);
            } else {
                return (long) (x - 0.5);
            }
        }

    }

    static class CachedPow {
        private int[] first;
        private int[] second;
        private Modular mod;
        private Modular powMod;

        public CachedPow(int x, Modular mod) {
            this(x, mod.getMod(), mod);
        }

        public CachedPow(int x, int maxExp, Modular mod) {
            this.mod = mod;
            this.powMod = mod.getModularForPowerComputation();
            int k = Math.max(1, (int) DigitUtils.round(Math.sqrt(maxExp)));
            first = new int[k];
            second = new int[maxExp / k + 1];
            first[0] = 1;
            for (int i = 1; i < k; i++) {
                first[i] = mod.mul(x, first[i - 1]);
            }
            second[0] = 1;
            int step = mod.mul(x, first[k - 1]);
            for (int i = 1; i < second.length; i++) {
                second[i] = mod.mul(second[i - 1], step);
            }
        }

        public int pow(int exp) {
            return mod.mul(first[exp % first.length], second[exp / first.length]);
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