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
            FRelativelyPrimePowers solver = new FRelativelyPrimePowers();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FRelativelyPrimePowers {
        long[][] dp;
        int[] ptr = new int[64];

        public FRelativelyPrimePowers() {
            dp = new long[64][];
            LongList list = new LongList(1000000);
            for (int j = 0; ; j++) {
                long x = pow(j, 3);
                if (x > (long) 1e18) {
                    break;
                }
                list.add(x);
            }
            dp[3] = list.toArray();
            for (int i = 4; i < 64; i++) {
                list.clear();
                for (int j = 0; j < dp[i - 1].length; j++) {
                    long x = mul(dp[i - 1][j], j);
                    if (x > (long) 1e18) {
                        break;
                    }
                    list.add(x);
                }
                dp[i] = list.toArray();
            }
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int t = in.readInt();
            Query[] qs = new Query[t];
            for (int i = 0; i < t; i++) {
                qs[i] = new Query();
                qs[i].n = in.readLong();
            }
            Query[] sorted = qs.clone();
            Arrays.sort(sorted, (a, b) -> Long.compare(a.n, b.n));
            for (Query q : sorted) {
                long n = q.n;
                int limit = 64;
                long[] cnts = new long[limit];
                cnts[1] = n - 1;
                for (int i = 2; i < limit; i++) {
                    cnts[i] = sqrt(n, i) - 1;
                }
                for (int i = limit - 1; i >= 1; i--) {
                    for (int j = i + i; j < limit; j += i) {
                        cnts[i] -= cnts[j];
                    }
                }

                long ans = cnts[1];
                q.ans = ans;
            }

            for (Query q : qs) {
                out.println(q.ans);
            }
        }

        public long mul(long a, long b) {
            return DigitUtils.isMultiplicationOverflow(a, b, (long) 2e18) ?
                    (long) 2e18 : a * b;
        }

        public long sqrt(long x, int t) {
            if (t == 2) {
                LongBinarySearch lbs = new LongBinarySearch() {

                    public boolean check(long mid) {
                        return mid * mid > x;
                    }
                };
                return lbs.binarySearch(1, (long) (1e9 + 1)) - 1;
            } else {
                while (ptr[t] + 1 < dp[t].length && dp[t][ptr[t] + 1] <= x) {
                    ptr[t]++;
                }
                return ptr[t];
            }
        }

        public long pow(long x, long n) {
            if (n == 0) {
                return 1;
            }
            long ans = pow(x, n / 2);
            ans = mul(ans, ans);
            if (n % 2 == 1) {
                ans = mul(ans, x);
            }
            return ans;
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

    static class DigitUtils {
        private DigitUtils() {
        }

        public static boolean isMultiplicationOverflow(long a, long b, long limit) {
            if (limit < 0) {
                limit = -limit;
            }
            if (a < 0) {
                a = -a;
            }
            if (b < 0) {
                b = -b;
            }
            if (a == 0 || b == 0) {
                return false;
            }
            //a * b > limit => a > limit / b
            return a > limit / b;
        }

    }

    static class Query {
        long ans;
        long n;

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

    static class SequenceUtils {
        public static boolean equal(long[] a, int al, int ar, long[] b, int bl, int br) {
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

    static class LongList implements Cloneable {
        private int size;
        private int cap;
        private long[] data;
        private static final long[] EMPTY = new long[0];

        public LongList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new long[cap];
            }
        }

        public LongList(LongList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public LongList() {
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

        public void add(long x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(long[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(LongList list) {
            addAll(list.data, 0, list.size);
        }

        public long[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof LongList)) {
                return false;
            }
            LongList other = (LongList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Long.hashCode(data[i]);
            }
            return h;
        }

        public LongList clone() {
            LongList ans = new LongList();
            ans.addAll(this);
            return ans;
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