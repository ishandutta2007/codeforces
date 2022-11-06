import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.TreeMap;
import java.util.Map;
import java.io.Closeable;
import java.util.Map.Entry;
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
            CBeautifulMirrorsWithQueries solver = new CBeautifulMirrorsWithQueries();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CBeautifulMirrorsWithQueries {
        Modular mod = new Modular(998244353);
        Power pow = new Power(mod);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int q = in.readInt();

            int[] prob = new int[n];
            int inv100 = pow.inverse(100);
            for (int i = 0; i < n; i++) {
                prob[i] = mod.mul(in.readInt(), inv100);
            }
            Transform[] transforms = new Transform[n];
            for (int i = 0; i < n; i++) {
                transforms[i] = new Transform();
                transforms[i].a = 1;
                transforms[i].b = mod.valueOf(1 - prob[i]);
            }

            CatTree<Transform, Transform> catTree = new CatTree<>(transforms, n,
                    new CatTree.SetHandler<Transform, Transform>() {

                        public Transform insertLeft(Transform element, Transform set) {
                            return mergeSet(element, set);
                        }


                        public Transform insertRight(Transform set, Transform element) {
                            return mergeSet(set, element);
                        }


                        public Transform makeSet(Transform element) {
                            return element;
                        }


                        public Transform mergeSet(Transform a, Transform b) {
                            return merge(a, b);
                        }
                    });

            //expect(transforms[0]);
            TreeMap<Integer, Integer> map = new TreeMap<>();
            Transform whole = catTree.query(0, n - 1);
            int total = expect(whole);
            map.put(0, total);
            map.put(n, 0);
            for (int i = 0; i < q; i++) {
                Integer u = in.readInt() - 1;
                if (map.containsKey(u)) {
                    total = mod.subtract(total, map.remove(u));
                    Map.Entry<Integer, Integer> floor = map.floorEntry(u);
                    Integer ceilKey = map.ceilingKey(u);
                    total = mod.subtract(total, floor.getValue());
                    Transform t = catTree.query(floor.getKey(), ceilKey - 1);
                    int exp = expect(t);
                    total = mod.plus(total, exp);
                    map.put(floor.getKey(), exp);
                } else {
                    Map.Entry<Integer, Integer> floor = map.floorEntry(u);
                    total = mod.subtract(total, floor.getValue());
                    Transform left = catTree.query(floor.getKey(), u - 1);
                    int leftExp = expect(left);
                    total = mod.plus(total, leftExp);
                    map.put(floor.getKey(), leftExp);

                    Integer ceil = map.ceilingKey(u);
                    Transform t = catTree.query(u, ceil - 1);
                    int exp = expect(t);
                    total = mod.plus(total, exp);
                    map.put(u, exp);
                }

                out.println(total);
            }
        }

        public int expect(Transform t) {
            return mod.mul(t.a, pow.inverse(1 - t.b));
        }

        public Transform merge(Transform a, Transform b) {
            Transform t = new Transform();
            t.a = mod.plus(a.a, mod.mul(b.a, 1 - a.b));
            t.b = mod.plus(a.b, mod.mul(b.b, 1 - a.b));
            return t;
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

    static class CachedLog2 {
        private static final int BITS = 16;
        private static final int LIMIT = 1 << BITS;
        private static final int[] CACHE = new int[LIMIT];

        static {
            int b = 0;
            for (int i = 0; i < LIMIT; i++) {
                while ((1 << (b + 1)) <= i) {
                    b++;
                }
                CACHE[i] = b;
            }
        }

        public static int ceilLog(int x) {
            int ans = floorLog(x);
            if ((1 << ans) < x) {
                ans++;
            }
            return ans;
        }

        public static int floorLog(int x) {
            return x < LIMIT ? CACHE[x] : (BITS + CACHE[x >>> BITS]);
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

    static class Bits {
        private Bits() {
        }

        public static int theFirstDifferentBit(int x, int y) {
            return CachedLog2.floorLog(x ^ y);
        }

    }

    static class CatTree<S, E> {
        Object[][] levels;
        private CatTree.SetHandler<S, E> handler;

        public CatTree(E[] data, int len, CatTree.SetHandler<S, E> handler) {
            this.handler = handler;
            int level = CachedLog2.ceilLog(len) + 1;
            levels = new Object[level][len];
            for (int i = 0; i < len; i++) {
                levels[0][i] = handler.makeSet(data[i]);
            }
            build(data, len, level - 1);
        }

        public S query(int l, int r) {
            if (l == r) {
                return (S) levels[0][l];
            }
            int level = Bits.theFirstDifferentBit(l, r) + 1;
            return handler.mergeSet((S) levels[level][l], (S) levels[level][r]);
        }

        private void build(E[] data, int len, int level) {
            if (level <= 0) {
                return;
            }
            build(data, len, level - 1);

            int bit = level - 1;
            int mask = (1 << bit) - 1;
            int step = 1 << level;

            for (int i = mask; i < len; i += step) {
                levels[level][i] = levels[0][i];
                for (int j = i - 1; (j & mask) != mask; j--) {
                    levels[level][j] = handler.insertLeft(data[j], (S) levels[level][j + 1]);
                }
                if (i + 1 >= len) {
                    continue;
                }
                levels[level][i + 1] = levels[0][i + 1];
                for (int j = i + 2; j < len && (j & mask) != 0; j++) {
                    levels[level][j] = handler.insertRight((S) levels[level][j - 1], data[j]);
                }
            }
        }

        public static interface SetHandler<S, E> {
            S insertLeft(E element, S set);

            S insertRight(S set, E element);

            S makeSet(E element);

            S mergeSet(S a, S b);

        }

    }

    static class Transform {
        int a;
        int b;

        public String toString() {
            return String.format("a = %d, b = %d", a, b);
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

    static class Power {
        final Modular modular;

        public Power(Modular modular) {
            this.modular = modular;
        }

        public int pow(int x, int n) {
            if (n == 0) {
                return modular.valueOf(1);
            }
            long r = pow(x, n >> 1);
            r = modular.valueOf(r * r);
            if ((n & 1) == 1) {
                r = modular.valueOf(r * x);
            }
            return (int) r;
        }

        public int inverse(int x) {
            return pow(x, modular.m - 2);
        }

    }
}