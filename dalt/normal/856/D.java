
import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by dalt on 2018/4/1.
 */
public class CF856D {
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF856D.in"));
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
        int m = input.nextInteger();

        Node[] nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
            nodes[i].id = i;
        }

        for (int i = 2; i <= n; i++) {
            int id = input.nextInteger();
            Node father = nodes[id];
            father.children.add(nodes[i]);
            Node.join(father, nodes[i]);
        }

        for (int i = 1; i <= m; i++) {
            PseudoEdge edge = new PseudoEdge();
            edge.a = nodes[input.nextInteger()];
            edge.b = nodes[input.nextInteger()];
            edge.beauty = input.nextInteger();

            Node lca = Node.lca(edge.a, edge.b);
            lca.pseudoEdgeList.add(edge);
        }

        dpOnTree(nodes[1]);

        output.println(nodes[1].include);
    }


    public static void dpOnTree(Node node) {
        int notInclude = 0;
        for (Node child : node.children) {
            dpOnTree(child);
            notInclude += child.include;
        }

        long max = notInclude;
        for (PseudoEdge edge : node.pseudoEdgeList) {
            Node.getPath(edge.a, edge.b);
            Node.splay(edge.a);

            max = Math.max(max, edge.beauty + (notInclude - edge.a.sum));
        }
        node.include = max;
        node.notInclude = notInclude;
        node.pushUp();
    }


    public static class Node {
        static final Node NIL = new Node();

        static {
            NIL.highest = NIL;
            NIL.depth = Integer.MAX_VALUE;
            NIL.father = NIL;
            NIL.sum = 0;
        }

        int id;
        List<Node> children = new ArrayList<>();
        long include;
        long notInclude;
        List<PseudoEdge> pseudoEdgeList = new ArrayList<>();
        int depth;
        Node highest;
        Node left = NIL;
        Node right = NIL;
        Node father = NIL;
        long sum;
        boolean rev;
        Node pathFather = NIL;

        public static void join(Node father, Node child) {
            makeRoot(child);
            child.pathFather = father;
            child.depth = father.depth + 1;
        }

        public static void zig(Node x) {
            Node y = x.father;
            Node z = y.father;
            Node t = x.right;

            z.replaceChild(y, x);
            x.asRight(y);
            y.asLeft(t);

            y.pushUp();
        }

        public static void zag(Node x) {
            Node y = x.father;
            Node z = y.father;
            Node t = x.left;

            z.replaceChild(y, x);
            x.asLeft(y);
            y.asRight(t);

            y.pushUp();
        }

        public static void splay(Node x) {
            if (x == NIL) {
                return;
            }

            Node y, z;
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

                    if (y == z.left) {
                        if (x == y.left) {
                            zig(y);
                            zig(x);
                        } else {
                            zag(x);
                            zig(x);
                        }
                    } else {
                        if (x == y.left) {
                            zig(x);
                            zag(x);
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

        public static void access(Node x) {
            Node last = NIL;
            while (x != NIL) {
                splay(x);
                x.right.father = NIL;
                x.right.pathFather = x;
                x.asRight(last);
                x.pushUp();

                last = x;
                x = x.pathFather;
            }
        }

        public static void makeRoot(Node x) {
            access(x);
            Node.splay(x);
            x.reverse();
        }

        public static Node lca(Node a, Node b) {
            getPath(a, b);
            Node.splay(a);
            return a.highest;
        }

        public static void getPath(Node a, Node b) {
            makeRoot(a);
            access(b);
        }

        @Override
        public String toString() {
            return "" + id;
        }

        public void replaceChild(Node oldNode, Node newNode) {
            if (left == oldNode) {
                asLeft(newNode);
            } else {
                asRight(newNode);
            }
        }

        public void asRight(Node x) {
            right = x;
            x.father = this;
        }

        public void asLeft(Node x) {
            left = x;
            x.father = this;
        }

        public void pushUp() {
            sum = left.sum + right.sum + (include - notInclude);
            highest = this;
            if (highest.depth > left.highest.depth) {
                highest = left.highest;
            }
            if (highest.depth > right.highest.depth) {
                highest = right.highest;
            }
        }

        public void pushDown() {
            if (rev) {
                Node tmp = left;
                left = right;
                right = tmp;

                left.reverse();
                right.reverse();

                rev = false;
            }

            left.pathFather = pathFather;
            right.pathFather = pathFather;
        }

        public void reverse() {
            rev = !rev;
        }
    }

    public static class PseudoEdge {
        Node a;
        Node b;
        int beauty;

        @Override
        public String toString() {
            return a.toString() + ":" + b.toString() + ":" + beauty;
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