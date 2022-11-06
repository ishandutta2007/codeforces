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
            TaskA solver = new TaskA();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskA {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int m = in.readInt();
            int k = in.readInt();
            int n = in.readInt();
            int s = in.readInt();

            if (s > k) {
                out.println(-1);
                return;
            }

            int[] data = new int[m + 1];
            for (int i = 1; i <= m; i++) {
                data[i] = in.readInt();
            }

            Counter counter = new Counter(1000000);
            for (int i = 0; i < s; i++) {
                counter.addReq(in.readInt());
            }

            int l = -1;
            int r = -1;
            boolean valid = false;
            int tail = 0;
            int prevRemove = -1;
            int middleRemove = -1;
            for (int i = 1; i <= m; i++) {
                if (i != 1) {
                    counter.delete(data[i - 1]);
                }
                while (tail + 1 <= m && !counter.enough()) {
                    counter.add(data[tail + 1]);
                    tail++;
                }
                if (!counter.enough()) {
                    break;
                }
                l = i;
                r = tail;
                prevRemove = (l - 1) % k;
                middleRemove = 0;
                if (r - l + 1 >= k) {
                    middleRemove += (r - l + 1) - k;
                } else {
                    prevRemove -= Math.min((l - 1) % k, k - (r - l + 1));
                }

                if (m - (prevRemove + middleRemove) >= (long) k * n) {
                    valid = true;
                    break;
                }
            }

            if (!valid) {
                out.println(-1);
                return;
            }

            out.println(prevRemove + middleRemove);
            for (int i = 1; i <= prevRemove; i++) {
                out.append(i).append(' ');
            }
            for (int i = l, j = 0; i <= r && j < middleRemove; i++) {
                counter.delete(data[i]);
                if (!counter.enough()) {
                    counter.add(data[i]);
                    continue;
                }
                out.append(i).append(' ');
                j++;
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
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

    static class Counter {
        int[] req;
        int total = 0;

        public Counter(int c) {
            req = new int[c];
        }

        public void addReq(int x) {
            req[x]++;
            if (req[x] == 1) {
                total++;
            }
        }

        public void add(int x) {
            req[x]--;
            if (req[x] == 0) {
                total--;
            }
        }

        public void delete(int x) {
            addReq(x);
        }

        public boolean enough() {
            return total == 0;
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