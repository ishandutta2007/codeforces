import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Arrays;
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
            BTreeArray solver = new BTreeArray();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class BTreeArray {
        int mod = (int) 1e9 + 7;
        InverseNumber inv = new ModPrimeInverseNumber((int) 2000, mod);
        long[][] f;
        int[][] g;
        int[] p;
        int[] depth;
        long[][] probs;
        IntegerArrayList collector;
        Debug debug = new Debug(false);

        public long f(int a, int b) {
            if (f[a][b] == -1) {
                if (a == 0) {
                    return f[a][b] = 1;
                } else if (b == 0) {
                    return f[a][b] = 0;
                }
                f[a][b] = (long) inv.inverse(2) * (f(a - 1, b) + f(a, b - 1)) % mod;
            }
            return f[a][b];
        }

        public void consider(int a, int b, int lca) {
            if (a < b) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            probs[a][b] += f(depth[a] - depth[lca], depth[b] - depth[lca]);
        }

        public void dfsForContrib(int root, int p) {
            collector.add(root);
            for (int node : g[root]) {
                if (node == p) {
                    continue;
                }
                calc(node, root, root);
                collect(node, root);
            }
            collector.clear();
            for (int node : g[root]) {
                if (node == p) {
                    continue;
                }
                dfsForContrib(node, root);
            }
        }

        public void collect(int root, int p) {
            for (int node : g[root]) {
                if (node == p) {
                    continue;
                }
                collect(node, root);
            }
            collector.add(root);
        }

        public void calc(int root, int p, int lca) {
            for (int node : g[root]) {
                if (node == p) {
                    continue;
                }
                calc(node, root, lca);
            }
            for (int i = 0; i < collector.size(); i++) {
                int node = collector.get(i);
                consider(node, root, lca);
            }
        }

        public void dfsForP(int root, int p) {
            this.p[root] = p;
            depth[root] = p == -1 ? 0 : depth[p] + 1;
            for (int node : g[root]) {
                if (node == p) {
                    continue;
                }
                dfsForP(node, root);
            }
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            IntegerArrayList us = new IntegerArrayList(n - 1);
            IntegerArrayList vs = new IntegerArrayList(n - 1);
            for (int i = 0; i < n - 1; i++) {
                us.add(in.ri() - 1);
                vs.add(in.ri() - 1);
            }
            f = new long[n + 1][n + 1];
            SequenceUtils.deepFill(f, -1L);
            g = Graph.createUndirectedGraph(n, n - 1, us.toArray(), vs.toArray());
            probs = new long[n][n];
            depth = new int[n];
            collector = new IntegerArrayList(n);
            for (int i = 0; i < n; i++) {
                p = new int[n];
                dfsForP(i, -1);
                dfsForContrib(i, -1);
            }
            long exp = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    exp += probs[i][j] % mod;
                }
            }
            debug.debug("2/5", (long) 2 * inv.inverse(5) % mod);
            debug.debug("2/5", (long) 1500000013L % mod);
            debug.debug("probs", probs);
            exp = exp % mod * inv.inverse(n);
            exp = DigitUtils.mod(exp, mod);
            out.println(exp);
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
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
        }

    }

    static class SequenceUtils {
        public static void deepFill(Object array, long val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof long[]) {
                long[] longArray = (long[]) array;
                Arrays.fill(longArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
            }
        }

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

    static class Graph {
        public static int[][] createUndirectedGraph(int n, int m, int[] u, int[] v) {
            int[] degs = new int[n];
            for (int i = 0; i < m; i++) {
                degs[u[i]]++;
                degs[v[i]]++;
            }
            int[][] g = new int[n][];
            for (int i = 0; i < n; i++) {
                g[i] = new int[degs[i]];
            }
            for (int i = 0; i < m; i++) {
                int a = u[i];
                int b = v[i];
                g[a][--degs[a]] = b;
                g[b][--degs[b]] = a;
            }
            return g;
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;
        static int[] empty = new int[0];

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debug(String name, long x) {
            if (offline) {
                debug(name, "" + x);
            }
            return this;
        }

        public Debug debug(String name, String x) {
            if (offline) {
                out.printf("%s=%s", name, x);
                out.println();
            }
            return this;
        }

        public Debug debug(String name, Object x) {
            return debug(name, x, empty);
        }

        public Debug debug(String name, Object x, int... indexes) {
            if (offline) {
                if (x == null || !x.getClass().isArray()) {
                    out.append(name);
                    for (int i : indexes) {
                        out.printf("[%d]", i);
                    }
                    out.append("=").append("" + x);
                    out.println();
                } else {
                    indexes = Arrays.copyOf(indexes, indexes.length + 1);
                    if (x instanceof byte[]) {
                        byte[] arr = (byte[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof short[]) {
                        short[] arr = (short[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof boolean[]) {
                        boolean[] arr = (boolean[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof char[]) {
                        char[] arr = (char[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof int[]) {
                        int[] arr = (int[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof float[]) {
                        float[] arr = (float[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof double[]) {
                        double[] arr = (double[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof long[]) {
                        long[] arr = (long[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else {
                        Object[] arr = (Object[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    }
                }
            }
            return this;
        }

    }

    static interface InverseNumber {
        int inverse(int x);

    }

    static class IntegerArrayList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerArrayList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerArrayList(int[] data) {
            this(0);
            addAll(data);
        }

        public IntegerArrayList(IntegerArrayList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerArrayList() {
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

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException("Access [" + i + "]");
            }
        }

        public int get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerArrayList list) {
            addAll(list.data, 0, list.size);
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerArrayList)) {
                return false;
            }
            IntegerArrayList other = (IntegerArrayList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerArrayList clone() {
            IntegerArrayList ans = new IntegerArrayList();
            ans.addAll(this);
            return ans;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int mod(long x, int mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return (int) x;
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

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(long c) {
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

    static class ModPrimeInverseNumber implements InverseNumber {
        int[] inv;

        public ModPrimeInverseNumber(int[] inv, int limit, int mod) {
            this.inv = inv;
            if (inv.length > 1) {
                inv[1] = 1;
            }
            int p = mod;
            for (int i = 2; i <= limit; i++) {
                int k = p / i;
                int r = p - k * i;
                inv[i] = DigitUtils.mod((long) -k * inv[r], mod);
            }
        }

        public ModPrimeInverseNumber(int limit, int mod) {
            this(new int[limit + 1], limit, mod);
        }

        public int inverse(int x) {
            return inv[x];
        }

    }
}