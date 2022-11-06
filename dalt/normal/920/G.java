

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Created by Administrator on 2018/2/10.
 */
public class CF920G {
    static final boolean IS_OJ = true;
    public static BlockReader input;
    public static int P_LIMIT = 1000000;
    public static boolean[] isComposite = new boolean[P_LIMIT + 1];
    public static int[] primes = new int[P_LIMIT + 1];

    public static void findPrimes() {
        int primesCnt = 0;

        isComposite[1] = true;
        for (int i = 2; i <= P_LIMIT; i++) {
            if (!isComposite[i]) {
                primes[primesCnt++] = i;
            }
            for (int j = 0; j < primesCnt && primes[j] * i <= P_LIMIT; j++) {
                isComposite[primes[j] * i] = true;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        input = new BlockReader(System.in);

        findPrimes();

        StringBuilder builder = new StringBuilder(4096);
        for (int i = 0, t = input.nextInteger(); i < t; i++) {
            builder.append(solve()).append('\n');
        }
        System.out.print(builder);
    }

    public static long solve() {

        int x = input.nextInteger();
        int p = input.nextInteger();
        int k = input.nextInteger();

        int primeCnt = 0;
        for (int i = 1; i * i <= p; i++) {
            if (p % i != 0) {
                continue;
            }
            if (!isComposite[i]) {
                primes[primeCnt++] = i;
            }
            int another = p / i;
            if (another != i && isComposite[another] == false) {
                primes[primeCnt++] = another;
            }
        }

        k += search(primes, primeCnt, x);
        long up = (long) 1e12;
        long bot = 1;
        //f(r)>= k and f(r-1)<k
        while (up != bot) {
            long mid = (up + bot) >> 1;
            long cnt = search(primes, primeCnt, mid);

            if (cnt >= k) {
                up = mid;
            } else {
                bot = mid + 1;
            }
        }

        return up;
    }

    public static long search(int[] primes, int primeCnt, long n) {
        return n - search(primes, primeCnt, 0, 0, 1, n);
    }

    public static long search(int[] primes, int primeCnt, int i, int choose, long product, long n) {
        if (i == primeCnt) {
            if (choose == 0) {
                return 0;
            }
            long res = n / product;
            if (choose % 2 == 0) {
                res = -res;
            }
            return res;
        }

        long res = search(primes, primeCnt, i + 1, choose, product, n)
                + search(primes, primeCnt, i + 1, choose + 1, product * primes[i], n);
        return res;
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

        public void skipBlank() {
            while (Character.isWhitespace(next)) {
                next = nextByte();
            }
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

        public int nextByte() {
            while (dPos >= dSize) {
                if (dSize == -1) {
                    return EOF;
                }
                dPos = 0;
                try {
                    dSize = is.read(dBuf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return dBuf[dPos++];
        }
    }
}