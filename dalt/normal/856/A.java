
import java.io.*;
import java.util.Arrays;

/**
 * Created by dalt on 2018/3/15.
 */
public class CF856A {
    public static BlockReader input;
    public static PrintStream output;
    static boolean[] set = new boolean[1000000];
    static int[] nums = new int[101];

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF856A.in"));
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

    public static void solve() {
        Arrays.fill(set, false);
        int n = input.nextInteger();
        for (int i = 1; i <= n; i++) {
            nums[i] = input.nextInteger();
        }

        output.println("YES");
        int bSize = 0;
        for (int i = 1; bSize < n; i++) {
            if (set[i]) {
                continue;
            }
            bSize++;
            output.print(i);
            output.print(' ');
            for (int j = 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    set[i + Math.abs(nums[j] - nums[k])] = true;
                }
            }
        }
        output.println();
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