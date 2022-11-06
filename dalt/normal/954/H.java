
import java.io.*;

/**
 * Created by dalt on 2018/4/2.
 */
public class CF954H {
    public static final int MOD = (int) (1e9 + 7);
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF954H.in"));
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
        long[] a = new long[n];
        long[] aRev = new long[n];
        long[] aChoose2Child = new long[n + 1];
        long[] aChoose2ChildRev = new long[n + 1];
        long negTwo = pow(2, MOD - 2);
        for (int i = 0, until = n - 1; i < until; i++) {
            a[i] = input.nextInteger();
            aRev[i] = pow(a[i], MOD - 2);
        }

        for (int i = 0; i < n; i++) {
            aChoose2Child[i] = a[i] * (a[i] - 1) % MOD;
            aChoose2ChildRev[i] = pow( aChoose2Child[i], MOD - 2);
        }

        long[] prefixMul = new long[n];
        long[] prefixRev = new long[n];
        prefixMul[0] = 1;
        prefixRev[0] = 1;
        for (int i = 1; i < n; i++) {
            prefixMul[i] = prefixMul[i - 1] * a[i - 1] % MOD;
            prefixRev[i] = prefixRev[i - 1] * aRev[i - 1] % MOD;
        }


        int m = (n - 1) * 2;
        long[] f = new long[m + 1];
        Loop<long[][]> dpLoop = new Loop<>(new long[m + 1][3], new long[m + 1][3]);
        final int ROTATE = 0;
        final int BALANCE = 2;
        final int LINE = 1;

        {
            long[][] next = dpLoop.turn();
            next[0][BALANCE] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            long[][] former = dpLoop.get(0);
            long[][] next = dpLoop.turn();

            long aChooseRev = aChoose2ChildRev[i + 1] * a[i + 1] % MOD * a[i + 1] % MOD * aChoose2Child[i] % MOD;
            for (int j = 2, until = ((n - 1) - i) * 2; j <= until; j++) {
                next[j][ROTATE] = (former[j - 2][ROTATE] * aChooseRev % MOD + former[j - 2][LINE] * aChoose2Child[i] % MOD) % MOD;

                int halfJ = j >> 1;
                if ((j & 1) == 0 && i + halfJ < n) {
                    long possible = prefixMul[i + halfJ] * prefixRev[i + 1] % MOD;
                    possible = possible * possible % MOD;
                    next[j][BALANCE] = possible * aChoose2Child[i]  % MOD * negTwo % MOD;
                } else {
                    next[j][BALANCE] = 0;
                }

                if (i + j < n) {
                    next[j][LINE] = prefixMul[i + j] * prefixRev[i] % MOD;
                } else {
                    next[j][LINE] = 0;
                }
            }

            next[2][BALANCE] = aChoose2Child[i] * negTwo % MOD;
            next[1][LINE] = a[i];
            next[0][BALANCE] = 1;

            for (int j = 1; j <= m; j++) {
                f[j] = (f[j] + (next[j][LINE] + next[j][ROTATE] + next[j][BALANCE]) * prefixMul[i]) % MOD;
            }
        }

        for (int i = 1; i <= m; i++) {
            output.print(f[i]);
            output.print(' ');
        }
    }

    public static long pow(long x, int n) {
        int bit = 31 - Integer.numberOfLeadingZeros(n);
        long product = 1;
        for (; bit >= 0; bit--) {
            product = product * product % MOD;
            if (((1 << bit) & n) != 0) {
                product = product * x % MOD;
            }
        }
        return product;
    }

    public static class Loop<T> {
        T[] data;
        int offset;

        public Loop(T... data) {
            this.data = data;
        }

        public T turn() {
            offset++;
            return get(0);
        }

        public T get(int index) {
            return data[(index + offset) % data.length];
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