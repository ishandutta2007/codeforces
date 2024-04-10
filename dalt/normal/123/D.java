
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * Created by dalt on 2018/4/2.
 */
public class CF123D {
    public static final int MOD = (int) (1e9 + 7);
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {

        init();

        solve();

        output.flush();
    }

    public static void init() throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF123D.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }
    }

    public static void solve() {
        char[] data = new char[100000];
        int n = input.nextBlock(data, 0);

        SAM sam = new SAM();
        for (int i = 0; i < n; i++) {
            sam.build(data[i]);
        }

        long sum = 0;
        SAM.Node[] nodes = sam.nodeList.toArray(new SAM.Node[0]);
        Arrays.sort(nodes, new Comparator<SAM.Node>() {
            @Override
            public int compare(SAM.Node o1, SAM.Node o2) {
                return o2.maxlen - o1.maxlen;
            }
        });


        for (int i = 0, until = nodes.length; i < until; i++) {
            SAM.Node node = nodes[i];
            node.fail.cnt += node.cnt;
            sum += (long) node.cnt * (node.cnt + 1) / 2 * (node.maxlen - node.fail.maxlen);
        }

        output.println(sum);
    }

    public static class SAM {
        Node root;
        Node buildLast;
        Node matchLast;
        List<Node> nodeList = new ArrayList<>();

        public SAM() {
            buildLast = matchLast = root = new Node();
        }

        public void build(char c) {
            int index = c - 'a';
            Node now = new Node();
            now.cnt = 1;
            now.maxlen = buildLast.maxlen + 1;

            Node trace = replace(buildLast, now, null, index);
            if (trace == null) {
                now.fail = root;
            } else {
                Node q = trace.nodes[index];
                if (q.maxlen == trace.maxlen + 1) {
                    now.fail = q;
                } else {
                    Node clone = new Node(q);
                    clone.maxlen = trace.maxlen + 1;
                    q.fail = now.fail = clone;
                    clone.cnt = 0;
                    replace(trace, clone, q, index);
                    nodeList.add(clone);
                }
            }

            buildLast = now;
            nodeList.add(now);
        }

        public static Node replace(Node start, Node newNode, Node oldNode, int index) {
            while (start != null && start.nodes[index] == oldNode) {
                start.nodes[index] = newNode;
                start = start.fail;
            }
            return start;
        }

        public static class Node {
            Node[] nodes = new Node[26];
            Node fail;
            int maxlen;
            int cnt;

            public Node() {
            }

            public Node(Node other) {
                for (int i = 0; i < 26; i++) {
                    nodes[i] = other.nodes[i];
                }
                fail = other.fail;
                maxlen = other.maxlen;
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