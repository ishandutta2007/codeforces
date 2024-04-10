

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/3/20.
 */
public class CF915G {
    public static final long MODULO = 1000000007;
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF915G.in"));
        }
        input = new BlockReader(System.in);

        int n = input.nextInteger();
        int k = input.nextInteger();
        int[]  mobius = new int[k + 1];
        int[] primes = new int[k + 1];
        int primeCnt = 0;
        long[]  pns = new long[k + 1];
        boolean[] isComposites = new boolean[k + 1];

        //euler griddle
        mobius[1] = 1;
        pns[1] = 1;
        isComposites[1] = true;
        for (int i = 2; i <= k; i++) {
            if (!isComposites[i]) {
                primes[primeCnt++] = i;
                pns[i] = pow(i, n);
                mobius[i] = -1;
            }
            //i * primes[j] <= k => primes[j] <= k / i
            for (int j = 0, bound = k / i; j < primeCnt && primes[j] <= bound; j++) {
                int ip = i * primes[j];
                isComposites[ip] = true;
                pns[ip] = pns[i] * pns[primes[j]] % MODULO;
                if (i % primes[j] == 0) {
                    mobius[ip] = 0;
                    break;
                }
                mobius[ip] = mobius[i] * mobius[primes[j]];
            }
        }


        long[] differ = new long[k + 1];
        for (int i = 1; i <= k; i++) {
            for (int j = i, t = 1; j <= k; j += i, t++) {
                differ[j] += (pns[t] - pns[t - 1]) * mobius[i];
            }
        }


        long[] values = new long[k + 1];
        values[1] = 1;
        for (int i = 2; i <= k; i++) {
            values[i] = ((values[i - 1] + differ[i]) % MODULO + MODULO) % MODULO;
        }

        long sum = 0;
        for (int i = 1; i <= k; i++) {
            sum += values[i] ^ (long)i;
        }

        sum = (sum % MODULO + MODULO) % MODULO;
        System.out.println(sum);
    }

    public static long pow(long x, int n) {
        int bit = 31;
        while (bit >= 0 && (n & (1 << bit)) == 0) {
            bit--;
        }

        long v = 1;
        for (; bit >= 0; bit--) {
            v = v * v % MODULO;
            if ((n & (1 << bit)) != 0) {
                v = v * x % MODULO;
            }
        }

        return v;
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