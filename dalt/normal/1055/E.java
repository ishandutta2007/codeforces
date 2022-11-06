import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
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
            ESegmentsOnTheLine solver = new ESegmentsOnTheLine();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ESegmentsOnTheLine {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int s = in.readInt();
            int m = in.readInt();
            int k = in.readInt();

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt();
            }
            IntervalPickProblem.Interval[] intervals = new IntervalPickProblem.Interval[s];

            for (int i = 0; i < s; i++) {
                intervals[i] = new IntervalPickProblem.Interval(in.readInt() - 1, in.readInt() - 1);
            }
            intervals = IntervalPickProblem.sortAndRemoveUnusedInterval(intervals);


            IntervalPickProblem.Interval[] finalIntervals = intervals;
            IntBinarySearch ibs = new IntBinarySearch() {

                public boolean check(int mid) {
                    long[] data = new long[n];
                    for (int i = 0; i < n; i++) {
                        if (a[i] <= mid) {
                            data[i] = 1;
                        }
                    }
                    return IntervalPickProblem.solveNonNegative(data, finalIntervals, m) >= k;
                }
            };

            int ans = ibs.binarySearch(1, (int) 1e9);
            if (!ibs.check(ans)) {
                out.println(-1);
                return;
            }
            out.println(ans);
        }

    }

    static abstract class DoubleBinarySearch {
        private final double relativeErrorTolerance;
        private final double absoluteErrorTolerance;

        public DoubleBinarySearch(double relativeErrorTolerance, double absoluteErrorTolerance) {
            this.relativeErrorTolerance = relativeErrorTolerance;
            this.absoluteErrorTolerance = absoluteErrorTolerance;
        }

        public abstract boolean check(double mid);

        public double binarySearch(double l, double r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            while (r - l > absoluteErrorTolerance) {
                if ((r < 0 && (r - l) < -r * relativeErrorTolerance) || (l > 0 && (r - l) < l * relativeErrorTolerance)) {
                    break;
                }

                double mid = (l + r) / 2;
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            return (l + r) / 2;
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

    }

    static class LongPreSum {
        private long[] pre;

        public LongPreSum(int n) {
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

        public LongPreSum(long[] a) {
            this(a.length);
            populate(a);
        }

        public LongPreSum(int[] a) {
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

        public long prefix(int i) {
            return pre[i];
        }

    }

    static interface IntegerComparator {
        public int compare(int a, int b);

    }

    static interface IntegerDeque extends IntegerStack {
    }

    static class IntegerDequeImpl implements IntegerDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public IntegerDequeImpl(int cap) {
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
            bpos = 0;
            epos = 0;
            n = cap;
        }

        private void expandSpace(int len) {
            while (n < len) {
                n = Math.max(n + 10, n * 2);
            }
            int[] newData = new int[n];
            if (bpos <= epos) {
                if (bpos < epos) {
                    System.arraycopy(data, bpos, newData, 0, epos - bpos);
                }
            } else {
                System.arraycopy(data, bpos, newData, 0, data.length - bpos);
                System.arraycopy(data, 0, newData, data.length - bpos, epos);
            }
            epos = size();
            bpos = 0;
            data = newData;
        }

        public IntegerIterator iterator() {
            return new IntegerIterator() {
                int index = bpos;


                public boolean hasNext() {
                    return index != epos;
                }


                public int next() {
                    int ans = data[index];
                    index = IntegerDequeImpl.this.next(index);
                    return ans;
                }
            };
        }

        public int removeFirst() {
            int ans = data[bpos];
            bpos = next(bpos);
            return ans;
        }

        public int removeLast() {
            int ans = data[last(epos)];
            epos = last(epos);
            return ans;
        }

        public void addLast(int x) {
            ensureMore();
            data[epos] = x;
            epos = next(epos);
        }

        public int peekFirst() {
            return data[bpos];
        }

        public int peekLast() {
            return data[last(epos)];
        }

        private int last(int x) {
            return (x == 0 ? n : x) - 1;
        }

        private int next(int x) {
            return x + 1 >= n ? 0 : x + 1;
        }

        private void ensureMore() {
            if (next(epos) == bpos) {
                expandSpace(n + 1);
            }
        }

        public int size() {
            int ans = epos - bpos;
            if (ans < 0) {
                ans += data.length;
            }
            return ans;
        }

        public boolean isEmpty() {
            return bpos == epos;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (IntegerIterator iterator = iterator(); iterator.hasNext(); ) {
                builder.append(iterator.next()).append(' ');
            }
            return builder.toString();
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

    static class IntervalPickProblem {
        public static IntervalPickProblem.Interval[] sortAndRemoveUnusedInterval(IntervalPickProblem.Interval[] intervals) {
            Arrays.sort(intervals, (a, b) -> Long.compare(a.l, b.l));
            List<IntervalPickProblem.Interval> intervalList = new ArrayList<>(intervals.length);
            int n = 0;
            for (int i = 0; i < intervals.length; i++, n++) {
                int l = i;
                int r = i;
                IntervalPickProblem.Interval max = intervals[i];
                while (r + 1 < intervals.length && intervals[r + 1].l == intervals[l].l) {
                    r++;
                    if (intervals[r].r > max.r) {
                        max = intervals[r];
                    }
                }
                i = r;
                intervalList.add(max);
            }
            return intervalList.toArray(new IntervalPickProblem.Interval[0]);
        }

        private static IntervalPickProblem.WQSResult solve(long[] data, IntervalPickProblem.Interval[] intervals, double cost) {
            LongPreSum lps = new LongPreSum(data);
            Arrays.sort(intervals, (a, b) -> a.l == b.l ? a.r - b.r : a.l - b.l);
            int n = intervals.length;
            double[] dp = new double[n];
            int[] time = new int[n];

            IntervalPickProblem.DoubleSegmentQuery query = new IntervalPickProblem.DoubleSegmentQuery();
            int m = data.length;
            IntervalPickProblem.DoubleSegment lower = new IntervalPickProblem.DoubleSegment(0, m);
            IntervalPickProblem.DoubleSegment upper = new IntervalPickProblem.DoubleSegment(0, m);

            for (int i = 0; i < n; i++) {
                IntervalPickProblem.Interval now = intervals[i];
                dp[i] = lps.intervalSum(now.l, now.r);
                time[i] = 1;

                query.reset();
                lower.query(0, now.l - 1, 0, m, query);
                if (query.val + lps.intervalSum(now.l, now.r) > dp[i]) {
                    dp[i] = query.val + lps.intervalSum(now.l, now.r);
                    time[i] = time[query.index] + 1;
                }
                query.reset();
                upper.query(now.l, now.r, 0, m, query);
                if (query.val + lps.prefix(now.r) > dp[i]) {
                    dp[i] = query.val + lps.prefix(now.r);
                    time[i] = time[query.index] + 1;
                }

                dp[i] -= cost;
                lower.update(now.r, now.r, 0, m, dp[i], i);
                upper.update(now.r, now.r, 0, m, dp[i] - lps.prefix(now.r), i);
            }

            int maxIndex = 0;
            for (int i = 0; i < n; i++) {
                if (dp[i] > dp[maxIndex]) {
                    maxIndex = i;
                }
            }

            return new IntervalPickProblem.WQSResult(dp[maxIndex], time[maxIndex]);
        }

        private static IntervalPickProblem.WQSResult solveNonNegative(long[] data, IntervalPickProblem.Interval[] intervals, double cost) {
            LongPreSum lps = new LongPreSum(data);
            int n = intervals.length;
            double[] dp = new double[n + 1];
            int[] time = new int[n + 1];

            MinIntegerQueue left = new MinIntegerQueue(n, (a, b) -> -Double.compare(dp[a], dp[b]));
            MinIntegerQueue middle = new MinIntegerQueue(n, (a, b) -> -Double.compare(dp[a] - lps.prefix(intervals[a - 1].r), dp[b] - lps.prefix(intervals[b - 1].r)));
            left.addLast(0);
            for (int i = 1; i <= n; i++) {
                IntervalPickProblem.Interval now = intervals[i - 1];
                while (!middle.isEmpty() && intervals[middle.peek() - 1].r < now.l) {
                    left.addLast(middle.removeFirst());
                }
                dp[i] = -1e50;
                if (dp[i] < dp[left.min()] + lps.intervalSum(now.l, now.r)) {
                    dp[i] = dp[left.min()] + lps.intervalSum(now.l, now.r);
                    time[i] = time[left.min()] + 1;
                }
                if (!middle.isEmpty() && dp[i] < dp[middle.min()] + lps.prefix(now.r) - lps.prefix(intervals[middle.min() - 1].r)) {
                    dp[i] = dp[middle.min()] + lps.prefix(now.r) - lps.prefix(intervals[middle.min() - 1].r);
                    time[i] = time[middle.min()] + 1;
                }
                dp[i] -= cost;
                middle.addLast(i);
            }

            int maxIndex = 0;
            for (int i = 1; i <= n; i++) {
                if (dp[i] > dp[maxIndex]) {
                    maxIndex = i;
                }
            }

            return new IntervalPickProblem.WQSResult(dp[maxIndex], time[maxIndex]);
        }

        public static long solveNonNegative(long[] data, IntervalPickProblem.Interval[] intervals, int k) {
            DoubleBinarySearch dbs = new DoubleBinarySearch(1e-12, 1e-12) {
                public boolean check(double mid) {
                    return solveNonNegative(data, intervals, mid).time <= k;
                }
            };
            long sum = 0;
            for (long x : data) {
                sum += x;
            }
            double cost = dbs.binarySearch(0, sum);
            long ans = DigitUtils.round(solve(data, intervals, cost).maxValue + k * cost);
            return ans;
        }

        public static class Interval {
            public final int l;
            public final int r;

            public Interval(int l, int r) {
                this.l = l;
                this.r = r;
            }

            public String toString() {
                return String.format("(%d, %d)", l, r);
            }

        }

        private static class WQSResult {
            double maxValue;
            int time;

            public WQSResult(double maxValue, int time) {
                this.maxValue = maxValue;
                this.time = time;
            }

        }

        private static class DoubleSegmentQuery {
            int index;
            double val;

            public void reset() {
                index = -1;
                val = -IntervalPickProblem.DoubleSegment.inf;
            }

            public void update(int index, double val) {
                if (this.val < val) {
                    this.index = index;
                    this.val = val;
                }
            }

        }

        private static class DoubleSegment implements Cloneable {
            private static double inf = 1e50;
            private IntervalPickProblem.DoubleSegment left;
            private IntervalPickProblem.DoubleSegment right;
            private double val = -inf;
            private int index = -1;

            public void pushUp() {
                val = Math.max(left.val, right.val);
                if (val == left.val) {
                    index = left.index;
                } else {
                    index = right.index;
                }
            }

            public void pushDown() {
            }

            public DoubleSegment(int l, int r) {
                if (l < r) {
                    int m = (l + r) >> 1;
                    left = new IntervalPickProblem.DoubleSegment(l, m);
                    right = new IntervalPickProblem.DoubleSegment(m + 1, r);
                    pushUp();
                } else {
                }
            }

            private boolean covered(int ll, int rr, int l, int r) {
                return ll <= l && rr >= r;
            }

            private boolean noIntersection(int ll, int rr, int l, int r) {
                return ll > r || rr < l;
            }

            public void update(int ll, int rr, int l, int r, double x, int index) {
                if (noIntersection(ll, rr, l, r)) {
                    return;
                }
                if (covered(ll, rr, l, r)) {
                    if (x > val) {
                        this.val = x;
                        this.index = index;
                    }
                    return;
                }
                pushDown();
                int m = (l + r) >> 1;
                left.update(ll, rr, l, m, x, index);
                right.update(ll, rr, m + 1, r, x, index);
                pushUp();
            }

            public void query(int ll, int rr, int l, int r, IntervalPickProblem.DoubleSegmentQuery query) {
                if (noIntersection(ll, rr, l, r)) {
                    return;
                }
                if (covered(ll, rr, l, r)) {
                    query.update(index, val);
                    return;
                }
                pushDown();
                int m = (l + r) >> 1;
                left.query(ll, rr, l, m, query);
                right.query(ll, rr, m + 1, r, query);
            }

        }

    }

    static interface IntegerStack {
    }

    static class MinIntegerQueue {
        IntegerDequeImpl minQueue;
        IntegerDequeImpl data;
        IntegerComparator comparator;

        public MinIntegerQueue(int cap, IntegerComparator comparator) {
            minQueue = new IntegerDequeImpl(cap);
            data = new IntegerDequeImpl(cap);
            this.comparator = comparator;
        }

        public void addLast(int val) {
            data.addLast(val);
            while (!minQueue.isEmpty() && comparator.compare(minQueue.peekLast(), val) > 0) {
                minQueue.removeLast();
            }
            minQueue.addLast(val);
        }

        public int removeFirst() {
            int val = data.removeFirst();
            if (minQueue.peekFirst() == val) {
                minQueue.removeFirst();
            }
            return val;
        }

        public int peek() {
            return data.peekFirst();
        }

        public int min() {
            return minQueue.peekFirst();
        }

        public boolean isEmpty() {
            return data.isEmpty();
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }
}