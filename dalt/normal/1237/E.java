import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Set;
import java.io.IOException;
import java.util.HashSet;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.LinkedHashSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
 * 
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
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
            TaskE solver = new TaskE();
            solver.solve(1, in, out);
            out.close();
        }
    }
    static class TaskE {
        NumberTheory.Log2 log2 = new NumberTheory.Log2();

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();

            Set<Integer> left = new LinkedHashSet<>();
            Set<Integer> right = new LinkedHashSet<>();
            left.add(0);
            right.add(0);

            Set<Integer> all = new HashSet<>();
            all.add(0);

            for (int i = 1; i <= 21; i++) {
                int min = (1 << (i - 1));
                int max = (1 << i) - 1;
                Set<Integer> localLeft = new HashSet<>();
                Set<Integer> localRight = new HashSet<>();

                for (int l : left) {
                    for (int r : right) {
                        if (l + r + 1 < min || l + r + 1 > max) {
                            continue;
                        }
                        if (level(l) > level(r + 1) || level(l + 1) < level(r)) {
                            continue;
                        }

                        all.add(l + r + 1);
                        if ((l + 1) % 2 == (l + r + 1) % 2) {
                            localLeft.add(l + r + 1);
                        }
                        if ((l + 1) % 2 == 0) {
                            localRight.add(l + r + 1);
                        }
                    }
                }

                left.addAll(localLeft);
                right.addAll(localRight);
            }

            out.println(all.contains(n) ? 1 : 0);
        }

        public int level(int x) {
            return log2.ceilLog(x + 1);
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
                    throw new RuntimeException(e);
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
        private StringBuilder cache = new StringBuilder(1 << 20);
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

    }
    static class NumberTheory {
        public static class Log2 {
            public int ceilLog(int x) {
                return 32 - Integer.numberOfLeadingZeros(x - 1);
            }

        }

    }
}