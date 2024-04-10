import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Random;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.Iterator;
import java.util.Collection;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.AbstractMap;
import java.util.TreeMap;
import java.io.Closeable;
import java.io.Writer;
import java.util.Map.Entry;
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
            DCakesForClones solver = new DCakesForClones();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DCakesForClones {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            LongArrayList list = new LongArrayList(n + 1);
            list.add(0);
            Cake[] cakes = new Cake[n];
            for (int i = 0; i < n; i++) {
                cakes[i] = new Cake();
                cakes[i].t = in.ri();
                cakes[i].x = in.ri();
                list.add(cakes[i].x);
            }

            list.unique();
            for (Cake c : cakes) {
                c.compressedX = list.binarySearch(c.x);
            }

            long[] cp = list.toArray();
            int m = list.size();
            int zero = list.binarySearch(0);
            long[] pre = new long[m + 1];
            long[] next = new long[m + 1];
            //addTag(pre, zero, zero);

            Arrays.sort(cakes, (a, b) -> Integer.compare(a.t, b.t));
            int now = 0;
            int cur = zero;

            LongIntervalMap preMap = new LongIntervalMap();
            preMap.add(0, 1);
            LongIntervalMap nextMap = new LongIntervalMap();
            for (Cake c : cakes) {
                int elapse = c.t - now;
                now = c.t;
                useTag(pre);
                Arrays.fill(next, 0);
                nextMap.clear();

                boolean selfPossible = false;
                //self to self
                for (int i = 0; i < m; i++) {
                    if (pre[i] == 0) {
                        continue;
                    }
                    selfPossible = true;
                    //not add tag
                    if (Math.abs(cp[cur] - c.x) <= elapse) {
                        addTag(next, i, i);
                    }
                }
                //add new tag and self
                if (selfPossible) {
                    for (int i = 0; i < m; i++) {
                        if (Math.abs(cp[cur] - cp[i]) + Math.abs(cp[i] - c.x) <= elapse) {
                            addTag(next, i, i);
                        }
                    }
                }
                //self go to go by shadow
                if (pre[c.compressedX] > 0) {
                    nextMap.add(cp[cur] - elapse, cp[cur] + elapse + 1);
                }

                for (LongIntervalMap.Interval interval : preMap) {
                    long l = interval.l;
                    long r = interval.r - 1;
                    //shadow to self
                    for (int i = 0; i < m; i++) {
                        long shortest = dist(l, r, cp[i]);
                        if (shortest + Math.abs(cp[i] - c.x) <= elapse) {
                            addTag(next, i, i);
                        }
                    }
                    //shadow to shadow
                    {
                        long shortest = dist(l, r, c.x);
                        if (shortest <= elapse) {
                            long remain = elapse - shortest;
                            nextMap.add(c.x - remain, c.x + remain + 1);
                        }
                    }
                }

                {
                    long[] tmp = pre;
                    pre = next;
                    next = tmp;
                }
                {
                    LongIntervalMap tmp = preMap;
                    preMap = nextMap;
                    nextMap = tmp;
                }
                cur = c.compressedX;
            }

            boolean possible = !preMap.isEmpty();
            useTag(pre);
            for (int i = 0; i < m; i++) {
                if (pre[i] > 0) {
                    possible = true;
                }
            }

            out.println(possible ? "YES" : "NO");
        }

        public long dist(long l, long r, long x) {
            return x < l ? l - x : x > r ? x - r : 0;
        }

        public void addTag(long[] x, int l, int r) {
            x[l]++;
            x[r + 1]--;
        }

        public void useTag(long[] x) {
            long ps = 0;
            for (int i = 0; i < x.length; i++) {
                ps += x[i];
                x[i] = ps;
            }
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

    }

    static class Cake {
        int t;
        int x;
        int compressedX;

    }

    static class LongIntervalMap implements Iterable<LongIntervalMap.Interval> {
        private long total = 0;
        private TreeMap<Long, LongIntervalMap.Interval> map = new TreeMap<>();

        private void add(LongIntervalMap.Interval interval) {
            if (interval.length() <= 0) {
                return;
            }
            map.put(interval.l, interval);
            total += interval.length();
        }

        private void remove(LongIntervalMap.Interval interval) {
            map.remove(interval.l);
            total -= interval.length();
        }

        public boolean isEmpty() {
            return map.isEmpty();
        }

        public Iterator<LongIntervalMap.Interval> iterator() {
            return map.values().iterator();
        }

        public void add(long l, long r) {
            if (l >= r) {
                return;
            }
            LongIntervalMap.Interval interval = new LongIntervalMap.Interval();
            interval.l = l;
            interval.r = r;
            while (true) {
                Map.Entry<Long, LongIntervalMap.Interval> ceilEntry = map.ceilingEntry(interval.l);
                if (ceilEntry == null || ceilEntry.getValue().l > interval.r) {
                    break;
                }
                LongIntervalMap.Interval ceil = ceilEntry.getValue();
                remove(ceil);
                interval.r = Math.max(interval.r, ceil.r);
            }
            while (true) {
                Map.Entry<Long, LongIntervalMap.Interval> floorEntry = map.floorEntry(interval.l);
                if (floorEntry == null || floorEntry.getValue().r < interval.l) {
                    break;
                }
                LongIntervalMap.Interval floor = floorEntry.getValue();
                remove(floor);
                interval.l = Math.min(interval.l, floor.l);
                interval.r = Math.max(interval.r, floor.r);
            }
            add(interval);
        }

        public String toString() {
            return map.values().toString();
        }

        public void clear() {
            map.clear();
            total = 0;
        }

        public static class Interval {
            public long l;
            public long r;

            public long length() {
                return r - l;
            }

            public String toString() {
                return "[" + l + "," + r + ")";
            }

        }

    }

    static class Randomized {
        public static void shuffle(long[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                long tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return RandomWrapper.INSTANCE.nextInt(l, r);
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

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(String c) {
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

    static class LongArrayList implements Cloneable {
        private int size;
        private int cap;
        private long[] data;
        private static final long[] EMPTY = new long[0];

        public LongArrayList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new long[cap];
            }
        }

        public LongArrayList(long[] data) {
            this(0);
            addAll(data);
        }

        public LongArrayList(LongArrayList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public LongArrayList() {
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

        public void addAll(long[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(long[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(LongArrayList list) {
            addAll(list.data, 0, list.size);
        }

        public void sort() {
            if (size <= 1) {
                return;
            }
            Randomized.shuffle(data, 0, size);
            Arrays.sort(data, 0, size);
        }

        public void unique() {
            if (size <= 1) {
                return;
            }

            sort();
            int wpos = 1;
            for (int i = 1; i < size; i++) {
                if (data[i] != data[wpos - 1]) {
                    data[wpos++] = data[i];
                }
            }
            size = wpos;
        }

        public int binarySearch(long x) {
            return Arrays.binarySearch(data, 0, size, x);
        }

        public int size() {
            return size;
        }

        public long[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof LongArrayList)) {
                return false;
            }
            LongArrayList other = (LongArrayList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Long.hashCode(data[i]);
            }
            return h;
        }

        public LongArrayList clone() {
            LongArrayList ans = new LongArrayList();
            ans.addAll(this);
            return ans;
        }

    }

    static class RandomWrapper {
        private Random random;
        public static final RandomWrapper INSTANCE = new RandomWrapper(new Random());

        public RandomWrapper() {
            this(new Random());
        }

        public RandomWrapper(Random random) {
            this.random = random;
        }

        public int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }
}