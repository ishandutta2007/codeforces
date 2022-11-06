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
        new TaskAdapter().run();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            DArtisticPartition solver = new DArtisticPartition();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class DArtisticPartition {
        int K = 20;
        int N = (int) 1e5;
        long[][] dp = new long[K][N + 1];
        int[][] pts = new int[N + 1][];
        long[][] suffix = new long[N + 1][];
        int[][] start = new int[N + 1][];
        Cost cost;
        long inf = (long) 1e18;
        long[] p;

        public void preprocess() {
            IntegerArrayList ptBuf = new IntegerArrayList(N + 1);
            IntegerArrayList startBuf = new IntegerArrayList(N + 1);
            for (int i = 1; i <= N; i++) {
                ptBuf.clear();
                startBuf.clear();
                for (int j = 1, r; j <= i; j = r + 1) {
                    int v = i / j;
                    r = i / v;
                    ptBuf.add(v);
                    startBuf.add(j);
                }
                pts[i] = ptBuf.toArray();
                start[i] = startBuf.toArray();
                int m = pts[i].length;
                suffix[i] = new long[m];
                long last = i + 1;
                long lastSum = 0;
                for (int j = m - 1; j >= 0; j--) {
                    suffix[i][j] = lastSum + (last - start[i][j]) * p[pts[i][j]];
                    last = start[i][j];
                    lastSum = suffix[i][j];
                }
            }
        }

        public void dac(int level, int l, int r, int L, int R) {
            if (l > r) {
                return;
            }
            int m = (l + r) >>> 1;

            int start = Math.min(m, R);
            cost.reset(start + 1, m);

            int bestChoice = -1;
            long bestCost = inf;
            for (int i = start; i >= L; i--) {
                cost.move(i + 1);
                long cand = cost.cost + dp[level - 1][i];
                if (cand < bestCost) {
                    bestCost = cand;
                    bestChoice = i;
                }
            }

            dp[level][m] = bestCost;
            dac(level, l, m - 1, L, bestChoice);
            dac(level, m + 1, r, bestChoice, R);
        }

        public DArtisticPartition() {
            MultiplicativeFunctionSieve sieve = new MultiplicativeFunctionSieve(N);
            int[] euler = sieve.getEuler();
            p = new long[N + 1];
            p[0] = euler[0];
            for (int i = 1; i <= N; i++) {
                p[i] = p[i - 1] + euler[i];
            }
            preprocess();
            cost = new Cost();
            SequenceUtils.deepFill(dp, inf);
            dp[0][0] = 0;
            for (int i = 1; i < K; i++) {
                dac(i, 1, N, 0, N);
            }
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int k = in.ri();
            if (k >= K) {
                out.println(n);
                return;
            }
            long ans = dp[k][n];
            out.println(ans);
        }

        class Cost {
            int r;
            int l;
            long cost;

            public void reset(int L, int R) {
                r = R;
                l = L;

                if (l > r) {
                    cost = 0;
                    return;
                }

                int high = BinarySearch.upperBound(start[r], 0, start[r].length - 1, l);
                assert high > 0;
                cost = 0;
                int last = r + 1;
                if (high < suffix[r].length) {
                    cost += suffix[r][high];
                    last = start[r][high];
                }
                cost += (last - l) * p[pts[r][high - 1]];
            }

            public void move(int L) {
                while (l < L) {
                    cost -= p[r / l];
                    l++;
                }
                while (l > L) {
                    l--;
                    cost += p[r / l];
                }
            }

        }

    }

    static class SequenceUtils {
        public static void deepFill(Object array, long val) {
            if (array == null) {
                return;
            }
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

        public static boolean equal(int[] a, int al, int ar, int[] b, int bl, int br) {
            if ((ar - al) != (br - bl)) {
                return false;
            }
            for (int i = al, j = bl; i <= ar; i++, j++) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return true;
        }

    }

    static class BinarySearch {
        private BinarySearch() {
        }

        public static int lowerBound(int[] arr, int l, int r, int target) {
            while (l < r) {
                int mid = DigitUtils.floorAverage(l, r);
                if (arr[mid] >= target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (arr[l] < target) {
                l++;
            }
            return l;
        }

        public static int upperBound(int[] arr, int l, int r, int target) {
            return lowerBound(arr, l, r, target + 1);
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
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

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println(long c) {
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

    static class MultiplicativeFunctionSieve {
        public int[] primes;
        public boolean[] isComp;
        public int primeLength;
        public int[] smallestPrimeFactor;
        public int[] expOfSmallestPrimeFactor;
        int limit;

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

    static class IntegerArrayList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerArrayList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerArrayList(int[] data) {
            this(0);
            addAll(data);
        }

        public IntegerArrayList(IntegerArrayList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerArrayList() {
            this(0);
        }

        public void ensureSpace(int req) {
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerArrayList list) {
            addAll(list.data, 0, list.size);
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerArrayList)) {
                return false;
            }
            IntegerArrayList other = (IntegerArrayList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerArrayList clone() {
            IntegerArrayList ans = new IntegerArrayList();
            ans.addAll(this);
            return ans;
        }

    }
}