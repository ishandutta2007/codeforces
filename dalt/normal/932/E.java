
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/3/20.
 */
public class CF932E {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;
    public static int MODULO = 1000000007;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF932E.in"));
        }
        input = new BlockReader(System.in);

        int n = input.nextInteger();
        int k = input.nextInteger();

        if (n <= k) {
            long choose = 1;
            long sum = 0;
            int up = n;
            int low = 1;
            for (int i = 1; i <= n; i++) {
                choose = (choose * up) % MODULO;
                choose = (choose * pow(low, MODULO - 2)) % MODULO;
                up--;
                low++;
                long price = pow(i, k);
                sum = (sum + choose * price) % MODULO;
            }
            System.out.println(sum);
            return;
        }

        long[] dp = new long[k + 1];
        dp[k] = pow(2, n - k);
        for (int i = k - 1; i >= 0; i--) {
            dp[i] = (dp[i + 1] * 2) % MODULO;
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 0, bound = k - i; j <= bound; j++) {
                dp[j] = (j * dp[j] + (n - j) * dp[j + 1]) % MODULO;
            }
        }

        System.out.println(dp[0]);
    }

    public static long pow(int x, int n) {
        if (n < 20) {
            long r = 1;
            for (int i = 0; i < n; i++) {
                r = r * x % MODULO;
            }
            return r;
        }
        int bit = 31;
        for (; (n & (1 << bit)) == 0; bit--) ;
        long r = 1;
        for (; bit >= 0; bit--) {
            r = r * r % MODULO;
            if ((n & (1 << bit)) != 0) {
                r = r * x % MODULO;
            }
        }
        return r;
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