
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by Administrator on 2018/3/16.
 */
public class CF856C {
    public static final int MOD = 998244353;
    public static BlockReader input;
    public static PrintStream output;
    static int[][] ballInSlotsMemory = new int[2001][2001];
    static boolean[][] ballInSlotsMemoryVisit = new boolean[2001][2001];
    static int[] fact = new int[2001];
    static boolean[] factVisit = new boolean[2001];

    static {
        factVisit[0] = true;
        fact[0] = 1;
        Arrays.fill(ballInSlotsMemoryVisit[0], true);
        for (int i = 0; i < 2001; i++) {
            ballInSlotsMemory[i][0] = 1;
            ballInSlotsMemoryVisit[i][0] = true;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF856C.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        for (int t = input.nextInteger(); t > 0; t--) {
            solve();
        }

        output.flush();
    }

    public static int getBallInSlots(int slotNum, int ballNum) {
        if (ballInSlotsMemoryVisit[slotNum][ballNum] == false) {
            ballInSlotsMemoryVisit[slotNum][ballNum] = true;
            ballInSlotsMemory[slotNum][ballNum] = (getBallInSlots(slotNum, ballNum - 1)
                    + getBallInSlots(slotNum - 1, ballNum)) % MOD;
        }
        return ballInSlotsMemory[slotNum][ballNum];
    }

    public static int getFact(int i) {
        if (factVisit[i] == false) {
            factVisit[i] = true;
            fact[i] = (int) ((long) getFact(i - 1) * i % MOD);
        }
        return fact[i];
    }

    public static int getPositiveMod(long x, int m) {
        return (int) ((x % m + m) % m);
    }

    public static void solve() {
        int n = input.nextInteger();
        List<Info> evenInfoList = new ArrayList<>();
        List<Info> oddInfoList = new ArrayList<>();
        char[] buf = new char[20];

        for (int i = 1; i <= n; i++) {
            int len = input.nextBlock(buf, 0);
            Info info = new Info();
            for (int j = len - 1; j >= 0; j -= 2) {
                info.evenTotal += buf[j] - '0';
            }
            for (int j = len - 2; j >= 0; j -= 2) {
                info.oddTotal += buf[j] - '0';
            }
            if ((len & 1) == 0) {
                evenInfoList.add(info);
            } else {
                oddInfoList.add(info);
            }
        }

        if (oddInfoList.isEmpty()) {
            long total = 0;
            for (Info info : evenInfoList) {
                total += info.evenTotal;
                total -= info.oddTotal;
            }
            total = getPositiveMod(total, 11);
            if (total == 0) {
                output.println(getFact(n));
            } else {
                output.println(0);
            }
            return;
        }

        int oddCnt = oddInfoList.size();
        int evenCnt = evenInfoList.size();
        int[][] oddDp = makeDp(oddInfoList);

        int actuallyPossibleAllocation = oddInfoList.size() >> 1;
        int[] possibleOddDp = oddDp[actuallyPossibleAllocation];

        if (evenInfoList.isEmpty()) {
            int value = (int) ((long)possibleOddDp[0] * getFact(actuallyPossibleAllocation) % MOD
                                * getFact(oddCnt - actuallyPossibleAllocation) % MOD);
            output.println(value);
            return;
        }

        //even dp
        int[][] evenDp = makeDp(evenInfoList);
        int possibility = 0;
        for (int i = 0; i < 11; i++) {
            int j = (11 - i) % 11;
            long oddPossibility = (int) ((long)possibleOddDp[i] * getFact(actuallyPossibleAllocation) % MOD
                    * getFact(oddCnt - actuallyPossibleAllocation) % MOD);
            for (int k = 0, bound = evenCnt; k <= bound; k++) {
                int evenPosCnt = evenCnt - k;
                int evenNegCnt = k;
                long evenPosPossibility = ((long) getBallInSlots(((oddCnt + 2) >> 1), evenPosCnt) * getFact(evenPosCnt)) % MOD;
                long evenNegPossibility = ((long) getBallInSlots(((oddCnt + 1) >> 1), evenNegCnt) * getFact(evenNegCnt)) % MOD;
                possibility = (int) ((possibility + oddPossibility *
                        ((evenDp[k][j] * evenPosPossibility % MOD * evenNegPossibility) % MOD))
                        % MOD);
            }
        }

        output.println(possibility);
    }

    public static int[][] makeDp(List<Info> list) {
        int n = list.size();

        int[][][] dpLoop = new int[2][n + 1][11];
        dpLoop[0][0][0] = 1;
        int iter = 0;
        for (Info info : list) {
            iter++;
            int[][] curDp = dpLoop[iter & 1];
            int[][] lastDp = dpLoop[~iter & 1];

            int evenSubOdd = getPositiveMod(info.evenTotal - info.oddTotal, 11);

            for (int i = 0; i < 11; i++) {
                curDp[0][i] = lastDp[0][getPositiveMod(i - evenSubOdd, 11)];
            }
            for (int i = 1; i <= iter; i++) {
                for (int j = 0; j < 11; j++) {
                    curDp[i][j] = (lastDp[i][getPositiveMod(j - evenSubOdd, 11)] + lastDp[i - 1][getPositiveMod(j + evenSubOdd, 11)]) % MOD;
                }
            }
        }

        return dpLoop[iter & 1];
    }

    public static class Info {
        int evenTotal;
        int oddTotal;
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