
import java.io.*;

/**
 * Created by Administrator on 2018/4/4.
 */
public class CF960D {
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
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF960D.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }
    }

    public static void solve() {
        int n = input.nextInteger();
        int[][] points = new int[n][2];
        for (int i = 0; i < n; i++) {
            points[i][0] = input.nextInteger();
            points[i][1] = input.nextInteger();
        }

        if (n <= 4) {
            output.println("YES");
            return;
        }

        //If 0 and 1 on same line


        for (int a = 0; a < 2; a++) {
            for (int b = a + 1; b <= 2; b++) {
                int[] line1 = new int[]{a, b};
                int[] line2 = new int[]{0, 0};
                int line2Len = 0;
                boolean flag = true;
                for (int i = 0; i < n; i++) {
                    if (i == a || i == b) {
                        continue;
                    }
                    if (inSameLine(points[line1[0]], points[line1[1]], points[i])) {
                        continue;
                    }
                    if (line2Len < 2) {
                        line2[line2Len++] = i;
                    } else {
                        if (!inSameLine(points[line2[0]], points[line2[1]], points[i])) {
                            flag = false;
                            break;
                        }
                    }
                }

                if (flag) {
                    output.println("YES");
                    return;
                }
            }
        }


        output.println("NO");
        return;
    }

    public static long cmul(long ax, long ay, long bx, long by) {
        return ax * by - bx * ay;
    }

    public static boolean inSameLine(int[] a, int[] b, int[] c) {
        return cmul(b[0] - a[0], b[1] - a[1], c[0] - a[0], c[1] - a[1]) == 0;
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