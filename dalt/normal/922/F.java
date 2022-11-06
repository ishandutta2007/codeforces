

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Created by Administrator on 2018/3/4.
 */
public class CF922F {
    public static final int N_LIMIT = 300001;
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF922F.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }

    public static void solve() {
        int n = input.nextInteger();
        int k = input.nextInteger();

        int[] divisors = new int[n + 1];
        divisors[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                divisors[j] += 1;
            }
        }

        int sum = 0;
        int setId;
        for (setId = 1; setId <= n && sum < k; setId++) {
            sum += divisors[setId];
        }

        if (sum < k) {
            System.out.println("No");
            return;
        }
        setId--;

        System.out.println("Yes");
        boolean[] remove = new boolean[setId + 1];

        int remain = sum - k;
        if (setId <= 120) {
            tryRemove(remove, divisors, setId, sum - k, 1);
        } else {
            for (int i = setId / 2 + 1; i <= setId & remain > 0; i++) {
                if (divisors[i] == 1) {
                    remain--;
                    remove[i] = true;
                }
            }
        }

        int cnt = 0;
        StringBuilder builder = new StringBuilder();
        for (int i = 1; i <= setId; i++) {
            if (remove[i] == false) {
                cnt++;
                builder.append(i).append(' ');
            }
        }
        System.out.println(cnt);
        System.out.println(builder);
    }

    public static boolean tryRemove(boolean[] remove, int[] divisors, int setId, int remain, int i) {
        if (remain == 0) {
            return true;
        }
        if (i > setId) {
            return false;
        }
        if (remain >= setId / i + divisors[i] - 1) {
            remove[i] = true;
            for (int j = i + i; j <= setId; j += i) {
                divisors[j]--;
            }
            if (tryRemove(remove, divisors, setId, remain - (setId / i + divisors[i] - 1), i + 1)) {
                return true;
            }
            remove[i] = false;
            for (int j = i + i; j <= setId; j += i) {
                divisors[j]++;
            }
        }

        return tryRemove(remove, divisors, setId, remain, i + 1);
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