

import java.io.*;
import java.util.Arrays;

/**
 * Created by dalt on 2018/4/2.
 */
public class CF954G {
    public static final long MOD = (long) (1e9 + 7);
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF954G.in"));
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
        int r = input.nextInteger();
        long k = Long.parseLong(input.nextBlock());

        long[] data = new long[n + 1];
        long[] prefixSum = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            data[i] = input.nextInteger();
            prefixSum[i] = prefixSum[i - 1] + data[i];
        }

        for (int i = 1; i <= n; i++) {
            data[i] = prefixSum[Math.min(i + r, n)] - prefixSum[Math.max(0, i - r - 1)];
        }

        long right = (long) 2e18;
        long left = 0;
        while (left != right) {
            long center = (left + right + 1) >> 1;
            if (maybe(prefixSum, data, n, r, k, center)) {
                left = center;
            } else {
                right = center - 1;
            }
        }

        output.println(left);
    }

    public static boolean maybe(long[] prefixSum, long[] data, int n, int r, long k, long reliability) {
        Arrays.fill(prefixSum, 0);
        //until + r == data.length
        int i;
        for (i = r + 1; i <= n && k >= 0; i++) {
            int responsibleFor = i - r;
            long total = data[responsibleFor] + prefixSum[i - 1] - prefixSum[Math.max(0, responsibleFor - r - 1)];
            long needAppend = Math.max(0, reliability - total);
            k -= needAppend;
            prefixSum[i] = prefixSum[i - 1] + needAppend;
        }
        for (i = n + 1 - r; i <= n && k >= 0; i++) {
            if (prefixSum[n] - prefixSum[Math.max(0, i - r - 1)] + k + data[i] < reliability) {
                return false;
            }
        }
        return k >= 0;
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