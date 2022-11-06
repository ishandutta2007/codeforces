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
            ECompressWords solver = new ECompressWords();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ECompressWords {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            char[] buf = new char[1000000];
            AppendableHash h31 = new AppendableHash(1000000, 31);
            AppendableHash h11 = new AppendableHash(1000000, 11);
            AppendableHash new31 = new AppendableHash(h31, 1000000);
            AppendableHash new11 = new AppendableHash(h11, 1000000);
            for (int i = 0; i < n; i++) {
                int len = in.readString(buf, 0);
                new31.clear();
                new11.clear();
                for (int j = 0; j < len; j++) {
                    new31.append(buf[j]);
                    new11.append(buf[j]);
                }

                int repeat;
                int whole = h31.size();
                for (repeat = Math.min(len, whole);
                     repeat > 0; repeat--) {
                    int l = whole - repeat;
                    int r = whole - 1;

                    int ll = 0;
                    int rr = repeat - 1;
                    if (new31.hash(ll, rr) ==
                            h31.hash(l, r) &&
                            new11.hash(ll, rr) ==
                                    h11.hash(l, r)) {
                        break;
                    }
                }

                for (int j = repeat; j < len; j++) {
                    h31.append(buf[j]);
                    h11.append(buf[j]);
                    out.append(buf[j]);
                }
            }
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 20];
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

        public int readString(char[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
        }

    }

    static class Modular {
        int m;

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public int valueOf(int x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return x;
        }

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

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

    static class Power {
        final Modular modular;

        public Power(Modular modular) {
            this.modular = modular;
        }

        public int pow(int x, int n) {
            if (n == 0) {
                return modular.valueOf(1);
            }
            long r = pow(x, n >> 1);
            r = modular.valueOf(r * r);
            if ((n & 1) == 1) {
                r = modular.valueOf(r * x);
            }
            return (int) r;
        }

        public int inverseByFermat(int x) {
            return pow(x, modular.m - 2);
        }

    }

    static class AppendableHash {
        public static final Modular MOD = new Modular((int) (1e9 + 7));
        public static final Power POWER = new Power(MOD);
        private int[] inverse;
        private int[] xs;
        private int[] hash;
        int size;

        public AppendableHash(AppendableHash hash, int size) {
            this.inverse = hash.inverse;
            this.xs = hash.xs;
            this.hash = new int[size + 1];
        }

        public AppendableHash(int size, int x) {
            inverse = new int[size + 1];
            hash = new int[size + 1];
            xs = new int[size + 1];
            int invX = POWER.inverseByFermat(x);
            inverse[0] = 1;
            xs[0] = 1;
            for (int i = 1; i <= size; i++) {
                this.inverse[i] = MOD.mul(this.inverse[i - 1], invX);
                xs[i] = MOD.mul(xs[i - 1], x);
            }
        }

        public void append(int v) {
            hash[size] = MOD.mul(xs[size], v);
            if (size > 0) {
                hash[size] = MOD.plus(hash[size], hash[size - 1]);
            }
            size++;
        }

        public int size() {
            return size;
        }

        public void clear() {
            size = 0;
        }

        public int hash(int l, int r) {
            long h = hash[r];
            if (l > 0) {
                h -= hash[l - 1];
                h *= inverse[l];
            }
            return MOD.valueOf(h);
        }

    }
}