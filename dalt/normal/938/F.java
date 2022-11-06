

import java.io.*;
import java.util.Arrays;

/**
 * Created by dalt on 2018/4/1.
 */
public class CF938F {
    static final int INF = (int) 1e8;
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF938F.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        solve();

        output.flush();
    }

    public static void solve() {
        char[] data = input.nextBlock().toCharArray();
        int n = data.length;

        int k = log2(n);
        int maxMask = (1 << k) - 1;
        int remain = n - maxMask;

        int[][] dp = new int[remain + 1][n + 1];
        int[] bestEndingChar = new int[remain + 1];
        Arrays.fill(bestEndingChar, 1, remain + 1, INF);

        for (int i = maxMask + 1; i <= n; i++) {
            dp[0][i] = INF;
        }
        for (int i = 1; i <= remain; i++) {
            int lastI = i - 1;
            //len > maxMask + i
            for (int len = i, until = maxMask + i; len <= until; len++) {
                //len - mask == i
                int totalMask = len - i;
                int min = INF;

                char endChar = data[len - 1];

                //Special handle for mask=0
                if (dp[lastI][len - 1] == bestEndingChar[lastI]) {
                    min = Math.min(min, endChar);
                }


                for (int j = 0; j <= k; j++) {
                    int mask = 1 << j;
                    if (!subclass(mask, totalMask)) {
                        continue;
                    }

                    int lastMask = totalMask - mask;
                    int lastLength = lastI + lastMask;

                    //Ends with the minimum char
                    if (dp[lastI][lastLength] == bestEndingChar[lastI]) {
                        min = Math.min(min, endChar);
                    }
                    //Not ends with the minimum char
                    min = Math.min(min, dp[i][len - mask]);
                }

                dp[i][len] = min;
                bestEndingChar[i] = Math.min(bestEndingChar[i], min);
            }
        }

        for (int i = 1; i <= remain; i++) {
            output.print((char) bestEndingChar[i]);
        }
    }

    public static int log2(int n) {
        return 31 - Integer.numberOfLeadingZeros(n);
    }

    public static boolean subclass(int sub, int cls) {
        return (sub & cls) == sub;
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