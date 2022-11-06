

import java.io.*;

/**
 * Created by dalt on 2018/3/14.
 */
public class CF949D {
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF949D.in"));
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
        long d = input.nextInteger();
        int b = input.nextInteger();

        int[] rooms = new int[n + 1];
        int[] leftSum = new int[n + 2];
        int[] rightSum = new int[n + 2];

        for (int i = 1; i <= n; i++) {
            rooms[i] = input.nextInteger();
        }

        for (int i = 1; i <= n; i++) {
            leftSum[i] = leftSum[i - 1] + rooms[i];
        }
        for (int i = n; i >= 1; i--) {
            rightSum[i] = rightSum[i + 1] + rooms[i];
        }

        int lCnt = 0;
        int rCnt = 0;
        int lConsume = 0;
        int rConsume = 0;
        for (int l = 1, r = n; l <= r; l++, r--) {
            int lTo = (int) Math.min(n, l * d + l);
            int rFrom = (int) Math.max(1, r - l * d);
            if (leftSum[lTo] - lConsume >= b) {
                lConsume += b;
            } else {
                lCnt++;
            }

            if (l != r) {
                if (rightSum[rFrom] - rConsume >= b) {
                    rConsume += b;
                } else {
                    rCnt++;
                }
            }
        }

        output.println(Math.max(lCnt, rCnt));
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