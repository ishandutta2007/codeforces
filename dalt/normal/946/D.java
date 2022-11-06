

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Arrays;

/**
 * Created by Administrator on 2018/3/6.
 */
public class CF946D {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF946D.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }

    public static void solve() {
        char[] data = new char[501];
        final int INF = 100000000;
        int n = input.nextInteger();
        int m = input.nextInteger();
        int k = input.nextInteger();

        int[][] day = new int[n + 1][k + 1];
        int[] dp = new int[k + 1];
        int[] sum = new int[m + 1];
        for (int i = 1; i <= n; i++) {
            input.nextBlock(data, 1);
            Arrays.fill(dp, INF);
            sum[0] = 0;
            for (int j = 1; j <= m; j++) {
                sum[j] = data[j] - '0' + sum[j - 1];
            }

            for (int j = 1; j <= m; j++) {
                for (int t = j; t <= m; t++) {
                    int escape = sum[j - 1] + sum[m] - sum[t];
                    int time = t - j + 1;
                    if (escape <= k) {
                        dp[escape] = Math.min(dp[escape], time);
                    }
                }
            }

            if (sum[m] <= k) {
                dp[sum[m]] = 0;
            }

            Arrays.fill(day[i], INF);
            for (int j = k; j >= 0; j--) {
                for (int t = j; t >= 0; t--) {
                    day[i][j] = Math.min(day[i][j], day[i - 1][t] + dp[j - t]);
                }
            }
        }

        int min = INF;
        for (int i = 0; i <= k; i++) {
            min = Math.min(min, day[n][i]);
        }

        System.out.println(min);
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