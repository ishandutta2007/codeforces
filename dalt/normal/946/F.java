
import java.io.*;

/**
 * Created by dalt on 2018/3/25.
 */
public class CF946F {
    public static BlockReader input;
    public static PrintStream output;
    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF946F.in"));
            output = System.out;
        }else{
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        solve();

        output.flush();
    }

    public static void solve() {
        int n = input.nextInteger();
        int x = input.nextInteger();
        String s = input.nextBlock();
        int slen = s.length();
        final long MOD = 1000000007;
        final int ALIGN_LEFT = 0;
        final int ALIGN_RIGHT = 1;
        final int ALIGN_CENTER = 2;
        final int ALIGN_LEFT_RIGHT = 3;

        long[][][][] dp = new long[Math.max(x + 1, 2)][slen + 1][slen + 1][4];
        long[] lengthes = new long[101];
        lengthes[0] = lengthes[1] = 1;

        for (int j = 0, bound = 2; j < bound; j++) {
            for (int i = 0; i <= slen; i++) {
                for (int k = 0; k < 4; k++) {
                    dp[j][i][i][ALIGN_LEFT] = 2;
                    dp[j][i][i][ALIGN_RIGHT] = 2;
                    dp[j][i][i][ALIGN_CENTER] = 2;
                    dp[j][i][i][ALIGN_LEFT_RIGHT] = 1;
                }
            }
        }

        for (int i = 0; i < slen; i++) {
            int c = s.charAt(i) - '0';
            dp[c][i][i + 1][ALIGN_LEFT] = 1;
            dp[c][i][i + 1][ALIGN_RIGHT] = 1;
            dp[c][i][i + 1][ALIGN_CENTER] = 1;
            dp[c][i][i + 1][ALIGN_LEFT_RIGHT] = 1;
        }

        for (int i = 2; i <= x; i++) {
            int last = i - 1;
            int last2 = i - 2;
            lengthes[i] = (lengthes[last] + lengthes[last2]) % (MOD - 1);

            long pLast = pow(2, lengthes[last], MOD);
            long pLast2 = pow(2, lengthes[last2], MOD);
            for (int j = 0; j <= slen; j++) {
                dp[i][j][j][ALIGN_LEFT] = pLast * pLast2 % MOD;
                dp[i][j][j][ALIGN_RIGHT] = dp[i][j][j][ALIGN_LEFT];
                dp[i][j][j][ALIGN_CENTER] = dp[i][j][j][ALIGN_LEFT];
                dp[i][j][j][ALIGN_LEFT_RIGHT] = 1;
                for (int k = j + 1; k <= slen; k++) {
                    dp[i][j][k][ALIGN_LEFT] = (dp[last][j][k][ALIGN_LEFT] * pLast2 + dp[last2][j][k][ALIGN_LEFT]) % MOD;
                    dp[i][j][k][ALIGN_RIGHT] = (dp[last][j][k][ALIGN_RIGHT] + pLast * dp[last2][j][k][ALIGN_RIGHT]) % MOD;
                    dp[i][j][k][ALIGN_CENTER] = (dp[last][j][k][ALIGN_CENTER] * pLast2 + pLast * dp[last2][j][k][ALIGN_CENTER]) % MOD;
                    dp[i][j][k][ALIGN_LEFT_RIGHT] = (dp[last][j][k][ALIGN_LEFT_RIGHT] + dp[last2][j][k][ALIGN_LEFT_RIGHT]) % MOD;
                    for (int sep = j + 1; sep < k; sep++) {
                        dp[i][j][k][ALIGN_LEFT] = (dp[i][j][k][ALIGN_LEFT] + dp[last][j][sep][ALIGN_LEFT_RIGHT] * dp[last2][sep][k][ALIGN_LEFT]) % MOD;
                        dp[i][j][k][ALIGN_RIGHT] = (dp[i][j][k][ALIGN_RIGHT] + dp[last][j][sep][ALIGN_RIGHT] * dp[last2][sep][k][ALIGN_LEFT_RIGHT]) % MOD;
                        dp[i][j][k][ALIGN_LEFT_RIGHT] = (dp[i][j][k][ALIGN_LEFT_RIGHT] + dp[last][j][sep][ALIGN_LEFT_RIGHT] * dp[last2][sep][k][ALIGN_LEFT_RIGHT]) % MOD;
                        dp[i][j][k][ALIGN_CENTER] = (dp[i][j][k][ALIGN_CENTER] + dp[last][j][sep][ALIGN_RIGHT] * dp[last2][sep][k][ALIGN_LEFT]) % MOD;
                    }
                }
            }
        }

         System.out.println(dp[x][0][slen][ALIGN_CENTER]);
    }

    public static long pow(long x, long n, long MOD) {
        int bit = 31;
        for (; bit >= 0 && (n & (1 << bit)) == 0; bit--) ;
        long product = 1;
        for (; bit >= 0; bit--) {
            product = (product * product) % MOD;
            if ((n & (1 << bit)) != 0) {
                product = (product * x) % MOD;
            }
        }
        return (int) product;
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