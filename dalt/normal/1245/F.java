import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
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
            TaskF solver = new TaskF();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }
    static class TaskF {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int l = in.readInt();
            int r = in.readInt();

            int[] bitsOfL = new int[32];
            int[] bitsOfR = new int[32];
            DigitUtils.BitOperator bo = new DigitUtils.BitOperator();
            for (int i = 0; i < 32; i++) {
                bitsOfL[i] = bo.bitAt(l, i);
                bitsOfR[i] = bo.bitAt(r, i);
            }

            long[][][][] dp = new long[33][2][2][2];
            dp[32][1][1][1] = 1;
            for (int i = 31; i >= 0; i--) {
                // 000
                // 10
                // 01
                // 00
                dp[i][0][0][0] += 3 * dp[i + 1][0][0][0];

                // 001
                // 10
                dp[i][0][0][0] += dp[i + 1][0][0][1];
                // 00
                dp[i][0][0][1] += dp[i + 1][0][0][1];

                // 010
                if (bitsOfL[i] == 0) {
                    // 00
                    // 10
                    dp[i][0][1][0] += 2 * dp[i + 1][0][1][0];
                    // 01
                    dp[i][0][0][0] += dp[i + 1][0][1][0];
                } else {
                    // 01
                    dp[i][0][1][0] += dp[i + 1][0][1][0];
                }

                // 011
                if (bitsOfL[i] == 0) {
                    // 10
                    dp[i][0][1][0] += dp[i + 1][0][1][1];
                    // 00
                    dp[i][0][1][1] += dp[i + 1][0][1][1];
                } else {
                    // 11
                }

                // 100
                if (bitsOfR[i] == 0) {
                    // 00
                    // 01
                    dp[i][1][0][0] += 2 * dp[i + 1][1][0][0];
                } else {
                    // 10
                    dp[i][1][0][0] += dp[i + 1][1][0][0];
                    // 00
                    // 01
                    dp[i][0][0][0] += 2 * dp[i + 1][1][0][0];
                }

                // 101
                if (bitsOfR[i] == 0) {
                    // 00
                    dp[i][1][0][1] += dp[i + 1][1][0][1];
                } else {
                    // 10
                    dp[i][1][0][0] += dp[i + 1][1][0][1];
                    // 00
                    dp[i][0][0][1] += dp[i + 1][1][0][1];
                }

                // 110
                if (bitsOfR[i] == 0 && bitsOfL[i] == 0) {
                    // 00
                    dp[i][1][1][0] += dp[i + 1][1][1][0];
                    // 01
                    dp[i][1][0][0] += dp[i + 1][1][1][0];
                }
                if (bitsOfR[i] == 0 && bitsOfL[i] == 1) {
                    // 01
                    dp[i][1][1][0] += dp[i + 1][1][1][0];
                }
                if (bitsOfR[i] == 1 && bitsOfL[i] == 0) {
                    // 00
                    dp[i][0][1][0] += dp[i + 1][1][1][0];
                    // 10
                    dp[i][1][1][0] += dp[i + 1][1][1][0];
                    // 01
                    dp[i][0][0][0] += dp[i + 1][1][1][0];
                }
                if (bitsOfR[i] == 1 && bitsOfL[i] == 1) {
                    // 01
                    dp[i][0][1][0] += dp[i + 1][1][1][0];
                }

                // 111
                if (bitsOfR[i] == 0 && bitsOfL[i] == 0) {
                    // 00
                    dp[i][1][1][1] += dp[i + 1][1][1][1];
                }
                if (bitsOfR[i] == 1 && bitsOfL[i] == 0) {
                    // 00
                    dp[i][0][1][1] += dp[i + 1][1][1][1];
                    // 10
                    dp[i][1][1][0] += dp[i + 1][1][1][1];
                }
            }

            long ans = 2 * (dp[0][1][1][0] + dp[0][0][1][0] + dp[0][0][0][0] + dp[0][1][0][0]);

            if (l == 0) {
                ans++;
            }

            out.println(ans);
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
    static class DigitUtils {
        private static final long[] DIGIT_VALUES = new long[19];
        static {
            DIGIT_VALUES[0] = 1;
            for (int i = 1; i < 19; i++) {
                DIGIT_VALUES[i] = DIGIT_VALUES[i - 1] * 10;
            }
        }

        private DigitUtils() {}

        public static class BitOperator {
            public int bitAt(int x, int i) {
                return (x >> i) & 1;
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
}