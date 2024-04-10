
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by Administrator on 2018/1/29.
 */
public class CF920E {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;
    public static int orderAllocator = 1;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF920E.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }

    public static void solve() {
        int n = input.nextInteger();
        int m = input.nextInteger();
        Node[] nodes = new Node[n + 1];

        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
            nodes[i].id = i;
        }
        for (int i = 1; i <= m; i++) {
            Node a = nodes[input.nextInteger()];
            Node b = nodes[input.nextInteger()];
            a.nodes.add(b);
            b.nodes.add(a);
        }
        for (int i = 2; i <= n; i++) {
            nodes[i].former = nodes[i - 1];
            nodes[i - 1].next = nodes[i];
        }


        Node hTrace = nodes[1];
        while (hTrace != Node.NIL) {
            Node vTrace = hTrace;
            while (vTrace != Node.NIL) {
                Node nextTrace = hTrace.next;
                Node next = hTrace.next;
                while (nextTrace != Node.NIL) {
                    if (!vTrace.nodes.contains(nextTrace)) {
                        Node tmp = next;
                        nextTrace = next = next.next;
                        tmp.remove();
                        vTrace.append(tmp);
                    } else {
                        nextTrace = nextTrace.tail;
                        if (nextTrace == Node.NIL) {
                            nextTrace = next = next.next;
                        }
                    }
                }
                vTrace = vTrace.tail;
            }
            hTrace = hTrace.next;
        }

        int[] cnt = new int[n];
        int len = 0;
        for (Node i = nodes[1]; i != Node.NIL; i = i.next) {
            int sum = 0;
            for (Node j = i; j != Node.NIL; j = j.tail) {
                sum++;
            }
            cnt[len++] = sum;
        }

        Arrays.sort(cnt, 0, len);
        StringBuilder result = new StringBuilder();
        result.append(len).append('\n');
        for (int i = 0; i < len; i++) {
            result.append(cnt[i]).append(' ');
        }
        result.append('\n');
        System.out.println(result);
    }

    public static class Node {
        public static Node NIL = new Node();
        Node father;
        Node next = NIL;
        Node former = NIL;
        Set<Node> nodes = new HashSet();
        Node tail = NIL;
        int id;

        @Override
        public String toString() {
            return "" + id;
        }

        public void append(Node node) {
            node.tail = tail;
            tail = node;
        }

        public void remove() {
            former.next = next;
            next.former = former;
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