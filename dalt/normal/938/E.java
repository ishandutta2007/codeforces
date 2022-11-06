

import java.io.*;
import java.util.Arrays;
import java.util.Random;

/**
 * Created by dalt on 2018/4/1.
 */
public class CF938E {
    public static final int MOD = (int) (1e9 + 7);
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF938E.in"));
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
        int[] data = new int[n];
        for (int i = 0; i < n; i++) {
            data[i] = input.nextInteger();
        }

        Random random = new Random(19950823);
        for (int i = 0; i < n; i++) {
            int f = random.nextInt(n);
            int tmp = data[i];
            data[i] = data[f];
            data[f] = tmp;
        }
        Arrays.sort(data);

        int[] largerNum = new int[n];
        largerNum[n - 1] = 1;

        int[] theSameNum = new int[n];
        theSameNum[0] = 1;
        for (int i = 1; i < n; i++) {
            theSameNum[i] = data[i - 1] == data[i] ? theSameNum[i - 1] + 1 : 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (data[i] < data[i + 1]) {
                largerNum[i] = n - 1 - i;
            } else {
                theSameNum[i] = theSameNum[i + 1];
                largerNum[i] = largerNum[i + 1];
            }
        }

        long nfac = 1;
        for (int i = 2; i <= n; i++) {
            nfac = (nfac * i) % MOD;
        }

        //Euler to eliminate the time complexity from nlog2n to n
        boolean[] isComposite = new boolean[n + 1];
        isComposite[1] = true;
        int[] primes = new int[n + 1];
        int primeCnt = 0;
        long[] pow = new long[n + 1];
        pow[0] = 0;
        pow[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!isComposite[i]) {
                primes[primeCnt++] = i;
                pow[i] = pow(i, MOD - 2);
            }
            //p * i <= n -> p <= n / i
            for (int j = 0, until = n / i; primes[j] <= until; j++) {
                int p = primes[j];
                int pi = p * i;
                isComposite[pi] = true;
                pow[pi] = pow[p] * pow[i] % MOD;
                if (i % p == 0) {
                    break;
                }
            }
        }


        long sum = 0;
        for (int i = 0, until = n - theSameNum[n - 1]; i < until; i++) {
            sum = (sum + data[i] * nfac % MOD * pow[largerNum[i] + theSameNum[i]]) % MOD;
        }

        System.out.println(sum);
    }

    public static long pow(long x, int n) {
        int bit = 31 - Integer.numberOfLeadingZeros(n);
        long product = 1;
        for (; bit >= 0; bit--) {
            product = product * product % MOD;
            if ((n & (1 << bit)) != 0) {
                product = product * x % MOD;
            }
        }
        return product;
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