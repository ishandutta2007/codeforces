

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by Administrator on 2018/3/7.
 */
public class CF946G {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF946G.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }

    public static void solve() {
        int n = input.nextInteger();
        int[] data = new int[n + 1];
        int[] orderedData = new int[1 + 2 * n];
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            data[i] = input.nextInteger() - i;
            orderedData[2 * i - 1] = data[i];
            orderedData[2 * i] = data[i] - 1;
        }
        Arrays.sort(orderedData, 1, orderedData.length);
        int cnt = 1;
        map.put(orderedData[1], 1);
        for (int i = 1, bound = 2 * n; i <= bound; i++) {
            if (orderedData[i] == orderedData[i - 1]) {
                continue;
            }
            cnt++;
            map.put(orderedData[i], cnt);
        }

        Node leftPartNode = Node.build(1, cnt);
        Node rightPartNode = Node.build(1, cnt);
        int[] leftDp = new int[n + 1];

        int max = 0;
        for (int i = 1; i <= n; i++) {
            int no = map.get(data[i]);
            leftDp[i] = Node.queryMax(leftPartNode, 1, no, 1, cnt) + 1;
            Node.setMax(leftPartNode, no, no, 1, cnt, leftDp[i]);

            max = Math.max(max, leftDp[i]);
        }
        for (int i = n; i > 2; i--) {
            int no = map.get(data[i]);
            int dp = Node.queryMax(rightPartNode, no, cnt, 1, cnt) + 1;
            Node.setMax(rightPartNode, no, no, 1, cnt, dp);
            max = Math.max(max, leftDp[i - 2] + Node.queryMax(rightPartNode, map.get(data[i - 2] - 1), cnt, 1, cnt));
        }

        System.out.println(Math.max(n - max - 1, 0));
    }


    public static class Node {
        Node l;
        Node r;
        int max;
        boolean maxDirty;

        public static void setMax(Node node, int f, int t, int l, int r, int val) {
            if (f <= l && r <= t) {
                node.setMax(val);
                return;
            }
            node.pushDown();
            int m = (l + r) >> 1;
            if (f <= m) {
                setMax(node.l, f, t, l, m, val);
            }
            if (t > m) {
                setMax(node.r, f, t, m + 1, r, val);
            }
            node.pushUp();
        }

        public static int queryMax(Node node, int f, int t, int l, int r) {
            if (f > r || t < l) {
                return 0;
            }
            if (f <= l && r <= t) {
                return node.max;
            }
            node.pushDown();
            int m = (l + r) >> 1;
            return Math.max(queryMax(node.l, f, t, l, m), queryMax(node.r, f, t, m + 1, r));
        }

        public static Node build(int l, int r) {
            Node node = new Node();
            if (l != r) {
                int m = (l + r) >> 1;
                node.l = build(l, m);
                node.r = build(m + 1, r);
            }
            return node;
        }

        public void pushUp() {
            max = Math.max(l.max, r.max);
        }

        public void setMax(int max) {
            this.max = max;
            maxDirty = true;
        }

        public void pushDown() {
            if (maxDirty) {
                maxDirty = false;
                l.setMax(max);
                r.setMax(max);
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