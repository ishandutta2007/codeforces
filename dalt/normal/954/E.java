

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by dalt on 2018/4/2.
 */
public class CF954E {
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF954E.in"));
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
        int T = input.nextInteger();
        int[] cap = new int[n + 1];
        int[] temperature = new int[n + 1];
        int[][] neg = new int[n][2];
        int negLen = 0;
        int[][] pos = new int[n][2];
        int posLen = 0;
        double negSum = 0;
        double posSum = 0;
        for (int i = 1; i <= n; i++) {
            cap[i] = input.nextInteger();
        }

        double fix = 0;
        for (int j = 1; j <= n; j++) {
            temperature[j] = input.nextInteger() - T;
            if (temperature[j] > 0) {
                pos[posLen][0] = cap[j];
                pos[posLen][1] = temperature[j];
                posSum += (double) pos[posLen][0] * pos[posLen][1];
                posLen++;
            } else if (temperature[j] < 0) {
                neg[negLen][0] = cap[j];
                neg[negLen][1] = -temperature[j];
                negSum += (double) neg[negLen][0] * neg[negLen][1];
                negLen++;
            } else {
                fix += cap[j];
            }
        }

        Comparator<int[]> comparator = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        };
        Arrays.sort(pos, 0, posLen, comparator);
        Arrays.sort(neg, 0, negLen, comparator);

        double min = Math.min(posSum, negSum);
        double result = maxFlow(pos, posLen, min) + maxFlow(neg, negLen, min) + fix;

        output.println(String.format("%.13f", result));
    }

    public static double maxFlow(int[][] data, int len, double sum) {
        double total = 0;
        for (int i = 0; i < len && sum > 0; i++) {
            double occupied = Math.min(sum / data[i][1], data[i][0]);
            sum -= occupied * data[i][1];
            total += occupied;
        }
        return total;
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