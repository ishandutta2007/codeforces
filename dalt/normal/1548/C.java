import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.math.BigInteger;
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
            CTheThreeLittlePigs solver = new CTheThreeLittlePigs();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CTheThreeLittlePigs {
        int mod = (int) 1e9 + 7;
        Combination comb = new Combination((int) 3e6 + 10, mod);

        public int[] div(int[] a, int[] b) {
            int[] res = new int[a.length];
            for (int i = a.length - 1; i >= (b.length - 1); i--) {
                int wpos = i - (b.length - 1);
                res[wpos] = a[i];
                for (int j = 0; j < b.length; j++) {
                    a[i - j] = DigitUtils.mod(a[i - j] - (long) res[wpos] * b[b.length - 1 - j], mod);
                }
            }
            return res;
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int q = in.ri();
            int[] numerator = new int[3 * (n + 1) + 1];
            for (int i = 0; i <= 3 * (n + 1); i++) {
                numerator[i] = comb.combination(3 * (n + 1), i);
            }
            int[] denominator = new int[3 + 1];
            for (int i = 0; i <= 3; i++) {
                numerator[i] -= comb.combination(3, i);
                if (numerator[i] < 0) {
                    numerator[i] += mod;
                }
                denominator[i] += comb.combination(3, i);
            }
            denominator[0]--;
            if (denominator[0] < mod) {
                denominator[0] += mod;
            }
            int[] res = div(numerator, denominator);
            for (int i = 0; i < q; i++) {
                int x = in.ri();
                out.println(res[x]);
            }
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int mod(long x, int mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return (int) x;
        }

    }

    static interface IntCombination {
    }

    static class Combination implements IntCombination {
        final Factorial factorial;
        int modVal;

        public Combination(Factorial factorial) {
            this.factorial = factorial;
            this.modVal = factorial.getMod();
        }

        public Combination(int limit, int mod) {
            this(new Factorial(limit, mod));
        }

        public int combination(int m, int n) {
            if (n > m || n < 0) {
                return 0;
            }
            return (int) ((long) factorial.fact(m) * factorial.invFact(n) % modVal * factorial.invFact(m - n) % modVal);
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

    static class Factorial {
        int[] fact;
        int[] inv;
        int mod;

        public int getMod() {
            return mod;
        }

        public Factorial(int[] fact, int[] inv, int mod) {
            this.mod = mod;
            this.fact = fact;
            this.inv = inv;
            fact[0] = inv[0] = 1;
            int n = Math.min(fact.length, mod);
            for (int i = 1; i < n; i++) {
                fact[i] = i;
                fact[i] = (int) ((long) fact[i] * fact[i - 1] % mod);
            }
            if (n - 1 >= 0) {
                inv[n - 1] = BigInteger.valueOf(fact[n - 1]).modInverse(BigInteger.valueOf(mod)).intValue();
            }
            for (int i = n - 2; i >= 1; i--) {
                inv[i] = (int) ((long) inv[i + 1] * (i + 1) % mod);
            }
        }

        public Factorial(int limit, int mod) {
            this(new int[Math.min(limit + 1, mod)], new int[Math.min(limit + 1, mod)], mod);
        }

        public int fact(int n) {
            if (n >= mod) {
                return 0;
            }
            return fact[n];
        }

        public int invFact(int n) {
            if (n >= mod) {
                throw new IllegalArgumentException();
            }
            return inv[n];
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
}