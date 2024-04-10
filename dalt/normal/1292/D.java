import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
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
            DChaoticV solver = new DChaoticV();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DChaoticV {
        int limit = 669;
        Node[] nodes;
        int n;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            EulerSieve es = new EulerSieve(5000);
            nodes = new Node[5000 + 1];
            for (int i = 1; i <= 5000; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            n = in.readInt();
            for (int i = 1; i <= 5000; i++) {
                for (int j = 0; j < limit; j++) {
                    nodes[i].status[j] = countFactor(i, es.get(j));
                }
            }

            for (int i = 0; i < n; i++) {
                int which = in.readInt();
                if (which == 0) {
                    which = 1;
                }
                nodes[which].weight++;
            }
            rec(nodes.clone(), 1, 5000, limit - 1);
            dfs(nodes[1], null);
            Node center = findCenter(nodes[1], null, nodes[1].size);
            long ans = count(center, null, 0);
            out.println(ans);
        }

        public long count(Node root, Edge p, int depth) {
            long ans = (long) root.weight * depth;
            for (Edge e : root.next) {
                if (e == p) {
                    continue;
                }
                Node node = e.other(root);
                ans += count(node, e, depth + e.len);
            }
            return ans;
        }

        public Node findCenter(Node root, Edge p, int total) {
            int maxChild = total - root.size;
            for (Edge e : root.next) {
                if (e == p) {
                    continue;
                }
                Node node = e.other(root);
                maxChild = Math.max(maxChild, node.size);
            }
            if (maxChild * 2 <= total) {
                return root;
            }
            for (Edge e : root.next) {
                if (e == p) {
                    continue;
                }
                Node node = e.other(root);
                Node ans = findCenter(node, e, total);
                if (ans != null) {
                    return ans;
                }
            }
            return null;
        }

        public void dfs(Node root, Edge p) {
            root.size = root.weight;
            for (Edge e : root.next) {
                if (e == p) {
                    continue;
                }
                Node node = e.other(root);
                dfs(node, e);
                root.size += node.size;
            }
        }

        public Node rec(Node[] nodes, int l, int r, int k) {
            if (k < 0) {
                return nodes[l];
            }
            Arrays.sort(nodes, l, r + 1, (a, b) -> a.status[k] - b.status[k]);
            Node last = null;
            for (int i = r; i >= l; i--) {
                int j = i;
                while (i - 1 >= l && nodes[i - 1].status[k] == nodes[i].status[k]) {
                    i--;
                }
                Node merged = rec(nodes, i, j, k - 1);
                if (last == null) {
                    last = merged;
                } else {
                    last = merge(last, merged);
                }
            }
            return last;
        }

        public Node merge(Node a, Node b) {
            Node merged = new Node();
            for (int i = limit - 1; i >= 0; i--) {
                if (a.status[i] == b.status[i]) {
                    merged.status[i] = a.status[i];
                } else {
                    if (a.status[i] > b.status[i]) {
                        Node tmp = a;
                        a = b;
                        b = tmp;
                    }
                    merged.status[i] = a.status[i];
                    int distToA = 0;
                    int distToB = b.status[i] - a.status[i];
                    for (int j = 0; j < i; j++) {
                        distToA += a.status[j];
                        distToB += b.status[j];
                    }
                    if (distToA > 0) {
                        addEdge(merged, a, distToA);
                        addEdge(merged, b, distToB);
                        return merged;
                    } else {
                        addEdge(a, b, distToB);
                        return a;
                    }
                }
            }

            throw new RuntimeException();
        }

        public void addEdge(Node a, Node b, int len) {
            Edge e = new Edge();
            e.a = a;
            e.b = b;
            e.len = len;
            a.next.add(e);
            b.next.add(e);
        }

        public int countFactor(int n, int x) {
            return n <= 0 ? 0 : (n / x + countFactor(n / x, x));
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

    static class Node {
        List<Edge> next = new ArrayList<>();
        int size;
        int id;
        int weight;
        int[] status = new int[669];

        public String toString() {
            return "" + id;
        }

    }

    static class EulerSieve {
        private int[] primes;
        private boolean[] isComp;
        private int primeLength;

        public int get(int k) {
            return primes[k];
        }

        public EulerSieve(int limit) {
            isComp = new boolean[limit + 1];
            primes = new int[limit + 1];
            primeLength = 0;
            for (int i = 2; i <= limit; i++) {
                if (!isComp[i]) {
                    primes[primeLength++] = i;
                }
                for (int j = 0, until = limit / i; j < primeLength && primes[j] <= until; j++) {
                    int pi = primes[j] * i;
                    isComp[pi] = true;
                    if (i % primes[j] == 0) {
                        break;
                    }
                }
            }
        }

    }

    static class Edge {
        Node a;
        Node b;
        int len;

        Node other(Node x) {
            return a == x ? b : a;
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

    }
}