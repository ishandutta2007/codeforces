
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.List;

public class CF1163F {
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
        int mod = (int) 1e9 + 7;
        long lINf = (long) 1e18;

        public int mod(int val) {
            val %= mod;
            if (val < 0) {
                val += mod;
            }
            return val;
        }

        public int mod(long val) {
            val %= mod;
            if (val < 0) {
                val += mod;
            }
            return (int) val;
        }

        int bitAt(int x, int i) {
            return (x >> i) & 1;
        }

        int bitAt(long x, int i) {
            return (int) ((x >> i) & 1);
        }

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            int n = io.readInt();
            int m = io.readInt();
            int q = io.readInt();

            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            Edge[] edges = new Edge[m + 1];
            for (int i = 1; i <= m; i++) {
                Edge edge = new Edge();
                edge.a = nodes[io.readInt()];
                edge.b = nodes[io.readInt()];
                edge.a.edges.add(edge);
                edge.b.edges.add(edge);
                edge.w = io.readInt();
                edges[i] = edge;
            }

            //n->1
            MinHeap<Node> minHeap = new MinHeap<>(n, Node.compareByRDist);
            for (int i = 1; i <= n; i++) {
                nodes[i].rDist = lINf;
                nodes[i].key = minHeap.add(nodes[i]);
            }
            nodes[n].rDist = 0;
            minHeap.shiftUpward(nodes[n].key);
            while (minHeap.size > 0) {
                Node head = minHeap.remove().val;
                for (Edge edge : head.edges) {
                    Node node = edge.another(head);
                    long w = head.rDist + edge.w;
                    if (node.rDist <= w) {
                        continue;
                    }
                    node.rDist = w;
                    node.post = edge;
                    minHeap.shiftUpward(node.key);
                }
            }
            //1->n
            minHeap = new MinHeap<>(n, Node.compareByLDist);
            for (int i = 1; i <= n; i++) {
                nodes[i].lDist = lINf;
                nodes[i].key = minHeap.add(nodes[i]);
            }
            nodes[1].lDist = 0;
            minHeap.shiftUpward(nodes[1].key);
            while (minHeap.size > 0) {
                Node head = minHeap.remove().val;
                for (Edge edge : head.edges) {
                    Node node = edge.another(head);
                    long w = head.lDist + edge.w;
                    if (node.lDist <= w) {
                        continue;
                    }
                    node.lDist = w;
                    node.pre = edge;
                    minHeap.shiftUpward(node.key);
                }
            }


            Node trace = nodes[n];
            Deque<Edge> seq = new ArrayDeque<>();
            while (trace != nodes[1]) {
                seq.addFirst(trace.pre);
                trace = trace.pre.another(trace);
            }
            int mainPathLength = seq.size();
            while (!seq.isEmpty()) {
                Edge head = seq.removeLast();
                head.order = seq.size() + 1;
            }

            Segment root = Segment.build(1, mainPathLength);
            nodes[1].lf = 0;
            nodes[n].rf = mainPathLength + 1;

            for (int i = 1; i <= m; i++) {
                Edge edge = edges[i];
                if (edge.order != -1) {
                    continue;
                }
                if (edge.a.lDist == lINf && edge.b.lDist == lINf) {
                    continue;
                }
                Node a = edge.a;
                Node b = edge.b;
                long ab = a.lDist + edge.w + b.rDist;
                long ba = a.rDist + edge.w + b.lDist;
                if (ab > ba) {
                    Node tmp = a;
                    a = b;
                    b = tmp;
                    ab = ba;
                }

                Segment.update(lf(a) + 1, rf(b) - 1, 1, mainPathLength, ab, root);
            }

            for (int i = 0; i < q; i++) {
                Edge edge = edges[io.readInt()];
                int w = io.readInt();

                if (edge.order == -1) {
                    long min = nodes[n].lDist;
                    min = Math.min(min, edge.a.lDist + w + edge.b.rDist);
                    min = Math.min(min, edge.a.rDist + w + edge.b.lDist);
                    io.cache.append(min).append('\n');
                    continue;
                }

                long min = nodes[n].lDist - edge.w + w;
                long replacement = Segment.query(edge.order, edge.order, 1, mainPathLength, root);
                min = Math.min(replacement, min);
                io.cache.append(min).append('\n');
            }
        }

        public int lf(Node node) {
            if (node.lf == Integer.MIN_VALUE) {
                if (node.pre.order != -1) {
                    node.lf = node.pre.order;
                } else {
                    node.lf = lf(node.pre.another(node));
                }
            }
            return node.lf;
        }

        public int rf(Node node) {
            if (node.rf == Integer.MIN_VALUE) {
                if (node.post.order != -1) {
                    node.rf = node.post.order;
                } else {
                    node.rf = rf(node.post.another(node));
                }
            }
            return node.rf;
        }
    }

    public static class Edge {
        int w;
        Node a;
        Node b;
        int order = -1;

        Node another(Node me) {
            return a == me ? b : a;
        }

        @Override
        public String toString() {
            return a + "<->" + b;
        }
    }

    public static class Node {
        List<Edge> edges = new ArrayList<>();
        int id;
        Edge pre;
        Edge post;
        MinHeap.Key<Node> key;
        long lDist;
        long rDist;
        int lf = Integer.MIN_VALUE;
        int rf = Integer.MIN_VALUE;

        static Comparator<Node> compareByLDist = (a, b) -> Long.compare(a.lDist, b.lDist);
        static Comparator<Node> compareByRDist = (a, b) -> Long.compare(a.rDist, b.rDist);

        @Override
        public String toString() {
            return "" + id;
        }
    }

    public static class MinHeap<T> {
        final Key<T>[] data;
        final Comparator<T> comparator;
        int size;
        int cap;

        public MinHeap(int cap, Comparator<T> comparator) {
            this.cap = cap;
            data = new Key[cap + 1];
            this.comparator = comparator;
            size = 0;
        }

        public Key<T> add(T val) {
            Key<T> key = new Key<>();
            key.val = val;
            data[++size] = key;
            key.index = size;

            shiftUpward(key);

            return key;
        }

        public void shiftUpward(Key<T> key) {
            int index = key.index;
            T val = key.val;
            while (index != 1) {
                int fIndex = index >> 1;
                if (comparator.compare(val, data[fIndex].val) >= 0) {
                    break;
                }
                data[index] = data[fIndex];
                data[index].index = index;
                index = fIndex;
            }
            data[index] = key;
            key.index = index;
        }

        public Key<T> peek() {
            return data[1];
        }

        public Key<T> remove() {
            Key<T> key = data[1];
            data[1] = data[size--];
            data[1].index = 1;

            shiftDownward(data[1]);

            return key;
        }

        public void shiftDownward(Key<T> key) {
            int index = key.index;
            T val = key.val;
            int until = size >> 1;
            while (index <= until) {
                int lIndex = index << 1;
                int rIndex = lIndex + 1;
                int minIndex = rIndex > size || comparator.compare(data[lIndex].val, data[rIndex].val) <= 0 ?
                        lIndex : rIndex;

                if (comparator.compare(val, data[minIndex].val) <= 0) {
                    break;
                }
                data[index] = data[minIndex];
                data[index].index = index;
                index = minIndex;
            }
            data[index] = key;
            key.index = index;
        }

        public int size() {
            return size;
        }

        public static class Key<T> {
            T val;
            int index;
        }
    }

    public static class Segment implements Cloneable {
        static long lInf = (long) 1e18;
        Segment left;
        Segment right;
        long min = lInf;
        long minDirty = lInf;

        public void setMin(long minDirty) {
            this.minDirty = Math.min(this.minDirty, minDirty);
            min = Math.min(this.minDirty, min);
        }

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

        public static void update(int ll, int rr, int l, int r, long min, Segment segment) {
            if (checkOutOfRange(ll, rr, l, r)) {
                return;
            }
            if (checkCoverage(ll, rr, l, r)) {
                segment.setMin(min);
                return;
            }
            int m = (l + r) >> 1;

            segment.pushDown();
            update(ll, rr, l, m, min, segment.left);
            update(ll, rr, m + 1, r, min, segment.right);
            segment.pushUp();
        }

        public static long query(int ll, int rr, int l, int r, Segment segment) {
            if (checkOutOfRange(ll, rr, l, r)) {
                return lInf;
            }
            if (checkCoverage(ll, rr, l, r)) {
                return segment.min;
            }
            int m = (l + r) >> 1;

            segment.pushDown();
            return Math.min(query(ll, rr, l, m, segment.left),
                    query(ll, rr, m + 1, r, segment.right));
        }

        public void pushDown() {
            left.setMin(minDirty);
            right.setMin(minDirty);
        }

        public void pushUp() {
            min = Math.min(left.min, right.min);
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