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
            EPhoenixAndComputers solver = new EPhoenixAndComputers();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EPhoenixAndComputers {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int mod = in.ri();
            CachedPow2 cp = new CachedPow2(2, mod, n + 1, mod - 1);
            Combination comb = new Combination(n + 1, mod);
            long[][][] dp = new long[n + 1][n + 1][2];
            dp[0][0][0] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    dp[i][j][0] = dp[i - 1][j][1];
                    for (int k = 0; k < i; k++) {
                        int len = i - k;
                        int last = j - len;
                        if (last >= 0) {
                            dp[i][j][1] += dp[k][last][0] * cp.pow(len - 1) % mod * comb.combination(j, len) % mod;
                        }
                    }
                    dp[i][j][1] %= mod;
                }
            }

            long ans = 0;
            for (int i = 0; i <= n; i++) {
                ans += dp[n][i][1];
            }

            ans %= mod;
            out.println(ans);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
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

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append('\n');
        }

        public FastOutput flush() {
            try {
//            boolean success = false;
//            if (stringBuilderValueField != null) {
//                try {
//                    char[] value = (char[]) stringBuilderValueField.get(cache);
//                    os.write(value, 0, cache.length());
//                    success = true;
//                } catch (Exception e) {
//                }
//            }
//            if (!success) {
                os.append(cache);
//            }
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

    static interface IntegerEntryIterator {
        boolean hasNext();

        void next();

        int getEntryKey();

        int getEntryValue();

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

    static class Hasher {
        private long time = System.nanoTime() + System.currentTimeMillis() * 31L;

        public int shuffle(long z) {
            z += time;
            z = (z ^ (z >>> 33)) * 0x62a9d9ed799705f5L;
            return (int) (((z ^ (z >>> 28)) * 0xcb24d0a5c88c35b3L) >>> 32);
        }

        public int hash(int x) {
            return shuffle(x);
        }

    }

    static class CachedEulerFunction {
        private static int boundary = 1 << 16;
        private static int[] euler = MultiplicativeFunctionSieve.getInstance(boundary).getEuler();
        private static IntegerHashMap map = new IntegerHashMap(64, true);

        public static int get(int x) {
            return get(x, 2);
        }

        private static int get(int x, int begin) {
            if (x <= boundary) {
                return euler[x];
            }
            int ans = map.getOrDefault(x, -1);
            if (ans == -1) {
                int factor = findPrimeFactor(x, begin);
                int y = x;
                int exp = 1;
                while (y % factor == 0) {
                    y /= factor;
                    exp *= factor;
                }
                ans = get(y, factor + 1) * (exp - exp / factor);
                //ans = calc(x);
                map.put(x, ans);
            }
            return ans;
        }

        private static int findPrimeFactor(int x, int begin) {
            for (int i = Math.max(2, begin); i * i <= x; i++) {
                if (x % i == 0) {
                    return i;
                }
            }
            return x;
        }

    }

    static interface IntCombination {
    }

    static class MultiplicativeFunctionSieve {
        static MultiplicativeFunctionSieve instance = new MultiplicativeFunctionSieve(1 << 16);
        public int[] primes;
        public boolean[] isComp;
        public int primeLength;
        public int[] smallestPrimeFactor;
        public int[] expOfSmallestPrimeFactor;
        int limit;

        public static MultiplicativeFunctionSieve getInstance(int n) {
            if (n <= (1 << 16)) {
                return instance;
            }
            return new MultiplicativeFunctionSieve(n);
        }

        public int[] getEuler() {
            int[] euler = new int[limit + 1];
            euler[1] = 1;
            for (int i = 2; i <= limit; i++) {
                if (!isComp[i]) {
                    euler[i] = i - 1;
                } else {
                    if (expOfSmallestPrimeFactor[i] == i) {
                        euler[i] = i - i / smallestPrimeFactor[i];
                    } else {
                        euler[i] = euler[expOfSmallestPrimeFactor[i]] * euler[i / expOfSmallestPrimeFactor[i]];
                    }
                }
            }
            return euler;
        }

        public MultiplicativeFunctionSieve(int limit) {
            this.limit = limit;
            isComp = new boolean[limit + 1];
            primes = new int[limit + 1];
            expOfSmallestPrimeFactor = new int[limit + 1];
            smallestPrimeFactor = new int[limit + 1];
            primeLength = 0;
            for (int i = 2; i <= limit; i++) {
                if (!isComp[i]) {
                    primes[primeLength++] = i;
                    expOfSmallestPrimeFactor[i] = smallestPrimeFactor[i] = i;
                }
                for (int j = 0, until = limit / i; j < primeLength && primes[j] <= until; j++) {
                    int pi = primes[j] * i;
                    smallestPrimeFactor[pi] = primes[j];
                    expOfSmallestPrimeFactor[pi] = smallestPrimeFactor[i] == primes[j]
                            ? (expOfSmallestPrimeFactor[i] * expOfSmallestPrimeFactor[primes[j]])
                            : expOfSmallestPrimeFactor[primes[j]];
                    isComp[pi] = true;
                    if (i % primes[j] == 0) {
                        break;
                    }
                }
            }
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

    static class CachedPow2 {
        private int[] first;
        private int[] second;
        private int mod;
        private int low;
        private int mask;
        private int phi;
        private int xphi;

        public CachedPow2(int x, int mod) {
            this(x, mod, CachedEulerFunction.get(mod));
        }

        public CachedPow2(int x, int mod, int phi) {
            this(x, mod, mod, phi);
        }

        public CachedPow2(int x, int mod, int limit, int phi) {
            this.phi = phi;
            limit = Math.min(limit, mod);
            this.mod = mod;
            int log = Log2.ceilLog(limit + 1);
            low = (log + 1) / 2;
            mask = (1 << low) - 1;
            first = new int[1 << low];
            second = new int[1 << log - low];
            first[0] = 1;
            for (int i = 1; i < first.length; i++) {
                first[i] = (int) ((long) x * first[i - 1] % mod);
            }
            second[0] = 1;
            long step = (long) x * first[first.length - 1] % mod;
            for (int i = 1; i < second.length; i++) {
                second[i] = (int) (second[i - 1] * step % mod);
            }

            xphi = DigitUtils.modPow(x, phi, mod);
        }

        public int pow(int exp) {
            return (int) ((long) first[exp & mask] * second[exp >> low] % mod);
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

        public static int mod(int x, int mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return x;
        }

        public static int modPow(int x, long n, int m) {
            if (n == 0) {
                return DigitUtils.mod(1, m);
            }
            int ans = modPow(x, n / 2, m);
            ans = DigitUtils.mod((long) ans * ans, m);
            if (n % 2 == 1) {
                ans = DigitUtils.mod((long) ans * x, m);
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

    static class Log2 {
        public static int ceilLog(int x) {
            if (x <= 0) {
                return 0;
            }
            return 32 - Integer.numberOfLeadingZeros(x - 1);
        }

    }

    static class IntegerHashMap {
        private int now;
        private int[] slot;
        private int[] version;
        private int[] next;
        private int[] keys;
        private int[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;
        private Hasher hasher = new Hasher();

        public IntegerHashMap(int cap, boolean rehash) {
            now = 1;
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            version = new int[slot.length];
            next = new int[cap + 1];
            keys = new int[cap + 1];
            values = new int[cap + 1];
            removed = new boolean[cap + 1];
            this.rehash = rehash;
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            keys = Arrays.copyOf(keys, newSize);
            values = Arrays.copyOf(values, newSize);
            removed = Arrays.copyOf(removed, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
            removed[alloc] = false;
            size++;
        }

        private void rehash() {
            int[] newSlots = new int[Math.max(16, slot.length * 2)];
            int[] newVersions = new int[newSlots.length];
            int newMask = newSlots.length - 1;
            for (int i = 0; i < slot.length; i++) {
                access(i);
                if (slot[i] == 0) {
                    continue;
                }
                int head = slot[i];
                while (head != 0) {
                    int n = next[head];
                    int s = hash(keys[head]) & newMask;
                    next[head] = newSlots[s];
                    newSlots[s] = head;
                    head = n;
                }
            }
            this.slot = newSlots;
            this.version = newVersions;
            now = 0;
            this.mask = newMask;
        }

        private int hash(int x) {
            return hasher.hash(x);
        }

        public void put(int x, int y) {
            put(x, y, true);
        }

        public void put(int x, int y, boolean cover) {
            int h = hash(x);
            int s = h & mask;
            access(s);
            if (slot[s] == 0) {
                alloc();
                slot[s] = alloc;
                keys[alloc] = x;
                values[alloc] = y;
            } else {
                int index = findIndexOrLastEntry(s, x);
                if (keys[index] != x) {
                    alloc();
                    next[index] = alloc;
                    keys[alloc] = x;
                    values[alloc] = y;
                } else if (cover) {
                    values[index] = y;
                }
            }
            if (rehash && size >= slot.length) {
                rehash();
            }
        }

        public int getOrDefault(int x, int def) {
            int h = hash(x);
            int s = h & mask;
            access(s);
            if (slot[s] == 0) {
                return def;
            }
            int index = findIndexOrLastEntry(s, x);
            return keys[index] == x ? values[index] : def;
        }

        private int findIndexOrLastEntry(int s, int x) {
            int iter = slot[s];
            while (keys[iter] != x) {
                if (next[iter] != 0) {
                    iter = next[iter];
                } else {
                    return iter;
                }
            }
            return iter;
        }

        private void access(int i) {
            if (version[i] != now) {
                version[i] = now;
                slot[i] = 0;
            }
        }

        public IntegerEntryIterator iterator() {
            return new IntegerEntryIterator() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public int getEntryKey() {
                    return keys[readIndex];
                }


                public int getEntryValue() {
                    return values[readIndex];
                }


                public void next() {
                    if (!hasNext()) {
                        throw new IllegalStateException();
                    }
                    readIndex = index;
                    index++;
                }
            };
        }

        public String toString() {
            IntegerEntryIterator iterator = iterator();
            StringBuilder builder = new StringBuilder("{");
            while (iterator.hasNext()) {
                iterator.next();
                builder.append(iterator.getEntryKey()).append("->").append(iterator.getEntryValue()).append(',');
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append('}');
            return builder.toString();
        }

    }
}