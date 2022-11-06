import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.AbstractMap;
import java.util.TreeMap;
import java.util.Map;
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
            DEels solver = new DEels();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DEels {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            Log2 log2 = new Log2();

            int q = in.readInt();

            int limit = 30;
            TreeMap<Integer, Integer>[] maps = new TreeMap[limit];
            long[] sums = new long[limit];
            for (int i = 0; i < limit; i++) {
                maps[i] = new TreeMap<>();
            }

            int total = 0;
            for (int i = 0; i < q; i++) {
                char c = in.readChar();
                int x = in.readInt();
                int l = log2.floorLog(x);
                int cnt = maps[l].getOrDefault(x, 0);

                if (c == '+') {
                    cnt++;
                    sums[l] += x;
                    total++;
                } else {
                    cnt--;
                    sums[l] -= x;
                    total--;
                }

                if (cnt != 0) {
                    maps[l].put(x, cnt);
                } else {
                    maps[l].remove(x);
                }

                long prefix = 0;
                int ans = total;
                for (int j = 0; j < limit && prefix < (1 << limit); j++) {
                    if (maps[j].isEmpty()) {
                        continue;
                    }
                    if (maps[j].firstKey() > 2 * prefix) {
                        ans--;
                    }
                    prefix += sums[j];
                }

                out.println(ans);
            }
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

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

    }

    static class Log2 {
        public int floorLog(int x) {
            return 31 - Integer.numberOfLeadingZeros(x);
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

        public FastOutput println(int c) {
            cache.append(c).append('\n');
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