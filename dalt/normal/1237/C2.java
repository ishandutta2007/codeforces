import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.util.stream.Collectors;
import java.util.TreeSet;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
import java.util.Map;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
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
            TaskC2 solver = new TaskC2();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskC2 {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();

            List<Point> ptList = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                Point pt = new Point();
                pt.x = in.readInt();
                pt.y = in.readInt();
                pt.z = in.readInt();
                pt.id = i + 1;

                ptList.add(pt);
            }

            Map<Integer, List<Point>> groupByX = ptList.stream()
                    .collect(Collectors.groupingBy((x) -> x.x));

            TreeSet<Point> wait = new TreeSet<>(Point.sortByXYZ);
            for (List<Point> sameX : groupByX.values()) {
                TreeSet<Point> xQ = new TreeSet<>(Point.sortByXYZ);
                Map<Integer, List<Point>> groupByY = sameX.stream()
                        .collect(Collectors.groupingBy((x) -> x.y));
                for (List<Point> sameY : groupByY.values()) {
                    TreeSet<Point> yQ = new TreeSet<>(Point.sortByXYZ);
                    Map<Integer, List<Point>> groupByZ = sameY.stream()
                            .collect(Collectors.groupingBy((x) -> x.z));
                    for (List<Point> sameZ : groupByZ.values()) {
                        int m = sameZ.size();
                        int i;
                        for (i = 0; i + 1 < m; i += 2) {
                            answer(sameZ.get(i), sameZ.get(i + 1), out);
                        }
                        if (i < m) {
                            yQ.add(sameZ.get(i));
                        }
                    }

                    while (yQ.size() >= 2) {
                        answer(yQ.pollFirst(), yQ.pollFirst(), out);
                    }

                    xQ.addAll(yQ);
                }

                while (xQ.size() >= 2) {
                    answer(xQ.pollFirst(), xQ.pollFirst(), out);
                }
                wait.addAll(xQ);
            }

            while (wait.size() >= 2) {
                answer(wait.pollFirst(), wait.pollFirst(), out);
            }
        }

        public void answer(Point a, Point b, FastOutput out) {
            out.append(a.id).append(' ').append(b.id).append('\n');
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
                    throw new RuntimeException(e);
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

    static class Point {
        int id;
        int x;
        int y;
        int z;
        static Comparator<Point> sortByXYZ = (a, b) -> a.x != b.x ? a.x - b.x : a.y != b.y ? a.y - b.y : a.z - b.z;

        public int hashCode() {
            int h = x;
            h = h * 31 + y;
            h = h * 31 + z;
            return h;
        }

        public boolean equals(Object obj) {
            Point pt = (Point) obj;
            return x == pt.x && y == pt.y && z == pt.z;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(1 << 20);
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

        public FastOutput flush() {
            try {
                os.append(cache);
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

    }
}