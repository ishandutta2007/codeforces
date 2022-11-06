import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
            FTrucksAndCities solver = new FTrucksAndCities();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FTrucksAndCities {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt();
            }
            Car[] cars = new Car[m];
            for (int i = 0; i < m; i++) {
                cars[i] = new Car();
                cars[i].s = in.readInt() - 1;
                cars[i].f = in.readInt() - 1;
                cars[i].c = in.readInt();
                cars[i].r = in.readInt();
            }
            Map<Integer, List<Car>> carGroupByR =
                    Stream.of(cars).collect(Collectors.groupingBy(x -> x.r));

            int[][] lastDp = new int[n][n];
            int[][] nextDp = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    if (i == j) {
                        lastDp[i][j] = 0;
                    } else {
                        lastDp[i][j] = a[j] - a[i];
                    }
                }
            }

            relax(lastDp, carGroupByR.get(0));
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < n; j++) {
                    int ptr = j;
                    for (int k = j; k < n; k++) {
                        while (ptr < k && Math.max(lastDp[j][ptr], a[k] - a[ptr]) >=
                                Math.max(lastDp[j][ptr + 1], a[k] - a[ptr + 1])) {
                            ptr++;
                        }
                        nextDp[j][k] = Math.max(lastDp[j][ptr], a[j] - a[ptr]);
                    }
                }
                relax(nextDp, carGroupByR.get(i));
                {
                    int[][] tmp = lastDp;
                    lastDp = nextDp;
                    nextDp = tmp;
                }
            }

            long ans = 0;
            for (Car car : cars) {
                ans = Math.max(ans, car.v);
            }

            out.println(ans);
        }

        public void relax(int[][] dp, List<Car> cars) {
            if (cars == null) {
                return;
            }
            for (Car car : cars) {
                long stepAtLeast = (long) dp[car.s][car.f] * car.c;
                car.v = stepAtLeast;
            }
        }

    }

    static class Car {
        int s;
        int f;
        int c;
        int r;
        long v;

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