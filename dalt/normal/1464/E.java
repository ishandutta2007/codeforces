import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
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
            ENoGameNoLife solver = new ENoGameNoLife();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ENoGameNoLife {
        int mod = 998244353;
        Power pow = new Power(mod);
        Debug debug = new Debug(true);
        IntegerVersionArray iva = new IntegerVersionArray((int) 1e5);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
            }
            for (int i = 0; i < m; i++) {
                Node a = nodes[in.ri() - 1];
                Node b = nodes[in.ri() - 1];
                a.adj.add(b);
            }
            int maxSg = 0;
            for (int i = 0; i < n; i++) {
                maxSg = Math.max(maxSg, sg(nodes[i]));
            }
            int ceilLog = 1;
            while (maxSg >= ceilLog) {
                ceilLog *= 2;
            }
            int[] prob = new int[ceilLog];
            int inv = pow.inverse(n + 1);
            for (int i = 0; i < n; i++) {
                prob[sg(nodes[i])] = DigitUtils.modplus(prob[sg(nodes[i])], inv, mod);
            }
            ModGussianElimination mge = new ModGussianElimination(ceilLog + 1, ceilLog + 1, mod);
            for (int i = 0; i < ceilLog + 1; i++) {
                mge.setLeft(i, i, 1);
            }
            for (int i = 0; i < ceilLog; i++) {
                for (int j = 0; j < ceilLog; j++) {
                    mge.modifyLeft(i ^ j, i, -prob[j]);
                }
                mge.modifyLeft(ceilLog, i, -inv);
            }
            mge.setRight(0, 1);
            debug.debug("mge", mge);
            boolean possible = mge.solve();
            assert possible;
            int[] ans = mge.getSolutions();
            long zeroProb = (long) ans[0] * inv % mod;
            long winProb = DigitUtils.mod(1 - zeroProb, mod);
            out.println(winProb);
        }

        public int sg(Node root) {
            if (root.sg == -1) {
                for (Node node : root.adj) {
                    sg(node);
                }
                iva.clear();
                for (Node node : root.adj) {
                    iva.set(sg(node), 1);
                }
                root.sg = 0;
                while (iva.get(root.sg) == 1) {
                    root.sg++;
                }
            }
            return root.sg;
        }

    }

    static interface IntToIntegerFunction {
        int apply(int x);

    }

    static class Node {
        List<Node> adj = new ArrayList<>();
        int sg = -1;

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

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(long c) {
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

    static class Modular {
        int m;

        public int getMod() {
            return m;
        }

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

        public String toString() {
            return "mod " + m;
        }

    }

    static class IntExtGCDObject {
        private int[] xy = new int[2];

        public int extgcd(int a, int b) {
            return ExtGCD.extGCD(a, b, xy);
        }

        public int getX() {
            return xy[0];
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

        public static int mod(int x, int mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return x;
        }

        public static int modplus(int a, int b, int mod) {
            int ans = a + b;
            if (ans >= mod) {
                ans -= mod;
            }
            return ans;
        }

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

    }

    static interface InverseNumber {
        int inverse(int x);

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

    static class ExtGCD {
        public static int extGCD(int a, int b, int[] xy) {
            if (a >= b) {
                return extGCD0(a, b, xy);
            }
            int ans = extGCD0(b, a, xy);
            SequenceUtils.swap(xy, 0, 1);
            return ans;
        }

        private static int extGCD0(int a, int b, int[] xy) {
            if (b == 0) {
                xy[0] = 1;
                xy[1] = 0;
                return a;
            }
            int ans = extGCD0(b, a % b, xy);
            int x = xy[0];
            int y = xy[1];
            xy[0] = y;
            xy[1] = x - a / b * y;
            return ans;
        }

    }

    static class Power implements InverseNumber {
        static IntExtGCDObject extGCD = new IntExtGCDObject();
        int mod;

        public Power(Modular modular) {
            this.mod = modular.getMod();
        }

        public Power(int mod) {
            this(new Modular(mod));
        }

        public int inverse(int x) {
            int ans = inverseExtGCD(x);
//        if(modular.mul(ans, x) != 1){
//            throw new IllegalStateException();
//        }
            return ans;
        }

        public int inverseExtGCD(int x) {
            if (extGCD.extgcd(x, mod) != 1) {
                throw new IllegalArgumentException();
            }
            return DigitUtils.mod(extGCD.getX(), mod);
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;
        static int[] empty = new int[0];

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
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

    static class ModGussianElimination {
        int[][] mat;
        int[] solutions;
        int rank;
        InverseNumber power;
        int mod;
        int n;
        int m;
        int start;

        public ModGussianElimination(int n, int m, int modular) {
            this.n = n;
            this.m = m;
            mat = new int[n + 1][m + 1];
            solutions = mat[n];
            this.mod = modular;
            power = new Power(modular);
        }

        public void setRight(int row, int val) {
            mat[row][m] = DigitUtils.mod(val, mod);
        }

        public void setLeft(int row, int col, int val) {
            mat[row][col] = DigitUtils.mod(val, mod);
        }

        public void modifyLeft(int row, int col, int val) {
            mat[row][col] = DigitUtils.mod(mat[row][col] + val, mod);
        }

        public int[] getSolutions() {
            return solutions;
        }

        public boolean solve() {
            int now = 0;
            for (int i = 0; i < m; i++) {
                start = i;
                int maxRow = now;
                for (int j = now; j < n; j++) {
                    if (mat[j][i] != 0) {
                        maxRow = j;
                        break;
                    }
                }

                if (mat[maxRow][i] == 0) {
                    continue;
                }
                swapRow(now, maxRow);
                divideRow(now, mat[now][i]);
                for (int j = now + 1; j < n; j++) {
                    if (mat[j][i] == 0) {
                        continue;
                    }
                    int f = mat[j][i];
                    subtractRow(j, now, f);
                }

                now++;
            }

            rank = now;
            for (int i = now; i < n; i++) {
                if (mat[i][m] != 0) {
                    return false;
                }
            }

            for (int i = now - 1; i >= 0; i--) {
                int x = -1;
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] != 0) {
                        x = j;
                        break;
                    }
                }
                mat[n][x] = (int) ((long) mat[i][m] * power.inverse(mat[i][x]) % mod);
                for (int j = i - 1; j >= 0; j--) {
                    if (mat[j][x] == 0) {
                        continue;
                    }
                    mat[j][m] = DigitUtils.mod(mat[j][m] - (long) mat[j][x] * mat[n][x], mod);
                    mat[j][x] = 0;
                }
            }
            return true;
        }

        void swapRow(int i, int j) {
            int[] row = mat[i];
            mat[i] = mat[j];
            mat[j] = row;
        }

        void subtractRow(int i, int j, int f) {
            for (int k = start; k <= m; k++) {
                mat[i][k] = DigitUtils.mod(mat[i][k] - (long) mat[j][k] * f, mod);
            }
        }

        void divideRow(int i, int f) {
            int divisor = power.inverse(f);
            for (int k = start; k <= m; k++) {
                mat[i][k] = (int) ((long) mat[i][k] * divisor % mod);
            }
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < n; i++) {
                StringBuilder row = new StringBuilder();
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == 0) {
                        continue;
                    }
                    if (mat[i][j] != 1) {
                        row.append(mat[i][j]);
                    }
                    row.append("x").append(j).append('+');
                }
                if (row.length() > 0) {
                    row.setLength(row.length() - 1);
                } else {
                    row.append(0);
                }
                row.append("=").append(mat[i][m]);
                builder.append(row).append('\n');
            }
            return builder.toString();
        }

    }

    static class IntegerVersionArray {
        int[] data;
        int[] version;
        int now;
        IntToIntegerFunction def;

        public IntegerVersionArray(int cap) {
            this(cap, i -> 0);
        }

        public IntegerVersionArray(int cap, IntToIntegerFunction def) {
            data = new int[cap];
            version = new int[cap];
            now = 0;
            this.def = def;
        }

        public void clear() {
            now++;
        }

        public void visit(int i) {
            if (version[i] < now) {
                version[i] = now;
                data[i] = def.apply(i);
            }
        }

        public void set(int i, int v) {
            version[i] = now;
            data[i] = v;
        }

        public int get(int i) {
            visit(i);
            return data[i];
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < data.length; i++) {
                if (version[i] < now) {
                    continue;
                }
                builder.append(i).append(':').append(data[i]).append(',');
            }
            if (builder.length() > 0) {
                builder.setLength(builder.length() - 1);
            }
            return builder.toString();
        }

    }
}