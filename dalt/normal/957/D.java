

import java.io.*;

/**
 * Created by Administrator on 2018/3/24.
 */
public class CF956D {
    static final int INF = (int) 1e8;
    static final int MOD = (int) 1e9 + 7;
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF956D.in"));
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
        int[] m = new int[n];
        for (int i = 0; i < n; i++) {
            m[i] = input.nextInteger();
        }

        Stack stack = new Stack(n);
        boolean[] created = new boolean[n];
        int curExist = 1;
        for (int i = 1; i < n; i++) {
            stack.push(i);


            while (m[i] >= curExist) {
                created[stack.pop()] = true;
                curExist++;
            }

        }

        int tagTotal = 1;
        long sum = 0;
        for (int i = 1; i < n; i++) {
            sum += tagTotal - m[i] - 1;
            //Up or down
            if (created[i]) {
                sum++;
                tagTotal++;
            }
        }

        output.println(sum);
    }

    public static class Stack {
        int[] data;
        int top = -1;

        public Stack(int cap) {
            this.data = new int[cap];
        }

        public int pop() {
            return data[top--];
        }

        public void push(int i) {
            data[++top] = i;
        }
    }

    public static class BlockReader {
        static final int EOF = -1;
        InputStream is;
        byte[] dBuf;
        int dPos, dSize, next;
        StringBuilder builder = new StringBuilder();

        public BlockReader(InputStream is) {
            this(is, 8192);
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