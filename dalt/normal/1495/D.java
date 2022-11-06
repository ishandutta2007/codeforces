import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.ArrayDeque;
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
            DBFSTrees solver = new DBFSTrees();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DBFSTrees {
        int mod = 998244353;
        int inf = (int) 1e8;
        int now = 0;
        Deque<Node> dq = new ArrayDeque<>();

        int intersect(Node[] a, Node[] b) {
            int as = a.length - 1;
            int bs = b.length - 1;
            int ans = 0;
            while (as >= 0 && bs >= 0) {
                if (a[as].id == b[bs].id) {
                    ans++;
                    as--;
                    bs--;
                    continue;
                }
                if (a[as].id < b[bs].id) {
                    bs--;
                } else {
                    as--;
                }
            }
            return ans;
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            for (int i = 0; i < m; i++) {
                Node a = nodes[in.ri() - 1];
                Node b = nodes[in.ri() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }

            Node[][][] bs = new Node[n][n][];
            for (int i = 0; i < n; i++) {
                bfs(nodes[i], nodes);
                for (int j = 0; j < n; j++) {
                    bs[i][j] = nodes[j].prev.toArray(new Node[0]);
                    Arrays.sort(bs[i][j], Comparator.comparingInt(x -> x.id));
                }
            }

            long[][] ans = new long[n][n];
            for (int i = 0; i < n; i++) {
                bfs(nodes[i], nodes);
                for (int j = i; j < n; j++) {
                    if (nodes[j].dup) {
                        continue;
                    }
                    now++;
                    dfs(nodes[j]);
                    long prod = 1;
                    for (Node node : nodes) {
                        if (node.version == now) {
                            continue;
                        }
                        prod = prod * intersect(bs[i][node.id], bs[j][node.id]) % mod;
                        if (prod == 0) {
                            break;
                        }
                    }
                    ans[i][j] = ans[j][i] = prod;
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    out.append(ans[i][j]).append(' ');
                }
                out.println();
            }
        }

        public void dfs(Node root) {
            root.version = now;
            if (!root.prev.isEmpty()) {
                dfs(root.prev.get(0));
            }
        }

        public void bfs(Node root, Node[] nodes) {
            for (Node node : nodes) {
                node.dist = inf;
                node.dup = false;
                node.prev.clear();
            }
            root.dist = 0;
            dq.clear();
            dq.addLast(root);
            while (!dq.isEmpty()) {
                Node head = dq.removeFirst();
                if (head.prev.size() > 1) {
                    head.dup = true;
                }
                for (Node node : head.adj) {
                    if (node.dist > head.dist + 1) {
                        node.dist = head.dist + 1;
                        dq.addLast(node);
                    }
                    if (node.dist == head.dist + 1) {
                        node.prev.add(head);
                        if (head.dup) {
                            node.dup = true;
                        }
                    }
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

        public int ri() {
            return readInt();
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

    static class Node {
        int id;
        int dist;
        List<Node> prev = new ArrayList<>();
        boolean dup;
        List<Node> adj = new ArrayList<>();
        int version;

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

        public FastOutput append(long c) {
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