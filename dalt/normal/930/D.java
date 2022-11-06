import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;
import java.util.function.IntFunction;

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
            DGameWithTokens solver = new DGameWithTokens();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DGameWithTokens {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Point[] pts = new Point[n];
            List<Point>[] lists = new List[]{new ArrayList(n), new ArrayList(n)};
            for (int i = 0; i < n; i++) {
                pts[i] = new Point();
                int x = in.readInt();
                int y = in.readInt();
                pts[i].x = y - x;
                pts[i].y = y + x;
                lists[pts[i].y & 1].add(pts[i]);
            }
            long sum1 = count(lists[0].toArray(new Point[0]), 0);
            long sum2 = count(lists[1].toArray(new Point[0]), 1);
            out.println(sum1 + sum2);
        }

        public long count(Point[] pts, int odd) {
            Arrays.sort(pts, (a, b) -> Integer.compare(a.y, b.y));
            int limit = 300000;

            SimplifiedDeque<Point> dq = new Range2DequeAdapter<>(i -> pts[i], 0, pts.length - 1);
            int[] left = new int[limit * 2 + 1];
            int[] right = new int[limit * 2 + 1];
            int l = limit;
            int r = -limit;
            for (int i = limit; i >= -limit; i--) {
                while (!dq.isEmpty() && dq.peekLast().y > i) {
                    Point head = dq.removeLast();
                    l = Math.min(l, head.x);
                    r = Math.max(r, head.x);
                }
                left[i + limit] = l;
                right[i + limit] = r;
            }

            l = limit;
            r = -limit;
            dq = new Range2DequeAdapter<>(i -> pts[i], 0, pts.length - 1);
            for (int i = -limit; i <= limit; i++) {
                while (!dq.isEmpty() && dq.peekFirst().y < i) {
                    Point head = dq.removeFirst();
                    l = Math.min(l, head.x);
                    r = Math.max(r, head.x);
                }
                left[i + limit] = Math.max(left[i + limit], l);
                right[i + limit] = Math.min(right[i + limit], r);
            }

            long sum = 0;
            for (int i = 0; i < left.length; i++) {
                int y = i - limit;
                if ((y & 1) == (odd & 1)) {
                    continue;
                }
                if ((left[i] & 1) == (y & 1)) {
                    left[i]++;
                }
                if ((right[i] & 1) == (y & 1)) {
                    right[i]--;
                }
                if (right[i] <= left[i]) {
                    continue;
                }
                sum += (right[i] - left[i]) / 2;
            }
            return sum;
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

        public FastOutput println(long c) {
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

    static interface SimplifiedStack<T> extends Iterable<T> {
        boolean isEmpty();

        T peekLast();

        T removeLast();

    }

    static class Point {
        int x;
        int y;

    }

    static interface SimplifiedDeque<T> extends SimplifiedStack<T> {
        T peekFirst();

        T removeFirst();

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 20];
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

    static class Range2DequeAdapter<T> implements SimplifiedDeque<T> {
        IntFunction<T> data;
        int l;
        int r;

        public Range2DequeAdapter(IntFunction<T> data, int l, int r) {
            this.data = data;
            this.l = l;
            this.r = r;
        }

        public boolean isEmpty() {
            return l > r;
        }

        public T peekFirst() {
            return data.apply(l);
        }

        public T removeFirst() {
            return data.apply(l++);
        }

        public T peekLast() {
            return data.apply(r);
        }

        public T removeLast() {
            return data.apply(r--);
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                int iter = l;


                public boolean hasNext() {
                    return iter <= r;
                }


                public T next() {
                    return data.apply(iter++);
                }
            };
        }

    }
}