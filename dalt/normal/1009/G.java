

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.*;

public class CFContest {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("/Users/daltao/DATABASE/TESTCASE/CFContest.in"), System.out, charset) : new FastIO(System.in,
                System.out, charset);
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
            io.cache.append("\n\n--memory -- \n" + ((Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20) + "M");
        }

        io.flush();
    }

    public static class Task implements Runnable {
        final FastIO io;
        static final int INF = (int) 1e8;

        public Task(FastIO io) {
            this.io = io;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            char[] s = new char[100001];
            int len = io.readString(s, 1);

            int[] charCnt = new int[6];
            for (int i = 1; i <= len; i++) {
                int c = s[i] - 'a';
                charCnt[c]++;
            }

            int[] bitMasks = new int[len + 1];
            Arrays.fill(bitMasks, (1 << 6) - 1);
            int m = io.readInt();
            char[] buf = new char[6];
            for (int i = 0; i < m; i++) {
                int id = io.readInt();
                int l = io.readString(buf, 0);
                bitMasks[id] = 0;
                for (int j = 0; j < l; j++) {
                    int c = buf[j] - 'a';
                    bitMasks[id] |= 1 << c;
                }
            }

            int[] bitMaskCounts = new int[1 << 6];
            for (int i = 1; i <= len; i++) {
                bitMaskCounts[bitMasks[i]]++;
            }

            Node[] maskNodes = new Node[bitMaskCounts.length];
            Node[] charNodes = new Node[6];
            Node src = new Node("src");
            Node dst = new Node("dst");

            for (int i = 0; i < 6; i++) {
                charNodes[i] = new Node(String.valueOf((char) (i + 'a')));
                buildEdgeBetween(charNodes[i], dst, charCnt[i]);
            }

            for (int i = 0, until = maskNodes.length; i < until; i++) {
                maskNodes[i] = new Node(Integer.toBinaryString(i));
                buildEdgeBetween(src, maskNodes[i], bitMaskCounts[i]);

                for (int j = 0; j < 6; j++) {
                    if (bitAt(i, j) == 0) {
                        continue;
                    }
                    buildEdgeBetween(maskNodes[i], charNodes[j], INF);
                }
            }

            src.castEdges();
            dst.castEdges();
            for (int i = 0; i < 6; i++) {
                charNodes[i].castEdges();
            }
            for (int i = 0, until = maskNodes.length; i < until; i++) {
                maskNodes[i].castEdges();
            }

            int f = isap(src, dst, 2 + 6 + maskNodes.length);

            if (f < len) {
                io.cache.append("Impossible");
                return;
            }

            int version = 0;
            for (int i = 1; i <= len; i++) {
                int mask = bitMasks[i];
                for (int j = 0; j < 6; j++) {
                    if (bitAt(mask, j) == 0) {
                        continue;
                    }
                    //try bfs to find a way from j => mask
                    //Then reduce one unit flow
                    if (dfs(charNodes[j], maskNodes[mask], ++version)) {
                        s[i] = (char) (j + 'a');
                        break;
                    }
                }
            }

            io.cache.append(s, 1, len);
            return;
        }

        public static boolean dfs(Node src, Node target, int version) {
            if (src.visited == version) {
                return false;
            }
            src.visited = version;
            if (src == target) {
                return true;
            }

            for (Edge edge : src.edges) {
                if (edge.capacity() == edge.flow()) {
                    continue;
                }
                if (dfs(edge.dst(), target, version)) {
                    edge.send(1);
                    return true;
                }
            }
            return false;
        }

        public static int bitAt(int mask, int offset) {
            return (mask >> offset) & 1;
        }

        public static void bfs(Node sink, int[] distanceCnt, int n) {
            Deque<Node> deque = new ArrayDeque<>(n);
            deque.add(sink);
            sink.distance = 0;
            distanceCnt[0]++;
            while (!deque.isEmpty()) {
                Node head = deque.removeFirst();
                for (Edge edge : head.edges) {
                    Edge rev = edge.reverse();
                    Node src = rev.src();
                    if (rev.capacity() <= rev.flow() || src.distance != -1) {
                        continue;
                    }
                    src.distance = head.distance + 1;
                    distanceCnt[src.distance]++;
                    deque.addLast(src);
                }
            }
        }

        public static int sendFlow(Node node, int allow, int[] distanceCnt) {
            if (node.distance == 0) {
                return allow;
            }
            int originAllow = allow;
            for (Edge edge : node.edges) {
                Node dst = edge.dst();
                if (edge.capacity() == edge.flow() || dst.distance != node.distance - 1) {
                    continue;
                }
                int f = sendFlow(dst, Math.min(edge.capacity() - edge.flow(), allow), distanceCnt);
                edge.send(f);
                allow -= f;

                if (allow == 0 || distanceCnt[0] == 0) {
                    break;
                }
            }
            if (allow != 0) {
                distanceCnt[node.distance]--;
                if (distanceCnt[node.distance] == 0) {
                    distanceCnt[0] = 0;
                }
                distanceCnt[++node.distance]++;
            }
            return originAllow - allow;
        }

        public static int isap(Node src, Node dst, int n) {
            int[] distanceCnt = new int[n + 5];
            Arrays.fill(distanceCnt, 0);
            bfs(dst, distanceCnt, n);
            if (src.distance == -1) {
                return 0;
            }
            int f = 0;
            while (distanceCnt[0] != 0) {
                f += sendFlow(src, INF, distanceCnt);
            }
            return f;
        }

        public static void buildEdgeBetween(Node a, Node b, int cap) {
            Edge edge = new EdgeImpl(cap, 0, a, b);
            a.edgeList.add(edge);
            b.edgeList.add(edge.reverse());
        }
    }

    public static class Node {
        int distance = -1;
        int visited = -1;
        final String id;
        List<Edge> edgeList = new ArrayList<>(6);
        Edge[] edges;

        public Node(String id) {
            this.id = id;
        }

        public void castEdges() {
            edges = edgeList.toArray(new Edge[edgeList.size()]);
        }

        @Override
        public String toString() {
            return id;
        }
    }

    public static interface Edge {
        int capacity();

        int flow();

        Node src();

        Node dst();

        void send(int f);

        Edge reverse();
    }

    public static abstract class AbstractEdge implements Edge {
        @Override
        public String toString() {
            return src() + "=>" + dst();
        }
    }

    public static class EdgeImpl extends AbstractEdge {
        int cap;
        int flow;
        Node src;
        Node dst;
        Edge rev = new ReverseEdge(this);

        @Override
        public Edge reverse() {
            return rev;
        }

        public EdgeImpl(int cap, int flow, Node src, Node dst) {
            this.cap = cap;
            this.flow = flow;
            this.src = src;
            this.dst = dst;
        }

        @Override
        public int capacity() {
            return cap;
        }

        @Override
        public int flow() {
            return flow;
        }

        @Override
        public Node src() {
            return src;
        }

        @Override
        public Node dst() {
            return dst;
        }

        @Override
        public void send(int f) {
            flow += f;
        }
    }

    public static class ReverseEdge extends AbstractEdge {
        private final Edge edge;

        public ReverseEdge(Edge edge) {
            this.edge = edge;
        }

        @Override
        public int capacity() {
            return edge.flow();
        }

        @Override
        public int flow() {
            return 0;
        }

        @Override
        public Node src() {
            return edge.dst();
        }

        @Override
        public Node dst() {
            return edge.src();
        }

        @Override
        public void send(int f) {
            edge.send(-f);
        }

        @Override
        public Edge reverse() {
            return edge;
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
}