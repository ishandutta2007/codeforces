

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CF1168D {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("D:\\DATABASE\\TESTCASE\\Code.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
        Task task = new Task(io, new Debug(local));

        if (async) {
            Thread t = new Thread(null, task, "dalt", 1 << 27);
            t.setPriority(Thread.MAX_PRIORITY);
            t.start();
            t.join();
        } else {
            task.run();
        }

        if (local) {
            io.cache.append("\n\n--memory -- \n" + ((Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20) + "M");
        }

        io.flush();
    }

    public static class Task implements Runnable {
        final FastIO io;
        final Debug debug;
        int inf = (int) 1e8;

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }

        Node[] nodes;

        public void solve() {
            int n = io.readInt();
            int q = io.readInt();
            nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            int[] color = new int[n + 1];
            for (int i = 2; i <= n; i++) {
                setFather(nodes[i], nodes[io.readInt()]);
                color[i] = io.readChar();
                if (color[i] != '?') {
                    nodes[i].edges[color[i] - 'a']++;
                }
            }
            dfs(nodes[1], 1);
            compress(nodes[1], null);
            dpOnTree(nodes[1]);

            for (int i = 0; i < q; i++) {
                int nodeId = io.readInt();
                Node v = nodes[nodeId];
                int c = io.readChar();
                int old = color[nodeId];
                color[nodeId] = c;
                if (old != '?') {
                    v.edges[old - 'a']--;
                }
                if (c != '?') {
                    v.edges[c - 'a']++;
                }
                shiftUp(v);

                if (invalidCount > 0) {
                    io.cache.append("Fou\n");
                    continue;
                }

                int sum = 0;
                for (int j = 0; j < Node.SIZE; j++) {
                    sum += nodes[1].dp[j] + nodes[1].edges[j];
                }
                int flexible = leafDepth - 1 - sum;
                int func = 0;
                for (int j = 0; j < Node.SIZE; j++) {
                    func += (j + 1) * (flexible + nodes[1].dp[j] + nodes[1].edges[j]);
                }

                io.cache.append("Shi ").append(func).append('\n');
            }
        }

        public void dpOnNode(Node root, Node child) {
            for (int i = 0; i < Node.SIZE; i++) {
                root.dp[i] = Math.max(root.dp[i], child.edges[i] + child.dp[i]);
            }
        }

        public void shiftUp(Node root) {
            while (root != null) {
                dpOnNode(root);
                root = root.father;
            }
        }

        public void dpOnNode(Node root) {
            Arrays.fill(root.dp, 0);
            if (root.left != null) {
                dpOnNode(root, root.left);
                dpOnNode(root, root.right);
            } else {
                return;
            }
            int sum = 0;
            for (int i = 0; i < Node.SIZE; i++) {
                sum += root.dp[i];
            }
            boolean valid = sum <= Math.min(leafDepth - root.left.depth + 1, leafDepth - 1);
            if (valid != root.valid) {
                if (valid) {
                    invalidCount--;
                } else {
                    invalidCount++;
                }
                root.valid = valid;
            }
        }

        public void dfs(Node root, int depth) {
            if (root == null) {
                return;
            }
            root.depth = depth;
            dfs(root.left, depth + 1);
            dfs(root.right, depth + 1);
            if (root.left == null && root.right == null) {
                if (leafDepth == -1) {
                    leafDepth = depth;
                }
                if (leafDepth != depth) {
                    invalidCount = inf;
                }
            }
        }

        int leafDepth = -1;
        int invalidCount = 0;

        public void dpOnTree(Node root) {
            if (root == null) {
                return;
            }
            dpOnTree(root.left);
            dpOnTree(root.right);
            dpOnNode(root);
        }

        public void compress(Node root, Node father) {
            if (root == null) {
                return;
            }
            root.father = father;
            while (root.left != null && root.right == null) {
                for (int i = 0; i < Node.SIZE; i++) {
                    root.edges[i] += root.left.edges[i];
                }
                nodes[root.left.id] = root;
                root.right = root.left.right;
                root.left = root.left.left;
            }
            compress(root.left, root);
            compress(root.right, root);
        }

        public void setFather(Node node, Node father) {
            node.father = father;
            if (father.left == null) {
                father.left = node;
            } else if (father.right == null) {
                father.right = node;
            }
        }
    }

    public static class Node {
        public static final int SIZE = 'z' - 'a' + 1;
        int[] dp = new int[SIZE];
        int[] edges = new int[SIZE];
        Node left;
        Node right;
        int depth;
        int id;
        Node father;
        boolean valid = true;
    }

    public static class FastIO {
        public final StringBuilder cache = new StringBuilder();
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 8);
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastIO(InputStream is, OutputStream os, Charset charset) {
            this.is = is;
            this.os = os;
            this.charset = charset;
        }

        public FastIO(InputStream is, OutputStream os) {
            this(is, os, Charset.forName("ascii"));
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

        public long readLong() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            long val = 0;
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

        public double readDouble() {
            boolean sign = true;
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+';
                next = read();
            }

            long val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 + next - '0';
                next = read();
            }
            if (next != '.') {
                return sign ? val : -val;
            }
            next = read();
            long radix = 1;
            long point = 0;
            while (next >= '0' && next <= '9') {
                point = point * 10 + next - '0';
                radix = radix * 10;
                next = read();
            }
            double result = val + (double) point / radix;
            return sign ? result : -result;
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

        public int readLine(char[] data, int offset) {
            int originalOffset = offset;
            while (next != -1 && next != '\n') {
                data[offset++] = (char) next;
                next = read();
            }
            return offset - originalOffset;
        }

        public int readString(char[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
        }

        public int readString(byte[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (byte) next;
                next = read();
            }

            return offset - originalOffset;
        }

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

        public void flush() {
            try {
                os.write(cache.toString().getBytes(charset));
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public boolean hasMore() {
            skipBlank();
            return next != -1;
        }
    }

    public static class Debug {
        private boolean allowDebug;

        public Debug(boolean allowDebug) {
            this.allowDebug = allowDebug;
        }

        public void assertTrue(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (!flag) {
                fail();
            }
        }

        public void fail() {
            throw new RuntimeException();
        }

        public void assertFalse(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (flag) {
                fail();
            }
        }

        private void outputName(String name) {
            System.out.print(name + " = ");
        }

        public void debug(String name, int x) {
            if (!allowDebug) {
                return;
            }

            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, long x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, double x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, int[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, long[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, double[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, Object x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, Object... x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.deepToString(x));
        }
    }
}