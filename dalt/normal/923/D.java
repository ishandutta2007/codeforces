
import java.io.*;

/**
 * Created by dalt on 2018/3/14.
 */
public class CF923D {
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF923D.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        solve();

        output.flush();
    }

    public static void solve() {
        char[] s = new char[100001];
        char[] t = new char[100001];

        int slen = input.nextBlock(s, 1);
        int tlen = input.nextBlock(t, 1);

        int[] sumOfBOrCInS = new int[slen + 1];
        int[] tailALengthInS = new int[slen + 1];

        for (int i = 1; i <= slen; i++) {
            if (s[i] == 'A') {
                tailALengthInS[i] = tailALengthInS[i - 1] + 1;
            }
            sumOfBOrCInS[i] = sumOfBOrCInS[i - 1];
            if (s[i] != 'A') {
                sumOfBOrCInS[i]++;
            }
        }

        int[] sumOfBOrCInT = new int[tlen + 1];
        int[] tailALengthInT = new int[tlen + 1];
        for (int i = 1; i <= tlen; i++) {
            if (t[i] == 'A') {
                tailALengthInT[i] = tailALengthInT[i - 1] + 1;
            }
            sumOfBOrCInT[i] = sumOfBOrCInT[i - 1];
            if (t[i] != 'A') {
                sumOfBOrCInT[i]++;
            }
        }

        int q = input.nextInteger();
        for (int i = 0; i < q; i++) {
            int sl = input.nextInteger();
            int sr = input.nextInteger();

            int tl = input.nextInteger();
            int tr = input.nextInteger();

            int sbcCnt = sumOfBOrCInS[sr] - sumOfBOrCInS[sl - 1];
            int tbcCnt = sumOfBOrCInT[tr] - sumOfBOrCInT[tl - 1];
            if (sbcCnt > tbcCnt || ((tbcCnt - sbcCnt) & 1) != 0) {
                output.print('0');
                continue;
            }


            int stail = Math.min(tailALengthInS[sr], sr - sl + 1);
            int ttail = Math.min(tailALengthInT[tr], tr - tl + 1);


            if (ttail > stail) {
                output.print('0');
                continue;
            }

            if (ttail == stail && sbcCnt == 0 && tbcCnt > 0) {
                output.print('0');
                continue;
            }

            stail -= ttail;
            stail %= 3;
            if (stail != 0 && sbcCnt == tbcCnt) {
                output.print('0');
                continue;
            }

            output.print('1');
        }
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