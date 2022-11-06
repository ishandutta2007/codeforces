import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
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
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
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
            DFlipTheCards solver = new DFlipTheCards();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DFlipTheCards {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            Point[] pts = new Point[n];
            int sum = 0;
            for (int i = 0; i < n; i++) {
                pts[i] = new Point(i, in.ri(), in.ri(), 1);
                if (pts[i].y < pts[i].x) {
                    sum++;
                    pts[i].flip();
                }
            }

            XorDeltaDSU dsu = new XorDeltaDSU(n);
            dsu.init();
            Segment.dsu = dsu;
            Segment st = new Segment(1, 2 * n);
            Arrays.sort(pts, Comparator.comparingInt(x -> x.x));
            for (Point pt : pts) {
                st.update(1, pt.y - 1, 1, 2 * n, pt.id, 1, false);
                st.update(pt.y, pt.y, 1, 2 * n, pt.id, 0, true);
            }
            st.visit(1, 2 * n);
            if (!dsu.valid()) {
                out.println(-1);
                return;
            }

            long inf = (long) 1e18;
            List<Point>[] g = Graph.createGraph(n);
            for (Point pt : pts) {
                g[dsu.find(pt.id)].add(pt);
            }
            List<Point>[] group = new List[]{new ArrayList(n), new ArrayList(n)};
            for (List<Point> list : g) {
                if (list.isEmpty()) {
                    continue;
                }
                Point first = list.get(0);
                for (int i = 0; i < 2; i++) {
                    group[i].clear();
                }
                for (Point pt : list) {
                    group[dsu.delta(pt.id, first.id)].add(pt);
                }
                long best = inf;
                if (group[0].size() > 0 && group[1].size() > 0) {
                    for (int i = 0; i < 2; i++) {
                        long delta = 0;
                        long minX = inf;
                        long minY = inf;
                        long maxX = -inf;
                        long maxY = -inf;
                        for (Point pt : group[i]) {
                            delta += pt.cost;
                            minX = Math.min(minX, pt.y);
                            maxY = Math.max(maxY, pt.x);
                        }
                        for (Point pt : group[i ^ 1]) {
                            maxX = Math.max(maxX, pt.x);
                            minY = Math.min(minY, pt.y);
                        }
                        if (maxX < minX && maxY < minY) {
                            best = Math.min(delta, best);
                        }
                    }
                } else {
                    long delta = 0;
                    for (Point pt : list) {
                        delta += pt.cost;
                    }
                    best = Math.min(delta, 0);
                }

                if (best == inf) {
                    out.println(-1);
                    return;
                }
                sum += best;
            }

            out.println(sum);
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
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

        public int ri() {
            return readInt();
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
        int cost;

        public Point(int id, int x, int y, int cost) {
            this.id = id;
            this.x = x;
            this.y = y;
            this.cost = cost;
        }

        void flip() {
            int tmp = x;
            x = y;
            y = tmp;
            cost = -cost;
        }

        public String toString() {
            return String.format("(%d, %d)", x, y);
        }

    }

    static class XorDeltaDSU {
        int[] p;
        int[] size;
        int[] delta;
        boolean valid;

        public boolean valid() {
            return valid;
        }

        public XorDeltaDSU(int n) {
            p = new int[n];
            size = new int[n];
            delta = new int[n];
            init();
        }

        public void init() {
            init(p.length);
        }

        public void init(int n) {
            for (int i = 0; i < n; i++) {
                p[i] = i;
                size[i] = 0;
                delta[i] = 0;
            }
            valid = true;
        }

        public int find(int a) {
            if (p[a] == p[p[a]]) {
                return p[a];
            }
            find(p[a]);
            delta[a] ^= delta[p[a]];
            return p[a] = p[p[a]];
        }

        public int delta(int a, int b) {
            find(a);
            find(b);
            return delta[a] ^ delta[b];
        }

        public void merge(int a, int b, int d) {
            find(a);
            find(b);
            d = d ^ delta[a] ^ delta[b];
            a = find(a);
            b = find(b);
            if (a == b) {
                valid = valid && d == 0;
                return;
            }
            if (size[a] < size[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            size[a] += size[b];
            p[b] = a;
            delta[b] = d;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private final Writer os;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < THRESHOLD) {
                return;
            }
            flush();
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append('\n');
        }

        public FastOutput flush() {
            try {
//            boolean success = false;
//            if (stringBuilderValueField != null) {
//                try {
//                    char[] value = (char[]) stringBuilderValueField.get(cache);
//                    os.write(value, 0, cache.length());
//                    success = true;
//                } catch (Exception e) {
//                }
//            }
//            if (!success) {
                os.append(cache);
//            }
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

    static class Graph {
        public static List[] createGraph(int n) {
            return IntStream.range(0, n).mapToObj(i -> new ArrayList<>()).toArray(i -> new List[i]);
        }

    }

    static class Segment implements Cloneable {
        static XorDeltaDSU dsu;
        private Segment left;
        private Segment right;
        int xorWith = -1;
        int xorValue;
        boolean notEmpty = false;

        private void modify(int xorWith, int xorValue) {
            if (!notEmpty) {
                return;
            }
            if (this.xorWith != -1) {
                dsu.merge(this.xorWith, xorWith, this.xorValue ^ xorValue);
            } else {
                this.xorWith = xorWith;
                this.xorValue = xorValue;
            }
        }

        public void pushUp() {
            notEmpty = left.notEmpty || right.notEmpty;
        }

        public void pushDown() {
            if (xorWith != -1) {
                left.modify(xorWith, xorValue);
                right.modify(xorWith, xorValue);
                xorWith = -1;
            }
        }

        public Segment(int l, int r) {
            if (l < r) {
                int m = DigitUtils.floorAverage(l, r);
                left = new Segment(l, m);
                right = new Segment(m + 1, r);
                pushUp();
            } else {

            }
        }

        public void visit(int l, int r) {
            if (l == r) {
                return;
            }
            pushDown();
            int m = DigitUtils.floorAverage(l, r);
            left.visit(l, m);
            right.visit(m + 1, r);
        }

        private boolean enter(int L, int R, int l, int r) {
            return L <= l && R >= r;
        }

        private boolean leave(int L, int R, int l, int r) {
            return L > r || R < l;
        }

        public void update(int L, int R, int l, int r, int xorWith, int xorValue, boolean cover) {
            if (leave(L, R, l, r)) {
                return;
            }
            if (enter(L, R, l, r)) {
                if (cover) {
                    notEmpty = true;
                }
                modify(xorWith, xorValue);
                return;
            }
            pushDown();
            int m = DigitUtils.floorAverage(l, r);
            left.update(L, R, l, m, xorWith, xorValue, cover);
            right.update(L, R, m + 1, r, xorWith, xorValue, cover);
            pushUp();
        }

        private Segment deepClone() {
            Segment seg = clone();
            if (seg.left != null) {
                seg.left = seg.left.deepClone();
            }
            if (seg.right != null) {
                seg.right = seg.right.deepClone();
            }
            return seg;
        }

        protected Segment clone() {
            try {
                return (Segment) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        private void toString(StringBuilder builder) {
            if (left == null && right == null) {
                builder.append("val").append(",");
                return;
            }
            pushDown();
            left.toString(builder);
            right.toString(builder);
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            deepClone().toString(builder);
            if (builder.length() > 0) {
                builder.setLength(builder.length() - 1);
            }
            return builder.toString();
        }

    }
}