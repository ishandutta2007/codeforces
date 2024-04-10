import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
 * 
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
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
        NumberTheory.Modular mod = new NumberTheory.Modular(998244353);
        NumberTheory.Factorial fact = new NumberTheory.Factorial(10000, mod);
        NumberTheory.Composite comp = new NumberTheory.Composite(fact);
        boolean[] rows;
        boolean[] cols;
        int[][] rowPutWays;
        int[][] colPutWays;
        int h;
        int w;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            h = in.readInt();
            w = in.readInt();

            rows = new boolean[h + 1];
            cols = new boolean[w + 1];

            int rowCnt = 0;
            int colCnt = 0;

            int n = in.readInt();
            for (int i = 0; i < n; i++) {
                int x1 = in.readInt();
                int y1 = in.readInt();
                int x2 = in.readInt();
                int y2 = in.readInt();
                rows[x1] = rows[x2] = true;
                cols[y1] = cols[y2] = true;
            }

            for (int i = 1; i <= h; i++) {
                if (rows[i]) {
                    continue;
                }
                rowCnt++;
            }

            for (int i = 1; i <= w; i++) {
                if (cols[i]) {
                    continue;
                }
                colCnt++;
            }

            rowPutWays = new int[h + 1][h / 2 + 1];
            colPutWays = new int[w + 1][w / 2 + 1];

            ArrayUtils.deepFill(rowPutWays, -1);
            ArrayUtils.deepFill(colPutWays, -1);


            int ans = 0;
            for (int i = 0; i <= h / 2; i++) {
                for (int j = 0; j <= w / 2; j++) {
                    // check
                    if (i * 2 + j > rowCnt || j * 2 + i > colCnt) {
                        continue;
                    }
                    int rWay = rowPutWays(h, i);
                    int cWay = colPutWays(w, j);
                    int way = mod.mul(rWay, cWay);
                    way = mod.mul(way, comp.composite(rowCnt - i * 2, j));
                    way = mod.mul(way, comp.composite(colCnt - j * 2, i));
                    way = mod.mul(way, fact.fact(j));
                    way = mod.mul(way, fact.fact(i));
                    ans = mod.plus(ans, way);
                }
            }

            out.println(ans);
        }

        public int rowPutWays(int i, int j) {
            if (j < 0) {
                return 0;
            }
            if (i <= 0) {
                return j == 0 ? 1 : 0;
            }
            if (rowPutWays[i][j] == -1) {
                if (rows[i]) {
                    rowPutWays[i][j] = rowPutWays(i - 1, j);
                } else {
                    rowPutWays[i][j] = rowPutWays(i - 1, j);
                    if (i > 1 && !rows[i - 1]) {
                        rowPutWays[i][j] = mod.plus(rowPutWays[i][j], rowPutWays(i - 2, j - 1));
                    }
                }
            }
            return rowPutWays[i][j];
        }

        public int colPutWays(int i, int j) {
            if (j < 0) {
                return 0;
            }
            if (i <= 0) {
                return j == 0 ? 1 : 0;
            }
            if (colPutWays[i][j] == -1) {
                if (cols[i]) {
                    colPutWays[i][j] = colPutWays(i - 1, j);
                } else {
                    colPutWays[i][j] = colPutWays(i - 1, j);
                    if (i > 1 && !cols[i - 1]) {
                        colPutWays[i][j] = mod.plus(colPutWays[i][j], colPutWays(i - 2, j - 1));
                    }
                }
            }
            return colPutWays[i][j];
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
                    throw new RuntimeException(e);
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
        private StringBuilder cache = new StringBuilder(1 << 20);
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

    }
    static class ArrayUtils {
        public static void deepFill(Object array, int val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof int[]) {
                int[] intArray = (int[]) array;
                Arrays.fill(intArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
            }
        }

    }
    static class NumberTheory {
        public static class Modular {
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

            public String toString() {
                return "mod " + m;
            }

        }

        public static class InverseNumber {
            int[] inv;

            public InverseNumber(int[] inv, int limit, NumberTheory.Modular modular) {
                this.inv = inv;
                inv[1] = 1;
                int p = modular.m;
                for (int i = 2; i <= limit; i++) {
                    int k = p / i;
                    int r = p % i;
                    inv[i] = modular.mul(-k, inv[r]);
                }
            }

            public InverseNumber(int limit, NumberTheory.Modular modular) {
                this(new int[limit + 1], limit, modular);
            }

        }

        public static class Factorial {
            int[] fact;
            int[] inv;
            NumberTheory.Modular modular;

            public Factorial(int[] fact, int[] inv, NumberTheory.InverseNumber in, int limit,
                            NumberTheory.Modular modular) {
                this.modular = modular;
                this.fact = fact;
                this.inv = inv;
                fact[0] = inv[0] = 1;
                for (int i = 1; i <= limit; i++) {
                    fact[i] = modular.mul(fact[i - 1], i);
                    inv[i] = modular.mul(inv[i - 1], in.inv[i]);
                }
            }

            public Factorial(int limit, NumberTheory.Modular modular) {
                this(new int[limit + 1], new int[limit + 1], new NumberTheory.InverseNumber(limit, modular), limit,
                                modular);
            }

            public int fact(int n) {
                return fact[n];
            }

        }

        public static class Composite {
            final NumberTheory.Factorial factorial;
            final NumberTheory.Modular modular;

            public Composite(NumberTheory.Factorial factorial) {
                this.factorial = factorial;
                this.modular = factorial.modular;
            }

            public Composite(int limit, NumberTheory.Modular modular) {
                this(new NumberTheory.Factorial(limit, modular));
            }

            public int composite(int m, int n) {
                if (n > m) {
                    return 0;
                }
                return modular.mul(modular.mul(factorial.fact[m], factorial.inv[n]), factorial.inv[m - n]);
            }

        }

    }
}