


import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Map;

/**
 * Created by Administrator on 2018/1/30.
 */
public class CF915C {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    static {
        if (!IS_OJ) {
            try {
                System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\915C.in"));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        input = new BlockReader(System.in);
    }

    public static void main(String[] args) throws FileNotFoundException {
        char[] a = input.nextBlock().toCharArray();
        char[] b = input.nextBlock().toCharArray();

        int[] cnt = new int[10];
        int[] inta = new int[a.length];
        int[] intb = new int[b.length];
        for (int i = 0; i < a.length; i++) {
            inta[i] = a[i] - '0';
            cnt[inta[i]]++;
        }

        for (int i = 0; i < b.length; i++) {
            intb[i] = b[i] - '0';
        }

        int[] permute = new int[a.length];
        if (a.length == b.length) {
            search(permute, intb, cnt, 0);
        } else {
            fillWithMax(permute, cnt, 0);
        }

        char[] cr = new char[a.length];
        for (int i = 0; i < a.length; i++) {
            cr[i] = (char) (permute[i] + '0');
        }

        System.out.println(new String(cr));
    }

    public static boolean fillWithMax(int[] data, int[] remain, int pos) {
        if (pos == data.length) {
            return true;
        }

        for (int i = 9; i >= 0; i--) {
            if (remain[i] > 0) {
                remain[i]--;
                data[pos] = i;
                fillWithMax(data, remain, pos + 1);
                remain[i]++;
                break;
            }
        }
        return true;
    }

    public static boolean search(int[] data, int[] up, int[] remain, int pos) {
        if (data.length == pos) {
            return true;
        }
        for (int i = up[pos]; i >= 0; i--) {
            if (remain[i] != 0) {
                remain[i]--;
                data[pos] = i;
                boolean test = data[pos] == up[pos] ?
                        search(data, up, remain, pos + 1) : fillWithMax(data, remain, pos + 1);
                remain[i]++;

                if (test) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void add(int v, Map<Integer, Integer> map) {
        map.put(v, map.getOrDefault(v, 0) + 1);
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