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
            ECommonNumber solver = new ECommonNumber();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ECommonNumber {
        private long[][] dp = new long[62][2];
        private long n;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            long n = in.readLong();
            long m = in.readLong();

            LongBinarySearch lbs1 = new LongBinarySearch() {

                public boolean check(long mid) {
                    mid = mid * 2 + 1;
                    return count(n, mid) < m;
                }
            };
            LongBinarySearch lbs2 = new LongBinarySearch() {

                public boolean check(long mid) {
                    mid = mid * 2;
                    return count(n, mid) + count(n, mid + 1) < m;
                }
            };

            long ans1 = lbs1.binarySearch(0, (long) 1e18);
            if (ans1 == 0) {
                ans1 = -1;
            } else if (lbs1.check(ans1)) {
                ans1 = (ans1 - 1) * 2 + 1;
            } else {
                ans1 = ans1 * 2 + 1;
            }

            long ans2 = lbs2.binarySearch(1, (long) 1e18);
            if (lbs2.check(ans2)) {
                ans2 = (ans2 - 1) * 2;
            } else {
                ans2 = ans2 * 2;
            }

            long ans = Math.max(ans1, ans2);
            out.println(ans);
        }

        public long dp(int i, int ceil) {
            if (i < 0) {
                return 1;
            }
            if (dp[i][ceil] == -1) {
                int bit = Bits.bitAt(n, i);
                dp[i][ceil] = 0;
                for (int j = 0; j <= 1; j++) {
                    if (ceil == 1 && j > bit) {
                        continue;
                    }
                    dp[i][ceil] += dp(i - 1, ceil == 1 &&
                            bit == j ? 1 : 0);
                }
            }
            return dp[i][ceil];
        }

        public long count(long n, long prefix) {
            if (prefix > n) {
                return 0;
            }
            int len = CachedLog2.floorLog(prefix);
            int totalLen = CachedLog2.floorLog(n);
            long ans = 0;
            for (int i = len; i < totalLen; i++) {
                ans += 1L << (i - len);
            }
            this.n = n;
            SequenceUtils.deepFill(dp, -1L);
            if (prefix > (n >>> (totalLen - len))) {
                return ans;
            }
            int ceil = (prefix == (n >>> (totalLen - len))) ? 1 : 0;
            long plus = dp(totalLen - len - 1, ceil);
            return ans + plus;
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

        public FastOutput append(long c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(long c) {
            return append(c).println();
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

        public static int floorLog(long x) {
            int ans = 0;
            while (x >= LIMIT) {
                ans += BITS;
                x >>>= BITS;
            }
            return ans + CACHE[(int) x];
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 20];
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

        public long readLong() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            long val = 0;
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

    static class Bits {
        private Bits() {
        }

        public static int bitAt(long x, int i) {
            return (int) ((x >> i) & 1);
        }

    }

    static abstract class LongBinarySearch {
        public abstract boolean check(long mid);

        public long binarySearch(long l, long r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            while (l < r) {
                long mid = (l + r) >>> 1;
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }

    }
}