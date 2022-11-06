import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.TreeSet;
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
            int m = in.readInt();
            int k = in.readInt();
            int q = in.readInt();

            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            Edge[] edges = new Edge[m];
            for (int i = 0; i < m; i++) {
                edges[i] = new Edge();
                edges[i].a = nodes[in.readInt()];
                edges[i].b = nodes[in.readInt()];
                edges[i].w = in.readInt();
                edges[i].a.next.add(edges[i]);
                edges[i].b.next.add(edges[i]);
            }

            for (int i = k + 1; i <= n; i++) {
                nodes[i].dist = (long) 1e18;
            }

            TreeSet<Node> set = new TreeSet<>((a, b) -> a.dist == b.dist ? a.id - b.id : Long.compare(a.dist, b.dist));
            for (int i = 1; i <= k; i++) {
                nodes[i].dist = 0;
                set.add(nodes[i]);
            }

            while (!set.isEmpty()) {
                Node head = set.pollFirst();
                for (Edge e : head.next) {
                    Node node = e.other(head);
                    if (head.dist + e.w >= node.dist) {
                        continue;
                    }
                    set.remove(node);
                    node.dist = head.dist + e.w;
                    set.add(node);
                }
            }

            for (Edge e : edges) {
                e.w += e.a.dist + e.b.dist;
            }

            DynamicMST mst = new DynamicMST(n);
            for (Edge e : edges) {
                mst.addEdge(e.a.id - 1, e.b.id - 1, e.w);
            }

            for (int i = 0; i < q; i++) {
                int a = in.readInt();
                int b = in.readInt();
                long maxW = mst.maxWeightBetween(a - 1, b - 1);
                out.println(maxW);
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

        public FastOutput println(long c) {
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

    static class Node {
        List<Edge> next = new ArrayList<>();
        long dist;
        int id;

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

    static class DynamicMST {
        private DynamicMST.LCTNode[] nodes;
        private long totalWeight;
        private int edgeNum;

        public DynamicMST(int n) {
            nodes = new DynamicMST.LCTNode[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new DynamicMST.LCTNode();
                nodes[i].id = i;
                nodes[i].weight = 0;
                nodes[i].pushUp();
            }
            for (int i = 1; i < n; i++) {
                DynamicMST.LCTNode node = new DynamicMST.LCTNode();
                node.weight = Long.MAX_VALUE;
                node.a = nodes[i - 1];
                node.b = nodes[i];
                node.pushUp();
                DynamicMST.LCTNode.join(node.a, node);
                DynamicMST.LCTNode.join(node.b, node);
            }
        }

        public void addEdge(int aId, int bId, long weight) {
            DynamicMST.LCTNode a = nodes[aId];
            DynamicMST.LCTNode b = nodes[bId];
            DynamicMST.LCTNode.findRoute(a, b);
            DynamicMST.LCTNode.splay(a);
            if (a.largest.weight <= weight) {
                return;
            }
            DynamicMST.LCTNode largest = a.largest;
            DynamicMST.LCTNode.splay(largest);
            DynamicMST.LCTNode.cut(largest.a, largest);
            DynamicMST.LCTNode.cut(largest.b, largest);
            if (largest.weight < Long.MAX_VALUE) {
                edgeNum--;
                totalWeight -= largest.weight;
            }

            DynamicMST.LCTNode node = new DynamicMST.LCTNode();
            node.weight = weight;
            node.a = a;
            node.b = b;
            node.pushUp();
            DynamicMST.LCTNode.join(node.a, node);
            DynamicMST.LCTNode.join(node.b, node);
            edgeNum++;
            totalWeight += node.weight;
        }

        public long maxWeightBetween(int aId, int bId) {
            DynamicMST.LCTNode a = nodes[aId];
            DynamicMST.LCTNode b = nodes[bId];
            DynamicMST.LCTNode.findRoute(a, b);
            DynamicMST.LCTNode.splay(b);
            return b.largest.weight;
        }

        private static class LCTNode {
            public static final DynamicMST.LCTNode NIL = new DynamicMST.LCTNode();
            DynamicMST.LCTNode left = NIL;
            DynamicMST.LCTNode right = NIL;
            DynamicMST.LCTNode father = NIL;
            DynamicMST.LCTNode treeFather = NIL;
            boolean reverse;
            int id;
            DynamicMST.LCTNode a;
            DynamicMST.LCTNode b;
            DynamicMST.LCTNode largest;
            long weight;

            static {
                NIL.left = NIL;
                NIL.right = NIL;
                NIL.father = NIL;
                NIL.treeFather = NIL;
                NIL.weight = 0;
                NIL.largest = NIL;
            }

            public static DynamicMST.LCTNode larger(DynamicMST.LCTNode a, DynamicMST.LCTNode b) {
                return a.weight >= b.weight ? a : b;
            }

            public static void access(DynamicMST.LCTNode x) {
                DynamicMST.LCTNode last = NIL;
                while (x != NIL) {
                    splay(x);
                    x.right.father = NIL;
                    x.right.treeFather = x;
                    x.setRight(last);
                    x.pushUp();

                    last = x;
                    x = x.treeFather;
                }
            }

            public static void makeRoot(DynamicMST.LCTNode x) {
                access(x);
                splay(x);
                x.reverse();
            }

            public static void cut(DynamicMST.LCTNode y, DynamicMST.LCTNode x) {
                makeRoot(y);
                access(x);
                splay(y);
                y.right.treeFather = NIL;
                y.right.father = NIL;
                y.setRight(NIL);
                y.pushUp();
            }

            public static void join(DynamicMST.LCTNode y, DynamicMST.LCTNode x) {
                makeRoot(x);
                x.treeFather = y;
            }

            public static void findRoute(DynamicMST.LCTNode x, DynamicMST.LCTNode y) {
                makeRoot(y);
                access(x);
            }

            public static void splay(DynamicMST.LCTNode x) {
                if (x == NIL) {
                    return;
                }
                DynamicMST.LCTNode y, z;
                while ((y = x.father) != NIL) {
                    if ((z = y.father) == NIL) {
                        y.pushDown();
                        x.pushDown();
                        if (x == y.left) {
                            zig(x);
                        } else {
                            zag(x);
                        }
                    } else {
                        z.pushDown();
                        y.pushDown();
                        x.pushDown();
                        if (x == y.left) {
                            if (y == z.left) {
                                zig(y);
                                zig(x);
                            } else {
                                zig(x);
                                zag(x);
                            }
                        } else {
                            if (y == z.left) {
                                zag(x);
                                zig(x);
                            } else {
                                zag(y);
                                zag(x);
                            }
                        }
                    }
                }

                x.pushDown();
                x.pushUp();
            }

            public static void zig(DynamicMST.LCTNode x) {
                DynamicMST.LCTNode y = x.father;
                DynamicMST.LCTNode z = y.father;
                DynamicMST.LCTNode b = x.right;

                y.setLeft(b);
                x.setRight(y);
                z.changeChild(y, x);

                y.pushUp();
            }

            public static void zag(DynamicMST.LCTNode x) {
                DynamicMST.LCTNode y = x.father;
                DynamicMST.LCTNode z = y.father;
                DynamicMST.LCTNode b = x.left;

                y.setRight(b);
                x.setLeft(y);
                z.changeChild(y, x);

                y.pushUp();
            }

            public String toString() {
                return "" + id;
            }

            public void pushDown() {
                if (reverse) {
                    reverse = false;

                    DynamicMST.LCTNode tmpNode = left;
                    left = right;
                    right = tmpNode;

                    left.reverse();
                    right.reverse();
                }

                left.treeFather = treeFather;
                right.treeFather = treeFather;
            }

            public void reverse() {
                reverse = !reverse;
            }

            public void setLeft(DynamicMST.LCTNode x) {
                left = x;
                x.father = this;
            }

            public void setRight(DynamicMST.LCTNode x) {
                right = x;
                x.father = this;
            }

            public void changeChild(DynamicMST.LCTNode y, DynamicMST.LCTNode x) {
                if (left == y) {
                    setLeft(x);
                } else {
                    setRight(x);
                }
            }

            public void pushUp() {
                largest = larger(this, left.largest);
                largest = larger(largest, right.largest);
            }

        }

    }

    static class Edge {
        Node a;
        Node b;
        long w;

        Node other(Node x) {
            return a == x ? b : a;
        }

    }
}