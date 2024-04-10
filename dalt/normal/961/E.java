
import java.io.*;

/**
 * Created by Administrator on 2018/4/4.
 */
public class CF960E {
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
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF960E.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }
    }

    public static void solve() {
        int n = input.nextInteger();
        int[] seasons = new int[n + 1];
        Node[] history = new Node[n + 1];
        history[0] = Node.build(0, n);
        for (int i = 1; i <= n; i++) {
            seasons[i] = Math.min(input.nextInteger(), n);
        }

        long sum = 0;
        for (int i = 1; i <= n; i++) {
            int endVersion = Math.min(i - 1, Math.max(0, seasons[i]));
            sum += Node.query(history[endVersion], i, n, 0, n);
            history[i] = Node.update(history[i - 1], seasons[i], 0, n, 1);
        }

        output.println(sum);
    }

    public static class Node implements Cloneable {
        Node left;
        Node right;
        int sum;

        public static Node build(int l, int r) {
            Node node = new Node();
            if (l != r) {
                int m = (l + r) >> 1;
                node.left = build(l, m);
                node.right = build(m + 1, r);
            }
            return node;
        }

        public static Node update(Node node, int x, int l, int r, int v) {
            if (x > r || x < l) {
                return node;
            }
            node = node.clone();
            if (x <= l && r <= x) {
                node.sum += v;
                return node;
            }
            int m = (l + r) >> 1;
            node.left = update(node.left, x, l, m, v);
            node.right = update(node.right, x, m + 1, r, v);
            node.pushUp();
            return node;
        }

        public static int query(Node node, int f, int t, int l, int r) {
            if (f > r || t < l) {
                return 0;
            }
            if (f <= l && r <= t) {
                return node.sum;
            }
            int m = (l + r) >> 1;
            return query(node.left, f, t, l, m) + query(node.right, f, t, m + 1, r);
        }

        @Override
        public Node clone() {
            try {
                return (Node) super.clone();
            } catch (CloneNotSupportedException e) {
                e.printStackTrace();
                return null;
            }
        }

        public void pushUp() {
            sum = left.sum + right.sum;
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