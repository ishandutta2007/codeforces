import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.util.Random;
import java.util.Deque;
import java.io.UncheckedIOException;
import java.util.Map;
import java.io.Closeable;
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
            TaskA solver = new TaskA();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskA {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            Deque<Long> deque = new ArrayDeque<>(n);
            long max = 0;
            for (int i = 0; i < n; i++) {
                deque.addLast(in.readLong());
                max = Math.max(max, deque.peekLast());
            }

            long time = 0;
            boolean stable = false;
            long[] queue = new long[n];
            int point = 0;

            Query[] qs = new Query[m];
            LongList ask = new LongList(m);
            for (int i = 0; i < m; i++) {
                qs[i] = new Query();
                qs[i].time = in.readLong();
                ask.add(qs[i].time);
            }


            ask.unique();
            Map<Long, long[]> ans = new HashMap<>();
            for (int i = 0; i < ask.size(); i++) {
                long t = ask.get(i);
                long elapse = t - time;
                time = t;

                if (!stable) {
                    while (elapse > 1 && deque.peekFirst() != max) {
                        elapse--;
                        long a = deque.removeFirst();
                        long b = deque.removeFirst();
                        deque.addLast(Math.min(a, b));
                        deque.addFirst(Math.max(a, b));
                    }
                    if (deque.peekFirst() == max) {
                        for (int j = 0; j < n; j++) {
                            queue[j] = deque.removeFirst();
                        }
                        point = 0;
                        stable = true;
                    } else {
                        long a = deque.removeFirst();
                        long b = deque.removeFirst();
                        deque.addLast(Math.min(a, b));
                        deque.addFirst(Math.max(a, b));
                        ans.put(t, SequenceUtils.wrapArray(a, b));
                        continue;
                    }
                }

                point = (int) ((point + elapse - 1) % (n - 1));
                ans.put(t, SequenceUtils.wrapArray(queue[0], queue[point + 1]));
                point = (int) ((point + 1) % (n - 1));
            }

            for (Query q : qs) {
                long[] val = ans.get(q.time);
                out.append(val[0]).append(' ').append(val[1]).append('\n');
            }
        }

    }

    static class LongList {
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

        private void ensureSpace(int need) {
            int req = size + need;
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException();
            }
        }

        public long get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(long x) {
            ensureSpace(1);
            data[size++] = x;
        }

        public void sort() {
            if (size <= 1) {
                return;
            }
            Randomized.randomizedArray(data, 0, size);
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

        public int size() {
            return size;
        }

        public String toString() {
            return Arrays.toString(Arrays.copyOf(data, size));
        }

    }

    static class Randomized {
        static Random random = new Random();

        public static void randomizedArray(long[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                long tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
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

    static class SequenceUtils {
        public static long[] wrapArray(long... x) {
            return x;
        }

    }

    static class Query {
        long time;

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
}