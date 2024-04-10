import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Collection;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.TreeMap;
import java.io.Closeable;
import java.util.Map;
import java.io.Writer;
import java.util.Map.Entry;
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
            DNewYearAndConference solver = new DNewYearAndConference();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DNewYearAndConference {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Item[] items = new Item[n];
            for (int i = 0; i < n; i++) {
                items[i] = new Item();
                items[i].a.l = in.readInt();
                items[i].a.r = in.readInt();
                items[i].b.l = in.readInt();
                items[i].b.r = in.readInt();
            }

            boolean valid = check(items);
            for (Item item : items) {
                Interval tmp = item.a;
                item.a = item.b;
                item.b = tmp;
            }
            valid = valid && check(items);

            if (valid) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }

        public boolean check(Item[] items) {
            int n = items.length;
            IntervalBooleanMap map = new IntervalBooleanMap();
            Item[] sortedByAL = items.clone();
            Item[] sortedByAR = items.clone();
            Arrays.sort(sortedByAL, (a, b) -> a.a.l - b.a.l);
            Arrays.sort(sortedByAR, (a, b) -> a.a.r - b.a.r);
            SimplifiedDeque<Item> deque = new Array2DequeAdapter<>(sortedByAR);
            for (Item item : sortedByAL) {
                while (!deque.isEmpty() && deque.peekFirst().a.r < item.a.l) {
                    Item head = deque.removeFirst();
                    map.setTrue(head.b.l, head.b.r);
                }
                if (map.or(item.b.l, item.b.r)) {
                    return false;
                }
            }
            return true;
        }

    }

    static class Interval {
        int l;
        int r;

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

    static interface SimplifiedStack<T> extends Iterable<T> {
        boolean isEmpty();

    }

    static class Item {
        Interval a = new Interval();
        Interval b = new Interval();

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

        public FastOutput println(String c) {
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

    static interface SimplifiedDeque<T> extends SimplifiedStack<T> {
        T peekFirst();

        T removeFirst();

    }

    static class IntervalBooleanMap implements Iterable<IntervalBooleanMap.Interval> {
        private TreeMap<Long, IntervalBooleanMap.Interval> map = new TreeMap<>();
        private long total = 0;

        public void removeInterval(IntervalBooleanMap.Interval interval) {
            map.remove(interval.l);
            total -= interval.length();
        }

        public void addInterval(IntervalBooleanMap.Interval interval) {
            if (interval.length() <= 0) {
                return;
            }
            map.put(interval.l, interval);
            total += interval.length();
        }

        public void setTrue(long l, long r) {
            if (l > r) {
                return;
            }
            IntervalBooleanMap.Interval interval = new IntervalBooleanMap.Interval();
            interval.l = l;
            interval.r = r;
            while (true) {
                Map.Entry<Long, IntervalBooleanMap.Interval> floorEntry = map.floorEntry(interval.l);
                if (floorEntry == null) {
                    break;
                }
                IntervalBooleanMap.Interval floorInterval = floorEntry.getValue();
                if (floorInterval.r >= interval.r) {
                    return;
                } else if (floorInterval.r < interval.l) {
                    break;
                } else {
                    interval.l = Math.min(interval.l, floorInterval.l);
                    removeInterval(floorInterval);
                }
            }
            while (true) {
                Map.Entry<Long, IntervalBooleanMap.Interval> ceilEntry = map.ceilingEntry(interval.l);
                if (ceilEntry == null) {
                    break;
                }
                IntervalBooleanMap.Interval ceilInterval = ceilEntry.getValue();
                if (ceilInterval.l <= interval.l) {
                    return;
                } else if (ceilInterval.l > interval.r) {
                    break;
                } else {
                    interval.r = Math.max(interval.r, ceilInterval.r);
                    removeInterval(ceilInterval);
                }
            }

            addInterval(interval);
        }

        public boolean or(long l, long r) {
            Map.Entry<Long, IntervalBooleanMap.Interval> entry = map.floorEntry(r);
            return entry != null && entry.getValue().r >= l;
        }

        public Iterator<IntervalBooleanMap.Interval> iterator() {
            return map.values().iterator();
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (IntervalBooleanMap.Interval interval : map.values()) {
                builder.append(interval).append(',');
            }
            if (builder.length() > 0) {
                builder.setLength(builder.length() - 1);
            }
            return builder.toString();
        }

        public static class Interval {
            long l;
            long r;

            long length() {
                return r - l + 1;
            }

            public String toString() {
                return String.format("[%d, %d]", l, r);
            }

        }

    }
}