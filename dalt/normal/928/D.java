
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/3/25.
 */
public class CF928D {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF928D.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }

    public static void solve() {
        char[] data = new char[300001];
        int len = 1;
        while (input.next != -1) {
            data[len++] = (char) input.next;
            input.next = input.nextByte();
        }


        Node root = new Node();
        Node trace = root;
        Node highest = null;
        Node meet = null;
        int minTypeNum = 0;

        for (int i = 1; i < len; i++) {
            if (data[i] < 'a' || data[i] > 'z') {
                if (data[i - 1] >= 'a' && data[i - 1] <= 'z') {

                    if (trace.containValue) {
                        Node tmp = trace;
                        while (trace != root) {
                            trace.subTreeSize--;
                            trace = trace.father;
                        }
                        trace = tmp;
                    }

                    trace.containValue = true;
                    minTypeNum += trace.depth;
                    if (highest != null && meet != null && meet.depth > highest.depth) {
                        minTypeNum += highest.depth + 1 - meet.depth;
                    }

                    trace = root;
                    highest = null;
                    meet = null;
                }
                if (data[i] == '\n' && data[i - 1] == '\r') {
                    minTypeNum--;
                }
                minTypeNum++;

                continue;
            }

            int c = data[i];
            if (trace.nodes[c] == null) {
                Node node = new Node();
                node.depth = trace.depth + 1;
                node.father = trace;
                trace.nodes[c] = node;
            } else {
                trace.nodes[c].subTreeSize++;
            }

            trace = trace.nodes[c];
            if (trace.subTreeSize == 2 && highest == null) {
                highest = trace;
            }
            if (trace.containValue) {
                meet = trace;
            }
        }

        if (data[len - 1] >= 'a' && data[len - 1] <= 'z') {
            trace.containValue = true;
            minTypeNum += trace.depth;
            if (highest != null && meet != null && meet.depth < highest.depth) {
                minTypeNum += highest.depth + 1 - meet.depth;
            }
        }

        System.out.println(minTypeNum);
    }


    public static class Node {
        Node[] nodes = new Node[128];
        int subTreeSize = 1;
        boolean containValue;
        Node father;
        int depth;
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