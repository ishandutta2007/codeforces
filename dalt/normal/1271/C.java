import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
            CShawarmaTent solver = new CShawarmaTent();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CShawarmaTent {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int sx = in.readInt();
            int sy = in.readInt();

            Point[] points = new Point[n];
            for (int i = 0; i < n; i++) {
                points[i] = new Point(in.readInt() - sx, in.readInt() - sy);
            }

            int ans = 0;
            Point best = new Point(0, 0);

            for (int[] sign : new int[][]{
                    {1, 1},
                    {-1, 1},
                    {-1, -1},
                    {1, -1}
            }) {
                for (Point pt : points) {
                    pt.x *= sign[0];
                    pt.y *= sign[1];
                }

                Point tmp = new Point(0, 0);
                int x = solve(points, tmp);
                if (x > ans) {
                    ans = x;
                    best = tmp;
                    best.x *= sign[0];
                    best.y *= sign[1];
                }

                for (Point pt : points) {
                    pt.x *= sign[0];
                    pt.y *= sign[1];
                }
            }

            out.println(ans);
            out.append(best.x + sx).append(' ').append(best.y + sy).println();
        }

        public int solve(Point[] pts, Point camp) {
            int ans = 0;
            int ct1 = count(pts, new Point(1, 0));
            if (ct1 > ans) {
                ans = ct1;
                camp.x = 1;
                camp.y = 0;
            }
            int ct2 = count(pts, new Point(1, 1));
            if (ct2 > ans) {
                ans = ct2;
                camp.x = 1;
                camp.y = 1;
            }
            int ct3 = count(pts, new Point(0, 1));
            if (ct3 > ans) {
                ans = ct3;
                camp.x = 0;
                camp.y = 1;
            }
            return ans;
        }

        public int count(Point[] pts, Point lb) {
            int count = 0;
            for (Point pt : pts) {
                if (lb.y == 0 && pt.x >= lb.x) {
                    count++;
                } else if (lb.x == 0 && pt.y >= lb.y) {
                    count++;
                } else if (lb.x > 0 && lb.y > 0 && pt.x >= lb.x && pt.y >= lb.y) {
                    count++;
                }
            }
            return count;
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

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
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

    static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
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
}