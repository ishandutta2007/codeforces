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
            TaskC solver = new TaskC();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskC {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int limit = (int) 1e6;
            int[] scores = new int[limit + 1];
            int[] aCnt = new int[limit + 1];
            int[] bCnt = new int[limit + 1];
            int[] a = new int[n + 1];
            int[] b = new int[m + 1];


            for (int i = 1; i <= n; i++) {
                a[i] = in.readInt();
                aCnt[a[i]]++;
            }
            for (int i = 1; i <= m; i++) {
                b[i] = in.readInt();
                bCnt[b[i]]++;
            }

            scores[limit] = aCnt[limit] - bCnt[limit];
            for (int i = limit - 1; i >= 1; i--) {
                scores[i] = scores[i + 1] + aCnt[i] - bCnt[i];
            }

            Segment seg = new Segment(1, limit, scores);

            int q = in.readInt();
            for (int i = 0; i < q; i++) {
                int t = in.readInt();
                int which = in.readInt();
                int x = in.readInt();
                if (t == 1) {
                    seg.update(1, a[which], 1, limit, -1);
                    a[which] = x;
                    seg.update(1, a[which], 1, limit, 1);
                } else {
                    seg.update(1, b[which], 1, limit, 1);
                    b[which] = x;
                    seg.update(1, b[which], 1, limit, -1);
                }

                int ans = seg.query(1, limit);
                out.println(ans);
            }
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

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        private int score;
        private int mod;

        public void mod(int x) {
            mod += x;
            score += x;
        }

        public void pushUp() {
            score = Math.max(left.score, right.score);
        }

        public void pushDown() {
            if (mod != 0) {
                left.mod(mod);
                right.mod(mod);
                mod = 0;
            }
        }

        public Segment(int l, int r, int[] scores) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m, scores);
                right = new Segment(m + 1, r, scores);
                pushUp();
            } else {
                score = scores[l];
            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void update(int ll, int rr, int l, int r, int x) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                mod(x);
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.update(ll, rr, l, m, x);
            right.update(ll, rr, m + 1, r, x);
            pushUp();
        }

        public int query(int l, int r) {
            Segment seg = this;
            while (l < r) {
                seg.pushDown();
                int m = (l + r) >> 1;
                if (seg.right.score > 0) {
                    l = m + 1;
                    seg = seg.right;
                } else {
                    r = m;
                    seg = seg.left;
                }
            }
            if (seg.score > 0) {
                return l;
            }
            return -1;
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
}