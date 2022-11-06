
import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by Administrator on 2018/3/13.
 */
public class CF949C {
    public static BlockReader input;
    public static PrintStream output;
    static int idAllocator;
    static Node minLeaf;
    static int minRemove = (int) 1e8;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF949C.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }


        solve();

        output.flush();
    }

    public static void solve() {
        int n = input.nextInteger();
        int c = input.nextInteger();
        int h = input.nextInteger();

        Node[] nodes = new Node[n + 1];
        nodes[0] = new Node();
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
            nodes[i].hour = input.nextInteger();

            nodes[0].neighborList.add(nodes[i]);
        }

        for (int i = 0; i < c; i++) {
            Node a = nodes[input.nextInteger()];
            Node b = nodes[input.nextInteger()];

            if ((a.hour + 1) % h == b.hour) {
                a.neighborList.add(b);
            }
            if ((b.hour + 1) % h == a.hour) {
                b.neighborList.add(a);
            }
        }

        tarjan(nodes[0], new ArrayList<>(n + 1));

        output.println(minRemove);
        for (int i = 1; i <= n; i++) {
            if (nodes[i].getRepr() == minLeaf) {
                output.print(i);
                output.print(' ');
            }
        }
    }

    public static void tarjan(Node node, List<Node> stk) {
        if (node.timestamp != 0) {
            return;
        }
        node.timestamp = ++idAllocator;
        node.inStack = true;
        node.lowest = node.timestamp;
        stk.add(node);

        for (Node neighbor : node.neighborList) {
            tarjan(neighbor, stk);

            if (neighbor.inStack && neighbor.lowest < node.lowest) {
                node.lowest = neighbor.lowest;
            }
        }

        if (node.lowest == node.timestamp) {
            int nodeIndex = stk.size() - 1;
            for (; ; nodeIndex--) {
                Node child = stk.get(nodeIndex);
                if (child == node) {
                    break;
                }
                Node.union(child, node);
            }
            boolean isLeaf = true;
            for (int i = stk.size() - 1; isLeaf && i >= nodeIndex; i--) {
                Node child = stk.get(i);
                for (Node neighbor : child.neighborList) {
                    if (neighbor.getRepr() != node.getRepr()) {
                        isLeaf = false;
                        break;
                    }
                }
            }

            if (isLeaf && stk.size() - nodeIndex < minRemove) {
                minRemove = stk.size() - nodeIndex;
                minLeaf = node.getRepr();
            }

            for (int i = stk.size() - 1; i >= nodeIndex; i--) {
                stk.remove(i);
            }
        }
    }

    public static class Node {
        List<Node> neighborList = new ArrayList<>(1);
        int timestamp;
        int lowest;
        boolean inStack;
        Node p = this;
        int rank;
        int hour;

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
            } else {
                a.p = b;
            }
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
            this(is, 8192);
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