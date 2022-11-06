import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Iterator;
import java.io.IOException;
import java.util.TreeSet;
import java.io.UncheckedIOException;
import java.io.Closeable;
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
            DComputerGame solver = new DComputerGame();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DComputerGame {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            long t = in.readLong();
            Quest[] quests = new Quest[n];
            for (int i = 0; i < n; i++) {
                quests[i] = new Quest();
                quests[i].a = in.readInt();
                quests[i].b = in.readInt();
                quests[i].p = in.readDouble();
            }

            double E = 0;
            for (int i = 0; i < n; i++) {
                E = Math.max(E, quests[i].p * quests[i].b);
            }

            ConvexHullTrick cht = new ConvexHullTrick();
            for (Quest q : quests) {
                cht.insert(q.p, q.a * q.p, q);
            }

            long now = 0;
            double begin = 0;
            for (ConvexHullTrick.Line line : cht) {
                double rx = line.rx;
                BSResult result = bs(now, t, line.quest, E, begin, rx);
                begin = result.state;
                now = result.now;
                if (now == t) {
                    break;
                }
            }

            out.printf("%.13f", begin);
        }

        public BSResult bs(long l, long r, Quest q, double E, double begin, double rx) {
            Matrix[] mats = new Matrix[35];
            Matrix x = new Matrix(new double[][]{
                    {1 - q.p, E * q.p, q.a * q.p},
                    {0, 1, 1},
                    {0, 0, 1}
            });
            mats[0] = x;
            for (int i = 1; i < 35; i++) {
                mats[i] = Matrix.mul(mats[i - 1], mats[i - 1]);
            }

            Matrix next = new Matrix(3, 1);
            Matrix vector = new Matrix(new double[][]{
                    {begin},
                    {l},
                    {1}
            });
            long now = l;
            for (int i = 35 - 1; i >= 0; i--) {
                if (now + (1L << i) > r) {
                    continue;
                }
                Matrix.mul(mats[i], vector, next);
                if (E * (now + (1L << i)) - next.get(0, 0) < rx) {
                    now += 1L << i;
                    Matrix tmp = next;
                    next = vector;
                    vector = tmp;
                }
            }

            if (now < r && E * now - vector.get(0, 0) < rx) {
                now++;
                vector = Matrix.mul(mats[0], vector);
            }

            return new BSResult(vector.get(0, 0), now);
        }

    }

    static class ConvexHullTrick implements Iterable<ConvexHullTrick.Line> {
        static final double INF = 1e50;
        private TreeSet<ConvexHullTrick.Line> setOrderByA = new TreeSet(ConvexHullTrick.Line.orderByA);
        private TreeSet<ConvexHullTrick.Line> setOrderByLx = new TreeSet(ConvexHullTrick.Line.orderByLx);

        public ConvexHullTrick.Line insert(double a, double b, Quest quest) {
            ConvexHullTrick.Line newLine = new ConvexHullTrick.Line(a, b);
            newLine.quest = quest;
            boolean add = true;
            while (add) {
                ConvexHullTrick.Line prev = setOrderByA.floor(newLine);
                if (prev == null) {
                    newLine.lx = -INF;
                    break;
                }
                if (prev.a == newLine.a) {
                    if (prev.b >= newLine.b) {
                        add = false;
                        break;
                    } else {
                        setOrderByA.remove(prev);
                        setOrderByLx.remove(prev);
                    }
                } else {
                    double lx = ConvexHullTrick.Line.intersectAt(prev, newLine);
                    if (lx <= prev.lx) {
                        setOrderByA.remove(prev);
                        setOrderByLx.remove(prev);
                    } else if (lx > prev.rx) {
                        add = false;
                        break;
                    } else {
                        prev.rx = lx;
                        newLine.lx = lx;
                        break;
                    }
                }
            }

            while (add) {
                ConvexHullTrick.Line next = setOrderByA.ceiling(newLine);
                if (next == null) {
                    newLine.rx = INF;
                    break;
                }
                double rx = ConvexHullTrick.Line.intersectAt(newLine, next);
                if (rx >= next.rx) {
                    setOrderByA.remove(next);
                    setOrderByLx.remove(next);
                } else if (rx < next.lx || (newLine.lx >= rx)) {
                    ConvexHullTrick.Line lastLine = setOrderByA.floor(newLine);
                    if (lastLine != null) {
                        lastLine.rx = next.lx;
                    }
                    add = false;
                    break;
                } else {
                    next.lx = rx;
                    newLine.rx = rx;
                    break;
                }
            }

            if (add) {
                setOrderByA.add(newLine);
                setOrderByLx.add(newLine);
            }

            return newLine;
        }

        public Iterator<ConvexHullTrick.Line> iterator() {
            return setOrderByA.iterator();
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (ConvexHullTrick.Line line : this) {
                builder.append(line).append('\n');
            }
            return builder.toString();
        }

        public static class Line {
            double a;
            double b;
            double lx;
            double rx;
            Quest quest;
            static Comparator<ConvexHullTrick.Line> orderByA = new Comparator<ConvexHullTrick.Line>() {

                public int compare(ConvexHullTrick.Line o1, ConvexHullTrick.Line o2) {
                    return Double.compare(o1.a, o2.a);
                }
            };
            static Comparator<ConvexHullTrick.Line> orderByLx = new Comparator<ConvexHullTrick.Line>() {

                public int compare(ConvexHullTrick.Line o1, ConvexHullTrick.Line o2) {
                    return Double.compare(o1.lx, o2.lx);
                }
            };

            public Line(double a, double b) {
                this.a = a;
                this.b = b;
            }

            public static double intersectAt(ConvexHullTrick.Line a, ConvexHullTrick.Line b) {
                return (b.b - a.b) / (a.a - b.a);
            }

            public int hashCode() {
                return (int) (Double.doubleToLongBits(a) * 31 + Double.doubleToLongBits(b));
            }

            public boolean equals(Object obj) {
                ConvexHullTrick.Line line = (ConvexHullTrick.Line) obj;
                return a == line.a && b == line.b;
            }

            public String toString() {
                return a + "x+" + b;
            }

        }

    }

    static class Quest {
        int a;
        int b;
        double p;

    }

    static class BSResult {
        double state;
        long now;

        public BSResult(double state, long now) {
            this.state = state;
            this.now = now;
        }

        public String toString() {
            return String.format("(%d, %f)", now, state);
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

    static class Matrix implements Cloneable {
        double[][] mat;
        int n;
        int m;

        public double get(int i, int j) {
            return mat[i][j];
        }

        public Matrix(Matrix model) {
            n = model.n;
            m = model.m;
            mat = new double[n][m];
            asSame(model);
        }

        public Matrix(double[][] mat) {
            if (mat.length == 0 || mat[0].length == 0) {
                throw new IllegalArgumentException();
            }
            this.n = mat.length;
            this.m = mat[0].length;
            this.mat = mat;
        }

        public Matrix(int n, int m) {
            this.n = n;
            this.m = m;
            mat = new double[n][m];
        }

        public void fill(int v) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = v;
                }
            }
        }

        public static Matrix mul(Matrix a, Matrix b, Matrix c) {
            c.fill(0);
            for (int i = 0; i < c.n; i++) {
                for (int j = 0; j < c.m; j++) {
                    for (int k = 0; k < a.m; k++) {
                        c.mat[i][j] = c.mat[i][j] + a.mat[i][k] * b.mat[k][j];
                    }
                }
            }
            return c;
        }

        public static Matrix mul(Matrix a, Matrix b) {
            Matrix c = new Matrix(a.n, b.m);
            return mul(a, b, c);
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    builder.append(mat[i][j]).append(' ');
                }
                builder.append('\n');
            }
            return builder.toString();
        }

        public void asSame(Matrix matrix) {
            if (matrix.n != n || matrix.m != m) {
                throw new IllegalArgumentException();
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = matrix.mat[i][j];
                }
            }
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

        public double readDouble() {
            boolean sign = true;
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+';
                next = read();
            }

            long val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 + next - '0';
                next = read();
            }
            if (next != '.') {
                return sign ? val : -val;
            }
            next = read();
            long radix = 1;
            long point = 0;
            while (next >= '0' && next <= '9') {
                point = point * 10 + next - '0';
                radix = radix * 10;
                next = read();
            }
            double result = val + (double) point / radix;
            return sign ? result : -result;
        }

    }
}