
import java.io.*;

/**
 * Created by dalt on 2018/4/7.
 */
public class CF900E {
    static final int INF = (int) 1e8;
    static final int MOD = (int) 1e9 + 7;
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        init();

        solve();

        output.flush();
    }

    public static void init() throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF900E.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }
    }

    public static void solve() {
        int n = input.nextInteger();
        char[] data = new char[1 + n];
        input.nextBlock(data, 1);

        int t = input.nextInteger();

        if (n < t) {
            output.println(0);
            return;
        }



        final int A = 0;
        final int B = 1;
        final int ANY = 2;

        int endEnum = t % 2 == 0 ? B : A;

        int[][] allow = new int[n + 1][3];
        for (int i = 1; i <= n; i++) {
            switch (data[i]) {
                case 'a':
                    allow[i][A] = Math.max(allow[i - 1][B], allow[i - 1][ANY]) + 1;
                    break;
                case 'b':
                    allow[i][B] = Math.max(allow[i - 1][A], allow[i - 1][ANY]) + 1;
                    break;
                case '?':
                    allow[i][A] = Math.max(allow[i - 1][B], allow[i - 1][ANY]) + 1;
                    allow[i][B] = Math.max(allow[i - 1][A], allow[i - 1][ANY]) + 1;
                    allow[i][ANY] = allow[i - 1][ANY] + 1;
                    break;
            }
        }

        int sum = 0;
        for (int i = 1; i < t; i++) {
            if (data[i] != '?') {
                sum++;
            }
        }


        int[][] dp = new int[n + 1][2];
        for (int i = t; i <= n; i++) {
            if (data[i] != '?') {
                sum++;
            }


            int available = Math.max(allow[i][endEnum], allow[i][ANY]);
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            if (available >= t) {
                int j = i - t;
                int newCost = dp[j][1] + t - sum;
                if (dp[i][0] < dp[j][0] + 1 || (dp[i][0] == dp[j][0] + 1 && dp[i][1] > newCost)) {
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = newCost;
                }
            }

            if (data[i - t + 1] != '?') {
                sum--;
            }
        }

        output.println(dp[n][1]);
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