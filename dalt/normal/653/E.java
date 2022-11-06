import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Deque;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.Iterator;
import java.util.Collection;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
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
            EBearAndForgottenTree2 solver = new EBearAndForgottenTree2();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EBearAndForgottenTree2 {
        LongHashSet set = new LongHashSet((int) 1e6, false);

        public long id(LinkedListBeta.Node<Integer> a, LinkedListBeta.Node<Integer> b) {
            return id(a.val, b.val);
        }

        public long id(int a, int b) {
            if (a > b) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            return DigitUtils.asLong(a, b);
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            int k = in.ri();
            LinkedListBeta.Node<Integer>[] nodes = new LinkedListBeta.Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new LinkedListBeta.Node<>(i);
            }
            for (int i = 0; i < m; i++) {
                set.add(id(in.ri() - 1, in.ri() - 1));
            }
            LinkedListBeta<Integer> list = new LinkedListBeta<>();
            for (int i = 1; i < n; i++) {
                list.addLast(nodes[i]);
            }
            Deque<LinkedListBeta.Node<Integer>> dq = new ArrayDeque<>();
            List<LinkedListBeta.Node<Integer>> seq = new ArrayList<>();
            boolean[] withZero = new boolean[n];
            int scc = 0;
            while (!list.isEmpty()) {
                seq.clear();
                dq.clear();
                dq.addLast(list.begin());
                list.remove(list.begin());
                while (!dq.isEmpty()) {
                    LinkedListBeta.Node<Integer> head = dq.removeFirst();
                    seq.add(head);
                    for (LinkedListBeta.Node<Integer> node = list.begin(), next; node != list.end(); node = next) {
                        next = node.next;
                        if (set.contain(id(head, node))) {
                            continue;
                        }
                        dq.addLast(node);
                        list.remove(node);
                    }
                }
                boolean added = false;
                for (LinkedListBeta.Node<Integer> node : seq) {
                    if (set.contain(id(node, nodes[0]))) {
                        continue;
                    }
                    added = true;
                    withZero[node.val] = true;
                    break;
                }
                if (!added) {
                    out.println("impossible");
                    return;
                }

                scc++;
            }

            int totalEdge = 0;
            for (int i = 1; i < n; i++) {
                if (set.contain(id(nodes[0], nodes[i]))) {
                    continue;
                }
                totalEdge++;
            }
            if (k < scc || totalEdge < k) {
                out.println("impossible");
                return;
            }

            out.println("possible");

        }

    }

    static interface RevokeIterator<E> extends Iterator<E> {
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

        public LinkedListBeta.Node<E> addAfter(LinkedListBeta.Node<E> node, LinkedListBeta.Node<E> follow) {
            follow.attach(node);
            size++;
            return follow;
        }

        public LinkedListBeta.Node<E> addLast(LinkedListBeta.Node<E> node) {
            return addAfter(dummy.prev, node);
        }

        public void remove(LinkedListBeta.Node<E> node) {
            node.detach();
            size--;
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

        public static class Node<E> extends CircularLinkedNode<LinkedListBeta.Node<E>> {
            public E val;

            public Node(E val) {
                this.val = val;
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

    static class DigitUtils {
        public static long INT_TO_LONG_MASK = (1L << 32) - 1;

        private DigitUtils() {
        }

        public static long asLong(int high, int low) {
            return (((long) high) << 32) | (((long) low) & INT_TO_LONG_MASK);
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

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(String c) {
            return append(c).println();
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

    static interface LongIterator {
        boolean hasNext();

        long next();

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

    static class LongHashSet {
        private int now;
        private int[] slot;
        private int[] version;
        private int[] next;
        private long[] keys;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;
        private Hasher hasher = new Hasher();

        public LongHashSet(int cap, boolean rehash) {
            now = 1;
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            this.rehash = rehash;
            slot = new int[mask + 1];
            version = new int[slot.length + 1];
            next = new int[cap + 1];
            keys = new long[cap + 1];
            removed = new boolean[cap + 1];
        }

        private void access(int i) {
            if (version[i] != now) {
                version[i] = now;
                slot[i] = 0;
            }
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            keys = Arrays.copyOf(keys, newSize);
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

        private int hash(long x) {
            return hasher.hash(x);
        }

        public void add(long x) {
            int h = hash(x);
            int s = h & mask;
            access(s);
            if (slot[s] == 0) {
                alloc();
                slot[s] = alloc;
                keys[alloc] = x;
                return;
            } else {
                int index = findIndexOrLastEntry(s, x);
                if (keys[index] != x) {
                    alloc();
                    next[index] = alloc;
                    keys[alloc] = x;
                }
            }
            if (rehash && size >= slot.length) {
                rehash();
            }
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

        public boolean contain(long x) {
            int h = hash(x);
            int s = h & mask;
            access(s);
            if (slot[s] == 0) {
                return false;
            }
            return keys[findIndexOrLastEntry(s, x)] == x;
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

        public LongIterator iterator() {
            return new LongIterator() {
                int index = 1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public long next() {
                    if (!hasNext()) {
                        throw new IllegalStateException();
                    }
                    return keys[index++];
                }
            };
        }

        public String toString() {
            LongIterator iterator = iterator();
            StringBuilder builder = new StringBuilder("{");
            while (iterator.hasNext()) {
                builder.append(iterator.next()).append(',');
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append('}');
            return builder.toString();
        }

    }
}