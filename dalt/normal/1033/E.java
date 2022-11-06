import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
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
            EHiddenBipartiteGraph solver = new EHiddenBipartiteGraph();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EHiddenBipartiteGraph {
        FastInput in;
        FastOutput out;
        Node[] nodes;
        List<Node> buf = new ArrayList<>(600);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            this.in = in;
            this.out = out;

            int n = in.readInt();

            nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            for (int i = 1; i < n; i++) {
                dac(0, i - 1, i);
            }

            for (Node node : nodes) {
                paint(node, 0);
            }

            List<Node> black = new ArrayList<>(n);
            for (Node node : nodes) {
                if (node.find() != node) {
                    continue;
                }
                List<Node>[] lists = new ArrayList[]{new ArrayList<>(), new ArrayList<>()};
                for (Node next : node.all) {
                    lists[next.color].add(next);
                }
                black.addAll(lists[0]);

                for (List<Node> list : lists) {
                    if (query(list) == 0) {
                        continue;
                    }
                    int first = 0;
                    while (query(list.subList(first + 1, list.size())) != 0) {
                        first++;
                    }
                    int second = first + 1;
                    while (query(list.get(first), list.get(second)) == 0) {
                        second++;
                    }
                    Deque deque = new ArrayDeque(n);
                    findPathBetween(list.get(first), null, list.get(second), deque);
                    outputLoop(deque);
                    return;
                }
            }

            outputBipartite(black);
        }

        public void paint(Node root, int color) {
            if (root.color != -1) {
                return;
            }
            root.color = color;
            for (Node node : root.next) {
                paint(node, color ^ 1);
            }
        }

        public void dac(int l, int r, int x) {
            int total = query(l, r, x);
            for (int i = l; i <= r; i++) {
                if (nodes[i].find() != nodes[i]) {
                    continue;
                }
                total -= nodes[i].edgeCnt;
            }
            if (total == 0) {
                return;
            }
            if (l == r) {
                int near = find(l, x);
                nodes[near].next.add(nodes[x]);
                nodes[x].next.add(nodes[near]);
                Node.merge(nodes[near], nodes[x]);
                nodes[x].find().edgeCnt += total;
                //System.err.printf("add edge(%d,%d)\n", near + 1, x + 1);
                return;
            }
            int m = (l + r) / 2;
            dac(l, m, x);
            dac(m + 1, r, x);
        }

        public boolean findPathBetween(Node root, Node p, Node target, Deque<Node> deque) {
            deque.addLast(root);
            if (root == target) {
                return true;
            }
            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                if (findPathBetween(node, root, target, deque)) {
                    return true;
                }
            }
            deque.removeLast();
            return false;
        }

        public int find(int which, int x) {
            int l = 0;
            int r = nodes[which].all.size() - 1;
            while (l < r) {
                int m = (l + r) / 2;
                List<Node> left = nodes[which].all.subList(l, m + 1);
                if (query(left, nodes[x]) > query(left)) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            return nodes[which].all.get(l).id;
        }

        public int query() {
            if (buf.size() <= 1) {
                return 0;
            }

            out.append("? ").append(buf.size()).println();
            for (Node node : buf) {
                out.append(node.id + 1).append(' ');
            }
            out.println().flush();
            return in.readInt();
        }

        public int query(List<Node> nodes) {
            buf.clear();
            buf.addAll(nodes);
            return query();
        }

        public int query(List<Node> nodes, Node x) {
            buf.clear();
            buf.addAll(nodes);
            buf.add(x);
            return query();
        }

        public int query(Node a, Node b) {
            buf.clear();
            buf.add(a);
            buf.add(b);
            return query();
        }

        public int query(int l, int r, int x) {
            buf.clear();
            for (int i = l; i <= r; i++) {
                if (nodes[i].find() != nodes[i]) {
                    continue;
                }
                buf.addAll(nodes[i].all);
            }
            buf.add(nodes[x]);

            return query();
        }

        public void outputLoop(Collection<Node> deque) {
            out.append("N ").append(deque.size()).println();
            for (Node node : deque) {
                out.append(node.id + 1).append(' ');
            }
            out.flush();
        }

        public void outputBipartite(List<Node> list) {
            out.append("Y ").append(list.size()).println();
            for (Node node : list) {
                out.append(node.id + 1).append(' ');
            }
            out.flush();
        }

    }

    static class Node {
        int id;
        List<Node> next = new ArrayList<>();
        int color = -1;
        int edgeCnt;
        Node p = this;
        int rank;
        List<Node> all = new ArrayList<>();

        {
            all.add(this);
        }

        public Node find() {
            return p.p == p ? p : (p = p.find());
        }

        public static void merge(Node a, Node b) {
            a = a.find();
            b = b.find();
            if (a == b) {
                return;
            }
            if (a.rank == b.rank) {
                a.rank++;
            }
            if (a.rank < b.rank) {
                Node tmp = a;
                a = b;
                b = tmp;
            }
            b.p = a;
            a.all = CollectionUtils.mergeHeuristically(a.all, b.all);
            a.edgeCnt += b.edgeCnt;
        }

    }

    static class CollectionUtils {
        public static <E, T extends Collection<E>> T mergeHeuristically(T a, T b) {
            if (a.size() >= b.size()) {
                a.addAll(b);
                return a;
            } else {
                b.addAll(a);
                return b;
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

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
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
}