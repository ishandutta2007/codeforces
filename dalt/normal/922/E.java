

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/3/20.
 */
public class CF922E {

    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;
    public static long INF = (long) 1e16;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF922E.in"));
        }
        input = new BlockReader(System.in);

        int n = input.nextInteger();//the number of trees,
        int w = input.nextInteger();//the initial points of mana,
        int b = input.nextInteger();//the number of points the mana capacity increases after a bird is summoned,
        int x = input.nextInteger();//and the number of points restored when Imp moves from a tree to the next one.

        int[] cnts = new int[n + 1];
        int total = 0;
        for (int i = 1; i <= n; i++) {
            cnts[i] = input.nextInteger();
            total += cnts[i];
        }
        int[] costs = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            costs[i] = input.nextInteger();
        }
        long[] dp = new long[total + 1];
        dp[0] = w - x;
        long[] cap = new long[total + 1];
        cap[0] = w;
        for (int i = 1; i <= total; i++) {
            cap[i] = cap[i - 1] + b;
        }
        int possible = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= possible; j++) {
                dp[j] = Math.min(dp[j] + x, cap[j]);
            }
            for (int j = 0, bound = cnts[i]; j < bound; j++) {
                if (dp[possible] >= costs[i]) {
                    dp[possible + 1] = dp[possible] - costs[i];
                    possible++;
                }
                for (int t = possible; t >= 1; t--) {
                    dp[t] = Math.max(dp[t], dp[t - 1] - costs[i]);
                }

            }
        }

        System.out.println(possible);
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