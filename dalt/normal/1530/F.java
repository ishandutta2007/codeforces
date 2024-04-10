import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.io.Closeable;
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
            FBingo solver = new FBingo();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FBingo {
        int mod = 31607;
        Power pow = new Power(mod);
        int[] prob;
        int[] dp;

        public void consider(int i, int state, int p) {
            if (i < 0) {
                dp[state] = DigitUtils.mod(p, mod);
                return;
            }
            consider(i - 1, state | (1 << i), p * prob[i] % mod);
            consider(i - 1, state, p * (1 - prob[i]) % mod);
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int[][] prob = new int[n][n];
            int inv10000 = pow.inverse(10000);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    prob[i][j] = in.ri() * inv10000 % mod;
                }
            }
            int[] state = new int[1 << n + 2];
            int[] sum = new int[1 << n + 2];
            Arrays.fill(sum, 1);
            dp = new int[1 << n];
            for (int j = 0; j < n; j++) {
                this.prob = prob[j];
                consider(n - 1, 0, 1);
                dp[dp.length - 1] = 0;
                FastWalshHadamardTransform.andFWT(dp, 0, dp.length - 1, mod);
                int l = j;
                int r = n - 1 - j;
                int m1 = ((1 << l) | (1 << n));
                int m2 = ((1 << r) | (1 << n + 1));
                int mask = (1 << n) - 1;
                for (int i = 0; i < 1 << n + 2; i++) {
                    int actual = i;
                    if (Bits.get(i, l) != Bits.get(i, n)) {
                        actual |= m1;
                    }
                    if (Bits.get(i, r) != Bits.get(i, n + 1)) {
                        actual |= m2;
                    }
                    state[i] = dp[actual & mask];
                }
                for (int i = 0; i < 1 << n + 2; i++) {
                    sum[i] = sum[i] * state[i] % mod;
                }
            }

            FastWalshHadamardTransform.andIFWT(sum, 0, sum.length - 1, mod);
            int ans = 1 - sum[0];
            ans = DigitUtils.mod(ans, mod);
            out.println(ans);
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
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
        }

    }

    static class SequenceUtils {
        public static void swap(long[] data, int i, int j) {
            long tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private OutputStream writer;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);
        private static Field stringBuilderValueField;
        private char[] charBuf = new char[THRESHOLD * 2];
        private byte[] byteBuf = new byte[THRESHOLD * 2];

        static {
            try {
                stringBuilderValueField = StringBuilder.class.getSuperclass().getDeclaredField("value");
                stringBuilderValueField.setAccessible(true);
            } catch (Exception e) {
                stringBuilderValueField = null;
            }
            stringBuilderValueField = null;
        }

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

        public FastOutput(OutputStream writer) {
            this.writer = writer;
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

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append('\n');
        }

        public FastOutput flush() {
            try {
                if (stringBuilderValueField != null) {
                    try {
                        byte[] value = (byte[]) stringBuilderValueField.get(cache);
                        writer.write(value, 0, cache.length());
                    } catch (Exception e) {
                        stringBuilderValueField = null;
                    }
                }
                if (stringBuilderValueField == null) {
                    int n = cache.length();
                    if (n > byteBuf.length) {
                        //slow
                        writer.write(cache.toString().getBytes(StandardCharsets.UTF_8));
//                writer.append(cache);
                    } else {
                        cache.getChars(0, n, charBuf, 0);
                        for (int i = 0; i < n; i++) {
                            byteBuf[i] = (byte) charBuf[i];
                        }
                        writer.write(byteBuf, 0, n);
                    }
                }
                writer.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                writer.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class DigitUtils {
        private static LongExtGCDObject longExtGCDObject = new LongExtGCDObject();

        private DigitUtils() {
        }

        public static int mod(int x, int mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return x;
        }

        public static int modsub(int a, int b, int mod) {
            int ans = a - b;
            if (ans < 0) {
                ans += mod;
            }
            return ans;
        }

        public static int modplus(int a, int b, int mod) {
            int ans = a + b;
            if (ans >= mod) {
                ans -= mod;
            }
            return ans;
        }

        public static long mod(long x, long mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return x;
        }

        public static long modInverse(long x, long mod) {
            long g = longExtGCDObject.extgcd(x, mod);
            assert g == 1;
            long a = longExtGCDObject.getX();
            return DigitUtils.mod(a, mod);
        }

    }

    static class Bits {
        private Bits() {
        }

        public static int get(int x, int i) {
            return (x >>> i) & 1;
        }

    }

    static class FastWalshHadamardTransform {
        public static void andFWT(int[] p, int l, int r, int mod) {
            if (l == r) {
                return;
            }
            int m = (l + r) / 2;
            andFWT(p, l, m, mod);
            andFWT(p, m + 1, r, mod);
            for (int i = 0, until = m - l; i <= until; i++) {
                int a = p[l + i];
                int b = p[m + 1 + i];
                p[l + i] = DigitUtils.modplus(a, b, mod);
            }
        }

        public static void andIFWT(int[] p, int l, int r, int mod) {
            if (l == r) {
                return;
            }
            int m = (l + r) / 2;
            for (int i = 0, until = m - l; i <= until; i++) {
                int a = p[l + i];
                int b = p[m + 1 + i];
                p[l + i] = DigitUtils.modsub(a, b, mod);
            }
            andIFWT(p, l, m, mod);
            andIFWT(p, m + 1, r, mod);
        }

    }

    static interface InverseNumber {
    }

    static class ExtGCD {
        public static long extGCD(long a, long b, long[] xy) {
            if (a >= b) {
                return extGCD0(a, b, xy);
            }
            long ans = extGCD0(b, a, xy);
            SequenceUtils.swap(xy, 0, 1);
            return ans;
        }

        private static long extGCD0(long a, long b, long[] xy) {
            if (b == 0) {
                xy[0] = 1;
                xy[1] = 0;
                return a;
            }
            long ans = extGCD0(b, a % b, xy);
            long x = xy[0];
            long y = xy[1];
            xy[0] = y;
            xy[1] = x - a / b * y;
            return ans;
        }

    }

    static class Power implements InverseNumber {
        int mod;

        public Power(int mod) {
            this.mod = mod;
        }

        public int inverse(int x) {
            int ans = inverseExtGCD(x);
//        if(modular.mul(ans, x) != 1){
//            throw new IllegalStateException();
//        }
            return ans;
        }

        public int inverseExtGCD(int x) {
            return (int) DigitUtils.modInverse(x, mod);
        }

    }

    static class LongExtGCDObject {
        private long[] xy = new long[2];

        public long extgcd(long a, long b) {
            return ExtGCD.extGCD(a, b, xy);
        }

        public long getX() {
            return xy[0];
        }

    }
}