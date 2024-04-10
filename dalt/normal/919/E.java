

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/2/25.
 */
public class Main {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF919E.in"));
        }
        input = new BlockReader(System.in);
        StringBuilder builder = new StringBuilder();

        long a = input.nextInteger();
        long b = input.nextInteger();
        int p = input.nextInteger();
        long x = Long.parseLong(input.nextBlock()) + 1;

        long loopSize = (long)p * (p - 1);
        long[] possible = new long[(p - 1)];

        long M = (long)p * (p - 1);
        long mi = p;
        long mj = p - 1;
        long Mi = mj;
        long Mj = mi;
        long ti = 0;
        long tj = 0;
        for (int i = 0; i < p && (ti == 0 || tj == 0); i++) {
            if (Mi * i % mi == 1) {
                ti = i;
            }
            if (Mj * i % mj == 1) {
                tj = i;
            }
        }


        long[] aexp = new long[(int) p];
        aexp[0] = 1;
        for (int i = 1, bound = aexp.length; i < bound; i++) {
            aexp[i] = aexp[i - 1] * a % p;
        }

        for (int j = 0, bound = possible.length; j < bound; j++) {
            long a_j = aexp[ (p - 1 - j)];
            long i = a_j * b % M;

            //chinese remainder
            long n = ((i * ti) % M) * Mi + ((j * tj) % M) * Mj;
            possible[j] = n % M;
        }


        //consider 0 is impossible
        long sum = x / loopSize * possible.length;
        long remain = x % loopSize;
        for (int i = 0, bound = possible.length; i < bound; i++) {
            if (possible[i] < remain) {
                sum++;
            }
        }

        System.out.println(sum);
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