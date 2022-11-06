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
            H1MultithreadingEasyVersion solver = new H1MultithreadingEasyVersion();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class H1MultithreadingEasyVersion {
        int mod = 998244353;
        Combination comb = new Combination((int) 1e6, mod);
        Power pow = new Power(mod);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();

            int[] cnts = new int[2];
            int[] marks = new int[2];

            for (int i = 0; i < n; i++) {
                char c = in.rc();
                if (c == 'b') {
                    cnts[i & 1]++;
                }
                if (c == '?') {
                    marks[i & 1]++;
                }
            }
            long[] way = new long[n + 1];
            long[] waySum = new long[n + 1];
            for (int i = 0; i <= n; i++) {
                if (i < cnts[1]) {
                    way[i] = 0;
                    waySum[i] = 0;
                    continue;
                }
                int req = i - cnts[1];
                way[i] = comb.combination(marks[1], req);
                waySum[i] = way[i] * i % mod;
            }
            ModPreSum[] wayPs = new ModPreSum[2];
            ModPreSum[] waySumPs = new ModPreSum[2];
            for (int i = 0; i < 2; i++) {
                wayPs[i] = new ModPreSum(n + 1, mod);
                waySumPs[i] = new ModPreSum(n + 1, mod);
                int finalI = i;
                wayPs[i].populate(j -> (j & 1) == finalI ? (int) way[j] : 0, n + 1);
                waySumPs[i].populate(j -> (j & 1) == finalI ? (int) waySum[j] : 0, n + 1);
            }
            long sum = 0;
            for (int i = 0; i <= n; i++) {
                if (i < cnts[0]) {
                    continue;
                }
                int sign = i & 1;
                int req = i - cnts[0];
                long local = 0;
                local += i * wayPs[sign].prefix(i) - waySumPs[sign].prefix(i);
                local += -i * wayPs[sign].post(i + 1) + waySumPs[sign].post(i + 1);
                local = local % mod * comb.combination(marks[0], req) % mod;
                sum += local;
            }
            sum = sum % mod * pow.inversePower(2, marks[0] + marks[1]);
            sum = DigitUtils.mod(sum, mod);
            out.println(sum);
        }

    }

    static interface IntCombination {
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

        public String toString() {
            return "mod " + m;
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

    static interface IntToIntegerFunction {
        int apply(int x);

    }

    static class ModPreSum {
        private int[] pre;
        private int mod;
        private int n;

        public ModPreSum(int n, int mod) {
            pre = new int[n];
            this.mod = mod;
        }

        public void populate(IntToIntegerFunction a, int n) {
            this.n = n;
            if (n <= 0) {
                return;
            }
            pre[0] = a.apply(0);
            for (int i = 1; i < n; i++) {
                pre[i] = (pre[i - 1] + a.apply(i)) % mod;
            }
        }

        public long prefix(int i) {
            i = Math.min(i, n - 1);
            if (i < 0) {
                return 0;
            }
            return pre[i];
        }

        public long post(int i) {
            return DigitUtils.modsub(prefix(n), prefix(i - 1), mod);
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

        public static long modsub(long a, long b, long mod) {
            long ans = a - b;
            if (ans < 0) {
                ans += mod;
            }
            return ans;
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

    static interface InverseNumber {
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

        public char rc() {
            return readChar();
        }

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

    }

    static class Power implements InverseNumber {
        int mod;

        public Power(Modular modular) {
            this.mod = modular.getMod();
        }

        public Power(int mod) {
            this(new Modular(mod));
        }

        public int pow(int x, long n) {
            if (n == 0) {
                return 1 % mod;
            }
            long r = pow(x, n >> 1);
            r = r * r % mod;
            if ((n & 1) == 1) {
                r = r * x % mod;
            }
            return (int) r;
        }

        public int inversePower(int x, long n) {
            n = DigitUtils.mod(-n, mod - 1);
            return pow(x, n);
        }

    }
}