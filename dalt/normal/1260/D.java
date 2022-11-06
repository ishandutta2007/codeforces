import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.util.Random;
import java.util.Deque;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
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
            TaskD solver = new TaskD();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskD {
        Deque<int[]> deque = new ArrayDeque<>(200000);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int m = in.readInt();
            int n = in.readInt();
            int k = in.readInt();
            int t = in.readInt();
            int[] a = new int[m];
            for (int i = 0; i < m; i++) {
                a[i] = in.readInt();
            }
            int[][] traps = new int[k][3];
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < 3; j++) {
                    traps[i][j] = in.readInt();
                }
            }
            Randomized.randomizedArray(a, 0, m);
            Arrays.sort(a);
            Arrays.sort(traps, (x, y) -> x[0] - y[0]);

            int l = 0;
            int r = m;
            while (l < r) {
                int mid = (l + r + 1) >>> 1;
                if (check(a, traps, n, mid) <= t) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }

            out.println(l);
        }

        public int check(int[] a, int[][] traps, int n, int mid) {
            int agi;
            if (mid > 0) {
                agi = a[a.length - mid];
            } else {
                agi = (int) 1e9;
            }
            int users = 0;
            deque.clear();
            deque.addAll(Arrays.asList(traps));
            int time = 0;
            while (users < n + 1) {
                int initPos = users;
                while (!deque.isEmpty() && deque.peekFirst()[0] <= users + 1) {
                    int[] trap = deque.removeFirst();
                    if (trap[2] <= agi) {
                        continue;
                    }
                    if (trap[1] > users) {
                        time += trap[1] - users;
                        users = trap[1];
                    }
                }
                if (users > initPos) {
                    time += users - initPos;
                    users = initPos;
                } else {
                    time++;
                    users++;
                }
            }

            return time;
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

    static class Randomized {
        static Random random = new Random();

        public static void randomizedArray(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }
}