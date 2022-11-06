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
            TaskF solver = new TaskF();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskF {
        Segment seg;
        MinMaxSegment valSeg;
        int n;
        int[] valToIndex;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();

            if (n == 1) {
                out.append("1 0");
                return;
            }
            int[] perm = new int[1 + n * 2];
            valToIndex = new int[1 + n];
            for (int i = 1; i <= n; i++) {
                perm[i + n] = perm[i] = in.readInt();
                valToIndex[perm[i]] = i;
            }

            seg = new Segment(1, 2 * n);
            valSeg = new MinMaxSegment(1, n, perm);
            buildTree(1, n);
            Recoder recoder = new Recoder();
            recoder.record(seg.query(1, n, 1, 2 * n), 0);

            int[] rightIndex = new int[2 * n + 1];
            IntDeque deque = new IntDeque(2 * n);
            for (int i = 2 * n; i >= 1; i--) {
                while (!deque.isEmpty() && perm[deque.peekFirst()] >= perm[i]) {
                    deque.removeFirst();
                }
                if (deque.isEmpty()) {
                    rightIndex[i] = 2 * n + 1;
                } else {
                    rightIndex[i] = deque.peekFirst();
                }
                deque.addFirst(i);
            }

            IntDeque rightSide = new IntDeque(2 * n);
            for (int i = 1; i <= n; i++) {
                while (!rightSide.isEmpty() && perm[rightSide.peekLast()] >= perm[i]) {
                    rightSide.removeLast();
                }
                rightSide.addLast(i);
            }

            for (int i = 1; i <= n; i++) {
                int r = rightIndex[i];
                if (rightSide.peekFirst() == i) {
                    rightSide.removeFirst();
                    seg.update(i + 1, n - 1 + i, 1, 2 * n, -1);
                } else {
                    seg.update(i + 1, r - 1, 1, 2 * n, -1);
                }

                while (!rightSide.isEmpty() && perm[rightSide.peekLast()] >= perm[i]) {
                    rightSide.removeLast();
                }
                if (rightSide.isEmpty()) {
                    seg.update(i + 1, n - 1 + i, 1, 2 * n, 1);
                    //seg.update(i + n, i + n, 1 , 2 * n, 0);
                } else {
                    seg.update(rightSide.peekLast() + 1, n - 1 + i, 1, 2 * n, 1);
                    int fatherDepth = seg.query(rightSide.peekLast(), rightSide.peekLast(), 1, 2 * n);
                    seg.update(i + n, i + n, 1, 2 * n, fatherDepth + 1);
                }
                rightSide.addLast(i + n);
                recoder.record(seg.query(i + 1, i + n, 1, 2 * n), i);
            }

            out.append(recoder.height + 1).append(' ').append(recoder.offset);
        }

        public void buildTree(int l, int r) {
            int minVal = valSeg.query(l, r, 1, n);
            int m = valToIndex[minVal];
            if (l < m) {
                buildTree(l, m - 1);
                seg.update(l, m - 1, 1, 2 * n, 1);
            }
            if (r > m) {
                buildTree(m + 1, r);
                seg.update(m + 1, r, 1, 2 * n, 1);
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
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

    static class IntDeque {
        int[] data;
        int bpos;
        int epos;
        int cap;

        public IntDeque(int cap) {
            this.cap = cap + 1;
            this.data = new int[this.cap];
        }

        public boolean isEmpty() {
            return epos == bpos;
        }

        public int peekFirst() {
            return data[bpos];
        }

        private int last(int i) {
            return (i == 0 ? cap : i) - 1;
        }

        private int next(int i) {
            int n = i + 1;
            return n == cap ? 0 : n;
        }

        public int peekLast() {
            return data[last(epos)];
        }

        public int removeFirst() {
            int t = bpos;
            bpos = next(bpos);
            return data[t];
        }

        public int removeLast() {
            return data[epos = last(epos)];
        }

        public void addLast(int val) {
            data[epos] = val;
            epos = next(epos);
        }

        public void addFirst(int val) {
            data[bpos = last(bpos)] = val;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = bpos; i != epos; i = next(i)) {
                builder.append(data[i]).append(' ');
            }
            return builder.toString();
        }

    }

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        private int height;
        private int mod;

        public void mod(int x) {
            mod += x;
            height += x;
        }

        public void pushUp() {
            height = Math.max(left.height, right.height);
        }

        public void pushDown() {
            if (mod != 0) {
                left.mod(mod);
                right.mod(mod);
                mod = 0;
            }
        }

        public Segment(int l, int r) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m);
                right = new Segment(m + 1, r);
                pushUp();
            } else {

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

        public int query(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return 0;
            }
            if (covered(ll, rr, l, r)) {
                return height;
            }
            pushDown();
            int m = (l + r) >> 1;
            return Math.max(left.query(ll, rr, l, m),
                    right.query(ll, rr, m + 1, r));
        }

    }

    static class Recoder {
        int height = Integer.MAX_VALUE;
        int offset = -1;

        public void record(int h, int o) {
            if (h < height) {
                height = h;
                offset = o;
            }
        }

        public String toString() {
            return offset + "=" + height;
        }

    }

    static class MinMaxSegment implements Cloneable {
        private MinMaxSegment left;
        private MinMaxSegment right;
        private int val;

        public void pushUp() {
            val = Math.min(left.val, right.val);
        }

        public void pushDown() {
        }

        public MinMaxSegment(int l, int r, int[] p) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new MinMaxSegment(l, m, p);
                right = new MinMaxSegment(m + 1, r, p);
                pushUp();
            } else {
                val = p[l];
            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public int query(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return Integer.MAX_VALUE;
            }
            if (covered(ll, rr, l, r)) {
                return val;
            }
            pushDown();
            int m = (l + r) >> 1;
            return Math.min(left.query(ll, rr, l, m),
                    right.query(ll, rr, m + 1, r));
        }

    }
}