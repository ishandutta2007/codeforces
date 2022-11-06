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
            DEnchantedArtifact solver = new DEnchantedArtifact();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DEnchantedArtifact {
        FastOutput out;
        FastInput in;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            this.out = out;
            this.in = in;
            char[] allA = new char[300];
            char[] allB = new char[300];
            for (int i = 0; i < 300; i++) {
                allA[i] = 'a';
                allB[i] = 'b';
            }
            int aCnt = 300 - cast(allA);
            if (aCnt == 300) {
                return;
            }
            int bCnt = 300 - cast(allB);
            if (bCnt == 300) {
                return;
            }
            int n = aCnt + bCnt;
            char[] data = new char[n];
            Arrays.fill(data, 'a');
            int status = n - aCnt;
            for (int i = 0; i < n - 1; i++) {
                data[i] = 'b';
                int newStatus = cast(data);
                if (newStatus > status) {
                    data[i] = 'a';
                    continue;
                }
                status = newStatus;
            }

            if (status == 0) {
                cast(data);
                return;
            } else {
                data[n - 1] = 'b';
                cast(data);
            }
        }

        public int cast(char[] s) {
            for (char c : s) {
                out.append(c);
            }
            out.println();
            out.flush();
            return in.readInt();
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
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

    }
}