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
            TaskE solver = new TaskE();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskE {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt();
            }
            int[] k = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                k[i] = in.readInt();
            }
            long[] b = new long[n];
            for (int i = 1; i < n; i++) {
                b[i] = b[i - 1] + k[i - 1];
            }
            PreSum psB = new PreSum(b);
            long[] aa = new long[n + 1];
            for (int i = 0; i < n; i++) {
                aa[i] = a[i] - b[i];
            }
            int q = in.readInt();
            Segment seg = new Segment(0, n, aa);
            seg.update(n, n, 0, n, (long) 1e18);
            for (int i = 0; i < q; i++) {
                char cmd = in.readChar();
                if (cmd == '+') {
                    int index = in.readInt() - 1;
                    int x = in.readInt();
                    long val = seg.query(index, index, 0, n) + x;
                    int until = seg.queryFloorIndex(val, 0, n);
                    seg.update(index, until, 0, n, val);
                } else {
                    int l = in.readInt() - 1;
                    int r = in.readInt() - 1;
                    long sum = seg.query(l, r, 0, n) +
                            psB.intervalSum(l, r);
                    out.println(sum);
                }
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

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

    }

    static class PreSum {
        private long[] pre;

        public PreSum(long[] a) {
            int n = a.length;
            pre = new long[n];
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a[i];
            }
        }

        public PreSum(int[] a) {
            int n = a.length;
            pre = new long[n];
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a[i];
            }
        }

        public long intervalSum(int l, int r) {
            if (l > r) {
                return 0;
            }
            if (l == 0) {
                return pre[r];
            }
            return pre[r] - pre[l - 1];
        }

    }

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        private long sum;
        private long dirtyVal;
        private int size;
        private boolean dirty;
        private long min;

        public void pushUp() {
            sum = left.sum + right.sum;
            size = left.size + right.size;
            min = Math.min(left.min, right.min);
        }

        public void set(long val) {
            dirtyVal = val;
            dirty = true;
            sum = dirtyVal * size;
            min = dirtyVal;
        }

        public void pushDown() {
            if (dirty) {
                left.set(dirtyVal);
                right.set(dirtyVal);
                dirty = false;
            }
        }

        public Segment(int l, int r, long[] vals) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m, vals);
                right = new Segment(m + 1, r, vals);
                pushUp();
            } else {
                size = 1;
                min = sum = vals[l];
            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void update(int ll, int rr, int l, int r, long x) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                set(x);
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.update(ll, rr, l, m, x);
            right.update(ll, rr, m + 1, r, x);
            pushUp();
        }

        public long query(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return 0;
            }
            if (covered(ll, rr, l, r)) {
                return sum;
            }
            pushDown();
            int m = (l + r) >> 1;
            return left.query(ll, rr, l, m) +
                    right.query(ll, rr, m + 1, r);
        }

        public int queryFloorIndex(long x, int l, int r) {
            Segment seg = this;
            while (l < r) {
                seg.pushDown();
                int m = (l + r) >>> 1;
                if (seg.right.min <= x) {
                    l = m + 1;
                    seg = seg.right;
                } else {
                    r = m;
                    seg = seg.left;
                }
            }
            return l;
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
}