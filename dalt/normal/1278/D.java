import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.io.UncheckedIOException;
import java.util.AbstractMap;
import java.util.TreeMap;
import java.util.Map;
import java.io.Closeable;
import java.util.Map.Entry;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
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
            DSegmentTree solver = new DSegmentTree();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DSegmentTree {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Interval[] intervals = new Interval[n];
            for (int i = 0; i < n; i++) {
                intervals[i] = new Interval();
                intervals[i].l = in.readInt();
                intervals[i].r = in.readInt();
            }
            Arrays.sort(intervals, (a, b) -> a.r - b.r);
            TreeMap<Integer, Interval> map = new TreeMap<>();
            for (int i = 0; i < n; i++) {
                map.put(intervals[i].l, intervals[i]);
            }

            Deque<Interval> deque = new ArrayDeque<>(n);

            for (int i = 0; i < n; i++) {
                while (!map.isEmpty() && map.floorKey(intervals[i].r) > intervals[i].l) {
                    Map.Entry<Integer, Interval> floor = map.floorEntry(intervals[i].r);
                    if (floor.getValue().r <= intervals[i].r) {
                        map.remove(floor.getKey());
                        continue;
                    }

                    if (intervals[i].find() == floor.getValue().find()) {
                        //find loop
                        out.println("NO");
                        return;
                    }

                    Interval.merge(intervals[i], floor.getValue());
                    deque.addLast(map.remove(floor.getKey()));
                }

                while (!deque.isEmpty()) {
                    map.put(deque.peekFirst().l, deque.removeFirst());
                }
            }

            for (int i = 1; i < n; i++) {
                if (intervals[i].find() != intervals[0].find()) {
                    out.println("NO");
                    return;
                }
            }

            out.println("YES");
            return;
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

    static class Interval {
        int l;
        int r;
        Interval p = this;
        int rank;

        Interval find() {
            return p.p == p ? p : (p = p.find());
        }

        static void merge(Interval a, Interval b) {
            a = a.find();
            b = b.find();
            if (a == b) {
                return;
            }
            if (a.rank == b.rank) {
                a.rank++;
            }
            if (a.rank > b.rank) {
                b.p = a;
            } else {
                a.p = b;
            }
        }

    }
}