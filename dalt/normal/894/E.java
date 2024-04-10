

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by dalt on 2018/3/20.
 */
public class CF894E implements Runnable {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;
    static Node[] nodes;
    static int idAllocator = 1;


    static Node[] stack;
    static int stackTop = -1;

    static int[] fcache = new int[20001];
    static long[] gcache = new long[20001];

    static {
        for (int i = 1; i <= 20000; i++) {
            fcache[i] = i * (i + 1) >> 1;
            long li = i;
            gcache[i] = (li * li * li - li) / 6;
        }
    }

    public static void tarjan(Node node) {
        if (node.dfn != 0) {
            return;
        }

        node.dfn = idAllocator++;
        node.instk = true;
        node.lowest = node.dfn;
        stack[++stackTop] = node;

        for (Edge edge : node.outEdge) {
            tarjan(edge.dst);
            if (edge.dst.instk) {
                node.lowest = Math.min(node.lowest, edge.dst.lowest);
            }
        }

        if (node.lowest == node.dfn) {
            for (; stack[stackTop] != node; stackTop--) {
                Node top = stack[stackTop];
                top.instk = false;
                top.repr = node;
                for (Edge edge : top.inEdge) {
                    edge.dst = node;
                }
                for (Edge edge : top.outEdge) {
                    edge.src = node;
                }
                node.outEdge.addAll(top.outEdge);
                node.inEdge.addAll(top.inEdge);
            }
            stackTop--;
            node.instk = false;
        }
    }

    public static long evaluate(int m) {
        //1 + 2 + 3 + ... + k >= m
        //we could go through the street for k time, where k(k+1)/2>=m>k(k-1)/2
        //f(m)=m + (m - 1) + (m - 1- 2) + ... + (m - 1 - 2 - ... - (k-1)) = km - g(k),
        //g(k)=(k-1)*1+(k-2)*2+...+1*(k-1)
        //the formula of g(k) is g(k-1)=k*(k-1)*(k-2)/6, or g(k)=(k+1)k(k-1)/6
        int up = 20000; //up*(up+1)>=m
        int low = 0; //low*(low+1)<m
        while (low < up) {
            int mid = (up + low) >> 1;
            if (fcache[mid] >= m) {
                up = mid;
            } else {
                low = mid + 1;
            }
        }

        int k = low;
        return (long) k * m - gcache[k];
    }

    public static long makeDp(Node node) {
        if (node.dp == -1) {
            long extra = 0;
            node.dp = 0;
            //unable to visit node
            for (Edge edge : node.inEdge) {
                Node src = edge.src;
                if (src.dfn == 0) {
                    continue;
                }
                if (src == node) {
                    extra += evaluate(edge.mushroom);
                    continue;
                }
                node.dp = Math.max(node.dp, makeDp(src) + edge.mushroom);
            }
            node.dp += extra;
        }
        return node.dp;
    }

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF894E.in"));
        }
        input = new BlockReader(System.in);

        Thread t = new Thread(null, new CF894E(), "", 1 << 27);
        t.setPriority(Thread.MAX_PRIORITY);
        t.start();
    }

    public static void buildEdge(Node a, Node b, int mushroom) {
        Edge edge = new Edge();
        edge.src = a;
        edge.dst = b;
        edge.mushroom = mushroom;

        a.outEdge.add(edge);
        b.inEdge.add(edge);
    }

    public static void solve() {
        int n = input.nextInteger();
        int m = input.nextInteger();
        nodes = new Node[n + 1];
        stack = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
        }
        for (int i = 1; i <= m; i++) {
            Node a = nodes[input.nextInteger()];
            Node b = nodes[input.nextInteger()];
            buildEdge(a, b, input.nextInteger());
        }

        Node root = nodes[input.nextInteger()];
        tarjan(root);

        long max = 0;
        for (int i = 1; i <= n; i++) {
            if (nodes[i].repr != nodes[i] || nodes[i].dfn == 0) {
                continue;
            }
            max = Math.max(max, makeDp(nodes[i]));
        }

        System.out.print(max);
    }

    @Override
    public void run() {
        solve();
    }

    public static class Node {
        List<Edge> inEdge = new ArrayList(1);
        List<Edge> outEdge = new ArrayList<>(1);
        int dfn;
        int lowest;
        boolean instk;
        Node repr = this;
        long dp = -1;
    }

    public static class Edge {
        Node src;
        Node dst;
        int mushroom;
    }

    public static class BlockReader {
        static final int EOF = -1;
        InputStream is;
        byte[] dBuf;
        int dPos, dSize, next;
        StringBuilder builder = new StringBuilder();

        public BlockReader(InputStream is) {
            this(is, 4096);
        }

        public BlockReader(InputStream is, int bufSize) {
            this.is = is;
            dBuf = new byte[bufSize];
            next = nextByte();
        }

        public int nextByte() {
            while (dPos >= dSize) {
                if (dSize == -1) {
                    return EOF;
                }
                dPos = 0;
                try {
                    dSize = is.read(dBuf);
                } catch (Exception e) {
                }
            }
            return dBuf[dPos++];
        }

        public String nextBlock() {
            builder.setLength(0);
            skipBlank();
            while (next != EOF && !Character.isWhitespace(next)) {
                builder.append((char) next);
                next = nextByte();
            }
            return builder.toString();
        }

        public void skipBlank() {
            while (Character.isWhitespace(next)) {
                next = nextByte();
            }
        }

        public int nextInteger() {
            skipBlank();
            int ret = 0;
            boolean rev = false;
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = nextByte();
            }
            while (next >= '0' && next <= '9') {
                ret = (ret << 3) + (ret << 1) + next - '0';
                next = nextByte();
            }
            return rev ? -ret : ret;
        }

        public int nextBlock(char[] data, int offset) {
            skipBlank();
            int index = offset;
            int bound = data.length;
            while (next != EOF && index < bound && !Character.isWhitespace(next)) {
                data[index++] = (char) next;
                next = nextByte();
            }
            return index - offset;
        }

        public boolean hasMore() {
            skipBlank();
            return next != EOF;
        }
    }
}