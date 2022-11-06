import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.function.IntUnaryOperator;
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
            FPuttingBoxesTogether solver = new FPuttingBoxesTogether();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FPuttingBoxesTogether {
        Modular mod = new Modular(1e9 + 7);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int q = in.readInt();
            int[] as = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                as[i] = in.readInt();
            }

            int[] ws = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                ws[i] = in.readInt();
            }
            ModBIT bit = new ModBIT(n, mod);
            ModBIT indexBIT = new ModBIT(n, mod);
            Segment segment = new Segment(1, n, i -> ws[i]);
            for (int i = 1; i <= n; i++) {
                bit.update(i, mod.mul(as[i], ws[i]));
                indexBIT.update(i, mod.mul(i, ws[i]));
            }

            for (int i = 0; i < q; i++) {
                int x = in.readInt();
                int y = in.readInt();
                if (x < 0) {
                    int id = -x;
                    int nw = y;
                    segment.update(id, id, 1, n, nw);
                    bit.update(id, -bit.interval(id, id));
                    bit.update(id, mod.mul(nw, as[id]));
                    indexBIT.update(id, -indexBIT.interval(id, id));
                    indexBIT.update(id, mod.mul(nw, id));
                } else {
                    int l = x;
                    int r = y;
                    long leftWeight = segment.query(1, l - 1, 1, n);
                    long wholeWeight = segment.query(l, r, 1, n);
                    int center = segment.binarySearch(1, n, leftWeight + (wholeWeight + 1) / 2);

                    int leftSum = mod.valueOf(segment.query(l, center - 1, 1, n));
                    int rightSum = mod.valueOf(segment.query(center + 1, r, 1, n));
                    int leftContrib1 = mod.subtract(mod.mul(as[center], leftSum),
                            bit.interval(l, center - 1));
                    int rightContrib1 = mod.subtract(bit.interval(center + 1, r),
                            mod.mul(as[center], rightSum));
                    int leftContrib2 = mod.subtract(indexBIT.interval(l, center - 1),
                            mod.mul(center, leftSum));
                    int rightContrib2 = mod.subtract(mod.mul(center, rightSum),
                            indexBIT.interval(center + 1, r));

                    int ans = mod.plus(leftContrib1, rightContrib1);
                    ans = mod.plus(ans, leftContrib2);
                    ans = mod.plus(ans, rightContrib2);
                    out.println(ans);
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

    }

    static class Modular {
        int m;

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public int valueOf(int x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return x;
        }

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public int subtract(int x, int y) {
            return valueOf(x - y);
        }

        public String toString() {
            return "mod " + m;
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

        public FastOutput println(int c) {
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

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        private long sum;

        private void setSum(long x) {
            sum = x;
        }

        public void pushUp() {
            sum = left.sum + right.sum;
        }

        public void pushDown() {
        }

        public Segment(int l, int r, IntUnaryOperator operator) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m, operator);
                right = new Segment(m + 1, r, operator);
                pushUp();
            } else {
                sum = operator.applyAsInt(l);
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
                setSum(x);
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

        public int binarySearch(int l, int r, long limit) {
            if (l == r) {
                return l;
            }
            pushDown();
            int m = (l + r) >> 1;
            if (left.sum >= limit) {
                return left.binarySearch(l, m, limit);
            }
            return right.binarySearch(m + 1, r, limit - left.sum);
        }

    }

    static class ModBIT {
        private int[] data;
        private int n;
        private Modular modular;

        public ModBIT(int n, Modular mod) {
            this.n = n;
            data = new int[n + 1];
            this.modular = mod;
        }

        public int query(int i) {
            long sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += data[i];
            }
            return modular.valueOf(sum);
        }

        public void update(int i, int mod) {
            if (i <= 0) {
                return;
            }
            for (; i <= n; i += i & -i) {
                data[i] = modular.plus(data[i], mod);
            }
        }

        public int interval(int l, int r) {
            int sum = query(r);
            if (l > 1) {
                sum = modular.subtract(sum, query(l - 1));
            }
            return sum;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 1; i <= n; i++) {
                builder.append(query(i) - query(i - 1)).append(' ');
            }
            return builder.toString();
        }

    }
}