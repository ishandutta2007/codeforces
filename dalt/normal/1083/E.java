import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.Deque;
import java.io.UncheckedIOException;
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
            ETheFairNutAndRectangles solver = new ETheFairNutAndRectangles();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ETheFairNutAndRectangles {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Rect[] rects = new Rect[n + 1];
            for (int i = 1; i <= n; i++) {
                rects[i] = new Rect();
                rects[i].x = in.readInt();
                rects[i].y = in.readInt();
                rects[i].a = in.readLong();
            }
            rects[0] = new Rect();
            rects[0].x = 0;
            rects[0].y = Integer.MAX_VALUE;
            rects[0].a = 0;
            Arrays.sort(rects, (a, b) -> a.x - b.x);

            long[] dp = new long[n + 1];
            GeqSlopeOptimizer optimizer = new GeqSlopeOptimizer(n + 1);
            dp[0] = 0;
            optimizer.add(dp[0], 0, 0);
            for (int i = 1; i <= n; i++) {
                int index = optimizer.getBestChoice(rects[i].y);
                dp[i] = dp[index] - (long) rects[index].x * rects[i].y + (long) rects[i].x * rects[i].y - rects[i].a;
                optimizer.add(dp[i], rects[i].x, i);
            }

            long max = 0;
            for (int i = 1; i <= n; i++) {
                max = Math.max(max, dp[i]);
            }

            out.println(max);
        }

    }

    static class GeqSlopeOptimizer {
        Deque<GeqSlopeOptimizer.Point> deque;

        public GeqSlopeOptimizer() {
            this(0);
        }

        public GeqSlopeOptimizer(int exp) {
            deque = new ArrayDeque<>(exp);
        }

        private double slope(GeqSlopeOptimizer.Point a, GeqSlopeOptimizer.Point b) {
            if (b.x == a.x) {
                if (b.y == a.y) {
                    return 0;
                } else if (b.y > a.y) {
                    return 1e50;
                } else {
                    return 1e-50;
                }
            }
            return (double) (b.y - a.y) / (b.x - a.x);
        }

        public GeqSlopeOptimizer.Point add(long y, long x, int id) {
            GeqSlopeOptimizer.Point t1 = new GeqSlopeOptimizer.Point(x, y, id);
            while (deque.size() >= 2) {
                GeqSlopeOptimizer.Point t2 = deque.removeLast();
                GeqSlopeOptimizer.Point t3 = deque.peekLast();
                if (slope(t3, t2) > slope(t2, t1)) {
                    deque.addLast(t2);
                    break;
                }
            }
            deque.addLast(t1);
            return t1;
        }

        public int getBestChoice(long s) {
            while (deque.size() >= 2) {
                GeqSlopeOptimizer.Point h1 = deque.removeFirst();
                GeqSlopeOptimizer.Point h2 = deque.peekFirst();
                if (slope(h2, h1) < s) {
                    deque.addFirst(h1);
                    break;
                }
            }
            return deque.peekFirst().id;
        }

        private static class Point {
            final long x;
            final long y;
            final int id;

            private Point(long x, long y, int id) {
                this.x = x;
                this.y = y;
                this.id = id;
            }

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

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(long c) {
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

    static class Rect {
        int x;
        int y;
        long a;

    }
}