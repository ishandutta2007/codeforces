import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
            TaskF solver = new TaskF();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskF {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int[] s = new int[1000000];
            int n = in.readString(s, 0);
            for (int i = 0; i < n; i++) {
                s[i] -= 'a';
            }

            BitOperator bo = new BitOperator();
            int[] len = new int[1 << 20];
            for (int i = 0; i < n; i++) {
                int mask = 0;
                for (int j = i; j < i + 20 && j < n; j++) {
                    if (bo.bitAt(mask, s[j]) == 1) {
                        break;
                    }
                    mask = bo.setBit(mask, s[j], true);
                    len[mask] = j - i + 1;
                }
            }

            for (int i = 1; i < (1 << 20); i++) {
                if (Integer.lowestOneBit(i) == i) {
                    continue;
                }
                for (int j = 0; j < 20; j++) {
                    if (bo.bitAt(i, j) == 0) {
                        continue;
                    }
                    len[i] = Math.max(len[i], len[bo.setBit(i, j, false)]);
                }
            }

            int ans = 0;
            int mask = (1 << 20) - 1;
            for (int i = 0; i < (1 << 20); i++) {
                ans = Math.max(ans, len[i] + len[mask - i]);
            }
            out.println(ans);
        }

    }

    static class BitOperator {
        public int bitAt(int x, int i) {
            return (x >> i) & 1;
        }

        public int setBit(int x, int i, boolean v) {
            if (v) {
                x |= 1 << i;
            } else {
                x &= ~(1 << i);
            }
            return x;
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

        public int readString(int[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
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