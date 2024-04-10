

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

public class CF916E {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;
    public static int orderAllocator = 1;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\916E.in"));
        }
        input = new BlockReader(System.in);
        StringBuilder builder = new StringBuilder();

        int n = input.nextInteger();
        int q = input.nextInteger();
        Node[] nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
            nodes[i].id = i;
            nodes[i].val = input.nextInteger();
        }
        for (int i = 1; i < n; i++) {
            Node n1 = nodes[input.nextInteger()];
            Node n2 = nodes[input.nextInteger()];
            n1.neighbors.add(n2);
            n2.neighbors.add(n1);
        }

        buildTree(nodes[1], null, 0);
        int[] values = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            values[nodes[i].order] = nodes[i].val;
        }
        IntervalTree intervalTree = new IntervalTree(1, n, values);

        Node root = nodes[1];
        for (int i = 1; i <= q; i++) {
            switch (input.nextInteger()) {
                case 1: {
                    //1 v
                    int v = input.nextInteger();
                    root = nodes[v];
                }
                break;
                case 2: {
                    //2 u v x
                    Node u = nodes[input.nextInteger()];
                    Node v = nodes[input.nextInteger()];
                    int x = input.nextInteger();

                    Node lca = findLca(u, v);
                    if (lca == root || (root.contain(u) != root.contain(v))) {
                        intervalTree.update(nodes[1].order, nodes[1].subTreeEndOrder - 1, x);
                    } else if (root.contain(lca) || !lca.contain(root)) {
                        intervalTree.update(lca.order, lca.subTreeEndOrder - 1, x);
                    } else {
                        intervalTree.update(nodes[1].order, nodes[1].subTreeEndOrder - 1, x);
                        Node lcau = findLca(root, u);
                        Node lcav = findLca(root, v);
                        Node ancestor = ancestorOfXButChildOfY(root, lcau.depth > lcav.depth ? lcau : lcav);
                        intervalTree.update(ancestor.order, ancestor.subTreeEndOrder - 1, -x);
                    }
                }
                break;
                case 3: {
                    //3 u
                    Node u = nodes[input.nextInteger()];
                    long sum;
                    if (u == root) {
                        sum = intervalTree.query(nodes[1].order, nodes[1].subTreeEndOrder - 1);
                    } else if (root.contain(u) || !u.contain(root)) {
                        sum = intervalTree.query(u.order, u.subTreeEndOrder - 1);
                    } else {
                        Node ancestor = ancestorOfXButChildOfY(root, u);
                        sum = intervalTree.query(nodes[1].order, nodes[1].subTreeEndOrder - 1)
                                - intervalTree.query(ancestor.order, ancestor.subTreeEndOrder - 1);
                    }
                    builder.append(sum).append('\n');
                }
                break;
            }
        }

        System.out.print(builder.toString());
    }

    public static void buildTree(Node node, Node father, int depth) {
        node.fatherLink[0] = father;
        for (int i = 0; node.fatherLink[i] != null; i++) {
            node.fatherLink[i + 1] = node.fatherLink[i].fatherLink[i];
        }

        node.neighbors.remove(father);
        node.depth = depth;
        node.order = orderAllocator++;
        for (Node next : node.neighbors) {
            buildTree(next, node, depth + 1);
        }
        node.subTreeEndOrder = orderAllocator;
    }

    public static Node findLca(Node a, Node b) {
        if (a.depth < b.depth) {
            Node tmp = a;
            a = b;
            b = tmp;
        }

        int depthDiffer = a.depth - b.depth;
        for (int i = 0; depthDiffer != 0; i++) {
            int bit = (depthDiffer >> i) & 1;
            if (bit == 1) {
                a = a.fatherLink[i];
                depthDiffer ^= 1 << i;
            }
        }

        for (int i = 19; i >= 0 && a != b; i--) {
            if (a.fatherLink[i] != b.fatherLink[i]) {
                a = a.fatherLink[i];
                b = b.fatherLink[i];
            }
        }

        return a == b ? a : a.fatherLink[0];
    }

    public static Node ancestorOfXButChildOfY(Node x, Node y) {
        int depthDiffer = x.depth - 1 - y.depth;
        for (int i = 0; depthDiffer != 0; i++) {
            int bit = (depthDiffer >> i) & 1;
            if (bit == 1) {
                x = x.fatherLink[i];
                depthDiffer ^= 1 << i;
            }
        }
        return x;
    }

    public static class IntervalTree {
        int intervalLeft;
        int intervalRight;
        Node root;

        public IntervalTree(int l, int r, int[] initData) {
            intervalLeft = l;
            intervalRight = r;
            root = build(l, r, initData);
        }

        public void update(int from, int to, int val) {
            update(from, to, val, intervalLeft, intervalRight, root);
        }

        public void update(int from, int to, int val, int l, int r, Node node) {
            if (from <= l && to >= r) {
                node.markDirty(val, l, r);
                return;
            }

            node.pushDown(l, r);
            int mid = (l + r) >> 1;
            if (mid >= from) {
                update(from, to, val, l, mid, node.left);
            }
            if (mid < to) {
                update(from, to, val, mid + 1, r, node.right);
            }

            node.pushUp();
        }

        public long query(int from, int to) {
            return query(from, to, intervalLeft, intervalRight, root);
        }

        public long query(int from, int to, int l, int r, Node node) {
            if (from <= l && to >= r) {
                return node.sum;
            }
            node.pushDown(l, r);
            long sum = 0;
            int mid = (l + r) >> 1;
            if (mid >= from) {
                sum += query(from, to, l, mid, node.left);
            }
            if (mid < to) {
                sum += query(from, to, mid + 1, r, node.right);
            }

            return sum;
        }

        public Node build(int l, int r, int[] initData) {
            Node node = new Node();
            if (l == r) {
                node.sum = initData[l];
            } else {
                int mid = (l + r) >> 1;
                node.left = build(l, mid, initData);
                node.right = build(mid + 1, r, initData);
                node.pushUp();
            }
            return node;
        }

        public static class Node {
            Node left;
            Node right;
            long sum;
            long dirty;

            void pushUp() {
                sum = left.sum + right.sum;
            }

            void pushDown(int l, int r) {
                int half = (l + r) >> 1;
                left.markDirty(dirty, l, half);
                right.markDirty(dirty, half + 1, r);
                dirty = 0;
            }

            void markDirty(long fix, int l, int r) {
                dirty += fix;
                sum += fix * (r - l + 1);
            }
        }
    }

    public static class Node {
        List<Node> neighbors = new ArrayList<>();
        Node[] fatherLink = new Node[20];
        int depth;
        int id;
        int val;
        int order;
        int subTreeEndOrder;

        boolean contain(Node other) {
            return other.order >= order && other.order < subTreeEndOrder;
        }

        @Override
        public String toString() {
            return "" + id;
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

        public void skipBlank() {
            while (Character.isWhitespace(next)) {
                next = nextByte();
            }
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

        public int nextByte() {
            while (dPos >= dSize) {
                if (dSize == -1) {
                    return EOF;
                }
                dPos = 0;
                try {
                    dSize = is.read(dBuf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return dBuf[dPos++];
        }
    }
}