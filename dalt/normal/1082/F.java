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
            FSpeedDial solver = new FSpeedDial();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FSpeedDial {
        int k;
        int inf = (int) 1e9;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            k = in.readInt();
            Trie trie = new Trie();
            for (int i = 0; i < n; i++) {
                char[] s = in.readString().toCharArray();
                build(trie, s, 0, in.readInt());
            }

            int[] dp = dfsTrie(trie);
            int ans = CompareUtils.minOf(dp, 0, k);
            out.println(ans);
        }

        public int[] dfsTrie(Trie root) {
            for (Trie node : root.next) {
                if (node == null) {
                    continue;
                }
                dfs(node);
            }
            int[] dp2 = new int[k + 1];
            SequenceUtils.deepFill(dp2, inf);
            dp2[0] = 0;
            for (Trie node : root.next) {
                if (node == null) {
                    continue;
                }
                for (int j = k; j >= 0; j--) {
                    int val = inf;
                    for (int t = 0; t <= j; t++) {
                        val = Math.min(dp2[j - t] + node.dp[root.depth][t], val);
                    }
                    dp2[j] = val;
                }
            }

            return dp2;
        }

        public void dfs(Trie root) {
            for (Trie node : root.next) {
                if (node == null) {
                    continue;
                }
                dfs(node);
            }
            int[][] dp1 = new int[root.depth][k + 1];
            int[] dp2 = new int[k + 1];
            SequenceUtils.deepFill(dp1, inf);
            SequenceUtils.deepFill(dp2, inf);
            dp2[1] = 0;
            for (int i = 0; i < root.depth; i++) {
                dp1[i][0] = root.w * (root.depth - i);
            }
            for (Trie node : root.next) {
                if (node == null) {
                    continue;
                }
                for (int i = 0; i < root.depth; i++) {
                    for (int j = k; j >= 0; j--) {
                        int val = inf;
                        for (int t = 0; t <= j; t++) {
                            val = Math.min(dp1[i][j - t] + node.dp[i][t], val);
                        }
                        dp1[i][j] = val;
                    }
                }

                for (int j = k; j >= 0; j--) {
                    int val = inf;
                    for (int t = 0; t <= j; t++) {
                        val = Math.min(dp2[j - t] + node.dp[root.depth][t], val);
                    }
                    dp2[j] = val;
                }
            }

            for (int i = 0; i < root.depth; i++) {
                for (int j = 0; j <= k; j++) {
                    dp1[i][j] = Math.min(dp1[i][j], dp2[j]);
                }
            }

            root.dp = dp1;
        }

        public void build(Trie root, char[] s, int i, int w) {
            if (i == s.length) {
                root.w += w;
                return;
            }
            build(root.get(s[i] - '0'), s, i + 1, w);
        }

    }

    static class CompareUtils {
        private CompareUtils() {
        }

        public static int minOf(int[] a, int l, int r) {
            int x = a[l];
            for (int i = l; i <= r; i++) {
                x = Math.min(x, a[i]);
            }
            return x;
        }

    }

    static class Trie {
        int w;
        int depth;
        Trie[] next = new Trie[10];
        int[][] dp;

        public Trie get(int i) {
            if (next[i] == null) {
                next[i] = new Trie();
                next[i].depth = depth + 1;
            }
            return next[i];
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
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