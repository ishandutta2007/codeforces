import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.TreeSet;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.Iterator;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.Objects;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.util.Comparator;
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
            CCompleteTheMST solver = new CCompleteTheMST();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CCompleteTheMST {
        LongHashMap E = new LongHashMap((int) 5e5, false);
        public static int inf = (int) 2e9;

        long id(int u, int v) {
            if (u > v) {
                int tmp = u;
                u = v;
                v = tmp;
            }
            return DigitUtils.asLong(u, v);
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();

            Edge[] edges = new Edge[m];
            List<Edge> created = new ArrayList<>(n + m);
            int xor = 0;
            for (int i = 0; i < m; i++) {
                edges[i] = new Edge();
                edges[i].u = in.ri() - 1;
                edges[i].v = in.ri() - 1;
                edges[i].w = in.ri();
                E.put(id(edges[i].u, edges[i].v), edges[i].w);
                xor ^= edges[i].w;
            }

            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
                nodes[i].dist = inf;
                nodes[i].lct = new LCTNode();
            }
            LinkedListBeta<Node> cand = new LinkedListBeta<>();
            for (int i = 1; i < n; i++) {
                nodes[i].lnode = cand.addLast(nodes[i]);
            }
            nodes[0].dist = 0;
            TreeSet<Node> set = new TreeSet<>(Comparator.<Node>comparingInt(x -> x.dist).thenComparingInt(x -> x.id));
            for (int i = 0; i < n; i++) {
                set.add(nodes[i]);
            }

            long sum = 0;
            while (!set.isEmpty()) {
                Node head = set.pollFirst();
                if (head.lnode != null) {
                    cand.remove(head.lnode);
                    head.lnode = null;
                }
                sum += head.dist;
                for (LinkedListBeta.Node<Node> iter = cand.begin(); iter != cand.end(); iter = iter.next) {
                    Node node = iter.val;
                    long id = id(head.id, node.id);
                    int newW;
                    if (E.containKey(id)) {
                        //upd
                        newW = (int) E.get(id);
                    } else {
                        Edge e = new Edge();
                        e.u = head.id;
                        e.v = node.id;
                        newW = 0;
                        created.add(e);
                        iter = iter.prev;
                        cand.remove(node.lnode);
                        node.lnode = null;
                    }

                    if (node.dist > newW) {
                        set.remove(node);
                        node.dist = newW;
                        set.add(node);
                    }
                }
            }

            if (created.size() + m != (long) n * (n - 1) / 2) {
                out.println(sum);
                return;
            }

            //have to remove an edge
            DSU dsu = new DSU(n);
            dsu.init();
            for (Edge e : created) {
                Node a = nodes[e.u];
                Node b = nodes[e.v];
                LCTNode.join(a.lct, e.lct);
                LCTNode.join(b.lct, e.lct);
                dsu.merge(e.u, e.v);
            }
            Arrays.sort(edges, Comparator.comparingInt(x -> x.w));
            for (Edge e : edges) {
                Node a = nodes[e.u];
                Node b = nodes[e.v];
                if (dsu.find(e.u) != dsu.find(e.v)) {
                    dsu.merge(e.u, e.v);
                    LCTNode.join(a.lct, b.lct);
                } else {
                    LCTNode.makeRoot(a.lct);
                    LCTNode.access(b.lct);
                    LCTNode.splay(b.lct);
                    b.lct.modify(e.w);
                }
            }

            long best = inf;
            for (Edge e : created) {
                //delete e
                long c = sum;
                LCTNode.splay(e.lct);
                c += Math.min(xor, e.lct.rep);
                best = Math.min(best, c);
            }

            out.println(best);
        }

    }

    static class DigitUtils {
        public static long INT_TO_LONG_MASK = (1L << 32) - 1;

        private DigitUtils() {
        }

        public static long asLong(int high, int low) {
            return (((long) high) << 32) | (((long) low) & INT_TO_LONG_MASK);
        }

    }

    static class LCTNode {
        public static final LCTNode NIL = new LCTNode();
        public LCTNode left = NIL;
        public LCTNode right = NIL;
        public LCTNode father = NIL;
        public LCTNode treeFather = NIL;
        public boolean reverse;
        public static int inf = (int) 2e9;
        public int id;
        public int rep = inf;
        public int dirty = inf;

        static {
            NIL.left = NIL;
            NIL.right = NIL;
            NIL.father = NIL;
            NIL.treeFather = NIL;
        }

        void modify(int x) {
            rep = Math.min(rep, x);
            dirty = Math.min(dirty, x);
        }

        public static void access(LCTNode x) {
            LCTNode last = NIL;
            while (x != NIL) {
                splay(x);
                x.right.father = NIL;
                x.right.treeFather = x;
                x.setRight(last);
                x.pushUp();

                last = x;
                x = x.treeFather;
            }
        }

        public static void makeRoot(LCTNode x) {
            access(x);
            splay(x);
            x.reverse();
        }

        public static void join(LCTNode y, LCTNode x) {
            makeRoot(x);
            makeRoot(y);
            x.treeFather = y;
            y.pushUp();
        }

        public static void splay(LCTNode x) {
            if (x == NIL) {
                return;
            }
            LCTNode y, z;
            while ((y = x.father) != NIL) {
                if ((z = y.father) == NIL) {
                    y.pushDown();
                    x.pushDown();
                    if (x == y.left) {
                        zig(x);
                    } else {
                        zag(x);
                    }
                } else {
                    z.pushDown();
                    y.pushDown();
                    x.pushDown();
                    if (x == y.left) {
                        if (y == z.left) {
                            zig(y);
                            zig(x);
                        } else {
                            zig(x);
                            zag(x);
                        }
                    } else {
                        if (y == z.left) {
                            zag(x);
                            zig(x);
                        } else {
                            zag(y);
                            zag(x);
                        }
                    }
                }
            }

            x.pushDown();
            x.pushUp();
        }

        public static void zig(LCTNode x) {
            LCTNode y = x.father;
            LCTNode z = y.father;
            LCTNode b = x.right;

            y.setLeft(b);
            x.setRight(y);
            z.changeChild(y, x);

            y.pushUp();
        }

        public static void zag(LCTNode x) {
            LCTNode y = x.father;
            LCTNode z = y.father;
            LCTNode b = x.left;

            y.setRight(b);
            x.setLeft(y);
            z.changeChild(y, x);

            y.pushUp();
        }

        public String toString() {
            return "" + id;
        }

        public void pushDown() {
            if (this == NIL) {
                return;
            }
            if (reverse) {
                reverse = false;

                LCTNode tmpNode = left;
                left = right;
                right = tmpNode;

                left.reverse();
                right.reverse();
            }

            if (dirty < inf) {
                left.modify(dirty);
                right.modify(dirty);
                dirty = inf;
            }

            left.treeFather = treeFather;
            right.treeFather = treeFather;
        }

        public void reverse() {
            reverse = !reverse;
        }

        public void setLeft(LCTNode x) {
            left = x;
            x.father = this;
        }

        public void setRight(LCTNode x) {
            right = x;
            x.father = this;
        }

        public void changeChild(LCTNode y, LCTNode x) {
            if (left == y) {
                setLeft(x);
            } else {
                setRight(x);
            }
        }

        public void pushUp() {
            if (this == NIL) {
                return;
            }
        }

    }

    static class LongHashMap {
        private int now;
        private int[] slot;
        private int[] version;
        private int[] next;
        private long[] keys;
        private long[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;
        private Hasher hasher = new Hasher();

        public LongHashMap(int cap, boolean rehash) {
            now = 1;
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            version = new int[slot.length];
            next = new int[cap + 1];
            keys = new long[cap + 1];
            values = new long[cap + 1];
            removed = new boolean[cap + 1];
            this.rehash = rehash;
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            keys = Arrays.copyOf(keys, newSize);
            values = Arrays.copyOf(values, newSize);
            removed = Arrays.copyOf(removed, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
            removed[alloc] = false;
            size++;
        }

        private void rehash() {
            int[] newSlots = new int[Math.max(16, slot.length * 2)];
            int[] newVersions = new int[newSlots.length];
            int newMask = newSlots.length - 1;
            for (int i = 0; i < slot.length; i++) {
                access(i);
                if (slot[i] == 0) {
                    continue;
                }
                int head = slot[i];
                while (head != 0) {
                    int n = next[head];
                    int s = hash(keys[head]) & newMask;
                    next[head] = newSlots[s];
                    newSlots[s] = head;
                    head = n;
                }
            }
            this.slot = newSlots;
            this.version = newVersions;
            now = 0;
            this.mask = newMask;
        }

        private int hash(long x) {
            return hasher.hash(x);
        }

        public void put(long x, long y) {
            put(x, y, true);
        }

        public void put(long x, long y, boolean cover) {
            int h = hash(x);
            int s = h & mask;
            access(s);
            if (slot[s] == 0) {
                alloc();
                slot[s] = alloc;
                keys[alloc] = x;
                values[alloc] = y;
            } else {
                int index = findIndexOrLastEntry(s, x);
                if (keys[index] != x) {
                    alloc();
                    next[index] = alloc;
                    keys[alloc] = x;
                    values[alloc] = y;
                } else if (cover) {
                    values[index] = y;
                }
            }
            if (rehash && size >= slot.length) {
                rehash();
            }
        }

        public boolean containKey(long x) {
            int h = hash(x);
            int s = h & mask;
            access(s);
            if (slot[s] == 0) {
                return false;
            }
            return keys[findIndexOrLastEntry(s, x)] == x;
        }

        public long getOrDefault(long x, long def) {
            int h = hash(x);
            int s = h & mask;
            access(s);
            if (slot[s] == 0) {
                return def;
            }
            int index = findIndexOrLastEntry(s, x);
            return keys[index] == x ? values[index] : def;
        }

        public long get(long x) {
            return getOrDefault(x, 0);
        }

        private int findIndexOrLastEntry(int s, long x) {
            int iter = slot[s];
            while (keys[iter] != x) {
                if (next[iter] != 0) {
                    iter = next[iter];
                } else {
                    return iter;
                }
            }
            return iter;
        }

        private void access(int i) {
            if (version[i] != now) {
                version[i] = now;
                slot[i] = 0;
            }
        }

        public LongEntryIterator iterator() {
            return new LongEntryIterator() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public long getEntryKey() {
                    return keys[readIndex];
                }


                public long getEntryValue() {
                    return values[readIndex];
                }


                public void next() {
                    if (!hasNext()) {
                        throw new IllegalStateException();
                    }
                    readIndex = index;
                    index++;
                }
            };
        }

        public String toString() {
            LongEntryIterator iterator = iterator();
            StringBuilder builder = new StringBuilder("{");
            while (iterator.hasNext()) {
                iterator.next();
                builder.append(iterator.getEntryKey()).append("->").append(iterator.getEntryValue()).append(',');
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append('}');
            return builder.toString();
        }

    }

    static class Hasher {
        private long time = System.nanoTime() + System.currentTimeMillis() * 31L;

        public int shuffle(long z) {
            z += time;
            z = (z ^ (z >>> 33)) * 0x62a9d9ed799705f5L;
            return (int) (((z ^ (z >>> 28)) * 0xcb24d0a5c88c35b3L) >>> 32);
        }

        public int hash(long x) {
            return shuffle(x);
        }

    }

    static class LinkedListBeta<E> implements Iterable<E> {
        public LinkedListBeta.Node<E> dummy = new LinkedListBeta.Node<>(null);
        protected int size;

        public LinkedListBeta.Node<E> begin() {
            return dummy.next;
        }

        public LinkedListBeta.Node<E> end() {
            return dummy;
        }

        public LinkedListBeta.Node<E> addLast(E e) {
            LinkedListBeta.Node<E> node = new LinkedListBeta.Node<>(e);
            return addLast(node);
        }

        public LinkedListBeta.Node<E> addAfter(LinkedListBeta.Node<E> node, LinkedListBeta.Node<E> follow) {
            follow.attach(node);
            size++;
            return follow;
        }

        public LinkedListBeta.Node<E> addLast(LinkedListBeta.Node<E> node) {
            return addAfter(dummy.prev, node);
        }

        public void remove(LinkedListBeta.Node<E> node) {
            assert contain(node);
            node.detach();
            size--;
            assert size >= 0;
        }

        public boolean contain(LinkedListBeta.Node<E> node) {
            for (LinkedListBeta.Node<E> head = begin(); head != end(); head = head.next) {
                if (head == node) {
                    return true;
                }
            }
            return false;
        }

        public RevokeIterator<E> iterator() {
            return new RevokeIterator<E>() {
                LinkedListBeta.Node<E> trace = dummy;


                public void revoke() {
                    trace = trace.prev;
                }


                public boolean hasNext() {
                    return trace.next != dummy;
                }


                public E next() {
                    return (trace = trace.next).val;
                }
            };
        }

        public String toString() {
            StringBuilder ans = new StringBuilder("[");
            for (E e : this) {
                ans.append(e).append(',');
            }
            if (ans.length() > 1) {
                ans.setLength(ans.length() - 1);
            }
            ans.append(']');
            return ans.toString();
        }

        public static class Node<E> extends CircularLinkedNode<LinkedListBeta.Node<E>> {
            public E val;

            public Node(E val) {
                this.val = val;
            }

            public String toString() {
                return Objects.toString(val);
            }

        }

    }

    static interface LongEntryIterator {
        boolean hasNext();

        void next();

        long getEntryKey();

        long getEntryValue();

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

        public FastOutput println(long c) {
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

    static interface RevokeIterator<E> extends Iterator<E> {
    }

    static class Edge {
        int u;
        int v;
        int w;
        LCTNode lct = new LCTNode();

        public String toString() {
            return "(" + u + "," + v + "," + w + ")";
        }

    }

    static class CircularLinkedNode<T extends CircularLinkedNode<T>> {
        public T prev = (T) this;
        public T next = (T) this;

        public void attach(T node) {
            this.next = node.next;
            this.prev = node;
            this.next.prev = (T) this;
            this.prev.next = (T) this;
        }

        public void detach() {
            this.prev.next = next;
            this.next.prev = prev;
            this.next = this.prev = (T) this;
        }

    }

    static class Node {
        LCTNode lct;
        LinkedListBeta.Node<Node> lnode;
        int dist;
        int id;

        public String toString() {
            return "" + (id + 1);
        }

    }

    static class DSU {
        protected int[] p;
        public int[] size;
        protected int n;

        public DSU(int n) {
            p = new int[n];
            size = new int[n];
        }

        public void init() {
            init(p.length);
        }

        public void init(int n) {
            this.n = n;
            for (int i = 0; i < n; i++) {
                p[i] = i;
                size[i] = 1;
            }
        }

        public final int find(int a) {
            if (p[a] == p[p[a]]) {
                return p[a];
            }
            find(p[a]);
            preAccess(a);
            return p[a] = p[p[a]];
        }

        protected void preAccess(int a) {

        }

        protected void preMerge(int a, int b) {
            size[a] += size[b];
        }

        public final void merge(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return;
            }

            if (size[a] < size[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            preMerge(a, b);
            p[b] = a;
        }

        public String toString() {
            return Arrays.toString(Arrays.copyOf(p, n));
        }

    }
}