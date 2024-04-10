import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.lang.reflect.Field;
import java.util.stream.Collectors;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
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
            EAquaMoonAndPermutations solver = new EAquaMoonAndPermutations();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class EAquaMoonAndPermutations {
        int mod = 998244353;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            List<int[]> ps = new ArrayList<>(n * 2);
            for (int i = 0; i < n * 2; i++) {
                int[] p = new int[n + 1];
                for (int j = 0; j < n; j++) {
                    p[j] = in.ri();
                }
                p[n] = i;
                ps.add(p);
            }
            List<Integer> res = new ArrayList<>(n);
            int[][] cnts = new int[n + 1][n + 1];
            long ans = 1;
            while (!ps.isEmpty()) {
                SequenceUtils.fill(cnts, 0);
                for (int[] p : ps) {
                    for (int i = 0; i < n; i++) {
                        cnts[i][p[i]]++;
                    }
                }
                int col = -1;
                int v = -1;
                for (int i = 0; i < n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (cnts[i][j] == 1) {
                            col = i;
                            v = j;
                        }
                    }
                }
                int[] pick = null;
                if (col != -1) {
                    for (int i = 0; i < ps.size(); i++) {
                        int[] p = ps.get(i);
                        if (p[col] == v) {
                            //find
                            pick = p;
                        }
                    }
                } else {
                    pick = ps.get(0);
                    ans = ans * 2 % mod;
                }
                assert pick != null;
                res.add(pick[n]);
                int[] finalPick = pick;
                ps = ps.stream().filter(x -> {
                    for (int i = 0; i < n; i++) {
                        if (x[i] == finalPick[i]) {
                            return false;
                        }
                    }
                    return true;
                }).collect(Collectors.toList());
            }

            res.sort(Comparator.naturalOrder());
            out.println(ans);
            for (int x : res) {
                out.append(x + 1).append(' ');
            }
            out.println();
        }

    }

    static class SequenceUtils {
        public static void fill(int[][] x, int val) {
            for (int[] v : x) {
                Arrays.fill(v, val);
            }
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public String next() {
            return readString();
        }

        public int ri() {
            return readInt();
        }

        public int readInt() {
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
        }

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private OutputStream writer;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);
        private static Field stringBuilderValueField;

        static {
            try {
                stringBuilderValueField = StringBuilder.class.getSuperclass().getDeclaredField("value");
                stringBuilderValueField.setAccessible(true);
            } catch (Exception e) {
                stringBuilderValueField = null;
            }
        }

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < THRESHOLD) {
                return;
            }
            flush();
        }

        public FastOutput(OutputStream writer) {
            this.writer = writer;
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append('\n');
        }

        public FastOutput flush() {
            try {
                if (stringBuilderValueField != null) {
                    try {
                        byte[] value = (byte[]) stringBuilderValueField.get(cache);
                        writer.write(value, 0, cache.length());
                    } catch (Exception e) {
                        stringBuilderValueField = null;
                    }
                }
                if (stringBuilderValueField == null) {
                    //slow
                    writer.write(cache.toString().getBytes(StandardCharsets.UTF_8));
//                writer.append(cache);
                }
                writer.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                writer.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }
}