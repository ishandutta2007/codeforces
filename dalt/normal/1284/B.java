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
            BNewYearAndAscentSequence solver = new BNewYearAndAscentSequence();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class BNewYearAndAscentSequence {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Seq[] seqs = new Seq[n];
            for (int i = 0; i < n; i++) {
                int l = in.readInt();
                seqs[i] = new Seq();
                seqs[i].max = seqs[i].min = in.readInt();
                for (int j = 1; j < l; j++) {
                    int x = in.readInt();
                    if (x > seqs[i].min) {
                        seqs[i].include = true;
                    }
                    seqs[i].max = Math.max(seqs[i].max, x);
                    seqs[i].min = Math.min(seqs[i].min, x);
                }
            }

            int limit = 1000000;
            int[] cnts = new int[limit + 1];
            int include = 0;
            for (int i = 0; i < n; i++) {
                if (!seqs[i].include) {
                    cnts[seqs[i].min]++;
                } else {
                    include++;
                }
            }

            IntegerPreSum ps = new IntegerPreSum(cnts);
            long ans = 0;
            for (int i = 0; i < n; i++) {
                if (!seqs[i].include) {
                    ans += ps.intervalSum(0, seqs[i].max - 1) + include;
                } else {
                    ans += n;
                }
            }

            out.println(ans);
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

    static class IntegerPreSum {
        private int[] pre;

        public IntegerPreSum(int n) {
            pre = new int[n];
        }

        public void populate(int[] a) {
            int n = a.length;
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a[i];
            }
        }

        public IntegerPreSum(int[] a) {
            this(a.length);
            populate(a);
        }

        public int intervalSum(int l, int r) {
            if (l > r) {
                return 0;
            }
            if (l == 0) {
                return pre[r];
            }
            return pre[r] - pre[l - 1];
        }

    }

    static class Seq {
        int min;
        int max;
        boolean include;

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

        public FastOutput println(long c) {
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