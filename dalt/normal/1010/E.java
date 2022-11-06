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
            EStore solver = new EStore();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EStore {
        IntegerBIT bit = new IntegerBIT(100000);
        Point[] buf;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int xr = 1;
            int yr = 1;
            int zr = 1;
            int xl = in.readInt();
            int yl = in.readInt();
            int zl = in.readInt();
            int n = in.readInt();
            int m = in.readInt();
            int k = in.readInt();

            for (int i = 0; i < n; i++) {
                int x = in.readInt();
                int y = in.readInt();
                int z = in.readInt();
                xl = Math.min(xl, x);
                yl = Math.min(yl, y);
                zl = Math.min(zl, z);
                xr = Math.max(xr, x);
                yr = Math.max(yr, y);
                zr = Math.max(zr, z);
            }

            List<Point> list = new ArrayList<>(m + 8 * k);
            for (int i = 0; i < m; i++) {
                int x = in.readInt();
                int y = in.readInt();
                int z = in.readInt();
                if (x >= xl && x <= xr && y >= yl && y <= yr && z >= zl && z <= zr) {
                    out.println("INCORRECT");
                    return;
                }

                list.add(new Point(x, y, z, 1));
            }

            out.println("CORRECT");
            Query[] qs = new Query[k];
            for (int i = 0; i < k; i++) {
                int x = in.readInt();
                int y = in.readInt();
                int z = in.readInt();
                int tpx = Math.max(x, xr);
                int tpy = Math.max(y, yr);
                int tpz = Math.max(z, zr);
                int btx = Math.min(x, xl);
                int bty = Math.min(y, yl);
                int btz = Math.min(z, zl);

                Query q = new Query();
                q.include = xl <= x && x <= xr && yl <= y && y <= yr && zl <= z && z <= zr;
                q.points[0] = new Point(tpx, tpy, tpz, 0);
                q.points[1] = new Point(btx - 1, tpy, tpz, 0);
                q.points[2] = new Point(tpx, bty - 1, tpz, 0);
                q.points[3] = new Point(tpx, tpy, btz - 1, 0);
                q.points[4] = new Point(btx - 1, bty - 1, tpz, 0);
                q.points[5] = new Point(btx - 1, tpy, btz - 1, 0);
                q.points[6] = new Point(tpx, bty - 1, btz - 1, 0);
                q.points[7] = new Point(btx - 1, bty - 1, btz - 1, 0);
                qs[i] = q;
                for (Point pt : q.points) {
                    list.add(pt);
                }
            }

            Point[] points = list.toArray(new Point[0]);
            buf = new Point[points.length];
            Arrays.sort(points, (a, b) -> {
                int c = a.x - b.x;
                if (c == 0) {
                    c = a.y - b.y;
                }
                if (c == 0) {
                    c = a.z - b.z;
                }
                if (c == 0) {
                    c = -(a.w - b.w);
                }
                return c;
            });

            dac(points, 0, points.length - 1);
            for (Query q : qs) {
                if (q.include) {
                    out.println("OPEN");
                } else if (q.get() == 0) {
                    out.println("UNKNOWN");
                } else {
                    out.println("CLOSED");
                }
            }
        }

        public void dac(Point[] points, int l, int r) {
            if (l >= r) {
                return;
            }
            int m = (l + r) / 2;
            dac(points, l, m);
            dac(points, m + 1, r);
            Arrays.sort(points, l, m + 1, (a, b) -> a.y - b.y);
            Arrays.sort(points, m + 1, r + 1, (a, b) -> a.y - b.y);
            SimplifiedDeque<Point> dq1 = new Range2DequeAdapter<>(i -> points[i], l, m);
            SimplifiedDeque<Point> dq2 = new Range2DequeAdapter<>(i -> points[i], m + 1, r);
            while (!dq1.isEmpty() || !dq2.isEmpty()) {
                if (dq2.isEmpty() || (!dq1.isEmpty() && dq1.peekFirst().y <= dq2.peekFirst().y)) {
                    Point head = dq1.removeFirst();
                    if (head.w == 1) {
                        bit.update(head.z, head.w);
                    }
                } else {
                    Point head = dq2.removeFirst();
                    head.sum += bit.query(head.z);
                }
            }
            for (int i = l; i <= m; i++) {
                if (points[i].w == 1) {
                    bit.update(points[i].z, -points[i].w);
                }
            }
        }

    }

    static class Query {
        boolean include;
        Point[] points = new Point[8];

        public int get() {
            return points[0].sum - points[1].sum - points[2].sum - points[3].sum
                    + points[4].sum + points[5].sum + points[6].sum - points[7].sum;
        }

    }

    static class IntegerBIT {
        private int[] data;
        private int n;

        public IntegerBIT(int n) {
            this.n = n;
            data = new int[n + 1];
        }

        public int query(int i) {
            int sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += data[i];
            }
            return sum;
        }

        public void update(int i, int mod) {
            if (i <= 0) {
                return;
            }
            for (; i <= n; i += i & -i) {
                data[i] += mod;
            }
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 1; i <= n; i++) {
                builder.append(query(i) - query(i - 1)).append(' ');
            }
            return builder.toString();
        }

    }

    static class Point {
        int x;
        int y;
        int z;
        int w;
        int sum;

        public Point(int x, int y, int z, int w) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = w;
        }

        public String toString() {
            return String.format("(%d, %d, %d, %d, %d)", x, y, z, w, sum);
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

        public FastOutput println(String c) {
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

    static interface SimplifiedDeque<T> extends SimplifiedStack<T> {
        T peekFirst();

        T removeFirst();

    }

    static interface SimplifiedStack<T> extends Iterable<T> {
        boolean isEmpty();

    }
}