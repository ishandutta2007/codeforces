

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by Administrator on 2018/1/29.
 */
public class CF919D {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;
    public static int orderAllocator = 1;


    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            //   System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\916E.in"));
        }
        input = new BlockReader(System.in);

        int n = input.nextInteger();
        int m = input.nextInteger();
        Node[] nodes = new Node[n + 1];
        char[] sign = new char[n + 1];
        input.nextBlock(sign, 1);
        for (int i = 0; i <= n; i++) {
            nodes[i] = new Node();
            nodes[i].c = sign[i] - 'a';
            nodes[i].index = i;
        }

        for (int i = 1; i <= m; i++) {
            int a = input.nextInteger();
            int b = input.nextInteger();
            nodes[a].nodeList.add(nodes[b]);
        }

        for (int i = 1; i <= n; i++) {
            nodes[0].nodeList.add(nodes[i]);
        }

        if (findLoop(nodes[0])) {
            System.out.println("-1");
            return;
        }

        int max = 0;
        for (int i = 1; i <= n; i++) {
            memorySearch(nodes[i]);
            int[] dp = nodes[i].dp;
            for (int j = 0; j < 26; j++) {
                max = Math.max(max, dp[j]);
            }
        }

        System.out.println(max);
    }

    //Find loop
    public static boolean findLoop(Node node) {
        if (node.searched) {
            return node.instack;
        }

        node.searched = true;
        node.instack = true;

        for (Node child : node.nodeList) {
            if (findLoop(child)) {
                return true;
            }
        }

        node.instack = false;
        return false;
    }

    public static void memorySearch(Node node) {
        if (node.visited == false) {
            node.visited = true;
            for (Node near : node.nodeList) {
                memorySearch(near);

                for (int i = 0; i < 26; i++) {
                    node.dp[i] = Math.max(node.dp[i], near.dp[i]);
                }
            }

            node.dp[node.c]++;

        }
    }

    public static class Node {
        List<Node> nodeList = new ArrayList<>(2);
        int[] dp = new int[26];
        boolean visited = false;

        boolean searched;
        boolean instack;
        int c;

        int index;

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