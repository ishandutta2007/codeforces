import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.util.function.IntFunction;
import java.io.OutputStream;
import java.util.Iterator;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.util.Comparator;
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
            DLargeTriangle solver = new DLargeTriangle();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DLargeTriangle {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            long s = in.readLong() * 2;

            Point[] points = new Point[n];
            for (int i = 0; i < n; i++) {
                points[i] = new Point();
                points[i].x = in.readInt();
                points[i].y = in.readInt();
            }

            List<Vector> allVectors = new ArrayList<>(n * n / 2);
            List<Vector> events = allVectors;

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    Vector parallel = new Vector(points[i], points[j]);
                    allVectors.add(parallel);
                }
            }

            allVectors.sort(Comparator.naturalOrder());
            //events.sort(Comparator.naturalOrder());

            Point[] ptsSortByArea = points.clone();
            Arrays.sort(ptsSortByArea, (a, b) -> Math.abs(a.y - b.y));
            for (int i = 0; i < n; i++) {
                ptsSortByArea[i].index = i;
            }

            Range2DequeAdapter<Vector> eventsDeque = new Range2DequeAdapter<Vector>(i -> events.get(i),
                    0, events.size() - 1);
            for (Vector vector : allVectors) {
                Point pt1 = vector.a;
                Point pt2 = vector.b;
                while (!eventsDeque.isEmpty() && eventsDeque.peekFirst().compareTo(vector) < 0) {
                    Vector event = eventsDeque.removeFirst();
                    handleEvent(ptsSortByArea, event.a, pt1, pt2);
                    handleEvent(ptsSortByArea, event.b, pt1, pt2);
                }
                IntBinarySearch ibs = new IntBinarySearch() {

                    public boolean check(int mid) {
                        long area = area(pt1, pt2, ptsSortByArea[mid]);
                        return area >= s;
                    }
                };
                int index1 = ibs.binarySearch(0, ptsSortByArea.length - 1);
                IntBinarySearch ibs2 = new IntBinarySearch() {

                    public boolean check(int mid) {
                        long area = area(pt1, pt2, ptsSortByArea[mid]);
                        return area >= -s;
                    }
                };
                int index2 = ibs2.binarySearch(0, ptsSortByArea.length - 1);
                if (area(pt1, pt2, ptsSortByArea[index2]) == -s) {
                    index1 = index2;
                }
                if (Math.abs(area(pt1, pt2, ptsSortByArea[index1])) == s) {
                    out.println("Yes");
                    for (Point pt : SequenceUtils.wrapObjectArray(pt1, pt2, ptsSortByArea[index1])) {
                        out.append(pt.x).append(' ').append(pt.y).println();
                    }
                    return;
                }
            }

            out.println("No");
        }

        public long area(Point pt1, Point pt2, Point pt3) {
            return Vector.cross(pt2.x - pt1.x, pt2.y - pt1.y,
                    pt3.x - pt1.x, pt3.y - pt1.y);
        }

        public void handleEvent(Point[] data, Point pt, Point pt1, Point pt2) {
            long area = area(pt1, pt2, pt);
            while (pt.index > 0 &&
                    area < area(pt1, pt2, data[pt.index - 1])) {
                swap(data, pt.index, pt.index - 1);
            }
            while (pt.index + 1 < data.length &&
                    area > area(pt1, pt2, data[pt.index + 1])) {
                swap(data, pt.index, pt.index + 1);
            }
        }

        public void swap(Point[] data, int i, int j) {
            Point tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            data[i].index = i;
            data[j].index = j;
        }

    }

    static class SequenceUtils {
        public static <T> T[] wrapObjectArray(T... x) {
            return x;
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

    static interface SimplifiedStack<T> extends Iterable<T> {
    }

    static abstract class IntBinarySearch {
        public abstract boolean check(int mid);

        public int binarySearch(int l, int r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            while (l < r) {
                int mid = (l + r) >>> 1;
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }

    }

    static interface SimplifiedDeque<T> extends SimplifiedStack<T> {
    }

    static class Point {
        int x;
        int y;
        int index;

        public String toString() {
            return String.format("(%d,%d)", x, y);
        }

    }

    static class Vector implements Comparable<Vector> {
        int x;
        int y;
        Point a;
        Point b;

        public Vector(Point a, Point b) {
            if (b.y < a.y || b.y == a.y && b.x < a.x) {
                Point tmp = a;
                a = b;
                b = tmp;
            }
            this.a = a;
            this.b = b;
            this.x = b.x - a.x;
            this.y = b.y - a.y;
        }

        public static long cross(long x1, long y1, long x2, long y2) {
            return x1 * y2 - x2 * y1;
        }

        public int compareTo(Vector o) {
            return -Long.signum(cross(x, y, o.x, o.y));
        }

        public String toString() {
            return String.format("(%d,%d)", x, y);
        }

    }
}