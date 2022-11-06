

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/3/1.
 */
public class CF920D {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF920D.in"));
        }
        input = new BlockReader(System.in);
        StringBuilder builder = new StringBuilder();
        String moveLimit = "100000";

        int n = input.nextInteger();
        int k = input.nextInteger();
        int v = input.nextInteger();

        int[] remain = new int[n + 1];
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            remain[i] = input.nextInteger();
            sum += remain[i];
        }
        if (sum < v) {
            System.out.println("NO");
            return;
        }

        if (v % k == 0) {
            builder.append("YES\n");
            builder.append(moveLimit).append(' ').append(1).append(' ').append(2).append('\n');
            remain[2] += remain[1];
            remain[1] = 0;

            for (int i = 3; i <= n; i++) {
                builder.append(moveLimit).append(' ').append(i).append(' ').append(2).append('\n');
            }

            if (v != 0) {
                builder.append(v / k).append(' ').append(2).append(' ').append(1).append('\n');
            }
            System.out.print(builder);
            return;
        }
        int[] remainderDp = new int[k];
        int[] last = new int[k];
        boolean[] inSet = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < k; j++) {
                if (remainderDp[j] == 0 || remainderDp[j] == i) {
                    continue;
                }
                int index = (j + remain[i]) % k;
                if (remainderDp[index] != 0) {
                    continue;
                }

                remainderDp[index] = i;
                last[index] = j;
            }

            int index = remain[i] % k;
            if (remainderDp[index] == 0) {
                remainderDp[index] = i;
                last[index] = 0;
            }
        }

        if (remainderDp[v % k] == 0) {
            System.out.println("NO");
            return;
        }
        builder.append("YES\n");

        int index = v % k;
        while (index != 0) {
            inSet[remainderDp[index]] = true;
            index = last[index];
        }
        int inSetRepr = 0;
        int notInSetRepr = 0;
        for (int i = 1; i <= n; i++) {
            if (inSet[i]) {
                if (inSetRepr == 0) {
                    inSetRepr = i;
                } else {
                    builder.append(moveLimit).append(' ').append(i).append(' ').append(inSetRepr).append('\n');
                    remain[inSetRepr] += remain[i];
                    remain[i] = 0;
                }
            } else {
                if (notInSetRepr == 0) {
                    notInSetRepr = i;
                } else {
                    builder.append(moveLimit).append(' ').append(i).append(' ').append(notInSetRepr).append('\n');
                    remain[notInSetRepr] += remain[i];
                    remain[i] = 0;
                }
            }
        }

        if (remain[inSetRepr] < v) {
            builder.append((v - remain[inSetRepr]) / k).append(' ').append(notInSetRepr).append(' ').append(inSetRepr).append('\n');
        } else if (remain[inSetRepr] > v) {
            builder.append((remain[inSetRepr] - v) / k).append(' ').append(inSetRepr).append(' ').append(inSetRepr % k + 1).append('\n');
        }

        System.out.print(builder.toString());
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