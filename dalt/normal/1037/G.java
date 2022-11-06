import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            GAGameOnStrings solver = new GAGameOnStrings();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GAGameOnStrings {
        char[] s;
        int n;
        int[] prefixSum;
        int[][] prefix;
        int[][] suffix;
        int[][] nextIndex;
        int[][] lastIndex;
        int charset = 'z' - 'a' + 1;
        int[] mex = new int[32];

        public void solve(int testNumber, FastInput in, FastOutput out) {
            s = new char[(int) 1e5];
            n = in.readString(s, 0);
            for (int i = 0; i < n; i++) {
                s[i] -= 'a';
            }
            prefixSum = new int[n];
            prefix = new int[charset][n];
            suffix = new int[charset][n];
            nextIndex = new int[charset][n];
            lastIndex = new int[charset][n];

            SequenceUtils.deepFill(prefixSum, -1);
            SequenceUtils.deepFill(prefix, -1);
            SequenceUtils.deepFill(suffix, -1);
            SequenceUtils.deepFill(nextIndex, n);
            SequenceUtils.deepFill(lastIndex, -1);

            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    for (int j = 0; j < charset; j++) {
                        lastIndex[j][i] = lastIndex[j][i - 1];
                    }
                }
                lastIndex[s[i]][i] = i;
            }
            for (int i = n - 1; i >= 0; i--) {
                if (i < n - 1) {
                    for (int j = 0; j < charset; j++) {
                        nextIndex[j][i] = nextIndex[j][i + 1];
                    }
                }
                nextIndex[s[i]][i] = i;
            }

            for (int i = 0; i < n; i++) {
                prefixSum(i);
            }

            int m = in.readInt();
            for (int i = 0; i < m; i++) {
                int l = in.readInt() - 1;
                int r = in.readInt() - 1;
                int sg = queryInterval(l, r);
                out.println(sg == 0 ? "Bob" : "Alice");
            }
        }

        public int queryInterval(int l, int r) {
            if (l > r) {
                return 0;
            }
            for (int i = 0; i < charset; i++) {
                int begin = nextIndex[i][l];
                int end = lastIndex[i][r];
                if (begin > end) {
                    continue;
                }
                int xor = prefixSum(begin, end);
                if (begin > l) {
                    xor ^= suffix(i, l);
                }
                if (end < r) {
                    xor ^= prefix(i, r);
                }
            }
            Arrays.fill(mex, 0);
            for (int i = 0; i < charset; i++) {
                int begin = nextIndex[i][l];
                int end = lastIndex[i][r];
                if (begin > end) {
                    continue;
                }
                int xor = prefixSum(begin, end);
                if (begin > l) {
                    xor ^= suffix(i, l);
                }
                if (end < r) {
                    xor ^= prefix(i, r);
                }
                mex[xor] = 1;
            }

            for (int i = 0; ; i++) {
                if (mex[i] == 0) {
                    return i;
                }
            }
        }

        public int prefix(int c, int i) {
            if (prefix[c][i] == -1) {
                prefix[c][i] = queryInterval(lastIndex[c][i] + 1, i);
            }
            return prefix[c][i];
        }

        public int suffix(int c, int i) {
            if (suffix[c][i] == -1) {
                suffix[c][i] = queryInterval(i, nextIndex[c][i] - 1);
            }
            return suffix[c][i];
        }

        public int prefixSum(int l, int r) {
            if (l >= r) {
                return 0;
            }
            return prefixSum(l) ^ prefixSum(r);
        }

        public int strictlyLastIndex(int i) {
            return i == 0 ? -1 : lastIndex[s[i]][i - 1];
        }

        public int prefixSum(int i) {
            if (prefixSum[i] == -1) {
                int last = strictlyLastIndex(i);
                if (last == -1) {
                    prefixSum[i] = 0;
                } else {
                    prefixSum[i] = prefixSum(last) ^
                            queryInterval(last + 1, i - 1);
                }
            }
            return prefixSum[i];
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

        public int readString(char[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
        }

    }

    static class SequenceUtils {
        public static void deepFill(Object array, int val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof int[]) {
                int[] intArray = (int[]) array;
                Arrays.fill(intArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
            }
        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(String c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }
}