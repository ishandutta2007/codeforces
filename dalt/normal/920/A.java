

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Created by Administrator on 2018/1/29.
 */
public class CF920A {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;
    public static int orderAllocator = 1;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            //   System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\916E.in"));
        }
        input = new BlockReader(System.in);

        for (int i = 0, t = input.nextInteger(); i < t; i++) {
            solve();
        }
    }

    public static void solve() {
        int n = input.nextInteger();
        int k = input.nextInteger();

        Deque<Node> deque = new ArrayDeque<>();
        Node[] nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
            nodes[i].id = i;
        }

        for (int i = 1; i <= k; i++) {
            Node node = nodes[input.nextInteger()];
            deque.addLast(node);
            node.stamp = 1;
            node.visited = true;
        }

        int time = 0;
        while (!deque.isEmpty()) {
            Node head = deque.removeFirst();
            time = Math.max(time, head.stamp);

            if (head.id > 1 && nodes[head.id - 1].visited == false) {
                deque.addLast(nodes[head.id - 1]);
                nodes[head.id - 1].visited = true;
                nodes[head.id - 1].stamp = head.stamp + 1;
            }
            if (head.id < n && nodes[head.id + 1].visited == false) {
                deque.addLast(nodes[head.id + 1]);
                nodes[head.id + 1].visited = true;
                nodes[head.id + 1].stamp = head.stamp + 1;
            }
        }

        System.out.println(time);
    }

    public static class Node {
        boolean visited;
        int stamp;
        int id;
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