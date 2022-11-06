

import java.io.*;
import java.nio.charset.Charset;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class CR46E {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("/Users/daltao/DATABASE/TESTCASE/CR46E.in"), new FileOutputStream("/Users/daltao/DATABASE/TESTCASE/CR46E.out"), charset) : new FastIO(System.in, System.out, charset);
        Task task = new Task(io);

        if (async) {
            Thread t = new Thread(null, task, "dalt", 1 << 27);
            t.setPriority(Thread.MAX_PRIORITY);
            t.start();
            t.join();
        } else {
            task.run();
        }

        io.flush();
    }

    public static class Task implements Runnable {
        final FastIO io;

        public Task(FastIO io) {
            this.io = io;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            int n = io.readInt();
            int m = io.readInt();

            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            for (int i = 1; i <= m; i++) {
                Node a = nodes[io.readInt()];
                Node b = nodes[io.readInt()];


                Edge ea = new Edge(a);
                Edge eb = new Edge(b);

                a.out.add(eb);
                a.in.add(ea);
                b.out.add(ea);
                b.in.add(eb);
            }

            tarjan(nodes[1], null);
            dfs(nodes[1], 0);

            io.cache.append(nodes[1].longest);
        }

        Deque<Node> stack = new ArrayDeque<>(300000);
        int dfn = 1;

        public void tarjan(Node root, Node father) {
            if (root.dfn != 0) {
                return;
            }

            root.dfn = dfn++;
            stack.addLast(root);
            root.lowest = root.dfn;
            root.instack = true;

            for (Edge neighbor : root.out) {
                Node node = neighbor.node;
                if (node == father) {
                    continue;
                }
                tarjan(node, root);
                if (!node.instack) {
                    continue;
                }
                root.lowest = Math.min(root.lowest, node.lowest);
            }

            if (root.lowest == root.dfn) {
                while (stack.peekLast() != root) {
                    Node node = stack.removeLast();
                    node.instack = false;
                    for (Edge in : node.in) {
                        in.node = root;
                    }
                    root.out.addAll(node.out);
                    root.in.addAll(node.in);
                }
                stack.removeLast();
                root.instack = false;
            }
        }

        public static void dfs(Node root, int depth)
        {
            root.instack = true;

            root.deepest = depth;
            for(Edge out : root.out)
            {
                Node node = out.node;
                if(node.instack)
                {
                    continue;
                }
                dfs(node, depth + 1);
                root.longest = Math.max(root.longest, node.longest);
                root.longest = Math.max(root.longest, root.deepest + node.deepest - depth - depth);
                root.deepest = Math.max(root.deepest, node.deepest);
            }
        }
    }

    public static class Node {
        List<Edge> out = new ArrayList<Edge>(1);
        List<Edge> in = new ArrayList<Edge>(1);
        int dfn;
        int lowest;
        int id;
        boolean instack;

        int deepest;
        int longest;

        @Override
        public String toString() {
            return "" + id;
        }
    }

    public static class Edge {
        Node node;

        public Edge(Node node) {
            this.node = node;
        }

        @Override
        public String toString() {
            return node.toString();
        }
    }

    public static class FastIO {
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 8);
        public final StringBuilder cache = new StringBuilder(1 << 20);

        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastIO(InputStream is, OutputStream os, Charset charset) {
            this.is = is;
            this.os = os;
            this.charset = charset;
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
                    val = (val << 3) + (val << 1) + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = (val << 3) + (val << 1) - next + '0';
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
                    val = (val << 3) + (val << 1) + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = (val << 3) + (val << 1) - next + '0';
                    next = read();
                }
            }

            return val;
        }

        public double readDouble() {
            long num = readLong();
            if (next != '.') {
                return num;
            }

            next = read();
            long divisor = 1;
            long later = 0;
            while (next >= '0' && next <= '9') {
                divisor = (divisor << 3) + (divisor << 1);
                later = (later << 3) + (later << 1) + next - '0';
                next = read();
            }

            if (num >= 0) {
                return num + (later / (double) divisor);
            } else {
                return num - (later / (double) divisor);
            }
        }

        public String readString() {
            skipBlank();

            defaultStringBuf.setLength(0);
            while (next > 32) {
                defaultStringBuf.append((char) next);
                next = read();
            }
            return defaultStringBuf.toString();
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

        public void flush() {
            try {
                os.write(cache.toString().getBytes(charset));
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}