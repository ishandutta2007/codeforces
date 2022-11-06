import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
import java.io.UncheckedIOException;
import java.util.function.LongUnaryOperator;
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
            ENewYearAndTheAcquaintanceEstimation solver = new ENewYearAndTheAcquaintanceEstimation();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ENewYearAndTheAcquaintanceEstimation {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt();
            }
            Randomized.randomizedArray(a);
            Arrays.sort(a);
            SequenceUtils.reverse(a, 0, n - 1);
            IntList buf = new IntList(a.length);
            IntList buf2 = new IntList(a.length);
            long sum = 0;
            int zeroCnt = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i];
                if (a[i] == 0) {
                    zeroCnt++;
                }
            }
            int parity = (int) (sum % 2);
            int limit = (n - zeroCnt - parity) / 2;

            LongUnaryOperator function = (mid) -> {
                mid = mid * 2 + parity;
                buf.clear();
                buf.addAll(a);
                int[] data = buf.getData();
                for (int i = 0; i < mid; i++) {
                    data[i]--;
                }
                int[] newData = buf2.getData();
                CompareUtils.mergeDescending(data, 0, (int) mid - 1, data, (int) mid, n - 1, newData, 0);
                return ErdosGallaiTheorem.maxOnAllK(newData);
            };

            LongTernarySearch ts = new LongTernarySearch(function);
            int center = ts.find(0, limit);
            if (function.applyAsLong(center) > 0) {
                out.println(-1);
                return;
            }
            IntBinarySearch lbs = new IntBinarySearch() {

                public boolean check(int mid) {
                    return function.applyAsLong(mid) <= 0;
                }
            };
            IntBinarySearch rbs = new IntBinarySearch() {

                public boolean check(int mid) {
                    return function.applyAsLong(mid) > 0;
                }
            };
            int left = lbs.binarySearch(0, center);
            int right = rbs.binarySearch(center, limit);
            if (function.applyAsLong(right) > 0) {
                right--;
            }

            for (int i = left; i <= right; i++) {
                out.println(i * 2 + parity);
            }
        }

    }

    static abstract class IntBinarySearch {
        public abstract boolean check(int mid);

        public int binarySearch(int l, int r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            while (l < r) {
                int mid = (l + r) >>> 1;
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }

    }

    static class LongTernarySearch {
        private LongUnaryOperator operator;

        public LongTernarySearch(LongUnaryOperator operator) {
            this.operator = operator;
        }

        public int find(int l, int r) {
            while (r - l > 2) {
                int ml = l + DigitUtils.floorDiv(r - l, 3);
                int mr = r - DigitUtils.ceilDiv(r - l, 3);
                if (operator.applyAsLong(ml) >= operator.applyAsLong(mr)) {
                    l = ml;
                } else {
                    r = mr;
                }
            }
            while (l < r) {
                if (operator.applyAsLong(l) < operator.applyAsLong(r)) {
                    r--;
                } else {
                    l++;
                }
            }
            return l;
        }

    }

    static class ErdosGallaiTheorem {
        public static long maxOnAllK(int[] degs) {
//        long sum = 0;
//        int min = 0;
//        for (int i = 0; i < degs.length; i++) {
//            sum += degs[i];
//            min = Math.min(min, degs[i]);
//        }
//        if (sum % 2 == 1 || min < 0) {
//            throw new IllegalArgumentException();
//        }
//        CompareUtils.radixSort(degs, 0, degs.length - 1);
//        SequenceUtils.reverse(degs, 0, degs.length - 1);
            int n = degs.length;
            PreSum ps = new PreSum(degs);
            long[] ss = new long[n + 1];
            int rIter = n;
            for (int i = n - 1; i >= 0; i--) {
                int l = i;
                int r = n - 1;
                if (rIter - 1 >= l && degs[rIter - 1] < i) {
                    rIter--;
                }
                while (rIter < n && degs[rIter] > i) {
                    rIter++;
                }
                ss[i] = (long) (rIter - l) * i + ps.intervalSum(rIter, r);
            }

            long max = Long.MIN_VALUE;
            for (int i = 1; i <= n; i++) {
                max = Math.max(max, ps.intervalSum(0, i - 1) - (long) i * (i - 1) - ss[i]);
            }
            return max;
        }

    }

    static class CompareUtils {
        private CompareUtils() {
        }

        public static void mergeDescending(int[] a, int al, int ar, int[] b, int bl, int br, int[] c, int cl) {
            while (al <= ar || bl <= br) {
                if (bl > br || (al <= ar && a[al] >= b[bl])) {
                    c[cl++] = a[al++];
                } else {
                    c[cl++] = b[bl++];
                }
            }
        }

    }

    static class Randomized {
        static Random random = new Random();

        public static void randomizedArray(int[] data) {
            randomizedArray(data, 0, data.length - 1);
        }

        public static void randomizedArray(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }

    static class IntList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public int[] getData() {
            return data;
        }

        public IntList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntList(IntList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntList() {
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

        public void addAll(int[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntList list) {
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
            if (!(obj instanceof IntList)) {
                return false;
            }
            IntList other = (IntList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + data[i];
            }
            return h;
        }

        public IntList clone() {
            IntList ans = new IntList();
            ans.addAll(this);
            return ans;
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

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorDiv(int a, int b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static int ceilDiv(int a, int b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            int c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
        }

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static void reverse(int[] data, int l, int r) {
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
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

    static class PreSum {
        private long[] pre;

        public PreSum(int n) {
            pre = new long[n];
        }

        public void populate(long[] a) {
            int n = a.length;
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a[i];
            }
        }

        public void populate(int[] a) {
            int n = a.length;
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a[i];
            }
        }

        public PreSum(long[] a) {
            this(a.length);
            populate(a);
        }

        public PreSum(int[] a) {
            this(a.length);
            populate(a);
        }

        public long intervalSum(int l, int r) {
            if (l > r) {
                return 0;
            }
            if (l == 0) {
                return pre[r];
            }
            return pre[r] - pre[l - 1];
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

        public FastOutput println(int c) {
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