

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * Created by dalt on 2018/3/1.
 */
public class CF915F {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF915F.in"));
        }
        input = new BlockReader(System.in);
        StringBuilder builder = new StringBuilder();

        int n = input.nextInteger();
        Node[] nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
            nodes[i].init();
            nodes[i].val = input.nextInteger();
        }

        for (int i = 1; i < n; i++) {
            Node a = nodes[input.nextInteger()];
            Node b = nodes[input.nextInteger()];
            a.nearby.add(b);
            b.nearby.add(a);
        }

        Node[] ascendingNodes = nodes.clone();
        Comparator<Node> ascendingCmp = new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.val - o2.val;
            }
        };

        Arrays.sort(ascendingNodes, 1, n + 1, ascendingCmp);

        long maxsum = visit(ascendingNodes, n);
        Node[] descendingNodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            descendingNodes[i] = ascendingNodes[n - i + 1];
            descendingNodes[i].init();
        }

        long minsum = visit(descendingNodes, n);

        System.out.println(maxsum - minsum);
    }

    public static long visit(Node[] nodes, int n) {
        List<Node> nearby = new ArrayList<>();
        long sum = 0;
        for (int i = 1; i <= n; i++) {
            nearby.clear();
            long cnt1 = 0;
            long cnt2 = 0;
            for (Node neighbor : nodes[i].nearby) {
                neighbor = neighbor.getRepr();

                if (neighbor.visited == true) {
                    nearby.add(neighbor);
                    cnt2 += cnt1 * neighbor.size;
                    cnt1 += neighbor.size;
                    Node.union(nodes[i], neighbor);
                }
                nodes[i].visited = true;
            }

            sum += (cnt1 + cnt2) * nodes[i].val;
        }

        return sum;
    }

    public static class Node {
        List<Node> nearby = new ArrayList<>();
        int val;

        int size;
        Node p;
        int rank;
        boolean visited;

        public static void union(Node a, Node b) {
            a = a.getRepr();
            b = b.getRepr();
            if (a == b) {
                return;
            }
            if (a.rank == b.rank) {
                a.rank++;
            }

            if (a.rank > b.rank) {
                b.p = a;
                a.size += b.size;
            } else {
                a.p = b;
                b.size += a.size;
            }
        }

        public void init() {
            p = this;
            rank = 0;
            size = 1;
            visited = false;
        }

        public Node getRepr() {
            return p == p.p ? p : (p = p.getRepr());
        }
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