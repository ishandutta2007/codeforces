

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/3/25.
 */
public class CF940E {
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF940E.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }

    public static void solve() {
        int n = input.nextInteger();
        int k = input.nextInteger();

        int[] data = new int[n + 1];
        long[] dp = new long[n + 1];

        long sum = 0;
        for (int i = 1; i <= n; i++) {
            data[i] = input.nextInteger();
            sum += data[i];
        }

        if (k > n) {
            System.out.println(sum);
            return;
        }

        MinQueue queue = new MinQueue(n);
        for (int i = 1; i < k; i++) {
            queue.enque(data[i]);
        }
        for (int i = k; i <= n; i++) {
            queue.enque(data[i]);
            dp[i] = Math.max(dp[i - 1], dp[i - k] + queue.queryMin());
            queue.deque();
        }

        System.out.println(sum - dp[n]);
    }

    public static class MinQueue {
        int[] data;
        int tail;
        int head;
        int max = Integer.MIN_VALUE;
        int[] inc;
        int incTail;
        int incHead;

        public MinQueue(int cap) {
            data = new int[cap];
            head = 0;
            tail = -1;
            inc = new int[cap];
            incHead = 0;
            incTail = -1;
        }

        public void enque(int v) {
            while (incTail >= incHead && inc[incTail] > v) {
                incTail--;
            }
            inc[++incTail] = v;

            data[++tail] = v;
        }

        public int deque() {
            if (inc[incHead] == data[head]) {
                incHead++;
            }
            return data[head++];
        }

        public int queryMin() {
            return inc[incHead];
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