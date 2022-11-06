import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.AbstractMap;
import java.util.TreeMap;
import java.io.Closeable;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
            DFlipAndReverse solver = new DFlipAndReverse();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class DFlipAndReverse {
        char[] s = new char[(int) 1e6];

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.rs(s, 0);
            MultiSet<Integer> ms = new MultiSet<>();
            int ps = 0;
            for (int i = 0; i < n; i++) {
                int x = s[i] - '0';
                ps += x == 1 ? 1 : -1;
                if (x == 1) {
                    ms.add(ps);
                }
            }
            ps = 0;
            for (int i = 0; i < n; i++) {
                int cnt = ms.count(ps);
                if (cnt > 0) {
                    out.append(0);
                    ps--;
                } else if (ms.count(ps + 1) > 0) {
                    ms.remove(ps + 1);
                    out.append(1);
                    ps++;
                } else {
                    out.append(0);
                    ps--;
                }
            }
            out.println();
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 1 << 13;
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

        public FastOutput println() {
            return append(System.lineSeparator());
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
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public String next() {
            return readString();
        }

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
        }

        public int rs(char[] data, int offset) {
            return readString(data, offset);
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

    static class MultiSet<T> {
        private TreeMap<T, Integer> map;
        private int size;

        public MultiSet(Comparator<T> comp) {
            this.map = new TreeMap<>(comp);
        }

        public MultiSet() {
            this.map = new TreeMap<>();
        }

        public void add(T key) {
            size++;
            update(key, map.getOrDefault(key, 0) + 1);
        }

        public void remove(T key) {
            size--;
            update(key, map.getOrDefault(key, 0) - 1);
        }

        public void update(T key, int cnt) {
            if (cnt == 0) {
                map.remove(key);
            } else if (cnt > 0) {
                map.put(key, cnt);
            } else {
                size++;
            }
        }

        public int count(T key) {
            return map.getOrDefault(key, 0);
        }

        public String toString() {
            return map.toString();
        }

    }
}