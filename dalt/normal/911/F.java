

import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;


/**
 * Created by dalt on 2018/4/7.
 */
public class CF911F {
    static final int INF = (int) 1e8;
    static final int MOD = (int) 1e9 + 7;
    public static BlockReader input;
    public static PrintStream output;
    static int idAllocator = 0;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF911F.in"));
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
        Node[] nodes = new Node[n + 1];
        for (int i = 0; i <= n; i++) {
            nodes[i] = new Node();
            nodes[i].index = i;
        }
        for (int i = 1; i < n; i++) {
            Node a = nodes[input.nextInteger()];
            Node b = nodes[input.nextInteger()];
            a.nearby.add(b);
            b.nearby.add(a);
        }
        dfs1(nodes[1], nodes[0]);
        dfs2(nodes[1], nodes[0], nodes[1], 0);

        Node root = nodes[1];
        for (int i = 2; i <= n; i++) {
            if (root.distance < nodes[i].distance) {
                root = nodes[i];
            }
        }
        Deque<Node> deque = new ArrayDeque<>(n);
        findPath(root, null, root.farthest, deque);

        Node[] line = deque.toArray(new Node[0]);
        for (Node node : line) {
            node.visit = true;
        }
        for (int i = 0, until = line.length / 2; i < until; i++) {
            line[i].farthest = line[line.length - 1];
            line[i].distance = line.length - i - 1;
        }
        for (int i = line.length / 2, until = line.length; i < until; i++) {
            line[i].farthest = line[0];
            line[i].distance = i;
        }

        long sum = (long) line.length * (line.length - 1) / 2;

        List<Node> seq = new ArrayList<>(n);
        while (!deque.isEmpty()) {
            Node first = deque.removeFirst();
            seq.add(first);
            for (Node child : first.nearby) {
                if (child.visit) {
                    continue;
                }
                child.visit = true;
                child.farthest = first.farthest;
                child.distance = first.distance + 1;
                sum += child.distance;
                deque.addLast(child);
            }
        }

        output.println(sum);
        for (int i = n - 1, until = line.length; i >= until; i--) {
            Node node = seq.get(i);
            output.print(node.farthest.index);
            output.print(' ');
            output.print(node.index);
            output.print(' ');
            output.println(node.index);
        }

        for (int i = line.length - 1; i >= 1; i--) {
            Node node = line[i];
            output.print(line[0].index);
            output.print(' ');
            output.print(node.index);
            output.print(' ');
            output.println(node.index);
        }
    }

    public static void dfs1(Node root, Node father) {
        root.deepest = root.secondDeepest = root;
        root.maxId = root.id = idAllocator++;
        root.depth = father.depth + 1;
        for (Node child : root.nearby) {
            if (child == father) {
                continue;
            }
            dfs1(child, root);
            if (root.deepest.depth < child.deepest.depth) {
                root.deepest = child.deepest;
            } else if (root.secondDeepest.depth < child.deepest.depth) {
                root.secondDeepest = child.deepest;
            }
            root.maxId = child.maxId;
        }
    }

    public static void dfs2(Node root, Node father, Node farthest, int distance) {
        Node candidate;
        int candidateDistance;
        if (root.secondDeepest != root.deepest && root.secondDeepest.depth - root.depth > distance) {
            candidate = root.secondDeepest;
            candidateDistance = root.secondDeepest.depth - root.depth;
        } else {
            candidate = farthest;
            candidateDistance = distance;
        }

        if (root.deepest.depth - root.depth > distance) {
            farthest = root.deepest;
            distance = root.deepest.depth - root.depth;
        }
        root.farthest = farthest;
        root.distance = distance;


        for (Node child : root.nearby) {
            if (child == father) {
                continue;
            }
            if (child.id <= farthest.id && child.maxId >= farthest.id) {
                dfs2(child, root, candidate, candidateDistance + 1);
            } else {
                dfs2(child, root, farthest, distance + 1);
            }
        }
    }

    public static boolean findPath(Node root, Node father, Node target, Deque<Node> queue) {
        queue.addLast(root);
        if (root == target) {
            return true;
        }
        for (Node child : root.nearby) {
            if (child == father) {
                continue;
            }
            if (findPath(child, root, target, queue)) {
                return true;
            }
        }
        queue.removeLast();
        return false;
    }

    public static class Node {
        List<Node> nearby = new ArrayList<>(1);
        int index;
        Node deepest;
        Node secondDeepest;
        int depth;
        int id;
        int maxId;
        Node farthest;
        int distance;
        boolean visit = false;

        @Override
        public String toString() {
            return "" + index;
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