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
            GArrayGame solver = new GArrayGame();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GArrayGame {
        private static int m;
        private static int limit;
        private static int mask;
        private static int[] bitCount;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            m = in.readInt();
            int q = in.readInt();
            limit = 1 << m;
            mask = limit - 1;
            bitCount = new int[limit];
            for (int i = 0; i < limit; i++) {
                bitCount[i] = Integer.bitCount(i);
            }
            GArrayGame.Status.buf = new int[limit];
            GArrayGame.Status.buf2 = new int[limit];
            GArrayGame.Status.self = new int[limit];
            for (int i = 0; i < limit; i++) {
                GArrayGame.Status.self[i] = i;
            }

            int[] data = new int[n + 1];
            // IntegerBIT bit = new IntegerBIT(n + 1);
            for (int i = 1; i <= n; i++) {
                data[i] = 1 - (int) (in.readLong() % 2);
                //   bit.update(i, 1 - data[i]);
                // bit.update(i + 1, 1 - data[i]);
            }


            GArrayGame.Status[] evenOrOdd = new GArrayGame.Status[2];
            for (int i = 0; i < 2; i++) {
                evenOrOdd[i] = new GArrayGame.Status();
                evenOrOdd[i].initAsSingle(i % 2 == 1);
            }
            GArrayGame.Segment seg = new GArrayGame.Segment(1, n, data, evenOrOdd);
            GArrayGame.Status query = new GArrayGame.Status();
            for (int i = 0; i < q; i++) {
                if (in.readInt() == 1) {
                    int l = in.readInt();
                    int r = in.readInt();
                    int d = in.readInt();
                    if (d % 2 == 0) {
                        continue;
                    }
                    seg.update(l, r, 1, n);
                    //    bit.update(l, 1);
                    //  bit.update(r + 1, 1);
                } else {
                    int l = in.readInt();
                    int r = in.readInt();
                    //boolean odd = bit.query(l) % 2 == 1;
                    query.init();
                    seg.query(l, r, 1, n, query);
                    int ans = query.func[mask];
                    if (ans % 2 == 1) {
                        out.println(1);
                    } else {
                        out.println(2);
                    }
                }
            }
        }

        static class Status {
            int size;
            int[] func = new int[limit];
            static int[] buf;
            static int[] buf2;
            static int[] self;

            void init() {
                size = 0;
            }

            public void initAsSingle(boolean odd) {
                if (odd) {
                    for (int i = 0; i < limit; i++) {
                        func[i] = ((i << 1) | 1) & mask;
                    }
                } else {
                    for (int i = 0; i < limit; i++) {
                        func[i] = ((i << 1) | (bitCount[i] < m ? 1 : 0)) & mask;
                    }
                }
                size = 1;
            }

            public void apply(int[] input, int[] output) {
                for (int i = 0; i < limit; i++) {
                    output[i] = func[input[i]];
                }
                if (size < m) {
                    int bufMask = (1 << size) - 1;
                    for (int i = 0; i < limit; i++) {
                        output[i] = ((output[i] & bufMask) | (input[i] << size)) & mask;
                    }
                }
            }

            public void merge(GArrayGame.Status x) {
                x.apply(self, buf);
                apply(buf, buf2);
                for (int i = 0; i < limit; i++) {
                    func[i] = buf2[i];
                }
                size += x.size;
            }

            public void merge(GArrayGame.Status a, GArrayGame.Status b) {
                size = a.size;
                for (int i = 0; i < limit; i++) {
                    func[i] = a.func[i];
                }
                merge(b);
            }

        }

        static class Segment implements Cloneable {
            private GArrayGame.Segment left;
            private GArrayGame.Segment right;
            private GArrayGame.Status[] status = new GArrayGame.Status[2];
            private boolean rev;

            public void pushUp() {
                for (int i = 0; i < 2; i++) {
                    status[i].merge(left.status[i], right.status[i]);
                }
            }

            public void rev() {
                SequenceUtils.swap(status, 0, 1);
                rev = !rev;
            }

            public void pushDown() {
                if (rev) {
                    left.rev();
                    right.rev();
                    rev = false;
                }
            }

            public Segment(int l, int r, int[] val, GArrayGame.Status[] evenOrOdd) {
                if (l < r) {
                    for (int i = 0; i < 2; i++) {
                        status[i] = new GArrayGame.Status();
                    }
                    int m = (l + r) >> 1;
                    left = new GArrayGame.Segment(l, m, val, evenOrOdd);
                    right = new GArrayGame.Segment(m + 1, r, val, evenOrOdd);
                    pushUp();
                } else {
                    status[0] = evenOrOdd[val[l] % 2];
                    status[1] = evenOrOdd[1 - val[l] % 2];
                }
            }

            private boolean covered(int ll, int rr, int l, int r) {
                return ll <= l && rr >= r;
            }

            private boolean noIntersection(int ll, int rr, int l, int r) {
                return ll > r || rr < l;
            }

            public void update(int ll, int rr, int l, int r) {
                if (noIntersection(ll, rr, l, r)) {
                    return;
                }
                if (covered(ll, rr, l, r)) {
                    rev();
                    return;
                }
                pushDown();
                int m = (l + r) >> 1;
                left.update(ll, rr, l, m);
                right.update(ll, rr, m + 1, r);
                pushUp();
            }

            public void query(int ll, int rr, int l, int r, GArrayGame.Status x) {
                if (noIntersection(ll, rr, l, r)) {
                    return;
                }
                if (covered(ll, rr, l, r)) {
                    x.merge(status[0]);
                    return;
                }
                pushDown();
                int m = (l + r) >> 1;
                left.query(ll, rr, l, m, x);
                right.query(ll, rr, m + 1, r, x);
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

        public long readLong() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            long val = 0;
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

    static class SequenceUtils {
        public static <T> void swap(T[] data, int i, int j) {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

    }
}