import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.stream.Collectors;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
import java.util.Map;
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
            BGameWithString solver = new BGameWithString();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class BGameWithString {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            char[] s = in.readString().toCharArray();
            int n = s.length;
            Rotate[] rotates = new Rotate[n];
            for (int i = 0; i < n; i++) {
                rotates[i] = new Rotate(s, i);
            }
            Map<Integer, List<Rotate>> groupByFirst =
                    Stream.of(rotates)
                            .collect(Collectors.groupingBy(x -> x.get(0)));

            Rotate[] appear = new Rotate['z' - 'a' + 1];
            long sum = 0;
            Rotate dump = new Rotate(s, 0);
            for (List<Rotate> list : groupByFirst.values()) {
//            for (Rotate r : list) {
//                System.err.println(r);
//            }
                long max = 0;
                for (int i = 0; i < n; i++) {
                    Arrays.fill(appear, null);
                    for (Rotate r : list) {
                        int c = r.get(i) - 'a';
                        if (appear[c] != null) {
                            appear[c] = dump;
                        } else {
                            appear[c] = r;
                        }
                    }
                    int cnt = 0;
                    for (Rotate r : appear) {
                        if (r != null && r != dump) {
                            cnt++;
                        }
                    }
                    max = Math.max(max, cnt);
                }

                sum += max;
            }

            out.printf("%.15f", (double) sum / n);
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

        public FastOutput printf(String format, Object... args) {
            cache.append(String.format(format, args));
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

    static class Rotate {
        char[] s;
        int begin;

        public Rotate(char[] s, int begin) {
            this.s = s;
            this.begin = begin;
        }

        public int get(int i) {
            i += begin;
            if (i >= s.length) {
                i -= s.length;
            }
            return s[i];
        }

        public String toString() {
            int n = s.length;
            StringBuilder builder = new StringBuilder(n);
            for (int i = 0; i < n; i++) {
                builder.append((char) get(i));
            }
            return builder.toString();
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

    }
}