import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
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
            FChoosingTwoPaths solver = new FChoosingTwoPaths();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FChoosingTwoPaths {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            int[][] edges = new int[n - 1][2];
            for (int i = 0; i < n - 1; i++) {
                edges[i][0] = in.readInt() - 1;
                edges[i][1] = in.readInt() - 1;
                Node a = nodes[edges[i][0]];
                Node b = nodes[edges[i][1]];
                a.next.add(b);
                b.next.add(a);
            }

            Node root = null;
            for (Node node : nodes) {
                if (node.next.size() >= 3) {
                    root = node;
                    break;
                }
            }
            dfsForDepth(root, null, 0);

            for (Node node : nodes) {
                if (node.next.size() == 1) {
                    upward(node);
                }
            }

            MultiWayIntegerStack edgeStack = new MultiWayIntegerStack(n, n * 2);
            for (int[] e : edges) {
                if (nodes[e[0]].removed || nodes[e[1]].removed) {
                    continue;
                }
                edgeStack.addLast(e[0], e[1]);
                edgeStack.addLast(e[1], e[0]);
            }
            ForestDiameter td = new ForestDiameter(edgeStack, n);
            if (td.getCenters(root.id).size() == 1) {
                Node center = nodes[td.getCenters(root.id).get(0)];
                int sd = td.getDiameter(root.id) / 2;
                List<NodePair> pairs = new ArrayList<>(center.next.size());
                for (Node node : center.next) {
                    pairs.add(findLargestSum(node, center, 1, sd));
                }
                pairs.sort(this::compare);
                NodePair a = pairs.get(pairs.size() - 1);
                NodePair b = pairs.get(pairs.size() - 2);
                answer(out, a, b);
                return;
            }

            Node c1 = nodes[td.getCenters(root.id).get(0)];
            Node c2 = nodes[td.getCenters(root.id).get(1)];
            int sd = (td.getDiameter(root.id) - 1) / 2;
            NodePair a = findLargestSum(c1, c2, 0, sd);
            NodePair b = findLargestSum(c2, c1, 0, sd);
            answer(out, a, b);
        }

        public void answer(FastOutput out, NodePair a, NodePair b) {
            out.append(a.a.id + 1).append(' ').append(b.a.id + 1).println();
            out.append(a.b.id + 1).append(' ').append(b.b.id + 1).println();
        }

        public NodePair max(NodePair a, NodePair b) {
            return compare(a, b) >= 0 ? a : b;
        }

        public int compare(NodePair a, NodePair b) {
            if (a == null) {
                return -1;
            }
            if (b == null) {
                return 1;
            }
            return a.len - b.len;
        }

        public NodePair findLargestSum(Node root, Node p, int depth, int searchDepth) {
            if (root.removed) {
                return null;
            }

            NodePair ans = null;
            root.depth = depth;

            if (depth == searchDepth) {
                List<Node> nodes = new ArrayList<>(root.next.size());
                for (Node node : root.next) {
                    if (node == p) {
                        continue;
                    }
                    nodes.add(findDepthest(node, root, depth + 1));
                }
                nodes.sort((a, b) -> -(a.depth - b.depth));
                NodePair pair = new NodePair();
                pair.a = nodes.get(0);
                pair.b = nodes.get(1);
                pair.len = pair.a.depth + pair.b.depth - 2 * depth;
                return pair;
            }

            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                ans = max(ans, findLargestSum(node, root, depth + 1, searchDepth));
            }
            return ans;
        }

        public Node findDepthest(Node root, Node p, int depth) {
            root.depth = depth;
            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                return findDepthest(node, root, depth + 1);
            }
            return root;
        }

        public void upward(Node root) {
            if (root == null || root.removed || root.next.size() >= 3) {
                return;
            }
            root.removed = true;
            upward(root.p);
        }

        public void dfsForDepth(Node root, Node p, int depth) {
            root.depth = depth;
            root.p = p;
            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                dfsForDepth(node, root, depth + 1);
            }
        }

    }

    static class ForestDiameter {
        private MultiWayIntegerStack edges;
        private int[] depth;
        private int[] parents;
        private int[] diameters;
        private IntegerList[] centers;
        private IntegerList[] ends;
        private int[] treeIds;
        private IntegerList collector;

        public IntegerList getCenters(int i) {
            return centers[i];
        }

        public int getDiameter(int i) {
            return diameters[i];
        }

        public ForestDiameter(MultiWayIntegerStack edges, int n) {
            this.edges = edges;
            depth = new int[n];
            parents = new int[n];
            centers = new IntegerList[n];
            ends = new IntegerList[n];
            treeIds = new int[n];
            diameters = new int[n];
            collector = new IntegerList(n);
            int idAllocator = 0;
            Arrays.fill(treeIds, -1);

            for (int j = 0; j < n; j++) {
                if (treeIds[j] != -1) {
                    continue;
                }
                IntegerList endList = new IntegerList(2);
                IntegerList centerList = new IntegerList(2);
                collector.clear();
                dfsForCollect(j, -1);
                dfsForDepth(j, -1);
                int end = collector.get(0);
                for (IntegerIterator iterator = collector.iterator(); iterator.hasNext(); ) {
                    int node = iterator.next();
                    if (depth[node] > depth[end]) {
                        end = node;
                    }
                }
                dfsForDepth(end, -1);
                int another = collector.get(0);
                for (IntegerIterator iterator = collector.iterator(); iterator.hasNext(); ) {
                    int node = iterator.next();
                    if (depth[node] > depth[another]) {
                        another = node;
                    }
                }

                endList.add(end);
                endList.add(another);

                int diameter = depth[another];
                for (int i = another; i != -1; i = parents[i]) {
                    if (depth[i] == DigitUtils.ceilDiv(diameter, 2) ||
                            depth[i] == DigitUtils.floorDiv(diameter, 2)) {
                        centerList.add(i);
                    }
                }

                endList.unique();
                centerList.unique();

                for (IntegerIterator iterator = collector.iterator(); iterator.hasNext(); ) {
                    int node = iterator.next();
                    treeIds[node] = idAllocator;
                    diameters[node] = diameter;
                    ends[node] = endList;
                    centers[node] = centerList;
                }
                idAllocator++;
            }
        }

        private void dfsForCollect(int root, int p) {
            collector.add(root);
            for (IntegerIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                dfsForCollect(node, root);
            }
        }

        private void dfsForDepth(int root, int p) {
            parents[root] = p;
            depth[root] = p != -1 ? depth[p] + 1 : 0;
            for (IntegerIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                dfsForDepth(node, root);
            }
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class MultiWayIntegerStack {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public IntegerIterator iterator(final int queue) {
            return new IntegerIterator() {
                int ele = heads[queue];


                public boolean hasNext() {
                    return ele != 0;
                }


                public int next() {
                    int ans = values[ele];
                    ele = next[ele];
                    return ans;
                }
            };
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public MultiWayIntegerStack(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            stackNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < stackNum; i++) {
                builder.append(i).append(": ");
                for (IntegerIterator iterator = iterator(i); iterator.hasNext(); ) {
                    builder.append(iterator.next()).append(",");
                }
                if (builder.charAt(builder.length() - 1) == ',') {
                    builder.setLength(builder.length() - 1);
                }
                builder.append('\n');
            }
            return builder.toString();
        }

    }

    static class Node {
        List<Node> next = new ArrayList<>();
        boolean removed;
        int id;
        int depth;
        Node p;

        public String toString() {
            return "" + (id + 1);
        }

    }

    static class IntegerList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerList(IntegerList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerList() {
            this(0);
        }

        public void ensureSpace(int req) {
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

        public int get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerList list) {
            addAll(list.data, 0, list.size);
        }

        public void sort() {
            if (size <= 1) {
                return;
            }
            Randomized.randomizedArray(data, 0, size);
            Arrays.sort(data, 0, size);
        }

        public void unique() {
            if (size <= 1) {
                return;
            }

            sort();
            int wpos = 1;
            for (int i = 1; i < size; i++) {
                if (data[i] != data[wpos - 1]) {
                    data[wpos++] = data[i];
                }
            }
            size = wpos;
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public IntegerIterator iterator() {
            return new IntegerIterator() {
                int i = 0;


                public boolean hasNext() {
                    return i < size;
                }


                public int next() {
                    return data[i++];
                }
            };
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerList)) {
                return false;
            }
            IntegerList other = (IntegerList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerList clone() {
            IntegerList ans = new IntegerList();
            ans.addAll(this);
            return ans;
        }

    }

    static class Randomized {
        static Random random = new Random();

        public static void randomizedArray(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorDiv(int a, int b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static int ceilDiv(int a, int b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            int c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
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

    static class NodePair {
        Node a;
        Node b;
        int len;

    }

    static class SequenceUtils {
        public static boolean equal(int[] a, int al, int ar, int[] b, int bl, int br) {
            if ((ar - al) != (br - bl)) {
                return false;
            }
            for (int i = al, j = bl; i <= ar; i++, j++) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return true;
        }

    }
}