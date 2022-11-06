

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Arrays;

/**
 * Created by dalt on 2018/3/25.
 */
public class CF946E {
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF946E.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }

    public static void solve() {
        char[] data = new char[200000];
        int t = input.nextInteger();
        StringBuilder result = new StringBuilder();

        int[] registries = new int[128];
        int[] registriesCnt = new int[1];
        char[] matchWith = new char[200000];
        while (t-- > 0) {
            Arrays.fill(registries, '0', '9' + 1, 0);
            registriesCnt[0] = 0;

            int len = input.nextBlock(data, 0);
            int lastNotZero = len - 1;
            while (data[lastNotZero] == '0') {
                data[lastNotZero] = '9';
                lastNotZero--;
            }
            data[lastNotZero]--;

            if (data[0] == '0') {
                result.append(data, 2, len - 2).append('\n');
                continue;
            }

            Arrays.fill(matchWith, 0, len, (char) 0);
            int i;
            for (i = 0; (len - 1 - i) > registriesCnt[0]; i++) {
                addRegistries(registries, registriesCnt, data[i]);
                matchWith[i] = data[i];
            }


            int maxPosition = i;
            boolean findFlag = false;
            for (; maxPosition < len && !findFlag; maxPosition++) {
                for (char j = data[maxPosition]; j >= '0'; j--) {
                    if (registries[j] == 1) {
                        addRegistries(registries, registriesCnt, j);
                        matchWith[maxPosition] = j;

                        if (matchWith[maxPosition] != data[maxPosition]) {
                            for (int k = maxPosition + 1; k < len; k++) {
                                data[k] = '9';
                            }
                        }
                        break;
                    }
                }
                if (matchWith[maxPosition] == 0) {
                    findFlag = true;
                    maxPosition--;
                }
            }

            if (findFlag) {
                while (findFlag && len - maxPosition - 1 < registriesCnt[0]) {
                    findFlag = false;
                    int j = maxPosition - 1;
                    for (; data[j] == '0'; j--) {
                        addRegistries(registries, registriesCnt, matchWith[j]);
                    }
                    addRegistries(registries, registriesCnt, matchWith[j]);
                    data[j]--;
                    maxPosition = j;
                    if (registriesCnt[0] == len - j) {
                        int k;
                        for (k = data[maxPosition]; k >= '0' && registries[k] == 0; k--) ;
                        if (k < '0') {
                            findFlag = true;
                        } else {
                            matchWith[maxPosition] = (char) k;
                            addRegistries(registries, registriesCnt, matchWith[maxPosition]);
                        }
                    } else if (registriesCnt[0] + 1 <= len - j - 1) {
                        //Find the result
                        addRegistries(registries, registriesCnt, data[j]);
                        matchWith[j] = data[j];
                    }
                }

                if (maxPosition < len - 1) {
                    Arrays.fill(matchWith, maxPosition + 1, len, '9');
                }

                if (matchWith[0] != '0') {
                    int wpos = len - registriesCnt[0];
                    for (char j = '9'; j >= '0'; j--) {
                        if (registries[j] == 1) {
                            matchWith[wpos++] = j;
                        }
                    }
                }
            }

            if (data[0] == '0') {
                result.append(matchWith, 2, len - 2).append('\n');
            } else {
                result.append(matchWith, 0, len).append('\n');
            }
        }

        System.out.print(result);
    }

    public static void addRegistries(int[] registries, int[] registriesCnt, char c) {
        if (registries[c] == 0) {
            registries[c] = 1;
            registriesCnt[0]++;
        } else {
            registries[c] = 0;
            registriesCnt[0]--;
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