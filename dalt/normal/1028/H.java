import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
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
            HMakeSquare solver = new HMakeSquare();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class HMakeSquare {
        int maxA = 5032107;
        int maxAns = 7;
        int[][] dp;
        int[] best;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int q = in.readInt();
            int[] as = new int[n];
            for (int i = 0; i < n; i++) {
                as[i] = in.readInt();
            }
            Query[] qs = new Query[q];
            for (int i = 0; i < q; i++) {
                qs[i] = new Query();
                qs[i].l = in.readInt() - 1;
                qs[i].r = in.readInt() - 1;
            }
            Query[] sortedQs = qs.clone();
            Arrays.sort(sortedQs, (a, b) -> a.r != b.r ? a.r - b.r : a.l - b.l);
            MultiWayIntegerStack stack = Factorization.factorizeRangePrime(maxA);

            SimplifiedDeque<Query> deque = new Array2DequeAdapter<>(sortedQs);
            dp = new int[maxA + 1][maxAns + 1];
            best = new int[maxAns * 2 + 1];
            Arrays.fill(best, -1);
            SequenceUtils.deepFill(dp, -1);

            IntegerList buf = new IntegerList(7);
            for (int i = 0; i < n; i++) {
                buf.clear();
                for (IntegerIterator iterator = stack.iterator(as[i]); iterator.hasNext(); ) {
                    int next = iterator.next();
                    int cnt = 0;
                    int x = as[i];
                    while (x % next == 0) {
                        x /= next;
                        cnt++;
                    }
                    if (cnt % 2 == 1) {
                        buf.add(next);
                    }
                }

                int m = buf.size();
                dfsForBest(buf.getData(), m - 1, 1, m);
                dfsForDP(buf.getData(), m - 1, 1, m, i);

                for (int j = 1; j < best.length; j++) {
                    best[j] = Math.max(best[j], best[j - 1]);
                }

                int step = 0;
                while (!deque.isEmpty() && deque.peekFirst().r == i) {
                    Query first = deque.removeFirst();
                    while (best[step] < first.l) {
                        step++;
                    }
                    first.ans = step;
                }
            }

            for (Query query : qs) {
                out.println(query.ans);
            }
        }

        public void dfsForDP(int[] list, int i, int prod, int dist, int index) {
            if (i < 0) {
                dp[prod][dist] = index;
                return;
            }
            dfsForDP(list, i - 1, prod, dist, index);
            dfsForDP(list, i - 1, prod * list[i], dist - 1, index);
        }

        public void dfsForBest(int[] list, int i, int prod, int dist) {
            if (i < 0) {
                for (int j = 0; j <= maxAns; j++) {
                    if (dp[prod][j] == -1) {
                        continue;
                    }
                    best[dist + j] = Math.max(best[dist + j], dp[prod][j]);
                }
                return;
            }
            dfsForBest(list, i - 1, prod, dist);
            dfsForBest(list, i - 1, prod * list[i], dist - 1);
        }

    }

    static class MultiWayIntegerStack {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public IntegerIterator iterator(final int queue) {
            return new IntegerIterator() {
                int ele = heads[queue];


                public boolean hasNext() {
                    return ele != 0;
                }


                public int next() {
                    int ans = values[ele];
                    ele = next[ele];
                    return ans;
                }
            };
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public MultiWayIntegerStack(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            stackNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < stackNum; i++) {
                builder.append(i).append(": ");
                for (IntegerIterator iterator = iterator(i); iterator.hasNext(); ) {
                    builder.append(iterator.next()).append(",");
                }
                if (builder.charAt(builder.length() - 1) == ',') {
                    builder.setLength(builder.length() - 1);
                }
                builder.append('\n');
            }
            return builder.toString();
        }

    }

    static class Query {
        int l;
        int r;
        int ans;

    }

    static interface SimplifiedDeque<T> extends SimplifiedStack<T> {
        T peekFirst();

        T removeFirst();

    }

    static interface SimplifiedStack<T> extends Iterable<T> {
        boolean isEmpty();

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

    static class Array2DequeAdapter<T> implements SimplifiedDeque<T> {
        T[] data;
        int l;
        int r;

        public Array2DequeAdapter(T[] data) {
            this(data, 0, data.length - 1);
        }

        public Array2DequeAdapter(T[] data, int l, int r) {
            this.data = data;
            this.l = l;
            this.r = r;
        }

        public boolean isEmpty() {
            return l > r;
        }

        public T peekFirst() {
            return data[l];
        }

        public T removeFirst() {
            return data[l++];
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                int iter = l;


                public boolean hasNext() {
                    return iter <= r;
                }


                public T next() {
                    return data[iter++];
                }
            };
        }

    }

    static class IntegerList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public int[] getData() {
            return data;
        }

        public IntegerList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerList(IntegerList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerList() {
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

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerList list) {
            addAll(list.data, 0, list.size);
        }

        public int size() {
            return size;
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
            if (!(obj instanceof IntegerList)) {
                return false;
            }
            IntegerList other = (IntegerList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerList clone() {
            IntegerList ans = new IntegerList();
            ans.addAll(this);
            return ans;
        }

    }

    static class MinimumNumberWithMaximumFactors {
        private static int[] primes = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

        public static long[] maximumPrimeFactor(long n) {
            long[] ans = new long[2];
            ans[0] = 1;
            for (int i = 0; i < primes.length; i++) {
                if (DigitUtils.isMultiplicationOverflow(ans[0], primes[i], n)) {
                    break;
                }
                ans[0] *= primes[i];
                ans[1]++;
            }
            return ans;
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class Factorization {
        public static MultiWayIntegerStack factorizeRangePrime(int n) {
            int maxFactorCnt = (int) MinimumNumberWithMaximumFactors.maximumPrimeFactor(n)[1];
            MultiWayIntegerStack stack = new MultiWayIntegerStack(n + 1, n * maxFactorCnt);
            boolean[] isComp = new boolean[n + 1];
            for (int i = 2; i <= n; i++) {
                if (isComp[i]) {
                    continue;
                }
                for (int j = i; j <= n; j += i) {
                    isComp[j] = true;
                    stack.addLast(j, i);
                }
            }
            return stack;
        }

    }

    static class SequenceUtils {
        public static void deepFill(Object array, int val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof int[]) {
                int[] intArray = (int[]) array;
                Arrays.fill(intArray, val);
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

        public FastOutput println(int c) {
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

    }
}