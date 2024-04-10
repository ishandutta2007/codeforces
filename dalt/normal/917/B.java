

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/1/30.
 */
public class CF917B {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    static final int WIN = 1;
    static final int LOSE = 2;
    static final int MAX = 0;
    static final int LUCAS = 1;
    public static BlockReader input;
    static int[][] edgeMat;
    static int[][][][] dp;
    static int n;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF917B.in"));
        }
        input = new BlockReader(System.in);

        n = input.nextInteger();
        int m = input.nextInteger();

        edgeMat = new int[n + 1][n + 1];

        char[] c = new char[1];
        for (int i = 1; i <= m; i++) {
            int a = input.nextInteger();
            int b = input.nextInteger();
            input.nextBlock(c, 0);
            edgeMat[a][b] = c[0] - 'a' + 1;
        }

        dp = new int[2][27][n + 1][n + 1];
        StringBuilder builder = new StringBuilder((n + 1) * (n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                builder.append(memorySearch(0, 1, i, j) == WIN ? "A" : "B");
            }
            builder.append('\n');
        }

        System.out.print(builder);
    }

    public static int memorySearch(int who, int lastRoadChar, int maxWhere, int lucasWhere) {
        if (dp[who][lastRoadChar][maxWhere][lucasWhere] == 0) {
            dp[who][lastRoadChar][maxWhere][lucasWhere] = LOSE;
            if (who == MAX) {
                for (int i = 1; i <= n; i++) {
                    if (edgeMat[maxWhere][i] >= lastRoadChar && memorySearch(LUCAS, edgeMat[maxWhere][i], i, lucasWhere) == LOSE) {
                        dp[who][lastRoadChar][maxWhere][lucasWhere] = WIN;
                        break;
                    }
                }
            } else {
                for (int i = 1; i <= n; i++) {
                    if (edgeMat[lucasWhere][i] >= lastRoadChar && memorySearch(MAX, edgeMat[lucasWhere][i], maxWhere, i) == LOSE) {
                        dp[who][lastRoadChar][maxWhere][lucasWhere] = WIN;
                        break;
                    }
                }
            }
        }
        return dp[who][lastRoadChar][maxWhere][lucasWhere];
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