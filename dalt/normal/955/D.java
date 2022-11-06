
import java.io.*;
import java.util.Arrays;

/**
 * Created by dalt on 2018/4/2.
 */
public class CF955D {
    public static final int MOD = (int) (1e9 + 7);
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {

        init();

        solve();

        output.flush();
    }

    public static void init() throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF955D.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }
    }

    public static void solve() {
        int n = input.nextInteger();
        int m = input.nextInteger();
        int k = input.nextInteger();

        char[] s = new char[n];
        char[] t = new char[m];
        input.nextBlock(s, 0);
        input.nextBlock(t, 0);

        int p = Math.min(k, m);
        KAM prefixKAM = new KAM(p, t[0]);
        KAM suffixKAM = new KAM(p, t[m - 1]);
        for (int i = 1; i < p; i++) {
            prefixKAM.build(t[i]);
            suffixKAM.build(t[m - i - 1]);
        }

        if (k >= m) {
            prefixKAM.beginMatch();
            for (int i = 0; i < n; i++) {
                prefixKAM.match(s[i]);
                if (prefixKAM.matchLength == m) {
                    int start = i - k + 1;
                    int l = 0;
                    int r = Math.max(start, k);
                    output.println("Yes");
                    output.println(l + 1);
                    output.println(r + 1);
                    return;
                }
            }
        }

        prefixKAM.beginMatch();
        suffixKAM.beginMatch();
        int[] prefixRegistries = new int[p + 1];
        Arrays.fill(prefixRegistries, -1);
        int[] suffixRegistries = new int[p + 1];
        Arrays.fill(suffixRegistries, -1);
        for (int i = 0, until = k - 1; i < until; i++) {
            prefixKAM.match(s[i]);
            suffixKAM.match(s[n - i - 1]);
        }
        for (int i = k - 1; i < n; i++) {
            prefixKAM.match(s[i]);
            suffixKAM.match(s[n - i - 1]);
            addRegistry(prefixRegistries, prefixKAM, i);
            addRegistry(suffixRegistries, suffixKAM, n - i - 1);
        }

        for (int i = 1, until = p; i <= until; i++) {
            if (m - i > p) {
                continue;
            }
            if (prefixRegistries[i] != -1 && suffixRegistries[m - i] != -1 && prefixRegistries[i] < suffixRegistries[m - i]) {
                output.println("Yes");
                output.println(prefixRegistries[i] - k + 2);
                output.println(suffixRegistries[m - i] + 1);
                return;
            }
        }

        output.println("No");
        return;
    }

    public static void addRegistry(int[] registries, KAM kam, int id) {
        int match = kam.matchLength;
        while (match > 0 && registries[match] == -1) {
            registries[match] = id;
            match = kam.fail[match - 1];
        }
    }

    public static class KAM {
        int[] fail;
        char[] data;
        int buildLength;
        int matchLength;

        public KAM(int cap, char c) {
            fail = new int[cap + 1];
            data = new char[cap + 1];
            fail[0] = 0;
            data[0] = c;
            buildLength = 1;
        }

        public void beginMatch() {
            matchLength = 0;
        }

        public void build(char c) {
            data[buildLength] = c;
            fail[buildLength] = find(fail[buildLength - 1], c);
            buildLength++;
        }

        public int find(int curMatch, char c) {
            while (curMatch > 0 && data[curMatch] != c) {
                curMatch = fail[curMatch - 1];
            }
            return data[curMatch] == c ? curMatch + 1 : 0;
        }

        public void match(char c) {
            matchLength = find(matchLength, c);
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

        public long nextLong() {
            skipBlank();
            long ret = 0;
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