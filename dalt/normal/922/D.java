

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Arrays;

/**
 * Created by dalt on 2018/3/21.
 */
public class CF922D {

    public static final double INF = 1e100;
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF922D.in"));
        }
        input = new BlockReader(System.in);

        long total = 0;
        int n = input.nextInteger();
        char[] buf = new char[100000];
        Segment[] segments = new Segment[n];
        for (int i = 0; i < n; i++) {
            segments[i] = new Segment();
            int bufLen = input.nextBlock(buf, 0);
            int sCnt = 0;
            int hCnt = 0;
            for (int j = 0; j < bufLen; j++) {
                if (buf[j] == 's') {
                    sCnt++;
                } else {
                    total += sCnt;
                    hCnt++;
                }
            }

            segments[i].sCnt = sCnt;
            segments[i].hCnt = hCnt;
            segments[i].evaluate = hCnt == 0 ? INF : (double)sCnt / (double)hCnt;
        }

        Arrays.sort(segments);
        long sCnt = 0;
        for (int i = 0; i < n; i++) {
            total += sCnt * segments[i].hCnt;
            sCnt += segments[i].sCnt;
        }

        System.out.println(total);
    }

    public static class Segment implements Comparable<Segment> {
        int sCnt;
        int hCnt;
        double evaluate;

        @Override
        public int compareTo(Segment o) {
            return Double.compare(o.evaluate, evaluate);
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