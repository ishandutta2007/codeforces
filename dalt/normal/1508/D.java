import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.stream.Collectors;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
            DSwapPass solver = new DSwapPass();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DSwapPass {
        List<int[]> seq = new ArrayList<>();

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            PointExt[] pts = new PointExt[n];
            DSU dsu = new DSU(n);
            dsu.init();
            for (int i = 0; i < n; i++) {
                pts[i] = new PointExt(in.ri(), in.ri(), in.ri() - 1);
                pts[i].id = i;
                dsu.merge(pts[i].id, pts[i].a);
            }
            List<PointExt> list = Arrays.stream(pts).filter(x -> x.id != x.a).collect(Collectors.toList());
            if (list.isEmpty()) {
                out.println(0);
                return;
            }
            list.sort(Comparator.<PointExt>comparingLong(x -> x.x).thenComparingLong(x -> x.y));
            PointExt first = list.remove(0);
            list.sort(IntegerPoint2.sortByPolarAngleAround(first));
            for (int i = 0; i + 1 < list.size(); i++) {
                PointExt cur = list.get(i);
                PointExt next = list.get(i + 1);
                if (dsu.find(cur.a) != dsu.find(next.a)) {
                    dsu.merge(cur.a, next.a);
                    add(cur, next);
                }
            }
            while (first.id != first.a) {
                add(first, pts[first.a]);
            }
            out.println(seq.size());
            for (int[] x : seq) {
                out.append(x[0] + 1).append(' ').append(x[1] + 1).println();
            }
        }

        void add(PointExt a, PointExt b) {
            seq.add(new int[]{a.id, b.id});
            int tmp = a.a;
            a.a = b.a;
            b.a = tmp;
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

    static class IntegerPoint2 {
        public final long x;
        public final long y;

        public static Comparator<IntegerPoint2> sortByPolarAngleAround(IntegerPoint2 center) {
            return (a, b) -> {
                int aHalf = half(a.x - center.x, a.y - center.y);
                int bHalf = half(b.x - center.x, b.y - center.y);
                if (aHalf != bHalf) {
                    return aHalf - bHalf;
                }
                return orient(center, b, a);
            };
        }

        public IntegerPoint2(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public IntegerPoint2() {
            this(0, 0);
        }

        private static int half(double x, double y) {
            return y > 0 || y == 0 && x < 0 ? 1 : 0;
        }

        private static long cross(long x1, long y1, long x2, long y2) {
            return x1 * y2 - y1 * x2;
        }

        public static int orient(IntegerPoint2 a, IntegerPoint2 b, IntegerPoint2 c) {
            return Long.signum(cross(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y));
        }

        public IntegerPoint2 clone() {
            try {
                return (IntegerPoint2) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        public String toString() {
            return String.format("(%d, %d)", x, y);
        }

    }

    static class PointExt extends IntegerPoint2 {
        int a;
        int id;

        public PointExt(long x, long y, int a) {
            super(x, y);
            this.a = a;
        }

    }

    static class DSU {
        protected int[] p;
        public int[] size;
        protected int n;

        public DSU(int n) {
            p = new int[n];
            size = new int[n];
        }

        public void init() {
            init(p.length);
        }

        public void init(int n) {
            this.n = n;
            for (int i = 0; i < n; i++) {
                p[i] = i;
                size[i] = 1;
            }
        }

        public final int find(int a) {
            if (p[a] == p[p[a]]) {
                return p[a];
            }
            find(p[a]);
            preAccess(a);
            return p[a] = p[p[a]];
        }

        protected void preAccess(int a) {

        }

        protected void preMerge(int a, int b) {
            size[a] += size[b];
        }

        public final void merge(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return;
            }

            if (size[a] < size[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            preMerge(a, b);
            p[b] = a;
        }

        public String toString() {
            return Arrays.toString(Arrays.copyOf(p, n));
        }

    }
}