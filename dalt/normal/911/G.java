
import java.io.*;

/**
 * Created by dalt on 2018/4/5.
 */
public class CF911G {
    static final int INF = (int) 1e8;
    static final int MOD = (int) 1e9 + 7;
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF911G.in"));
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
        int[] data = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            data[i] = input.nextInteger() - 1;
        }

        Segment segment = Segment.makeTree(1, n);
        int q = input.nextInteger();
        for (int i = 0; i < q; i++) {
            int l = input.nextInteger();
            int r = input.nextInteger();
            int f = input.nextInteger() - 1;
            int t = input.nextInteger() - 1;
            Segment.update(l, r, 1, n, (byte) f, (byte) t, segment);
        }

        byte[][] maps = new byte[n + 1][];
        Segment.toArray(1, n, segment, maps);
        for (int i = 1; i <= n; i++) {
            output.print(maps[i][data[i]] + 1);
            output.print(' ');
        }
    }

    public static class Segment {
        Segment left;
        Segment right;
        boolean dirty;
        byte[] map = new byte[100];

        public static Segment makeTree(int l, int r) {
            Segment segment = new Segment();
            for (byte i = 0; i < 100; i++) {
                segment.map[i] = i;
            }
            if (l != r) {
                int m = (l + r) >> 1;
                segment.left = makeTree(l, m);
                segment.right = makeTree(m + 1, r);
            }
            return segment;
        }

        public static void update(int f, int t, int l, int r, byte origin, byte target, Segment segment) {
            if (t < l || f > r) {
                return;
            }
            if (f <= l && t >= r) {
                segment.set(origin, target);
                return;
            }
            segment.pushDown();
            int m = (l + r) >> 1;
            update(f, t, l, m, origin, target, segment.left);
            update(f, t, m + 1, r, origin, target, segment.right);
        }

        public static void toArray(int l, int r, Segment segment, byte[][] maps) {
            if (l == r) {
                maps[l] = segment.map;
                return;
            }
            segment.pushDown();
            int m = (l + r) >> 1;
            toArray(l, m, segment.left, maps);
            toArray(m + 1, r, segment.right, maps);
        }

        public void set(byte origin, byte target) {
            dirty = true;
            for (int i = 0; i < 100; i++) {
                if (map[i] == origin) {
                    map[i] = target;
                }
            }
        }

        public void pushDown() {
            if (dirty) {
                dirty = false;
                left.set(map);
                right.set(map);
                for (byte i = 0; i < 100; i++) {
                    map[i] = i;
                }
            }
        }

        public void set(byte[] data) {
            dirty = true;
            for (int i = 0; i < 100; i++) {
                map[i] = data[map[i]];
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
            this(is, 8192);
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