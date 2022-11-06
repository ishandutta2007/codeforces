import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
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
            TaskB solver = new TaskB();
            solver.solve(1, in, out);
            out.close();
        }
    }
    static class TaskB {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            long[] a = new long[n];
            long[] b = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.readChar() - '0';
            }
            for (int i = 0; i < n; i++) {
                b[i] = in.readChar() - '0';
            }
            long[] req = new long[n - 1];
            req[0] = b[0] - a[0];
            for (int i = 1; i < n - 1; i++) {
                req[i] = b[i] - (req[i - 1] + a[i]);
            }
            if (req[n - 2] + a[n - 1] != b[n - 1]) {
                out.println(-1);
                return;
            }

            long ans = 0;
            for (int i = 0; i < n - 1; i++) {
                ans += Math.abs(req[i]);
            }


            List<int[]> op = new ArrayList<>(100000);
            boolean[] inque = new boolean[n - 1];
            Deque<Integer> deque = new ArrayDeque<>(n - 1);
            for (int i = 0; i < n - 1; i++) {
                deque.addLast(i);
                inque[i] = true;
            }

            while (op.size() < 100000 && !deque.isEmpty()) {
                int head = deque.removeFirst();
                inque[head] = false;

                if (req[head] > 0) {
                    if (a[head] < 9 && a[head + 1] < 9) {
                        req[head]--;
                        a[head]++;
                        a[head + 1]++;
                        op.add(SequenceUtils.wrapArray(head, 1));
                        add(deque, inque, head);
                        add(deque, inque, head - 1);
                        add(deque, inque, head + 1);
                    }
                } else if (req[head] < 0) {
                    if (a[head + 1] > 0 && (head == 0 && a[head] > 1 || head > 0 && a[head] > 0)) {
                        req[head]++;
                        a[head]--;
                        a[head + 1]--;
                        op.add(SequenceUtils.wrapArray(head, -1));
                        add(deque, inque, head);
                        add(deque, inque, head - 1);
                        add(deque, inque, head + 1);
                    }
                }
            }

            out.println(ans);
            for (int[] x : op) {
                out.append(x[0] + 1).append(' ').append(x[1]).println();
            }
        }

        public void add(Deque<Integer> deque, boolean[] inque, int x) {
            if (x < 0 || x >= inque.length || inque[x]) {
                return;
            }
            deque.addLast(x);
            inque[x] = true;
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

        public FastOutput println(long c) {
            cache.append(c).append('\n');
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
    static class SequenceUtils {
        public static int[] wrapArray(int... x) {
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
}