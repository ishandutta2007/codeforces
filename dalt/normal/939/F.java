

import java.io.*;
import java.util.Arrays;

/**
 * Created by dalt on 2018/3/14.
 */
public class CF939F {
    public static final int INF = (int) 1e8;
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF939F.in"));
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
        int k = input.nextInteger();

        int[][] intervals = new int[k + 2][2];
        for (int i = 1; i <= k; i++) {
            intervals[i][0] = input.nextInteger();
            intervals[i][1] = input.nextInteger();
        }
        intervals[k + 1][0] = 2 * n;
        intervals[k + 1][1] = 2 * n;

        k++;

        Node[] loop = new Node[2];
        loop[0] = Node.build(0, n);
        loop[1] = Node.build(0, n);

        int[] data = new int[n + 1];

        for (int i = 1; i <= k; i++) {
            Node curDp = loop[i & 1];

            Node lastDp = loop[(i - 1) & 1];


            int[] interval = intervals[i];
            int intervalLength = interval[1] - interval[0];
            int middleLength = interval[0] - intervals[i - 1][1];

            Node.toArray(0, n, data, lastDp);
            System.arraycopy(data, 0, data, Math.min(data.length, intervalLength + middleLength), Math.max(0, n + 1 - (intervalLength + middleLength)));
            Arrays.fill(data, 0, Math.min(data.length, intervalLength + middleLength), INF);

            //No flip
/*            for (int j = intervalLength + middleLength; j <= n; j++) {
                int lastFryTotalTime = j - intervalLength - middleLength;
                int minNeedTime = Node.query(lastFryTotalTime, lastFryTotalTime, 0, n, lastDp);
                Node.update(j, 0, n, minNeedTime, curDp);
            }*/


            int minX = interval[1] - middleLength - intervalLength;
            int maxX = interval[1] - middleLength;
            for (int j = 0; j <= n; j++) {
                //Flip once
                int minNeedTime = Node.query(minX - j, maxX - j, 0, n, lastDp);
                data[j] = Math.min(data[j], minNeedTime + 1);
               // Node.update(j, 0, n, minNeedTime + 1, curDp);
            }

            for (int j = 0; j <= n; j++) {
                //Flip twice
                int minNeedTime = Node.query(j - middleLength - intervalLength, j - middleLength, 0, n, lastDp);
                //Node.update(j, 0, n, minNeedTime + 2, curDp);
                data[j] = Math.min(data[j], minNeedTime + 2);
            }

            Node.fromArray(0, n, data, curDp);
        }

        int minFlipTime = Node.query(n, n, 0, n, loop[k & 1]);

        if (minFlipTime < INF) {
            output.println("Full");
            output.println(minFlipTime);
        } else {
            output.println("Hungry");
        }
    }


    public static class Node {
        Node left;
        Node right;
        int batchSetValue;
        boolean dirty;
        int min;

        public static void setValue(int f, int t, int l, int r, int val, Node node) {
            if (f > r || t < l) {
                return;
            }
            if (f <= l && t >= r) {
                node.setValue(val);
                return;
            }

            node.pushDown();
            int m = (l + r) >> 1;
            setValue(f, t, l, m, val, node.left);
            setValue(f, t, m + 1, r, val, node.right);

            node.pushUp();
        }

        public static Node build(int l, int r) {
            Node node = new Node();
            if (l != r) {
                int m = (l + r) >> 1;
                node.left = build(l, m);
                node.right = build(m + 1, r);
            }
            return node;
        }

        public static int query(int f, int t, int l, int r, Node node) {
            if (f > r || t < l) {
                return INF;
            }
            if (f <= l && r <= t) {
                return node.min;
            }
            node.pushDown();
            int m = (l + r) >> 1;
            return Math.min(query(f, t, l, m, node.left), query(f, t, m + 1, r, node.right));
        }

        public static void update(int i, int l, int r, int val, Node node) {
            if (i > r || i < l) {
                return;
            }
            if (i <= l && i >= r) {
                node.min = Math.min(node.min, val);
                return;
            }

            node.pushDown();
            int m = (l + r) >> 1;
            update(i, l, m, val, node.left);
            update(i, m + 1, r, val, node.right);

            node.pushUp();
        }

        public static void toArray(int l, int r, int[] data, Node node) {
            if (l == r) {
                data[l] = node.min;
                return;
            }
            node.pushDown();
            int m = (l + r) >> 1;
            toArray(l, m, data, node.left);
            toArray(m + 1, r, data, node.right);
        }

        public static void fromArray(int l, int r, int[] data, Node node) {
            if (l == r) {
                node.min = data[l];
                return;
            }

            node.dirty = false;
            int m = (l + r) >> 1;
            fromArray(l, m, data, node.left);
            fromArray(m + 1, r, data, node.right);
            node.pushUp();
        }

        public void pushUp() {
            this.min = Math.min(left.min, right.min);
        }

        public void setValue(int val) {
            this.min = val;
            this.batchSetValue = val;
            this.dirty = true;
        }

        public void pushDown() {
            if (dirty) {
                left.setValue(batchSetValue);
                right.setValue(batchSetValue);
                dirty = false;
            }
        }

        @Override
        public String toString() {
            int t = 100;
            int[] data = new int[t + 1];
            for (int i = 0; i <= t; i++) {
                data[i] = query(i, i, 0, t, this);
            }
            return Arrays.toString(data);
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