
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/3/25.
 */
public class CF935E {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF935E.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }

    public static void solve() {
        char[] data = new char[10000];
        int len = input.nextBlock(data, 0);

        int p = input.nextInteger();
        int m = input.nextInteger();

        if (m <= p) {
            Node node = parseSubDp(data, new int[1]);
            System.out.println(node.dpMax[m]);
        }
        else{
            Node node = parsePlusDp(data, new int[1]);
            System.out.println(node.dpMax[p]);
        }
    }

    public static Node parsePlusDp(char[] data, int[] from) {
        if (data[from[0]] >= '0' && data[from[0]] <= '9') {
            from[0]++;
            return buildConstantNode(data[from[0] - 1] - '0');
        }
        from[0]++; //skip (
        Node node = new Node();
        node.left = parsePlusDp(data, from);
        from[0]++; //skip op
        node.right = parsePlusDp(data, from);
        from[0]++; //skip )

        node.opNum = 1 + node.left.opNum + node.right.opNum;

        for (int i = 0, bound = Math.min(node.opNum, 100); i <= bound; i++) {
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;

            //postive
            for (int left = 0; left < i; left++) {
                int right = i - 1 - left;
                if (left > node.left.opNum || right > node.right.opNum) {
                    continue;
                }
                max = Math.max(max, node.left.dpMax[left] + node.right.dpMax[right]);
                min = Math.min(min, node.left.dpMin[left] + node.right.dpMin[right]);
            }


            //negative
            for (int left = 0; left <= i; left++) {
                int right = i - left;
                if (left > node.left.opNum || right > node.right.opNum) {
                    continue;
                }
                max = Math.max(max, node.left.dpMax[left] - node.right.dpMin[right]);
                min = Math.min(min, node.left.dpMin[left] - node.right.dpMax[right]);
            }

            node.dpMax[i] = max;
            node.dpMin[i] = min;
        }

        return node;
    }

    public static Node parseSubDp(char[] data, int[] from) {
        if (data[from[0]] >= '0' && data[from[0]] <= '9') {
            from[0]++;
            return buildConstantNode(data[from[0] - 1] - '0');
        }
        from[0]++; //skip (
        Node node = new Node();
        node.left = parseSubDp(data, from);
        from[0]++; //skip op
        node.right = parseSubDp(data, from);
        from[0]++; //skip )

        node.opNum = 1 + node.left.opNum + node.right.opNum;

        for (int i = 0, bound = Math.min(node.opNum, 100); i <= bound; i++) {
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;

            //negative
            for (int left = 0; left < i; left++) {
                int right = i - 1 - left;
                if (left > node.left.opNum || right > node.right.opNum) {
                    continue;
                }
                max = Math.max(max, node.left.dpMax[left] - node.right.dpMin[right]);
                min = Math.min(min, node.left.dpMin[left] - node.right.dpMax[right]);
            }


            //positive
            for (int left = 0; left <= i; left++) {
                int right = i - left;
                if (left > node.left.opNum || right > node.right.opNum) {
                    continue;
                }
                max = Math.max(max, node.left.dpMax[left] + node.right.dpMax[right]);
                min = Math.min(min, node.left.dpMin[left] + node.right.dpMin[right]);
            }

            node.dpMax[i] = max;
            node.dpMin[i] = min;
        }

        return node;
    }

    public static Node buildConstantNode(int c) {
        Node node = new Node();
        node.opNum = 0;
        node.dpMax[0] = node.dpMin[0] = c;
        return node;
    }

    public static class Node {
        Node left;
        Node right;
        int opNum;
        int[] dpMax = new int[101];
        int[] dpMin = new int[101];
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