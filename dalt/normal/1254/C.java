import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
            TaskC solver = new TaskC();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskC {
        FastInput in;
        FastOutput out;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            this.in = in;
            this.out = out;
            int n = in.readInt();
            Point[] points = new Point[n + 1];
            for (int i = 1; i <= n; i++) {
                points[i] = new Point();
                points[i].id = i;
            }

            List<Point> up = new ArrayList<>();
            List<Point> down = new ArrayList<>();
            for (int i = 3; i <= n; i++) {
                points[i].area = gotY(1, 2, i);
                if (isCC(1, 2, i)) {
                    up.add(points[i]);
                } else {
                    down.add(points[i]);
                }
            }

            List<Point> lt = new ArrayList<>();
            List<Point> rt = new ArrayList<>();
            List<Point> ld = new ArrayList<>();
            List<Point> rd = new ArrayList<>();

            if (!up.isEmpty()) {
                Point upMax = maxAreaPoint(up);
                for (Point pt : up) {
                    if (pt == upMax) {
                        continue;
                    }
                    if (isCC(1, upMax.id, pt.id)) {
                        lt.add(pt);
                    } else {
                        rt.add(pt);
                    }
                }
                if (lt.isEmpty() || maxAreaPoint(lt).area < upMax.area) {
                    lt.add(upMax);
                } else {
                    rt.add(upMax);
                }
            }

            if (!down.isEmpty()) {
                Point downMax = maxAreaPoint(down);
                for (Point pt : down) {
                    if (pt == downMax) {
                        continue;
                    }
                    if (isCC(1, downMax.id, pt.id)) {
                        rd.add(pt);
                    } else {
                        ld.add(pt);
                    }
                }
                if (ld.isEmpty() || maxAreaPoint(ld).area < downMax.area) {
                    ld.add(downMax);
                } else {
                    rd.add(downMax);
                }
            }

            out.println(0);
            out.append(1).append(' ');
            ld.sort((a, b) -> Long.compare(a.area, b.area));
            for (Point p : ld) {
                out.append(p.id).append(' ');
            }
            rd.sort((a, b) -> -Long.compare(a.area, b.area));
            for (Point p : rd) {
                out.append(p.id).append(' ');
            }
            out.append(2).append(' ');
            rt.sort((a, b) -> Long.compare(a.area, b.area));
            for (Point p : rt) {
                out.append(p.id).append(' ');
            }
            lt.sort((a, b) -> -Long.compare(a.area, b.area));
            for (Point p : lt) {
                out.append(p.id).append(' ');
            }
            out.flush();
        }

        public Point maxAreaPoint(List<Point> pt) {
            Point max = pt.get(0);
            for (Point p : pt) {
                if (max.area < p.area) {
                    max = p;
                }
            }
            return max;
        }

        public boolean isCC(int zero, int i, int j) {
            out.printf("2 %d %d %d\n", zero, i, j);
            out.flush();
            int sign = in.readInt();
            return sign > 0;
        }

        public long gotY(int zero, int x, int j) {
            out.printf("1 %d %d %d\n", zero, x, j);
            out.flush();
            long area = in.readLong();
            return area;
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput printf(String format, Object... args) {
            cache.append(String.format(format, args));
            return this;
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

    static class Point {
        long area;
        int id;

    }
}