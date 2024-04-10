

import java.io.*;

/**
 * Created by Administrator on 2018/4/4.
 */
public class CF960C {
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
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF960C.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }
    }

    public static void solve() {
        int n = input.nextInteger();

        char[][][] board = new char[4][n][n];
        for (int i = 0; i < 4; i++) {
            for (int r = 0; r < n; r++) {
                input.nextBlock(board[i][r], 0);
            }
        }

        int[][] dp = new int[4][2];
        for (int i = 0; i < 4; i++) {
            int paint1 = 0;
            int paint2 = 0;
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    char color = board[i][r][c];
                    if ((color - '0') == (r + c) % 2) {
                        paint2++;
                    } else {
                        paint1++;
                    }
                }
            }
            dp[i][0] = paint1;
            dp[i][1] = paint2;
        }

        int min = Integer.MAX_VALUE;
        for (int i1 = 0; i1 <= 1; i1++) {
            for (int i2 = 0; i2 <= 1; i2++) {
                for (int i3 = 0; i3 <= 1; i3++) {
                    for (int i4 = 0; i4 <= 1; i4++) {
                        if (i1 + i2 + i3 + i4 != 2) {
                            continue;
                        }
                        min = Math.min(min, dp[0][i1] + dp[1][i2] + dp[2][i3] + dp[3][i4]);
                    }
                }
            }
        }

        output.println(min);
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