
import java.io.*;
import java.nio.charset.Charset;
import java.util.*;

public class CF1016F {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("/Users/daltao/DATABASE/TESTCASE/CF1016F.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
        Task task = new Task(io);

        if (async) {
            Thread t = new Thread(null, task, "dalt", 1 << 27);
            t.setPriority(Thread.MAX_PRIORITY);
            t.start();
            t.join();
        } else {
            task.run();
        }

        if (local) {
            io.cache.append("\n\n--memory -- " + (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()));
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
            for (int i = 0; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            for (int i = 1; i < n; i++) {
                Node a = nodes[io.readInt()];
                Node b = nodes[io.readInt()];

                Edge edge = new Edge();
                edge.src = a;
                edge.dst = b;
                edge.length = io.readInt();

                a.edgeList.add(edge);
                b.edgeList.add(edge);
            }

            dfs1(nodes[1], null, 0);
            dfsn(nodes[n], null, 0);

            Node[] orderedNodes = nodes.clone();
            Arrays.sort(orderedNodes, 1, n + 1, (a, b) -> Long.compare(a.distn, b.distn));
            for (int i = 1; i <= n; i++) {
                orderedNodes[i].order = i;
            }

            long maxDist = 0;
            Deque<Node> queue = new ArrayDeque<>(n);
            Segment segment = Segment.build(1, n);
            for (int i = 1; i <= n; i++) {
                Node node = orderedNodes[i];

                int maxOrder;
                while ((maxOrder = Segment.query(1, n, segment)) != -1) {
                    Node max = orderedNodes[maxOrder];
                    if (max.father1 == node || node.father1 == max) {
                        queue.add(max);
                        Segment.update(maxOrder, 1, n, -1, segment);
                    } else {
                        maxDist = Math.max(maxDist, node.dist1 + max.distn);
                        break;
                    }
                }

                while (!queue.isEmpty()) {
                    int order = queue.removeFirst().order;
                    Segment.update(order, 1, n, order, segment);
                }

                Segment.update(node.order, 1, n, node.order, segment);
            }

            for (int i = 0; i < m; i++) {
                long len = io.readInt();
                long shortest = Math.min(maxDist + len, nodes[1].distn);
                io.cache.append(shortest).append('\n');
            }
        }

        public static void dfs1(Node root, Node father, long length) {
            root.dist1 = length;
            root.father1 = father;

            for (Edge edge : root.edgeList) {
                Node other = edge.getOther(root);
                if (other == father) {
                    continue;
                }
                dfs1(other, root, length + edge.length);
            }
        }

        public static void dfsn(Node root, Node father, long length) {
            root.distn = length;
            root.fathern = father;

            for (Edge edge : root.edgeList) {
                Node other = edge.getOther(root);
                if (other == father) {
                    continue;
                }
                dfsn(other, root, length + edge.length);
            }
        }
    }

    public static class Segment implements Cloneable {
        Segment left;
        Segment right;
        int max = -1;

        public static Segment build(int l, int r) {
            Segment segment = new Segment();
            if (l != r) {
                int m = (l + r) >> 1;
                segment.left = build(l, m);
                segment.right = build(m + 1, r);
                segment.pushUp();
            }
            return segment;
        }

        public static boolean checkOutOfRange(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public static boolean checkCoverage(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        public static void update(int x, int l, int r, int max, Segment segment) {
            if (checkOutOfRange(x, x, l, r)) {
                return;
            }
            if (checkCoverage(x, x, l, r)) {
                segment.max = max;
                return;
            }
            int m = (l + r) >> 1;

            segment.pushDown();
            update(x, l, m, max, segment.left);
            update(x, m + 1, r, max, segment.right);
            segment.pushUp();
        }

        public static int query(int l, int r, Segment segment) {
            return segment.max;
        }

        public void pushDown() {
        }

        public void pushUp() {
            max = Math.max(left.max, right.max);
        }

        @Override
        public Segment clone() {
            try {
                return (Segment) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }
    }


    public static class Node {
        int id;
        Node father1;
        Node fathern;
        long dist1;
        long distn;
        int order;

        List<Edge> edgeList = new ArrayList<>(1);

        @Override
        public String toString() {
            return "" + id;
        }
    }

    public static class Edge {
        Node src;
        Node dst;
        int length;

        Node getOther(Node me) {
            return me == src ? dst : src;
        }

        @Override
        public String toString() {
            return String.format("%s-%d->%s", src, length, dst);
        }
    }

    public static class FastIO {
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 8);
        public final StringBuilder cache = new StringBuilder();

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
            long num = readLong();
            if (next != '.') {
                return num;
            }

            next = read();
            long divisor = 1;
            long later = 0;
            while (next >= '0' && next <= '9') {
                divisor = divisor * 10;
                later = later * 10 + next - '0';
                next = read();
            }

            if (num >= 0) {
                return num + (later / (double) divisor);
            } else {
                return num - (later / (double) divisor);
            }
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

        public boolean hasMore() {
            skipBlank();
            return next != -1;
        }
    }

    public static class Memory {
        public static <T> void swap(T[] data, int i, int j) {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static <T> int min(T[] data, int from, int to, Comparator<T> cmp) {
            int m = from;
            for (int i = from + 1; i < to; i++) {
                if (cmp.compare(data[m], data[i]) > 0) {
                    m = i;
                }
            }
            return m;
        }

        public static <T> void move(T[] data, int from, int to, int step) {
            int len = to - from;
            step = len - (step % len + len) % len;
            Object[] buf = new Object[len];
            for (int i = 0; i < len; i++) {
                buf[i] = data[(i + step) % len + from];
            }
            System.arraycopy(buf, 0, data, from, len);
        }
    }
}