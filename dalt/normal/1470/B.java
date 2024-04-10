import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.Serializable;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
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
            BStrangeDefinition solver = new BStrangeDefinition();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class BStrangeDefinition {
        MultiSetHasher hasher = new SparseMultiSetHasher((int) 1e6);
        LongHashMap map = new LongHashMap((int) 1e6, false);
        MultiplicativeFunctionSieve sieve = new MultiplicativeFunctionSieve((int) 1e6);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            map.clear();
            int n = in.ri();
            int[] a = new int[n];
            in.populate(a);
            int[] factors = sieve.getSmallestPrimeFactor();

            for (int x : a) {
                long sum = 0;
                while (x != 1) {
                    int factor = factors[x];
                    int xor = 0;
                    while (x % factor == 0) {
                        x /= factor;
                        xor ^= 1;
                    }
                    if (xor == 1) {
                        sum = hasher.merge(sum, hasher.hash(factor));
                    }
                }
                map.put(sum, map.getOrDefault(sum, 0) + 1);
            }

            long max = 0;
            long sumOfZero = 0;
            for (LongEntryIterator iterator = map.iterator(); iterator.hasNext(); ) {
                iterator.next();
                long k = iterator.getEntryKey();
                long v = iterator.getEntryValue();
                max = Math.max(v, max);
                if (k == 0 || v % 2 == 0) {
                    sumOfZero += v;
                }
            }
            long max2 = Math.max(max, sumOfZero);
            int q = in.ri();
            for (int i = 0; i < q; i++) {
                long w = in.rl();
                if (w == 0) {
                    out.println(max);
                } else {
                    out.println(max2);
                }
            }
        }

    }

    static interface MultiSetHasher {
        long hash(long x);

        long merge(long a, long b);

    }

    static class MultiplicativeFunctionSieve {
        public int[] primes;
        public boolean[] isComp;
        public int primeLength;
        public int[] smallestPrimeFactor;
        public int[] expOfSmallestPrimeFactor;
        int limit;

        public int[] getSmallestPrimeFactor() {
            return smallestPrimeFactor;
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

    static class RandomWrapper {
        private MersenneTwisterFast random;
        public static final RandomWrapper INSTANCE = new RandomWrapper();

        public RandomWrapper() {
            this(new MersenneTwisterFast());
        }

        public RandomWrapper(MersenneTwisterFast random) {
            this.random = random;
        }

        public RandomWrapper(long seed) {
            this(new MersenneTwisterFast(seed));
        }

        public long nextLong(long l, long r) {
            return random.nextLong(r - l + 1) + l;
        }

    }

    static strictfp class MersenneTwisterFast implements Serializable, Cloneable {
        private static final int N = 624;
        private static final int M = 397;
        private static final int MATRIX_A = 0x9908b0df;
        private static final int UPPER_MASK = 0x80000000;
        private static final int LOWER_MASK = 0x7fffffff;
        private static final int TEMPERING_MASK_B = 0x9d2c5680;
        private static final int TEMPERING_MASK_C = 0xefc60000;
        private int[] mt;
        private int mti;
        private int[] mag01;
        private boolean __haveNextNextGaussian;

        public Object clone() {
            try {
                MersenneTwisterFast f = (MersenneTwisterFast) (super.clone());
                f.mt = (int[]) (mt.clone());
                f.mag01 = (int[]) (mag01.clone());
                return f;
            } catch (CloneNotSupportedException e) {
                throw new InternalError();
            } // should never happen
        }

        public MersenneTwisterFast() {
            this(System.currentTimeMillis());
        }

        public MersenneTwisterFast(long seed) {
            setSeed(seed);
        }

        public MersenneTwisterFast(int[] array) {
            setSeed(array);
        }

        public void setSeed(long seed) {
            // Due to a bug in java.util.Random clear up to 1.2, we're
            // doing our own Gaussian variable.
            __haveNextNextGaussian = false;

            mt = new int[N];

            mag01 = new int[2];
            mag01[0] = 0x0;
            mag01[1] = MATRIX_A;

            mt[0] = (int) (seed & 0xffffffff);
            for (mti = 1; mti < N; mti++) {
                mt[mti] =
                        (1812433253 * (mt[mti - 1] ^ (mt[mti - 1] >>> 30)) + mti);
                /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
                /* In the previous versions, MSBs of the seed affect   */
                /* only MSBs of the array mt[].                        */
                /* 2002/01/09 modified by Makoto Matsumoto             */
                // mt[mti] &= 0xffffffff;
                /* for >32 bit machines */
            }
        }

        public void setSeed(int[] array) {
            if (array.length == 0)
                throw new IllegalArgumentException("Array length must be greater than zero");
            int i, j, k;
            setSeed(19650218);
            i = 1;
            j = 0;
            k = (N > array.length ? N : array.length);
            for (; k != 0; k--) {
                mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >>> 30)) * 1664525)) + array[j] + j; /* non linear */
                // mt[i] &= 0xffffffff; /* for WORDSIZE > 32 machines */
                i++;
                j++;
                if (i >= N) {
                    mt[0] = mt[N - 1];
                    i = 1;
                }
                if (j >= array.length) j = 0;
            }
            for (k = N - 1; k != 0; k--) {
                mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >>> 30)) * 1566083941)) - i; /* non linear */
                // mt[i] &= 0xffffffff; /* for WORDSIZE > 32 machines */
                i++;
                if (i >= N) {
                    mt[0] = mt[N - 1];
                    i = 1;
                }
            }
            mt[0] = 0x80000000; /* MSB is 1; assuring non-zero initial array */
        }

        public long nextLong(long n) {
            if (n <= 0)
                throw new IllegalArgumentException("n must be positive, got: " + n);

            long bits, val;
            do {
                int y;
                int z;

                if (mti >= N)   // generate N words at one time
                {
                    int kk;
                    final int[] mt = this.mt; // locals are slightly faster
                    final int[] mag01 = this.mag01; // locals are slightly faster

                    for (kk = 0; kk < N - M; kk++) {
                        y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
                        mt[kk] = mt[kk + M] ^ (y >>> 1) ^ mag01[y & 0x1];
                    }
                    for (; kk < N - 1; kk++) {
                        y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
                        mt[kk] = mt[kk + (M - N)] ^ (y >>> 1) ^ mag01[y & 0x1];
                    }
                    y = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
                    mt[N - 1] = mt[M - 1] ^ (y >>> 1) ^ mag01[y & 0x1];

                    mti = 0;
                }

                y = mt[mti++];
                y ^= y >>> 11;                          // TEMPERING_SHIFT_U(y)
                y ^= (y << 7) & TEMPERING_MASK_B;       // TEMPERING_SHIFT_S(y)
                y ^= (y << 15) & TEMPERING_MASK_C;      // TEMPERING_SHIFT_T(y)
                y ^= (y >>> 18);                        // TEMPERING_SHIFT_L(y)

                if (mti >= N)   // generate N words at one time
                {
                    int kk;
                    final int[] mt = this.mt; // locals are slightly faster
                    final int[] mag01 = this.mag01; // locals are slightly faster

                    for (kk = 0; kk < N - M; kk++) {
                        z = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
                        mt[kk] = mt[kk + M] ^ (z >>> 1) ^ mag01[z & 0x1];
                    }
                    for (; kk < N - 1; kk++) {
                        z = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
                        mt[kk] = mt[kk + (M - N)] ^ (z >>> 1) ^ mag01[z & 0x1];
                    }
                    z = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
                    mt[N - 1] = mt[M - 1] ^ (z >>> 1) ^ mag01[z & 0x1];

                    mti = 0;
                }

                z = mt[mti++];
                z ^= z >>> 11;                          // TEMPERING_SHIFT_U(z)
                z ^= (z << 7) & TEMPERING_MASK_B;       // TEMPERING_SHIFT_S(z)
                z ^= (z << 15) & TEMPERING_MASK_C;      // TEMPERING_SHIFT_T(z)
                z ^= (z >>> 18);                        // TEMPERING_SHIFT_L(z)

                bits = (((((long) y) << 32) + (long) z) >>> 1);
                val = bits % n;
            } while (bits - val + (n - 1) < 0);
            return val;
        }

    }

    static class SparseMultiSetHasher extends MultiSetHasherImpl {
        private LongHashMap map;

        public SparseMultiSetHasher(int cap) {
            map = new LongHashMap(cap, true);
        }

        public long hash(long x) {
            long ans = map.getOrDefault(x, -1);
            if (ans == -1) {
                ans = super.hash(x);
                map.put(x, ans);
            }
            return map.get(x);
        }

    }

    static class LongModular2305843009213693951 implements ILongModular {
        private static long mod = 2305843009213693951L;
        private static final LongModular2305843009213693951 INSTANCE = new LongModular2305843009213693951();

        private LongModular2305843009213693951() {
        }

        public static final LongModular2305843009213693951 getInstance() {
            return INSTANCE;
        }

        public long getMod() {
            return mod;
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

    static class LongHashMap {
        private int now;
        private int[] slot;
        private int[] version;
        private int[] next;
        private long[] keys;
        private long[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;
        private Hasher hasher = new Hasher();

        public LongHashMap(int cap, boolean rehash) {
            now = 1;
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            version = new int[slot.length];
            next = new int[cap + 1];
            keys = new long[cap + 1];
            values = new long[cap + 1];
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

        private int hash(long x) {
            return hasher.hash(x);
        }

        public void put(long x, long y) {
            put(x, y, true);
        }

        public void put(long x, long y, boolean cover) {
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

        public long getOrDefault(long x, long def) {
            int h = hash(x);
            int s = h & mask;
            access(s);
            if (slot[s] == 0) {
                return def;
            }
            int index = findIndexOrLastEntry(s, x);
            return keys[index] == x ? values[index] : def;
        }

        public long get(long x) {
            return getOrDefault(x, 0);
        }

        private int findIndexOrLastEntry(int s, long x) {
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

        public void clear() {
            alloc = 0;
            size = 0;
            now++;
        }

        private void access(int i) {
            if (version[i] != now) {
                version[i] = now;
                slot[i] = 0;
            }
        }

        public LongEntryIterator iterator() {
            return new LongEntryIterator() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public long getEntryKey() {
                    return keys[readIndex];
                }


                public long getEntryValue() {
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
            LongEntryIterator iterator = iterator();
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

    static class Hasher {
        private long time = System.nanoTime() + System.currentTimeMillis() * 31L;

        public int shuffle(long z) {
            z += time;
            z = (z ^ (z >>> 33)) * 0x62a9d9ed799705f5L;
            return (int) (((z ^ (z >>> 28)) * 0xcb24d0a5c88c35b3L) >>> 32);
        }

        public int hash(long x) {
            return shuffle(x);
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long modplus(long a, long b, long mod) {
            long ans = a + b;
            if (ans >= mod) {
                ans -= mod;
            }
            return ans;
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

        public void populate(int[] data) {
            for (int i = 0; i < data.length; i++) {
                data[i] = readInt();
            }
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

        public long rl() {
            return readLong();
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

    static interface LongEntryIterator {
        boolean hasNext();

        void next();

        long getEntryKey();

        long getEntryValue();

    }

    static interface ILongModular {
        long getMod();

        default long plus(long a, long b) {
            return DigitUtils.modplus(a, b, getMod());
        }

    }

    static class MultiSetHasherImpl implements MultiSetHasher {
        static LongModular2305843009213693951 mod = LongModular2305843009213693951.getInstance();

        public long hash(long x) {
            return RandomWrapper.INSTANCE.nextLong(1, mod.getMod() - 1);
        }

        public long merge(long a, long b) {
            return mod.plus(a, b);
        }

    }
}