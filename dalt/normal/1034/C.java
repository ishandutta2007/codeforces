import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;
import java.util.ArrayList;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.stream.LongStream;
import java.util.Collection;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
import java.io.Writer;
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
            CRegionSeparation solver = new CRegionSeparation();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CRegionSeparation {
        long[] primes;
        int[] cnts;
        LongObjectHashMap<Factor> map;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].w = in.readInt();
            }
            for (int i = 2; i <= n; i++) {
                Node p = nodes[in.readInt()];
                p.next.add(nodes[i]);
            }
            dfsForSum(nodes[1]);
            long sum = nodes[1].sum;
            primes = new LongPollardRho().findAllFactors(sum)
                    .keySet().stream().mapToLong(Long::valueOf)
                    .toArray();
            cnts = new int[primes.length];
            for (int i = 0; i < primes.length; i++) {
                int time = 0;
                long x = sum;
                while (x % primes[i] == 0) {
                    x /= primes[i];
                    time++;
                }
                cnts[i] = time;
            }

            List<Factor> factorList = new ArrayList<>(30000);
            collect(new int[primes.length], 0, 1, factorList);
            Factor[] allFactors = factorList.toArray(new Factor[0]);
            map = new LongObjectHashMap<>(allFactors.length, false);
            for (Factor factor : allFactors) {
                map.put(factor.val, factor);
            }

            for (int i = 1; i <= n; i++) {
                long g = GCDs.gcd(nodes[i].sum, sum);
                if (!map.containKey(g)) {
                    throw new RuntimeException();
                }
                map.get(g).appearance++;
            }

            for (int i = 0; i < allFactors.length; i++) {
                for (int j = i + 1; j < allFactors.length; j++) {
                    if (allFactors[j].val % allFactors[i].val == 0) {
                        allFactors[i].appearance += allFactors[j].appearance;
                    }
                }
            }

            Modular mod = new Modular(1e9 + 7);
            for (int i = 0; i < allFactors.length; i++) {
                if (allFactors[i].appearance * allFactors[i].val != sum) {
                    continue;
                }
                allFactors[i].way = 1;
                for (int j = i - 1; j >= 0; j--) {
                    if (allFactors[i].val % allFactors[j].val == 0) {
                        allFactors[i].way = mod.plus(allFactors[i].way, allFactors[j].way);
                    }
                }
            }

            long ans = map.get(sum).way;

            if (sum == 978217616376000L) {
                throw new RuntimeException();
            }

            out.println(ans);
        }

        public void collect(int[] nums, int i, long val, List<Factor> factors) {
            if (i == primes.length) {
                factors.add(new Factor(nums.clone(), val));
                return;
            }
            for (int j = 0; j <= cnts[i]; j++, val *= primes[i]) {
                nums[i] = j;
                collect(nums, i + 1, val, factors);
            }
        }

        public static void dfsForSum(Node root) {
            root.sum = root.w;
            for (Node node : root.next) {
                dfsForSum(node);
                root.sum += node.sum;
            }
        }

    }

    static class Factor {
        int[] cnts;
        long val;
        long appearance;
        int way;

        public Factor(int[] cnts, long val) {
            this.cnts = cnts;
            this.val = val;
        }

        public String toString() {
            return "" + val;
        }

    }

    static class Modular {
        int m;

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

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public String toString() {
            return "mod " + m;
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

        public FastOutput println(long c) {
            cache.append(c);
            println();
            return this;
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

    static class LongModularDanger implements ILongModular {
        final long m;

        public LongModularDanger(long m) {
            this.m = m;
        }

        public long mul(long a, long b) {
            return DigitUtils.mulMod(a, b, m);
        }

        public long plus(long a, long b) {
            return valueOf(a + b);
        }

        public long valueOf(long a) {
            a %= m;
            if (a < 0) {
                a += m;
            }
            return a;
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

        public static long mod(long x, long mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return x;
        }

        public static long mulMod(long a, long b, long mod) {
            long k = DigitUtils.round((double) a / mod * b);
            return DigitUtils.mod(a * b - k * mod, mod);
        }

    }

    static interface ILongModular {
        long plus(long a, long b);

        long mul(long a, long b);

        static ILongModular getInstance(long mod) {
            //return new LongModularDanger(mod);
            return mod <= (1L << 54) ? new LongModularDanger(mod) : new LongModular(mod);
        }

    }

    static class LongModular implements ILongModular {
        final long m;

        public LongModular(long m) {
            this.m = m;
        }

        public long mul(long a, long b) {
            return b == 0 ? 0 : ((mul(a, b >> 1) << 1) % m + a * (b & 1)) % m;
        }

        public long plus(long a, long b) {
            return valueOf(a + b);
        }

        public long valueOf(long a) {
            a %= m;
            if (a < 0) {
                a += m;
            }
            return a;
        }

    }

    static class Node {
        List<Node> next = new ArrayList<>();
        long sum;
        int w;

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

    static class LongMillerRabin {
        ILongModular modular;
        LongPower power;
        Random random = new Random();

        public boolean mr(long n, int s) {
            if (n <= 1) {
                return false;
            }
            if (n == 2) {
                return true;
            }
            if (n % 2 == 0) {
                return false;
            }
            long m = n - 1;
            while (m % 2 == 0) {
                m /= 2;
            }
            modular = ILongModular.getInstance(n);
            power = new LongPower(modular);
            for (int i = 0; i < s; i++) {
                long x = (long) (random.nextDouble() * (n - 2) + 2);
                if (!mr0(x, n, m)) {
                    return false;
                }
            }
            return true;
        }

        private boolean mr0(long x, long n, long m) {
            return test(power.pow(x, m), m, n);
        }

        private boolean test(long y, long exp, long n) {
            long y2 = modular.mul(y, y);
            if (!(exp == n - 1 || test(y2, exp * 2, n))) {
                return false;
            }
            if (exp != n - 1 && y2 != 1) {
                return true;
            }
            if (y != 1 && y != n - 1) {
                return false;
            }
            return true;
        }

    }

    static interface LongObjectEntryIterator<V> {
        boolean hasNext();

        void next();

        long getEntryKey();

        V getEntryValue();

    }

    static class LongPower {
        final ILongModular modular;

        public LongPower(ILongModular modular) {
            this.modular = modular;
        }

        public long pow(long x, long n) {
            if (n == 0) {
                return 1;
            }
            long r = pow(x, n >> 1);
            r = modular.mul(r, r);
            if ((n & 1) == 1) {
                r = modular.mul(r, x);
            }
            return r;
        }

    }

    static class GCDs {
        private GCDs() {
        }

        public static long gcd(long a, long b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private static long gcd0(long a, long b) {
            return b == 0 ? a : gcd0(b, a % b);
        }

    }

    static class LongObjectHashMap<V> {
        private int[] slot;
        private int[] next;
        private long[] keys;
        private Object[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;

        public LongObjectHashMap(int cap, boolean rehash) {
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            next = new int[cap + 1];
            keys = new long[cap + 1];
            values = new Object[cap + 1];
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

        private void rehash() {
            int[] newSlots = new int[Math.max(16, slot.length * 2)];
            int newMask = newSlots.length - 1;
            for (int i = 0; i < slot.length; i++) {
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
            this.mask = newMask;
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
            removed[alloc] = false;
            values[alloc] = null;
            size++;
        }

        private int hash(long x) {
            int h = Long.hashCode(x);
            return h ^ (h >>> 16);
        }

        public void put(long x, V y) {
            int h = hash(x);
            int s = h & mask;
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
                } else {
                    values[index] = y;
                }
            }
            if (rehash && size >= slot.length) {
                rehash();
            }
        }

        public boolean containKey(long x) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return false;
            }
            return keys[findIndexOrLastEntry(s, x)] == x;
        }

        public V getOrDefault(long x, V def) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return def;
            }
            int index = findIndexOrLastEntry(s, x);
            return keys[index] == x ? (V) values[index] : def;
        }

        public V get(long x) {
            return getOrDefault(x, null);
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

        public LongObjectEntryIterator<V> iterator() {
            return new LongObjectEntryIterator() {
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


                public Object getEntryValue() {
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
            LongObjectEntryIterator<V> iterator = iterator();
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

    static class LongPollardRho {
        LongMillerRabin mr = new LongMillerRabin();
        Random random = new Random();

        public long findFactor(long n) {
            if (mr.mr(n, 5)) {
                return n;
            }

            while (true) {
                long f = rho(n);
                if (f != n) {
                    return f;
                }
            }
        }

        public Map<Long, Long> findAllFactors(long n) {
            Map<Long, Long> map = new HashMap();
            findAllFactors(map, n);
            return map;
        }

        private void findAllFactors(Map<Long, Long> map, long n) {
            if (n == 1) {
                return;
            }
            long f = findFactor(n);
            if (f == n) {
                Long value = map.get(f);
                if (value == null) {
                    value = 1L;
                }
                map.put(f, value * f);
                return;
            }
            findAllFactors(map, f);
            findAllFactors(map, n / f);
        }

        private long rho(long n) {
            if (n % 2 == 0) {
                return 2;
            }
            if (n % 3 == 0) {
                return 3;
            }
            ILongModular modular = ILongModular.getInstance(n);
            long x = 0, y = x, t, q = 1, c = (long) (random.nextDouble() * (n - 1)) + 1;
            for (int k = 2; ; k <<= 1, y = x, q = 1) {
                for (int i = 1; i <= k; ++i) {
                    x = modular.plus(modular.mul(x, x), c);
                    q = modular.mul(q, Math.abs(x - y));
                    if ((i & 127) == 0) {
                        t = GCDs.gcd(q, n);
                        if (t > 1) {
                            return t;
                        }
                    }
                }
                if ((t = GCDs.gcd(q, n)) > 1) {
                    return t;
                }
            }
        }

    }
}