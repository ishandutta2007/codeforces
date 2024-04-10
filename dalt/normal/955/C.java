

import java.io.*;
import java.util.Arrays;

/**
 * Created by dalt on 2018/4/2.
 */
public class CF955C {
    public static final int MOD = (int) (1e9 + 7);
    public static BlockReader input;
    public static PrintStream output;
    static long[] sadPower = new long[2000000];
    static int sadPowerLen;

    public static void main(String[] args) throws FileNotFoundException {

        init();

        for (int t = input.nextInteger(); t > 0; t--) {
            solve();
        }

        output.flush();
    }

    public static void init() throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF955C.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        boolean[] isComposite = new boolean[64];
        isComposite[1] = true;
        for (int i = 2; i < 64; i++) {
            if (isComposite[i]) {
                continue;
            }
            for (int j = i + i; j < 64; j += i) {
                isComposite[j] = true;
            }
        }

        int[] cnt = new int[64];
        for (int i = 2; ; i++) {
            long ele = (long) i * (long) i;
            long allowed = ((long) 1e18) / i;
            if (allowed < ele) {
                break;
            }
            for (int j = 3; j < 64 && ele <= allowed; j++) {
                ele *= i;
                if (isComposite[j]) {
                    continue;
                }
                cnt[j]++;
                sadPower[sadPowerLen++] = ele;
            }
        }

        Arrays.sort(sadPower, 0, sadPowerLen);

        //Remove the same element
        int fixedSadPowerLen = 1;
        for (int i = 1; i < sadPowerLen; i++) {
            if (sadPower[i] != sadPower[fixedSadPowerLen - 1]) {
                sadPower[fixedSadPowerLen++] = sadPower[i];
            }
        }

        sadPowerLen = 0;
        for (int i = 0; i < fixedSadPowerLen; i++) {
            long sqrt = sqrt(sadPower[i]);
            if (sqrt * sqrt != sadPower[i]) {
                sadPower[sadPowerLen++] = sadPower[i];
            }
        }
    }

    public static void solve() {
        long l = input.nextLong();
        long r = input.nextLong();

        output.println(f(r) - f(l - 1));
    }

    //Return floor(sqrt(x))
    public static long sqrt(long x) {
        long l = 0;
        long r = (long) 1e9;
        while (l != r) {
            long m = (l + r + 1) >> 1;
            if (m * m <= x) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

    //Find the number of sad power in [1,n]
    public static long f(long n) {
        long sum = sqrt(n);
        int index = Arrays.binarySearch(sadPower, 0, sadPowerLen, n);
        index++;
        if (index < 0) {
            index = -index;
        }

        return sum + index;
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

        public long nextLong() {
            skipBlank();
            long ret = 0;
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