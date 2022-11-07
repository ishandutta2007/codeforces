import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.math.BigDecimal;
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
            FShrinkingTree solver = new FShrinkingTree();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FShrinkingTree {
        List<UndirectedEdge>[] g;
        double[][] dp;
        double[][] f;
        double[][] comp;
        int[] size;
        double[] fact;
        int n;

        public double comp(int n, int m) {
            if (n < 0 || m < 0) {
                return 0;
            }
            if (comp[n][m] == -1) {
                if (n < m) {
                    return comp[n][m] = 0;
                }
                if (m == 0) {
                    return comp[n][m] = 1;
                }
                comp[n][m] = comp(n - 1, m - 1) * n / m;
            }
            return comp[n][m];
        }

        public double fact(int i) {
            if (i < 0) {
                return 0;
            }
            if (fact[i] == -1) {
                if (i == 0) {
                    return fact[i] = 1;
                }
                fact[i] = i * fact(i - 1);
            }
            return fact[i];
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            g = Graph.createUndirectedGraph(n);
            for (int i = 1; i < n; i++) {
                int a = in.readInt() - 1;
                int b = in.readInt() - 1;
                Graph.addUndirectedEdge(g, a, b);
            }
            dp = new double[n][n];
            f = new double[n][n];
            comp = new double[n][n];
            size = new int[n];
            fact = new double[n];
            SequenceUtils.deepFill(fact, -1D);
            SequenceUtils.deepFill(comp, -1D);
            for (int i = 0; i < n; i++) {
                SequenceUtils.deepFill(dp, 0D);
                SequenceUtils.deepFill(f, 0D);
                Arrays.fill(size, 0);
                dfs(i, -1);
                double ans = dp[i][0] / fact(n - 1) / Math.pow(2, n - 1);
                out.println(ans);
            }

        }

        public void dfs(int root, int p) {
            size[root] = 1;
            for (UndirectedEdge e : g[root]) {
                if (e.to == p) {
                    continue;
                }
                dfs(e.to, root);
                size[root] += size[e.to];
            }

            int sum = 0;
            dp[root][0] = 1;
            for (UndirectedEdge e : g[root]) {
                if (e.to == p) {
                    continue;
                }
                double[] former = dp[root];
                dp[root] = new double[n];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; i + j < n; j++) {
                        dp[root][i + j] += comp(i + j, i) * comp(sum - i + size[e.to] - j, sum - i) * former[i] * f[e.to][j];
                    }
                }
                sum += size[e.to];
            }

            double[] suffix = new double[n];
            for (int i = n - 1; i >= 0; i--) {
                suffix[i] = dp[root][i];
                if (i + 1 < n) {
                    suffix[i] += suffix[i + 1];
                }
            }
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    f[root][i] += 2 * dp[root][i - 1] * i;
                }
                f[root][i] += suffix[i];
            }
        }

    }

    static class Graph {
        public static void addUndirectedEdge(List<UndirectedEdge>[] g, int s, int t) {
            UndirectedEdge toT = new UndirectedEdge(t);
            UndirectedEdge toS = new UndirectedEdge(s);
            toT.rev = toS;
            toS.rev = toT;
            g[s].add(toT);
            g[t].add(toS);
        }

        public static List<UndirectedEdge>[] createUndirectedGraph(int n) {
            List<UndirectedEdge>[] ans = new List[n];
            for (int i = 0; i < n; i++) {
                ans[i] = new ArrayList<>();
            }
            return ans;
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

        public FastOutput append(double c) {
            cache.append(new BigDecimal(c).toPlainString());
            return this;
        }

        public FastOutput println(double c) {
            return append(c).println();
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

    static class UndirectedEdge extends DirectedEdge {
        public UndirectedEdge rev;

        public UndirectedEdge(int to) {
            super(to);
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 20];
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

    static class SequenceUtils {
        public static void deepFill(Object array, double val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof double[]) {
                double[] doubleArray = (double[]) array;
                Arrays.fill(doubleArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
            }
        }

    }
}