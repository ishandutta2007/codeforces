
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dalt on 2018/3/15.
 */
public class CF856B {
    public static BlockReader input;
    public static PrintStream output;
    public static Node[] nodes = new Node[1000000 + 1];
    public static int nodesTop;
    public static char[] data = new char[1000000];
    public static int[] ranges = new int[1000001];
    public static Node[] dataNodes = new Node[1000000];

    static {
        for (int i = 0, bound = nodes.length; i < bound; i++) {
            nodes[i] = new Node();
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF856B.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        for (int t = input.nextInteger(); t > 0; t--) {
            solve();
        }

        output.flush();
    }

    public static void solve() {
        nodesTop = 0;

        int n = input.nextInteger();
        for (int i = 1; i <= n; i++) {
            ranges[i] = ranges[i - 1] + input.nextBlock(data, ranges[i - 1]);
        }

        //Build tries
        Node root = allocate();
        for (int i = 1; i <= n; i++) {
            Node trace = root;
            for (int j = ranges[i - 1], bound = ranges[i]; j < bound; j++) {
                int c = data[j] - 'a';
                if (trace.next[c] == null) {
                    trace.next[c] = allocate();
                }
                trace = trace.next[c];
                dataNodes[j] = trace;
            }
        }

        //Build tree
        for (int i = 1; i <= n; i++) {
            int beginPos = ranges[i - 1];
            int endPos = ranges[i];

            Node trace1 = root.next[data[beginPos] - 'a'];
            Node trace2 = root;
            for (int j = beginPos + 1; j < endPos; j++) {
                int c = data[j] - 'a';
                if (trace2.next[c] == null) {
                    break;
                }
                trace1 = trace1.next[c];
                trace2 = trace2.next[c];

                if (trace1.father == null) {
                    trace1.father = trace2;
                    trace2.children.add(trace1);
                }
            }
        }

        //Dp on tree
        for (int i = 0, bound = ranges[n]; i < bound; i++) {
            if (dataNodes[i].father == null) {
                dataNodes[i].father = root;
                root.children.add(dataNodes[i]);
            }
        }

        dp(root);

        int max = root.notInclude;
        output.println(max);
    }

    public static Node allocate() {
        Node node = nodes[nodesTop++];
        node.init();
        return node;
    }

    public static void dp(Node node) {
        node.include = 1;
        node.notInclude = 0;

        for (Node child : node.children) {
            dp(child);

            node.include += child.notInclude;
            node.notInclude += Math.max(child.notInclude, child.include);
        }
    }

    public static class Node {
        Node[] next = new Node[26];
        Node father;
        int include;
        int notInclude;
        List<Node> children = new ArrayList<>();

        public void init() {
            include = notInclude = 0;
            children.clear();
            father = null;
            Arrays.fill(next, null);
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