

import java.io.*;

/**
 * Created by dalt on 2018/4/1.
 */
public class CF936C {
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF936C.in"));
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
        char[] s = new char[n];
        char[] t = new char[n];
        input.nextBlock(s, 0);
        input.nextBlock(t, 0);

        int[] sCnt = new int[128];
        int[] tCnt = new int[128];
        for (int i = 0; i < n; i++) {
            sCnt[s[i]]++;
            tCnt[t[i]]++;
        }
        for (int i = 0; i < 128; i++) {
            if (sCnt[i] != tCnt[i]) {
                output.println("-1");
                return;
            }
        }

        int center = (n - 1) >> 1;
        int tl = center;
        int tr = center;

        output.println((n - 1) * 3 + 1 + (n % 2 == 0 ? 1 : 0));

        Loop<char[]> loop = new Loop<>(s, new char[n]);
        {
            int index = indexOf(loop.get(0), 0, n, t[center]);
            int x = n - (index + 1);
            output.println(x);
            transform(loop.get(0), loop.turn(1), x);
        }


        while (tr < n - 1) {
            {
                tr++;
                int index = indexOf(loop.get(0), 0, n - (tr - tl), t[tr]);

                int x = n - index - 1;
                output.println(x);
                transform(loop.get(0), loop.turn(1), x);

                x = 1;
                output.println(x);
                transform(loop.get(0), loop.turn(1), x);

                x = n - (tr - tl + 1);
                output.println(x);
                transform(loop.get(0), loop.turn(1), x);
            }

            {
                if (tl == 0) {
                    continue;
                }
                tl--;
                int index = indexOf(loop.get(0), 0, n - (tr - tl), t[tl]);

                int x = n - index - 1;
                output.println(x);
                transform(loop.get(0), loop.turn(1), x);

                x = 1;
                output.println(x);
                transform(loop.get(0), loop.turn(1), x);

                x = n - (tr - tl + 1);
                output.println(x);
                transform(loop.get(0), loop.turn(1), x);
            }
        }

        if (n % 2 == 0) {
            //reverse again
            int x = n;
            output.println(x);
            transform(loop.get(0), loop.turn(1), x);
        }

    }

    public static int indexOf(char[] data, int from, int to, char c) {
        for (int i = from; i < to; i++) {
            if (data[i] == c) {
                return i;
            }
        }
        return -1;
    }

    public static char[] transform(char[] src, char[] dst, int x) {
        int n_1 = src.length - 1;
        System.arraycopy(src, 0, dst, x, dst.length - x);
        for (int i = 0; i < x; i++) {
            dst[i] = src[n_1 - i];
        }
        return dst;
    }

    public static class Loop<T> {
        T[] data;
        int offset;

        public Loop(T... data) {
            this.data = data;
        }

        public T turn(int offset) {
            this.offset += offset;
            return get(0);
        }

        public T get(int i) {
            return data[(i + offset) % data.length];
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