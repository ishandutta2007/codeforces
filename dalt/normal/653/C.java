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
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
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
            CBearAndUpDown solver = new CBearAndUpDown();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CBearAndUpDown {
        int[] a;
        int invalid;

        private int consider(int i) {
            if (i < 0 || i + 1 >= a.length) {
                return 0;
            }
            if (i % 2 == 0) {
                if (a[i] >= a[i + 1]) {
                    return 1;
                }
            } else {
                if (a[i] <= a[i + 1]) {
                    return 1;
                }
            }
            return 0;
        }

        private void discard(int i) {
            invalid -= consider(i - 1) + consider(i);
        }

        private void add(int i) {
            invalid += consider(i - 1) + consider(i);
        }

        public void swap(int i, int j) {
            if (i > j) {
                i ^= j;
                j ^= i;
                i ^= j;
            }
            if (i + 1 == j) {
                invalid -= consider(i - 1) + consider(i) + consider(i + 1);
                SequenceUtils.swap(a, i, j);
                invalid += consider(i - 1) + consider(i) + consider(i + 1);
                return;
            }
            discard(i);
            discard(j);
            SequenceUtils.swap(a, i, j);
            add(i);
            add(j);
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            a = in.ri(n);
            int index = 0;
            for (int i = 0; i + 1 < n; i++) {
                int contrib = consider(i);
                invalid += contrib;
                if (contrib == 1) {
                    index = i;
                }
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (i == index) {
                    continue;
                }
                swap(i, index);
                if (invalid == 0) {
                    ans++;
                }
                swap(i, index);
            }
            for (int i = 0; i < n; i++) {
                if (i == index + 1) {
                    continue;
                }
                swap(i, index + 1);
                if (invalid == 0) {
                    ans++;
                }
                swap(i, index + 1);
            }
            swap(index, index + 1);
            if (invalid == 0) {
                ans--;
            }
            swap(index, index + 1);
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

        public void populate(int[] data) {
            for (int i = 0; i < data.length; i++) {
                data[i] = readInt();
            }
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

        public int ri() {
            return readInt();
        }

        public int[] ri(int n) {
            int[] ans = new int[n];
            populate(ans);
            return ans;
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

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private final Writer os;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < THRESHOLD) {
                return;
            }
            flush();
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
        }

        public FastOutput flush() {
            try {
//            boolean success = false;
//            if (stringBuilderValueField != null) {
//                try {
//                    char[] value = (char[]) stringBuilderValueField.get(cache);
//                    os.write(value, 0, cache.length());
//                    success = true;
//                } catch (Exception e) {
//                }
//            }
//            if (!success) {
                os.append(cache);
//            }
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