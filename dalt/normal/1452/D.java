import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
            DRadioTowers solver = new DRadioTowers();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DRadioTowers {
        int mod = 998244353;
        Combination comb = new Combination((int) 1e6, mod);
        CachedPow pow = new CachedPow(2, mod);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            long prob = 0;
            for (int i = 1; i <= n; i++) {
                if ((n - i) % 2 != 0) {
                    continue;
                }
                int m = (n - i) / 2;
                long way = comb.combination(m + i - 1, i - 1);
                prob += way * pow.inverse(n) % mod;
            }
            prob %= mod;
            out.println(prob);
        }

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

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 1 << 13;
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

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
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

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int negate(int x, int mod) {
            return x == 0 ? 0 : mod - x;
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
            inv[n - 1] = BigInteger.valueOf(fact[n - 1]).modInverse(BigInteger.valueOf(mod)).intValue();
            for (int i = n - 2; i >= 1; i--) {
                inv[i] = (int) ((long) inv[i + 1] * (i + 1) % mod);
            }
        }

        public Factorial(int limit, int mod) {
            this(new int[limit + 1], new int[limit + 1], mod);
        }

        public int fact(int n) {
            return fact[n];
        }

        public int invFact(int n) {
            return inv[n];
        }

    }

    static interface IntCombination {
    }

    static class CachedPow {
        private int[] first;
        private int[] second;
        private int mod;
        private int powMod;
        private static int step = 16;
        private static int limit = 1 << step;
        private static int mask = limit - 1;

        public CachedPow(int x, int mod) {
            this.mod = mod;
            this.powMod = mod - 1;
            first = new int[limit];
            second = new int[Integer.MAX_VALUE / limit + 1];
            first[0] = 1;
            for (int i = 1; i < first.length; i++) {
                first[i] = (int) ((long) x * first[i - 1] % mod);
            }
            second[0] = 1;
            long step = (long) x * first[first.length - 1] % mod;
            for (int i = 1; i < second.length; i++) {
                second[i] = (int) (second[i - 1] * step % mod);
            }
        }

        public int pow(int exp) {
            return (int) ((long) first[exp & mask] * second[exp >> step] % mod);
        }

        public int inverse(int exp) {
            return pow(DigitUtils.negate(exp, powMod));
        }

    }
}