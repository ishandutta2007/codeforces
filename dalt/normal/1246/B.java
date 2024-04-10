import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.Map;
import java.io.Closeable;
import java.util.Map.Entry;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
            TaskB solver = new TaskB();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskB {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();
            int[] a = new int[n];


            long limit = (long) 1e5;
            Map<Integer, Integer> cntMap = new HashMap<>(n);
            Map<Integer, Integer> invMap = new HashMap<>(n);
            for (int i = 0; i < n; i++) {
                int v = in.readInt();
                int built = 1;
                long inv = 1;
                boolean hasInv = true;
                for (int j = 2; j * j <= v; j++) {
                    if (v % j != 0) {
                        continue;
                    }
                    int factor = 0;
                    while (v % j == 0) {
                        v /= j;
                        factor++;
                    }
                    factor %= k;
                    for (int t = 0; t < factor; t++) {
                        built *= j;
                    }
                    for (int t = 0; t < (k - factor) % k; t++) {
                        inv *= j;
                        if (inv > limit) {
                            hasInv = false;
                        }
                    }
                }
                built *= v;
                for (int j = 1; j < k; j++) {
                    inv *= v;
                    if (inv > limit) {
                        hasInv = false;
                    }
                }

                if (hasInv) {
                    invMap.put(built, (int) inv);
                }
                a[i] = built;
                cntMap.put(a[i], cntMap.getOrDefault(a[i], 0) + 1);
            }

            LongList xk = new LongList();
            long limit2 = (long) 1e10;
            for (int i = 1; i <= 100000; i++) {
                long v = 1;
                boolean valid = true;
                for (int j = 0; j < k; j++) {
                    v *= i;
                    if (v > limit2) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    xk.add(v);
                }
            }

            if (k <= 3) {
                long ans = 0;
                for (Map.Entry<Integer, Integer> entry : cntMap.entrySet()) {
                    int key = entry.getKey();
                    if (!invMap.containsKey(key)) {
                        continue;
                    }
                    int inv = invMap.get(key);
                    if (inv == key) {
                        ans += (long) entry.getValue() * (entry.getValue() - 1);
                    } else {
                        ans += (long) entry.getValue() * (cntMap.getOrDefault(inv, 0));
                    }

                }
                out.println(ans / 2);
                return;
            }

            long ans = 0;
            for (Map.Entry<Integer, Integer> entry : cntMap.entrySet()) {
                int key = entry.getKey();
                for (int j = 0, until = xk.size(); j < until; j++) {
                    long v = xk.get(j);
                    if (v % key != 0) {
                        continue;
                    }
                    if (v / key > limit) {
                        continue;
                    }
                    int other = (int) (v / key);
                    if (other == key) {
                        ans += (long) entry.getValue() * (entry.getValue() - 1);
                    } else {
                        ans += (long) entry.getValue() * cntMap.getOrDefault(other, 0);
                    }
                }
            }

            out.println(ans / 2);
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

    static class LongList {
        private int size;
        private int cap;
        private long[] data;
        private static final long[] EMPTY = new long[0];

        public LongList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new long[cap];
            }
        }

        public LongList(LongList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public LongList() {
            this(0);
        }

        private void ensureSpace(int need) {
            int req = size + need;
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException();
            }
        }

        public long get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(long x) {
            ensureSpace(1);
            data[size++] = x;
        }

        public int size() {
            return size;
        }

        public String toString() {
            return Arrays.toString(Arrays.copyOf(data, size));
        }

    }
}