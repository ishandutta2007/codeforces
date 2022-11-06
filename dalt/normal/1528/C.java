import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.NavigableMap;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.TreeMap;
import java.io.Closeable;
import java.util.Map;
import java.io.Writer;
import java.util.Map.Entry;
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
            CTreesOfTranquillity solver = new CTreesOfTranquillity();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class CTreesOfTranquillity {
        TreeMap<Integer, Node> map;
        int best;
        int order = 0;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
            }
            for (int i = 1; i < n; i++) {
                Node a = nodes[in.ri() - 1];
                Node b = nodes[i];
                a.adj.add(b);
            }
            for (int i = 1; i < n; i++) {
                Node a = nodes[in.ri() - 1];
                Node b = nodes[i];
                a.badj.add(b);
            }

            order = 0;
            eulerTour(nodes[0], null);
            map = new TreeMap<>();
            best = 0;

            dfs(nodes[0], null);
            out.println(best);
        }

        public void dfs(Node root, Node p) {
            Node rep = null;
            boolean added = false;
            Node floor = CollectionUtils.floorValue(map, root.l);
            Node ceil = CollectionUtils.ceilValue(map, root.l);
            if (ceil != null && root.contain(ceil)) {
            } else {
                if (floor != null && floor.contain(root)) {
                    rep = map.remove(floor.l);
                }
                added = true;
                map.put(root.l, root);
            }

            best = Math.max(best, map.size());
            for (Node node : root.adj) {
                if (node == p) {
                    continue;
                }
                dfs(node, root);
            }

            if (added) {
                map.remove(root.l);
            }
            if (rep != null) {
                map.put(rep.l, rep);
            }
        }

        public void eulerTour(Node root, Node p) {
            root.l = order++;
            for (Node node : root.badj) {
                if (node == p) {
                    continue;
                }
                eulerTour(node, root);
            }
            root.r = order++;
        }

    }

    static class CollectionUtils {
        public static <K, V> V floorValue(NavigableMap<K, V> map, K key) {
            Map.Entry<K, V> entry = map.floorEntry(key);
            return entry == null ? null : entry.getValue();
        }

        public static <K, V> V ceilValue(NavigableMap<K, V> map, K key) {
            Map.Entry<K, V> entry = map.ceilingEntry(key);
            return entry == null ? null : entry.getValue();
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

        public int ri() {
            return readInt();
        }

        public int readInt() {
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
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

    static class Node {
        int l;
        int r;
        List<Node> adj = new ArrayList<>();
        List<Node> badj = new ArrayList<>();

        public boolean contain(Node x) {
            return l < x.l && r > x.r;
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

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append('\n');
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