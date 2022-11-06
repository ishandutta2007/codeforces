import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.stream.LongStream;
import java.util.Iterator;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.Objects;
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
            FPhoenixAndEarthquake solver = new FPhoenixAndEarthquake();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FPhoenixAndEarthquake {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            int x = in.ri();
            DSUExt dsu = new DSUExt(n);
            dsu.a = in.rl(n);
            long sum = Arrays.stream(dsu.a).sum();
            if (sum < (long) (n - 1) * x) {
                out.println("NO");
                return;
            }

            out.println("YES");
            Edge[] edges = new Edge[m];
            dsu.init(n);
            for (int i = 0; i < m; i++) {
                edges[i] = new Edge();
                edges[i].a = in.ri() - 1;
                edges[i].b = in.ri() - 1;
                edges[i].id = i;
                dsu.adj[edges[i].a].addLast(edges[i]);
                dsu.adj[edges[i].b].addLast(edges[i]);
            }
            List<Edge> pick = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                int root;
                while (dsu.a[root = dsu.find(i)] >= x && !dsu.adj[root].isEmpty()) {
                    Edge e = dsu.adj[root].removeFirst();
                    int u = dsu.find(e.a);
                    int v = dsu.find(e.b);
                    int node = u ^ v ^ root;
                    if (node == root) {
                        continue;
                    }
                    dsu.a[root] -= x;
                    dsu.merge(root, node);
                    pick.add(e);
                }
            }

            for (Edge e : edges) {
                if (dsu.find(e.a) != dsu.find(e.b)) {
                    pick.add(e);
                    dsu.merge(e.a, e.b);
                }
            }

            for (Edge e : pick) {
                out.append(e.id + 1).append(' ');
            }
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

    static interface RevokeIterator<E> extends Iterator<E> {
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

        public void populate(long[] data) {
            for (int i = 0; i < data.length; i++) {
                data[i] = readLong();
            }
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

        public long[] rl(int n) {
            long[] ans = new long[n];
            populate(ans);
            return ans;
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

        public long readLong() {
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            long val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
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

    static class Edge {
        int a;
        int b;
        int id;

    }

    static class DSUExt extends DSU {
        LinkedListBeta<Edge>[] adj;
        long[] a;

        public DSUExt(int n) {
            super(n);
            adj = new LinkedListBeta[n];
            for (int i = 0; i < n; i++) {
                adj[i] = new LinkedListBeta<>();
            }
        }

        protected void preMerge(int a, int b) {
            super.preMerge(a, b);
            adj[a].migrate(adj[b]);
            this.a[a] += this.a[b];
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

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(String c) {
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

        public E removeFirst() {
            assert !isEmpty();
            E ans = dummy.next.val;
            remove(dummy.next);
            return ans;
        }

        public boolean contain(LinkedListBeta.Node<E> node) {
            for (LinkedListBeta.Node<E> head = begin(); head != end(); head = head.next) {
                if (head == node) {
                    return true;
                }
            }
            return false;
        }

        public boolean isEmpty() {
            return size == 0;
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

        public void migrate(LinkedListBeta<E> list) {
            if (list.isEmpty()) {
                return;
            }
            size += list.size;
            LinkedListBeta.Node<E> head = list.dummy.next;
            LinkedListBeta.Node<E> end = list.dummy.prev;
            concat(dummy.prev, head);
            concat(end, dummy);
            list.clear();
        }

        public void clear() {
            dummy.prev = dummy.next = dummy;
            size = 0;
        }

        private void concat(LinkedListBeta.Node<E> a, LinkedListBeta.Node<E> b) {
            a.next = b;
            b.prev = a;
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
}