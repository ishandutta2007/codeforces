
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by Administrator on 2018/1/29.
 */
public class CF918B {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;
    public static int orderAllocator = 1;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            //   System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\916E.in"));
        }
        input = new BlockReader(System.in);

        int n = input.nextInteger();
        int m = input.nextInteger();
        Map<String, String> map = new HashMap<>();
        for(int i = 0; i < n; i++)
        {
            String name = input.nextBlock();
            String ip = input.nextBlock();
            map.put(ip, name);
        }


        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < m; i++)
        {
            builder.append(input.nextBlock());
            String ip = input.nextBlock();
            builder.append(' ').append(ip);
            String name = map.get(ip.substring(0, ip.length() - 1));
            builder.append(" #").append(name).append(System.lineSeparator());
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