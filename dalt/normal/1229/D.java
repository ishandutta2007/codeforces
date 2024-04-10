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
 * Built using CHelper plug-in Actual solution is at the top
 * 
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
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
            TaskD solver = new TaskD();
            solver.solve(1, in, out);
            out.close();
        }
    }
    static class TaskD {
        int[] perms;
        int[][] mergePerms;
        int[] permToIndex;
        List<Group> groups = new ArrayList<>();
        int m;
        Group[] groupArray;
        IntList queue = new IntList(120);
        int[] buf0 = new int[5];
        int[] buf1 = new int[5];

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();

            IntList list = new IntList(120);
            genAllPerm(new boolean[k], 0, 0, list);
            perms = list.toArray();


            m = perms.length;
            permToIndex = new int[100000];
            for (int i = 0; i < m; i++) {
                permToIndex[perms[i]] = i;
            }

            mergePerms = new int[m][m];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    mergePerms[i][j] = permToIndex[merge(perms[i], perms[j], k)];
                }
            }

            for (int i = 0; i < m; i++) {
                Group bs = new Group();
                bs.set(i, true);
                int j = i;
                while (true) {
                    int next = mergePerms[i][j];
                    if (bs.get(next)) {
                        break;
                    }
                    bs.set(next, true);
                    j = next;
                }
                addGroup(bs);
            }

            for (int i = 0; i < groups.size(); i++) {
                for (int j = 0; j < i; j++) {
                    Group g1 = groups.get(i);
                    Group g2 = groups.get(j);
                    addGroup(merge(g1, g2));
                }
            }

            groupArray = groups.toArray(new Group[0]);
            for (Group g : groupArray) {
                g.cardinality = Long.bitCount(g.b1) + Long.bitCount(g.b2);
            }
            Arrays.sort(groupArray, (a, b) -> a.cardinality() - b.cardinality());

            int[] tricks = new int[n];
            for (int i = 0; i < n; i++) {
                int t = 0;
                for (int j = 0; j < k; j++) {
                    t = t * 10 + in.readInt() - 1;
                }
                tricks[i] = permToIndex[t];
            }

            int[][] next = new int[m][n];
            ArrayUtils.deepFill(next, -1);
            next[tricks[n - 1]][n - 1] = n - 1;
            for (int i = n - 2; i >= 0; i--) {
                for (int j = 0; j < m; j++) {
                    next[j][i] = next[j][i + 1];
                    if (tricks[i] == j) {
                        next[j][i] = i;
                    }
                }
            }


            int nature = 0;
            for (int i = 1; i < k; i++) {
                nature = nature * 10 + i;
            }

            long ans = 0;
            Group empty = addElement(new Group(), permToIndex[nature]);
            for (int i = 0; i < n; i++) {

                Group state = empty;
                int trace = i;
                for (; trace < n;) {
                    state = addElement(state, tricks[trace]);

                    int jump = n;
                    for (int j = 0; j < m; j++) {
                        if (next[j][i] != -1 && !state.get(j)) {
                            jump = Math.min(jump, next[j][i]);
                        }
                    }

                    ans += (jump - trace) * state.cardinality();
                    trace = jump;
                }
            }

            out.println(ans);
        }

        public Group merge(Group a, Group b) {
            queue.clear();
            a = new Group(a);
            for (int i = 0; i < m; i++) {
                if (b.get(i) && !a.get(i)) {
                    queue.add(i);
                    a.set(i, true);
                }
            }
            while (!queue.isEmpty()) {
                int last = queue.pop();
                for (int i = 0; i < m; i++) {
                    if (!a.get(i)) {
                        continue;
                    }
                    if (!a.get(mergePerms[i][last])) {
                        a.set(mergePerms[i][last], true);
                        queue.add(mergePerms[i][last]);
                    }
                    if (!a.get(mergePerms[last][i])) {
                        a.set(mergePerms[last][i], true);
                        queue.add(mergePerms[last][i]);
                    }
                }
            }
            return a;
        }

        public void addGroup(Group g) {
            if (groups.contains(g)) {
                return;
            }
            groups.add(g);
        }

        public Group addElement(Group x, int t) {
            for (Group g : groupArray) {
                if (x.subset(g) && g.get(t)) {
                    return g;
                }
            }
            throw new RuntimeException();
        }

        int merge(int a, int b, int k) {
            deserialize(a, k, buf0);
            deserialize(b, k, buf1);
            int ans = 0;
            for (int i = 0; i < k; i++) {
                ans = ans * 10 + buf1[buf0[i]];
            }
            return ans;
        }

        public void deserialize(int x, int k, int[] buf) {
            for (int i = k - 1; i >= 0; i--) {
                buf[i] = x % 10;
                x /= 10;
            }
        }

        void genAllPerm(boolean[] used, int seq, int i, IntList perm) {
            if (i == used.length) {
                perm.add(seq);
                return;
            }
            for (int j = 0; j < used.length; j++) {
                if (used[j]) {
                    continue;
                }
                used[j] = true;
                genAllPerm(used, seq * 10 + j, i + 1, perm);
                used[j] = false;
            }
        }

    }
    static class DigitUtils {
        private DigitUtils() {}

        public static class BitOperator {
            public int bitAt(long x, int i) {
                return (int) ((x >> i) & 1);
            }

            public long setBit(long x, int i, boolean v) {
                if (v) {
                    x |= 1L << i;
                } else {
                    x &= ~(1L << i);
                }
                return x;
            }

            public boolean subset(long x, long y) {
                return intersect(x, y) == x;
            }

            public long intersect(long x, long y) {
                return x & y;
            }

        }

    }
    static class IntList {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntList(IntList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntList() {
            this(0);
        }

        private void ensureSpace(int need) {
            int req = size + need;
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        public void add(int x) {
            ensureSpace(1);
            data[size++] = x;
        }

        public int pop() {
            return data[--size];
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

    }
    static class ArrayUtils {
        public static void deepFill(Object array, int val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof int[]) {
                int[] intArray = (int[]) array;
                Arrays.fill(intArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
            }
        }

    }
    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(1 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(long c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
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

    }
    static class Group {
        static DigitUtils.BitOperator bo = new DigitUtils.BitOperator();
        long b1;
        long b2;
        int cardinality;

        public Group() {}

        public Group(Group g) {
            this.b1 = g.b1;
            this.b2 = g.b2;
            this.cardinality = g.cardinality;
        }

        public void set(int i, boolean v) {
            if (i < 64) {
                b1 = bo.setBit(b1, i, v);
            } else {
                b2 = bo.setBit(b2, i - 64, v);
            }
        }

        public boolean get(int i) {
            if (i < 64) {
                return bo.bitAt(b1, i) == 1;
            } else {
                return bo.bitAt(b2, i - 64) == 1;
            }
        }

        public int cardinality() {
            return cardinality;
        }

        public boolean subset(Group g) {
            return bo.subset(b1, g.b1) && bo.subset(b2, g.b2);
        }

        public boolean equals(Object obj) {
            Group g = (Group) obj;
            return g.b1 == b1 && g.b2 == b2;
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
                    throw new RuntimeException(e);
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