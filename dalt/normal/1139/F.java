import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
import java.io.IOException;
import java.util.Random;
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
            FDishShopping solver = new FDishShopping();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FDishShopping {
        BIT bit;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();

            Point[] ps = new Point[n];
            IntList list = new IntList(2 * n);

            for (int i = 0; i < n; i++) {
                ps[i] = new Point();
            }
            for (int i = 0; i < n; i++) {
                ps[i].x = in.readInt();
            }
            for (int i = 0; i < n; i++) {
                ps[i].y = in.readInt();
            }
            for (int i = 0; i < n; i++) {
                ps[i].z = in.readInt();
            }

            for (int i = 0; i < n; i++) {
                int x = ps[i].x;
                int y = ps[i].z;
                ps[i].z = ps[i].y;

                ps[i].x = x + y;
                ps[i].y = y - x;
                ps[i].val = 1;
                ps[i].id = "p" + i;
                list.add(ps[i].x);
            }

            Point[] qs = new Point[m];
            for (int i = 0; i < m; i++) {
                qs[i] = new Point();
            }

            for (int i = 0; i < m; i++) {
                qs[i].x = in.readInt();
            }

            for (int i = 0; i < m; i++) {
                qs[i].y = in.readInt();
            }

            for (int i = 0; i < m; i++) {
                int x = qs[i].x;
                int y = qs[i].y;
                qs[i].x = x + y;
                qs[i].y = y - x;
                qs[i].z = x;
                qs[i].id = "q" + i;
                list.add(qs[i].x);
            }

            DiscreteMap dm = new DiscreteMap(list.getData());
            Point[] allPts = new Point[n + m];
            System.arraycopy(ps, 0, allPts, 0, n);
            System.arraycopy(qs, 0, allPts, n, m);
            for (Point pt : allPts) {
                pt.x = dm.rankOf(pt.x) + 1;
            }
            bit = new BIT(dm.maxRank() + 1);

            Arrays.sort(allPts, (a, b) -> {
                int ans = -Integer.compare(a.z, b.z);
                if (ans == 0) {
                    ans = -Integer.compare(a.y, b.y);
                }
                if (ans == 0) {
                    ans = Integer.compare(a.x, b.x);
                }
                if (ans == 0) {
                    ans = -Integer.compare(a.val, b.val);
                }
                return ans;
            });

            dac(allPts, 0, n + m - 1);

            for (int i = 0; i < m; i++) {
                out.println(qs[i].ans);
            }
        }

        public void dac(Point[] pts, int l, int r) {
            if (l >= r) {
                pts[l].ans += pts[l].val;
                return;
            }
            int m = (l + r) >> 1;
            dac(pts, l, m);
            dac(pts, m + 1, r);

            Arrays.sort(pts, l, m + 1, (a, b) -> -Integer.compare(a.y, b.y));
            Arrays.sort(pts, m + 1, r + 1, (a, b) -> -Integer.compare(a.y, b.y));

            Array2DequeAdapter<Point> lDeque = new Array2DequeAdapter<>(pts, l, m);
            Array2DequeAdapter<Point> rDeque = new Array2DequeAdapter<>(pts, m + 1, r);
            for (int i = m + 1; i <= r; i++) {
                Point first = rDeque.removeFirst();
                while (!lDeque.isEmpty() && lDeque.peekFirst().y >= first.y) {
                    Point head = lDeque.removeFirst();
                    bit.update(head.x, head.val);
                }
                first.ans += bit.query(first.x);
            }
            while (!lDeque.isEmpty()) {
                Point head = lDeque.removeFirst();
                bit.update(head.x, head.val);
            }
            for (int i = l; i <= m; i++) {
                bit.update(pts[i].x, -pts[i].val);
            }
        }

    }

    static class IntList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public int[] getData() {
            return data;
        }

        public IntList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntList(IntList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntList() {
            this(0);
        }

        public void ensureSpace(int req) {
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntList list) {
            addAll(list.data, 0, list.size);
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntList)) {
                return false;
            }
            IntList other = (IntList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + data[i];
            }
            return h;
        }

        public IntList clone() {
            IntList ans = new IntList();
            ans.addAll(this);
            return ans;
        }

    }

    static class DiscreteMap {
        int[] val;
        int f;
        int t;

        public DiscreteMap(int[] val) {
            this(val, 0, val.length);
        }

        public DiscreteMap(int[] val, int f, int t) {
            Randomized.randomizedArray(val, f, t);
            Arrays.sort(val, f, t);
            int wpos = f + 1;
            for (int i = f + 1; i < t; i++) {
                if (val[i] == val[i - 1]) {
                    continue;
                }
                val[wpos++] = val[i];
            }
            this.val = val;
            this.f = f;
            this.t = wpos;
        }

        public int rankOf(int x) {
            return Arrays.binarySearch(val, f, t, x) - f;
        }

        public int maxRank() {
            return t - f - 1;
        }

        public String toString() {
            return Arrays.toString(Arrays.copyOfRange(val, f, t));
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
        int x;
        int y;
        int z;
        int val;
        int ans;
        String id;

        public String toString() {
            return id;
        }

    }

    static class SequenceUtils {
        public static boolean equal(int[] a, int al, int ar, int[] b, int bl, int br) {
            if ((ar - al) != (br - bl)) {
                return false;
            }
            for (int i = al, j = bl; i <= ar; i++, j++) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return true;
        }

    }

    static class BIT {
        private int[] data;
        private int n;

        public BIT(int n) {
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

    static interface SimplifiedDeque<T> extends SimplifiedStack<T> {
    }

    static class Randomized {
        static Random random = new Random();

        public static void randomizedArray(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }

    static class Array2DequeAdapter<T> implements SimplifiedDeque<T> {
        T[] data;
        int l;
        int r;

        public Array2DequeAdapter(T[] data) {
            this(data, 0, data.length - 1);
        }

        public Array2DequeAdapter(T[] data, int l, int r) {
            this.data = data;
            this.l = l;
            this.r = r;
        }

        public boolean isEmpty() {
            return l > r;
        }

        public T peekFirst() {
            return data[l];
        }

        public T removeFirst() {
            return data[l++];
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                int iter = l;


                public boolean hasNext() {
                    return iter <= r;
                }


                public T next() {
                    return data[iter++];
                }
            };
        }

    }

    static interface SimplifiedStack<T> extends Iterable<T> {
    }
}