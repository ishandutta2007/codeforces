

import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * Created by dalt on 2018/4/3.
 */
public class CF161D {
    public static final int MOD = (int) (1e9 + 7);
    public static BlockReader input;
    public static PrintStream output;
    public static int[] depthCnt = new int[501];
    public static LinkedList<Node> seq = new LinkedList<Node>(0);
    public static LinkedList<Node> subseq = new LinkedList<Node>(0);

    public static void main(String[] args) throws FileNotFoundException {

        init();

        solve();

        output.flush();
    }

    public static void init() throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF161D.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }
    }

    public static void solve() {
        int n = input.nextInteger();
        int k = input.nextInteger();

        Node[] nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
            nodes[i].id = i;
        }

        for (int i = 1; i < n; i++) {
            Node a = nodes[input.nextInteger()];
            Node b = nodes[input.nextInteger()];
            a.children.add(b);
            b.children.add(a);
        }

        output.println(dac(nodes[1], k));
    }

    public static int dac(Node root, int k) {
        dfs1(root, null);
        root = dfs2(root, root, root.size / 2);

        depthCnt[0] = 1;
        int sum = 0;
        for (Node child : root.children) {
            child.children.remove(root);
            dfs3(child, root, 1, subseq);

            for (Node e : subseq) {
                if (e.depth > k) {
                    continue;
                }
                sum += depthCnt[k - e.depth];
            }

            while (!subseq.isEmpty()) {
                Node e = subseq.removeLast();
                if (e.depth <= k) {
                    depthCnt[e.depth]++;
                }
                seq.addLast(e);
            }
        }
        while (!seq.isEmpty()) {
            Node e = seq.removeLast();
            if (e.depth <= k) {
                depthCnt[e.depth]--;
            }
        }

        for (Node child : root.children) {
            sum += dac(child, k);
        }

        return sum;
    }

    public static void dfs1(Node root, Node father) {
        int size = 1;
        int childSize = 0;
        for (Node node : root.children) {
            if (node == father) {
                continue;
            }
            dfs1(node, root);
            size += node.size;
            childSize = Math.max(childSize, node.size);
        }
        root.size = size;
        root.childSize = childSize;
    }

    public static Node dfs2(Node root, Node father, int limit) {
        root.childSize = Math.max(root.childSize, father.size - root.size);
        if (root.childSize <= limit) {
            return root;
        }
        for (Node node : root.children) {
            if (node == father) {
                continue;
            }
            Node r = dfs2(node, root, limit);
            if (r != null) {
                return r;
            }
        }
        return null;
    }

    public static void dfs3(Node root, Node father, int depth, LinkedList list) {
        root.depth = depth;
        list.addLast(root);
        for (Node node : root.children) {
            if (node == father) {
                continue;
            }
            dfs3(node, root, depth + 1, list);
        }
    }


    public static class Node extends LinkedList.LinkedNode {
        int id;

        List<Node> children = new ArrayList<>(1);

        int size;
        int childSize;
        int depth;

        public Node() {
            super(1);
        }
    }

    public static class LinkedList<T extends LinkedList.LinkedNode> implements Iterable<T>, Iterator<T> {
        LinkedNode head;
        int id;
        LinkedNode iter;

        public LinkedList(int id) {
            this.id = id;
            head = new LinkedNode(id + 1);
            head.next[id] = head.prev[id] = head;
        }

        @Override
        public Iterator<T> iterator() {
            iter = head.next[id];
            return this;
        }

        @Override
        public boolean hasNext() {
            return iter != head;
        }

        @Override
        public T next() {
            T t = (T) iter;
            iter = iter.next[id];
            return t;
        }

        public boolean isEmpty() {
            return head.next[id] == head;
        }

        public T removeLast() {
            T last = (T) head.prev[id];
            remove(last);
            return last;
        }

        public void remove(T node) {
            node.prev[id].next[id] = node.next[id];
            node.next[id].prev[id] = node.prev[id];
        }

        public void addLast(T node) {
            addAfter(head.prev[id], node);
        }

        private void addAfter(LinkedNode former, LinkedNode later) {
            later.next[id] = former.next[id];
            former.next[id].prev[id] = later;

            later.prev[id] = former;
            former.next[id] = later;
        }

        public static class LinkedNode {
            LinkedNode[] prev = new LinkedNode[1];
            LinkedNode[] next = new LinkedNode[1];

            public LinkedNode(int cap) {
                this.prev = new LinkedNode[cap];
                this.next = new LinkedNode[cap];
            }
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

        public long nextLong() {
            skipBlank();
            long ret = 0;
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