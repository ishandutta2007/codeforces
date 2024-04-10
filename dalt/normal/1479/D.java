import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.Serializable;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        new TaskAdapter().run();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            DOddMineralResource solver = new DOddMineralResource();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DOddMineralResource {
        int[] a;
        long[] hash;
        List<UndirectedEdge>[] g;
        int lo;
        int hi;
        NoTagPersistentSegment[] st;
        int[] fa;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int q = in.ri();
            lo = 1;
            hi = n;
            a = new int[n];
            hash = new long[n + 1];
            fa = new int[n];
            st = new NoTagPersistentSegment[n];
            for (int i = 0; i <= n; i++) {
                hash[i] = RandomWrapper.INSTANCE.nextLong();
            }
            g = Graph.createGraph(n);
            for (int i = 0; i < n; i++) {
                a[i] = in.ri();
            }
            for (int i = 0; i < n - 1; i++) {
                int u = in.ri() - 1;
                int v = in.ri() - 1;
                Graph.addUndirectedEdge(g, u, v);
            }
            dfs(0, -1);
            LcaOnTree lca = new LcaOnTree(g, 0);
            for (int i = 0; i < q; i++) {
                int u = in.ri() - 1;
                int v = in.ri() - 1;
                int l = lca.lca(u, v);
                int L = in.ri();
                int R = in.ri();
                int ans = search(L, R, lo, hi, st[u], st[v], st[l], fa[l] == -1 ? NoTagPersistentSegment.NIL : st[fa[l]]);
                out.println(ans);
            }
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        int search(int ll, int rr, int l, int r, NoTagPersistentSegment a, NoTagPersistentSegment b, NoTagPersistentSegment c, NoTagPersistentSegment d) {
            if (noIntersection(ll, rr, l, r) || (a.xor ^ b.xor ^ c.xor ^ d.xor) == 0) {
                return -1;
            }
            if (l == r) {
                return l;
            }
            int m = DigitUtils.floorAverage(l, r);
            int ans = search(ll, rr, l, m, a.left, b.left, c.left, d.left);
            if (ans == -1) {
                ans = search(ll, rr, m + 1, r, a.right, b.right, c.right, d.right);
            }
            return ans;
        }

        void dfs(int root, int p) {
            fa[root] = p;
            st[root] = (p == -1 ? NoTagPersistentSegment.NIL : st[p]).clone();
            st[root].update(a[root], a[root], lo, hi, hash[a[root]]);
            for (DirectedEdge e : g[root]) {
                if (e.to == p) {
                    continue;
                }
                dfs(e.to, root);
            }
        }

    }

    static class RandomWrapper {
        private MersenneTwisterFast random;
        public static final RandomWrapper INSTANCE = new RandomWrapper();

        public RandomWrapper() {
            this(new MersenneTwisterFast());
        }

        public RandomWrapper(MersenneTwisterFast random) {
            this.random = random;
        }

        public RandomWrapper(long seed) {
            this(new MersenneTwisterFast(seed));
        }

        public long nextLong() {
            return random.nextLong();
        }

    }

    static class Graph {
        public static UndirectedEdge addUndirectedEdge(List<UndirectedEdge>[] g, int s, int t) {
            UndirectedEdge toT = new UndirectedEdge(t);
            UndirectedEdge toS = new UndirectedEdge(s);
            toT.rev = toS;
            toS.rev = toT;
            g[s].add(toT);
            g[t].add(toS);
            return toT;
        }

        public static List[] createGraph(int n) {
            return IntStream.range(0, n).mapToObj(i -> new ArrayList<>()).toArray(i -> new List[i]);
        }

    }

    static class Log2 {
        public static int floorLog(int x) {
            if (x <= 0) {
                throw new IllegalArgumentException();
            }
            return 31 - Integer.numberOfLeadingZeros(x);
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
        private static final int THRESHOLD = 1 << 13;
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

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
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

    static class NoTagPersistentSegment implements Cloneable {
        public static final NoTagPersistentSegment NIL = new NoTagPersistentSegment();
        NoTagPersistentSegment left;
        NoTagPersistentSegment right;
        long xor;

        static {
            NIL.left = NIL.right = NIL;
        }

        public void pushUp() {
            xor = left.xor ^ right.xor;
        }

        public NoTagPersistentSegment() {
            left = right = NIL;
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void update(int ll, int rr, int l, int r, long x) {
            if (covered(ll, rr, l, r)) {
                xor ^= x;
                return;
            }
            int m = DigitUtils.floorAverage(l, r);
            if (!noIntersection(ll, rr, l, m)) {
                left = left.clone();
                left.update(ll, rr, l, m, x);
            }
            if (!noIntersection(ll, rr, m + 1, r)) {
                right = right.clone();
                right.update(ll, rr, m + 1, r, x);
            }
            pushUp();
        }

        public NoTagPersistentSegment clone() {
            try {
                return (NoTagPersistentSegment) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

    }

    static class LcaOnTree {
        int[] parent;
        int[] preOrder;
        int[] i;
        int[] head;
        int[] a;
        int time;

        void dfs1(List<? extends DirectedEdge>[] tree, int u, int p) {
            parent[u] = p;
            i[u] = preOrder[u] = time++;
            for (DirectedEdge e : tree[u]) {
                int v = e.to;
                if (v == p) continue;
                dfs1(tree, v, u);
                if (Integer.lowestOneBit(i[u]) < Integer.lowestOneBit(i[v])) {
                    i[u] = i[v];
                }
            }
            head[i[u]] = u;
        }

        void dfs2(List<? extends DirectedEdge>[] tree, int u, int p, int up) {
            a[u] = up | Integer.lowestOneBit(i[u]);
            for (DirectedEdge e : tree[u]) {
                int v = e.to;
                if (v == p) continue;
                dfs2(tree, v, u, a[u]);
            }
        }

        public void init(List<? extends DirectedEdge>[] tree, int root) {
            time = 0;
            dfs1(tree, root, -1);
            dfs2(tree, root, -1, 0);
        }

        public LcaOnTree(int n) {
            preOrder = new int[n];
            i = new int[n];
            head = new int[n];
            a = new int[n];
            parent = new int[n];
        }

        public LcaOnTree(List<? extends DirectedEdge>[] tree, int root) {
            this(tree.length);
            init(tree, root);
        }

        private int enterIntoStrip(int x, int hz) {
            if (Integer.lowestOneBit(i[x]) == hz)
                return x;
            int hw = 1 << Log2.floorLog(a[x] & (hz - 1));
            return parent[head[i[x] & -hw | hw]];
        }

        public int lca(int x, int y) {
            int hb = i[x] == i[y] ? Integer.lowestOneBit(i[x]) : (1 << Log2.floorLog(i[x] ^ i[y]));
            int hz = Integer.lowestOneBit(a[x] & a[y] & -hb);
            int ex = enterIntoStrip(x, hz);
            int ey = enterIntoStrip(y, hz);
            return preOrder[ex] < preOrder[ey] ? ex : ey;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
        }

    }

    static class DirectedEdge {
        public int to;

        public DirectedEdge(int to) {
            this.to = to;
        }

        public String toString() {
            return "->" + to;
        }

    }

    static class UndirectedEdge extends DirectedEdge {
        public UndirectedEdge rev;

        public UndirectedEdge(int to) {
            super(to);
        }

        public String toString() {
            return String.format("%d<->%d", Math.min(rev.to, to), Math.max(rev.to, to));
        }

    }

    static strictfp class MersenneTwisterFast implements Serializable, Cloneable {
        private static final int N = 624;
        private static final int M = 397;
        private static final int MATRIX_A = 0x9908b0df;
        private static final int UPPER_MASK = 0x80000000;
        private static final int LOWER_MASK = 0x7fffffff;
        private static final int TEMPERING_MASK_B = 0x9d2c5680;
        private static final int TEMPERING_MASK_C = 0xefc60000;
        private int[] mt;
        private int mti;
        private int[] mag01;
        private boolean __haveNextNextGaussian;

        public Object clone() {
            try {
                MersenneTwisterFast f = (MersenneTwisterFast) (super.clone());
                f.mt = (int[]) (mt.clone());
                f.mag01 = (int[]) (mag01.clone());
                return f;
            } catch (CloneNotSupportedException e) {
                throw new InternalError();
            } // should never happen
        }

        public MersenneTwisterFast() {
            this(System.currentTimeMillis());
        }

        public MersenneTwisterFast(long seed) {
            setSeed(seed);
        }

        public MersenneTwisterFast(int[] array) {
            setSeed(array);
        }

        public void setSeed(long seed) {
            // Due to a bug in java.util.Random clear up to 1.2, we're
            // doing our own Gaussian variable.
            __haveNextNextGaussian = false;

            mt = new int[N];

            mag01 = new int[2];
            mag01[0] = 0x0;
            mag01[1] = MATRIX_A;

            mt[0] = (int) (seed & 0xffffffff);
            for (mti = 1; mti < N; mti++) {
                mt[mti] =
                        (1812433253 * (mt[mti - 1] ^ (mt[mti - 1] >>> 30)) + mti);
                /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
                /* In the previous versions, MSBs of the seed affect   */
                /* only MSBs of the array mt[].                        */
                /* 2002/01/09 modified by Makoto Matsumoto             */
                // mt[mti] &= 0xffffffff;
                /* for >32 bit machines */
            }
        }

        public void setSeed(int[] array) {
            if (array.length == 0)
                throw new IllegalArgumentException("Array length must be greater than zero");
            int i, j, k;
            setSeed(19650218);
            i = 1;
            j = 0;
            k = (N > array.length ? N : array.length);
            for (; k != 0; k--) {
                mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >>> 30)) * 1664525)) + array[j] + j; /* non linear */
                // mt[i] &= 0xffffffff; /* for WORDSIZE > 32 machines */
                i++;
                j++;
                if (i >= N) {
                    mt[0] = mt[N - 1];
                    i = 1;
                }
                if (j >= array.length) j = 0;
            }
            for (k = N - 1; k != 0; k--) {
                mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >>> 30)) * 1566083941)) - i; /* non linear */
                // mt[i] &= 0xffffffff; /* for WORDSIZE > 32 machines */
                i++;
                if (i >= N) {
                    mt[0] = mt[N - 1];
                    i = 1;
                }
            }
            mt[0] = 0x80000000; /* MSB is 1; assuring non-zero initial array */
        }

        public long nextLong() {
            int y;
            int z;

            if (mti >= N)   // generate N words at one time
            {
                int kk;
                final int[] mt = this.mt; // locals are slightly faster
                final int[] mag01 = this.mag01; // locals are slightly faster

                for (kk = 0; kk < N - M; kk++) {
                    y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
                    mt[kk] = mt[kk + M] ^ (y >>> 1) ^ mag01[y & 0x1];
                }
                for (; kk < N - 1; kk++) {
                    y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
                    mt[kk] = mt[kk + (M - N)] ^ (y >>> 1) ^ mag01[y & 0x1];
                }
                y = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
                mt[N - 1] = mt[M - 1] ^ (y >>> 1) ^ mag01[y & 0x1];

                mti = 0;
            }

            y = mt[mti++];
            y ^= y >>> 11;                          // TEMPERING_SHIFT_U(y)
            y ^= (y << 7) & TEMPERING_MASK_B;       // TEMPERING_SHIFT_S(y)
            y ^= (y << 15) & TEMPERING_MASK_C;      // TEMPERING_SHIFT_T(y)
            y ^= (y >>> 18);                        // TEMPERING_SHIFT_L(y)

            if (mti >= N)   // generate N words at one time
            {
                int kk;
                final int[] mt = this.mt; // locals are slightly faster
                final int[] mag01 = this.mag01; // locals are slightly faster

                for (kk = 0; kk < N - M; kk++) {
                    z = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
                    mt[kk] = mt[kk + M] ^ (z >>> 1) ^ mag01[z & 0x1];
                }
                for (; kk < N - 1; kk++) {
                    z = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
                    mt[kk] = mt[kk + (M - N)] ^ (z >>> 1) ^ mag01[z & 0x1];
                }
                z = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
                mt[N - 1] = mt[M - 1] ^ (z >>> 1) ^ mag01[z & 0x1];

                mti = 0;
            }

            z = mt[mti++];
            z ^= z >>> 11;                          // TEMPERING_SHIFT_U(z)
            z ^= (z << 7) & TEMPERING_MASK_B;       // TEMPERING_SHIFT_S(z)
            z ^= (z << 15) & TEMPERING_MASK_C;      // TEMPERING_SHIFT_T(z)
            z ^= (z >>> 18);                        // TEMPERING_SHIFT_L(z)

            return (((long) y) << 32) + (long) z;
        }

    }
}