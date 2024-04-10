

import java.io.*;

/**
 * Created by Administrator on 2018/3/24.
 */
public class CF956B {
    static final int INF = (int) 1e8;
    static final int MOD = (int) 1e9 + 7;
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF956B.in"));
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
        int m = input.nextInteger();
        char[][] data = new char[n][m];
        for (int i = 0; i < n; i++) {
            input.nextBlock(data[i], 0);
        }

        int[] rowValid = new int[n];
        int[] colValid = new int[m];
        for (int i = 0; i < n; i++) {
            tryRemoveRow(data, rowValid, colValid, i, i + 1);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (data[i][j] == '#' && rowValid[i] != colValid[j]) {
                    output.println("No");
                    return;
                }
                if (data[i][j] == '.' && rowValid[i] == colValid[j]) {
                    output.println("No");
                    return;
                }
            }
        }

        output.println("Yes");
        return;
    }

    public static boolean tryRemoveRow(char[][] data, int[] rowValid, int[] colValid, int i, int version) {
        if (rowValid[i] != 0) {
            return rowValid[i] == version;
        }
        rowValid[i] = version;
        for (int j = 0, until = colValid.length; j < until; j++) {
            if (data[i][j] == '#' && tryRemoveCol(
                    data, rowValid, colValid, j, version
            )) ;
        }
        return true;
    }

    public static boolean tryRemoveCol(char[][] data, int[] rowValid, int[] colValid, int j, int version) {
        if (colValid[j] != 0) {
            return colValid[j] == version;
        }
        colValid[j] = version;
        for (int i = 0, until = rowValid.length; i < until; i++) {
            if (data[i][j] == '#' && tryRemoveRow(
                    data, rowValid, colValid, i, version
            )) ;
        }
        return true;
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