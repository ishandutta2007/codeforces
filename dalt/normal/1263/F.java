import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.function.BiFunction;
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
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int a = in.readInt();
            Node[] top = new Node[a + 1];
            for (int i = 1; i <= a; i++) {
                top[i] = new Node();
                top[i].id = i;
            }
            for (int i = 2; i <= a; i++) {
                Node p = top[in.readInt()];
                top[i].p = p;
                p.next.add(top[i]);
            }
            Node[] topRelation = new Node[n];
            for (int i = 0; i < n; i++) {
                topRelation[i] = top[in.readInt()];
            }
            int b = in.readInt();
            Node[] bot = new Node[b + 1];
            for (int i = 1; i <= b; i++) {
                bot[i] = new Node();
                bot[i].id = i;
            }
            for (int i = 2; i <= b; i++) {
                Node p = bot[in.readInt()];
                bot[i].p = p;
                p.next.add(bot[i]);
            }
            Node[] botRelation = new Node[n];
            for (int i = 0; i < n; i++) {
                botRelation[i] = bot[in.readInt()];
            }

            Node topRoot = null;
            for (int i = 1; i <= a; i++) {
                if (top[i].p == null) {
                    topRoot = top[i];
                }
            }
            Node botRoot = null;
            for (int i = 1; i <= b; i++) {
                if (bot[i].p == null) {
                    botRoot = bot[i];
                }
            }
            List<Node> topTrace = new ArrayList<>(2 * a);
            List<Node> botTrace = new ArrayList<>(2 * b);
            dfs(topRoot, topTrace);
            dfs(botRoot, botTrace);

            SparseTable<Node> topST = new SparseTable<>(topTrace.toArray(), topTrace.size(), (x, y) -> x.dfn <
                    y.dfn ? x : y);
            SparseTable<Node> botST = new SparseTable<>(botTrace.toArray(), botTrace.size(), (x, y) -> x.dfn <
                    y.dfn ? x : y);


            int[][] topReq = new int[n][n];
            int[][] botReq = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    Node l = topRelation[i];
                    Node r = topRelation[j];
                    if (i == j) {
                        topReq[i][j] = l.depth;
                    } else {
                        topReq[i][j] = topReq[i][j - 1];
                        Node lca = lca(topST, topRelation[j - 1], topRelation[j]);
                        topReq[i][j] += r.depth - lca.depth;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    Node l = botRelation[i];
                    Node r = botRelation[j];
                    if (i == j) {
                        botReq[i][j] = l.depth;
                    } else {
                        botReq[i][j] = botReq[i][j - 1];
                        Node lca = lca(botST, botRelation[j - 1], botRelation[j]);
                        botReq[i][j] += r.depth - lca.depth;
                    }
                }
            }

            int[][] dp = new int[n][2];
            SequenceUtils.deepFill(dp, (int) 1e8);
            dp[0][0] = topReq[0][0];
            dp[0][1] = botReq[0][0];

            for (int i = 1; i < n; i++) {

                for (int j = 0; j <= i - 1; j++) {
                    if (j == 0) {
                        dp[i][0] = Math.min(dp[i][0], botReq[j][i - 1] + topReq[i][i]);
                    } else {
                        Node topLca = lca(topST, topRelation[i], topRelation[j - 1]);
                        Node botLca = lca(botST, botRelation[j], botRelation[j + 1]);
                        int challenger = dp[j][1];
                        if (j + 1 <= i - 1) {
                            challenger += botReq[j + 1][i - 1] - botLca.depth;
                        }
                        challenger += topRelation[i].depth - topLca.depth;
                        dp[i][0] = Math.min(dp[i][0], challenger);
                    }
                }

                for (int j = 0; j <= i - 1; j++) {
                    if (j == 0) {
                        dp[i][1] = Math.min(dp[i][1], topReq[j][i - 1] + botReq[i][i]);
                    } else {
                        Node botLca = lca(botST, botRelation[i], botRelation[j - 1]);
                        Node topLca = lca(topST, topRelation[j], topRelation[j + 1]);
                        int challenger = dp[j][0];
                        if (j + 1 <= i - 1) {
                            challenger += topReq[j + 1][i - 1] - topLca.depth;
                        }
                        challenger += botRelation[i].depth - botLca.depth;
                        dp[i][1] = Math.min(dp[i][1], challenger);
                    }
                }

            }

            int ans = (int) 1e8;
            for (int i = 0; i < n; i++) {
                int topC = dp[i][0];
                if (i < n - 1) {
                    Node lca = lca(topST, topRelation[i + 1], topRelation[i]);
                    topC += topReq[i + 1][n - 1] - lca.depth;
                }
                int botC = dp[i][1];
                if (i < n - 1) {
                    Node lca = lca(botST, botRelation[i + 1], botRelation[i]);
                    botC += botReq[i + 1][n - 1] - lca.depth;
                }
                ans = Math.min(topC, ans);
                ans = Math.min(botC, ans);
            }

            out.println(a + b - 2 - ans);
        }

        public Node lca(SparseTable<Node> st, Node a, Node b) {
            return st.query(Math.min(a.dfn, b.dfn), Math.max(a.dfn, b.dfn));
        }

        public void dfs(Node root, List<Node> trace) {
            if (root.p == null) {
                root.depth = 0;
            } else {
                root.depth = root.p.depth + 1;
            }
            root.dfn = trace.size();
            trace.add(root);
            for (Node node : root.next) {
                dfs(node, trace);
                trace.add(root);
            }
        }

    }

    static class SparseTable<T> {
        private Object[][] st;
        private BiFunction<T, T, T> merger;
        private CachedLog2 log2;

        public SparseTable(Object[] data, int length, BiFunction<T, T, T> merger) {
            log2 = new CachedLog2(length);
            int m = log2.floorLog(length);

            st = new Object[m + 1][length];
            this.merger = merger;
            for (int i = 0; i < length; i++) {
                st[0][i] = data[i];
            }
            for (int i = 0; i < m; i++) {
                int interval = 1 << i;
                for (int j = 0; j < length; j++) {
                    if (j + interval < length) {
                        st[i + 1][j] = merge((T) st[i][j], (T) st[i][j + interval]);
                    } else {
                        st[i + 1][j] = st[i][j];
                    }
                }
            }
        }

        private T merge(T a, T b) {
            return merger.apply(a, b);
        }

        public T query(int left, int right) {
            int queryLen = right - left + 1;
            int bit = log2.floorLog(queryLen);
            // x + 2^bit == right + 1
            // So x should be right + 1 - 2^bit - left=queryLen - 2^bit
            return merge((T) st[bit][left], (T) st[bit][right + 1 - (1 << bit)]);
        }

        public String toString() {
            return Arrays.toString(st[0]);
        }

    }

    static class SequenceUtils {
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

    static class Log2 {
        public int floorLog(int x) {
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

    static class Node {
        Node p;
        int depth;
        int dfn;
        List<Node> next = new ArrayList<>();
        int id;

    }

    static class CachedLog2 {
        private int[] cache;
        private Log2 log2;

        public CachedLog2(int n) {
            cache = new int[n + 1];
            int b = 0;
            for (int i = 0; i <= n; i++) {
                while ((1 << (b + 1)) <= i) {
                    b++;
                }
                cache[i] = b;
            }
        }

        public int floorLog(int x) {
            if (x >= cache.length) {
                return log2.floorLog(x);
            }
            return cache[x];
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
}