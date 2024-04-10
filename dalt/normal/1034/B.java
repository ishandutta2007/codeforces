import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
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
            BLittleCLoves3II solver = new BLittleCLoves3II();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class BLittleCLoves3II {
        int n;
        int m;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            m = in.readInt();

            long ans = 0;
            int remain = 30;
            if (n > remain) {
                int extra = n - remain;
                ans += (long) (extra - extra % 6) * m;
                n -= extra - extra % 6;
            }
            if (m > remain) {
                int extra = m - remain;
                ans += (long) (extra - extra % 6) * n;
                m -= extra - extra % 6;
            }

            KMAlgo km = new KMAlgo(n * m, n * m);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((i + j) % 2 != 0) {
                        continue;
                    }
                    for (int k = 0; k < n; k++) {
                        for (int t = 0; t < m; t++) {
                            if ((k + t) % 2 != 1) {
                                continue;
                            }
                            if (Math.abs(i - k) + Math.abs(j - t) == 3) {
                                km.addEdge(cellId(i, j), cellId(k, t), true);
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (km.matchLeft(cellId(i, j))) {
                        ans += 2;
                    }
                }
            }

            out.println(ans);
        }

        int cellId(int i, int j) {
            return i * m + j;
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

        public FastOutput println(long c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
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

    static class KMAlgo {
        KMAlgo.Node[] leftSides;
        KMAlgo.Node[] rightSides;
        int version;

        public KMAlgo(int l, int r) {
            leftSides = new KMAlgo.Node[l];
            for (int i = 0; i < l; i++) {
                leftSides[i] = new KMAlgo.Node();
                leftSides[i].id = i;
                leftSides[i].leftSide = true;
            }
            rightSides = new KMAlgo.Node[r];
            for (int i = 0; i < r; i++) {
                rightSides[i] = new KMAlgo.Node();
                rightSides[i].id = i;
            }
        }

        public void addEdge(int lId, int rId, boolean urge) {
            leftSides[lId].nodes.add(rightSides[rId]);
            rightSides[rId].nodes.add(leftSides[lId]);
            if (urge && leftSides[lId].partner == null && rightSides[rId].partner == null) {
                leftSides[lId].partner = rightSides[rId];
                rightSides[rId].partner = leftSides[lId];
            }
        }

        private void prepare() {
            version++;
        }

        public boolean matchLeft(int id) {
            if (leftSides[id].partner != null) {
                return true;
            }
            prepare();
            return findPartner(leftSides[id]);
        }

        private boolean findPartner(KMAlgo.Node src) {
            if (src.visited == version) {
                return false;
            }
            src.visited = version;
            for (KMAlgo.Node node : src.nodes) {
                if (!tryRelease(node)) {
                    continue;
                }
                node.partner = src;
                src.partner = node;
                return true;
            }
            return false;
        }

        private boolean tryRelease(KMAlgo.Node src) {
            if (src.visited == version) {
                return false;
            }
            src.visited = version;
            if (src.partner == null) {
                return true;
            }
            if (findPartner(src.partner)) {
                src.partner = null;
                return true;
            }
            return false;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < leftSides.length; i++) {
                if (leftSides[i].partner == null) {
                    continue;
                }
                builder.append(leftSides[i].id).append(" - ").append(leftSides[i].partner.id).append("\n");
            }
            return builder.toString();
        }

        public static class Node {
            List<KMAlgo.Node> nodes = new ArrayList<>();
            int visited;
            KMAlgo.Node partner;
            int id;
            boolean leftSide;

            public String toString() {
                return "" + id;
            }

        }

    }
}