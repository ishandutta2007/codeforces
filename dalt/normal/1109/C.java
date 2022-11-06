import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
import java.io.UncheckedIOException;
import java.util.TreeMap;
import java.util.Map;
import java.io.Closeable;
import java.util.Map.Entry;
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
            CSashaAndAPatientFriend solver = new CSashaAndAPatientFriend();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CSashaAndAPatientFriend {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int q = in.readInt();
            TreeMap<Integer, Integer> events = new TreeMap<>();

            int[][] qs = new int[q][];
            IntegerList list = new IntegerList(2 * q);
            for (int i = 0; i < q; i++) {
                int t = in.readInt();
                if (t == 1) {
                    qs[i] = new int[]{t, in.readInt(), in.readInt()};
                    list.add(qs[i][1]);
                } else if (t == 2) {
                    qs[i] = new int[]{t, in.readInt()};
                } else {
                    qs[i] = new int[]{t, in.readInt(), in.readInt(), in.readInt()};
                    list.add(qs[i][1]);
                    list.add(qs[i][2]);
                }
            }

            IntegerDiscreteMap dm = new IntegerDiscreteMap(list.getData(), 0, list.size());

            Interval interval = new Interval();
            Segment segment = new Segment(dm.minRank(), dm.maxRank());
            for (int i = 0; i < q; i++) {
                if (qs[i][0] == 1) {
                    int t = dm.rankOf(qs[i][1]);
                    int s = qs[i][2];
                    Map.Entry<Integer, Integer> floor = events.floorEntry(t);
                    Map.Entry<Integer, Integer> ceil = events.ceilingEntry(t);
                    if (floor != null && ceil != null) {
                        long contrib = (long) (dm.iThElement(ceil.getKey()) - dm.iThElement(floor.getKey())) * floor.getValue();
                        segment.update(ceil.getKey(), ceil.getKey(), dm.minRank(), dm.maxRank(), -contrib);
                    }
                    if (floor != null) {
                        long contrib = (long) (dm.iThElement(t) - dm.iThElement(floor.getKey())) * floor.getValue();
                        segment.update(t, t, dm.minRank(), dm.maxRank(), contrib);
                    }
                    if (ceil != null) {
                        long contrib = (long) (dm.iThElement(ceil.getKey()) - dm.iThElement(t)) * s;
                        segment.update(ceil.getKey(), ceil.getKey(), dm.minRank(), dm.maxRank(), contrib);
                    }
                    events.put(t, s);
                } else if (qs[i][0] == 2) {
                    int t = dm.rankOf(qs[i][1]);
                    int s = events.remove(t);
                    Map.Entry<Integer, Integer> floor = events.floorEntry(t);
                    Map.Entry<Integer, Integer> ceil = events.ceilingEntry(t);
                    if (floor != null) {
                        long contrib = (long) (dm.iThElement(t) - dm.iThElement(floor.getKey())) * floor.getValue();
                        segment.update(t, t, dm.minRank(), dm.maxRank(), -contrib);
                    }
                    if (ceil != null) {
                        long contrib = (long) (dm.iThElement(ceil.getKey()) - dm.iThElement(t)) * s;
                        segment.update(ceil.getKey(), ceil.getKey(), dm.minRank(), dm.maxRank(), -contrib);
                    }
                    if (floor != null && ceil != null) {
                        long contrib = (long) (dm.iThElement(ceil.getKey()) - dm.iThElement(floor.getKey())) * floor.getValue();
                        segment.update(ceil.getKey(), ceil.getKey(), dm.minRank(), dm.maxRank(), contrib);
                    }
                } else {
                    int l = dm.rankOf(qs[i][1]);
                    int r = dm.rankOf(qs[i][2]);
                    int v = qs[i][3];
                    if (v == 0) {
                        out.println(dm.iThElement(l));
                        continue;
                    }
                    Integer ceilingKey = events.ceilingKey(l);
                    if (ceilingKey == null || ceilingKey > r) {
                        out.println(-1);
                        continue;
                    }
                    l = ceilingKey + 1;
                    int finalL = l;

                    if (l > r) {
                        out.println(-1);
                        continue;
                    }

                    IntBinarySearch ibs = new IntBinarySearch() {

                        public boolean check(int mid) {
                            interval.init();
                            segment.query(finalL, mid, dm.minRank(), dm.maxRank(), interval);
                            return interval.min + v <= 0;
                        }
                    };
                    int time = ibs.binarySearch(l, r);

                    if (!ibs.check(time)) {
                        Map.Entry<Integer, Integer> entry = events.floorEntry(r);
                        if (entry == null || entry.getValue() >= 0) {
                            out.println(-1);
                            continue;
                        }
                        interval.init();
                        segment.query(finalL, entry.getKey(), dm.minRank(), dm.maxRank(), interval);
                        long remain = v + interval.total;
                        if (dm.iThElement(entry.getKey()) + DigitUtils.ceilDiv(remain, -entry.getValue()) > dm.iThElement(r)) {
                            out.println(-1);
                        } else {
                            out.println(dm.iThElement(entry.getKey()) + (double) remain / -entry.getValue());
                        }
                        continue;
                    }

                    Map.Entry<Integer, Integer> entry = events.floorEntry(time - 1);
                    interval.init();
                    segment.query(finalL, entry.getKey(), dm.minRank(), dm.maxRank(), interval);
                    long remain = v + interval.total;
                    if (dm.iThElement(entry.getKey()) + DigitUtils.ceilDiv(remain, -entry.getValue()) > dm.iThElement(r)) {
                        out.println(-1);
                    } else {
                        out.println(dm.iThElement(entry.getKey()) + (double) remain / -entry.getValue());
                    }
                    continue;
                }
            }
        }

    }

    static class IntegerDiscreteMap {
        int[] val;
        int f;
        int t;

        public IntegerDiscreteMap(int[] val, int f, int t) {
            Randomized.randomizedArray(val, f, t);
            Arrays.sort(val, f, t);
            int wpos = f + 1;
            for (int i = f + 1; i < t; i++) {
                if (val[i] == val[i - 1]) {
                    continue;
                }
                val[wpos++] = val[i];
            }
            this.val = val;
            this.f = f;
            this.t = wpos;
        }

        public int rankOf(int x) {
            return Arrays.binarySearch(val, f, t, x) - f;
        }

        public int iThElement(int i) {
            return val[f + i];
        }

        public int minRank() {
            return 0;
        }

        public int maxRank() {
            return t - f - 1;
        }

        public String toString() {
            return Arrays.toString(Arrays.copyOfRange(val, f, t));
        }

    }

    static class SequenceUtils {
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

    static class Randomized {
        static Random random = new Random();

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

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        private Interval interval = new Interval();

        private void modify(long x) {
            interval.total += x;
            interval.min = Math.min(0, interval.total);
        }

        public void pushUp() {
            interval.merge(left.interval, right.interval);
        }

        public void pushDown() {
        }

        public Segment(int l, int r) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m);
                right = new Segment(m + 1, r);
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

        public void update(int ll, int rr, int l, int r, long x) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                modify(x);
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.update(ll, rr, l, m, x);
            right.update(ll, rr, m + 1, r, x);
            pushUp();
        }

        public void query(int ll, int rr, int l, int r, Interval interval) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                interval.rightMerge(this.interval);
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.query(ll, rr, l, m, interval);
            right.query(ll, rr, m + 1, r, interval);
        }

    }

    static class Interval {
        long min;
        long total;

        public void merge(Interval a, Interval b) {
            min = Math.min(a.min, a.total + b.min);
            total = a.total + b.total;
        }

        public void rightMerge(Interval r) {
            min = Math.min(min, total + r.min);
            total += r.total;
        }

        public void init() {
            min = total = 0;
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

        public FastOutput println(double c) {
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

        public static long floorDiv(long a, long b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static long ceilDiv(long a, long b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            long c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
        }

    }
}