
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/3/25.
 */
public class CF935F {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF935F.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }

    public static void solve() {
        int n = input.nextInteger();
        long[] numbers = new long[n + 1];
        long sum = 0;


        IntervalTree valueTree = new IntervalTree(1, n);
        numbers[1] = input.nextInteger();
        valueTree.setValue(1, 1, numbers[1]);
        for (int i = 2; i <= n; i++) {
            numbers[i] = input.nextInteger();
            sum += Math.abs(numbers[i] - numbers[i - 1]);
            valueTree.setValue(i, i, numbers[i]);
        }

        IntervalTree depthTree = new IntervalTree(2, n - 1);
        for (int i = 2; i < n; i++) {
            setHeight(depthTree, numbers[i - 1], numbers[i], numbers[i + 1], i);
        }

        int q = input.nextInteger();

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < q; i++) {
            int t = input.nextInteger();
            int l = input.nextInteger();
            int r = input.nextInteger();
            int x = input.nextInteger();

            // find the maximum possible value of f(A),
            // if x is to be added to one element in the range [l,r].
            // You can choose to which element to add x.
            int[] position = new int[1];
            if (t == 1) {
                long maxAdd = Long.MIN_VALUE;
                boolean containL = l == 1;
                boolean containR = r == n;
                l = Math.max(l, 2);
                r = Math.min(r, n - 1);
                if (l <= r) {
                    long minNeed = depthTree.queryMin(l, r);
                    if (minNeed < Long.MAX_VALUE) {
                        maxAdd = Math.max(maxAdd, Math.max(0, (x - minNeed) * 2));
                    }
                    if (depthTree.findMaxIndex(l, r, position)) {
                        int pos = position[0];
                        long nPos = valueTree.queryMin(pos, pos);
                        long nPosSub1 = valueTree.queryMin(pos - 1, pos - 1);
                        long nPosAdd1 = valueTree.queryMin(pos + 1, pos + 1);
                        maxAdd = Math.max(maxAdd, Math.abs(nPos + x - nPosSub1) +
                                Math.abs(nPos + x - nPosAdd1) - Math.abs(nPos - nPosSub1) -
                                Math.abs(nPos - nPosAdd1));
                    }
                }
                if (containL) {
                    long n1 = valueTree.queryMin(1, 1);
                    long n2 = valueTree.queryMin(2, 2);
                    maxAdd = Math.max(maxAdd, Math.abs(n1 + x - n2) - Math.abs(n1 - n2));
                }
                if (containR) {
                    long nNSub1 = valueTree.queryMin(n - 1, n - 1);
                    long nN = valueTree.queryMin(n, n);
                    maxAdd = Math.max(maxAdd, Math.abs(nN + x - nNSub1) - Math.abs(nN - nNSub1));
                }
                result.append(sum + maxAdd).append('\n');
            }
            //2lrx  increase all the elements in the range [l,r] by value x.
            else {
                if (l != 1) {
                    long nl = valueTree.queryMin(l, l);
                    long nlSub1 = valueTree.queryMin(l - 1, l - 1);
                    long nlAdd1 = valueTree.queryMin(l + 1, l + 1);
                    sum += Math.abs(nl + x - nlSub1) - Math.abs(nl - nlSub1);
                    nl += x;
                    if (l < r) {
                        nlAdd1 += x;
                    }
                    setHeight(depthTree, nlSub1, nl, nlAdd1, l);

                    if (l - 1 != 1) {
                        long nlSub2 = valueTree.queryMin(l - 2, l - 2);
                        setHeight(depthTree, nlSub2, nlSub1, nl, l - 1);
                    }
                }
                if (r != n) {
                    long nr = valueTree.queryMin(r, r);
                    long nrSub1 = valueTree.queryMin(r - 1, r - 1);
                    long nrAdd1 = valueTree.queryMin(r + 1, r + 1);
                    sum += Math.abs(nr + x - nrAdd1) - Math.abs(nr - nrAdd1);
                    nr += x;
                    if (l < r) {
                        nrSub1 += x;
                    }
                    setHeight(depthTree, nrSub1, nr, nrAdd1, r);

                    if (r + 1 != n) {
                        long nrAdd2 = valueTree.queryMin(r + 2, r + 2);
                        setHeight(depthTree, nr, nrAdd1, nrAdd2, r + 1);
                    }
                }
                valueTree.update(l, r, x);
            }
        }

        System.out.println(result);

    }

    public static void setHeight(IntervalTree heightTree, long vl, long v, long vr, int i) {
        if (v < vl && v < vr) {
            heightTree.setValue(i, i, Long.MAX_VALUE);
        } else {
            heightTree.setValue(i, i, Math.max(0, Math.max(vl, vr) - v));
        }
    }

    public static class IntervalTree {
        int left, right;
        Interval root;

        public IntervalTree(int l, int r) {
            left = l;
            right = r;
            root = build(l, r);
        }

        public static Interval build(int l, int r) {
            Interval interval = new Interval();
            if (l != r) {
                int m = (l + r) >> 1;
                interval.left = build(l, m);
                interval.right = build(m + 1, r);
            }
            return interval;
        }

        public static void setValue(int from, int to, int l, int r, long val, Interval node) {
            if (from <= l && r <= to) {
                node.setValue(val);
                return;
            }
            node.pushDown();
            int m = (l + r) >> 1;
            if (from <= m) {
                setValue(from, to, l, m, val, node.left);
            }
            if (m < to) {
                setValue(from, to, m + 1, r, val, node.right);
            }
            node.pushUp();
        }

        public static long queryMin(int from, int to, int l, int r, Interval node) {
            if (from <= l && r <= to) {
                return node.min;
            }
            node.pushDown();
            int m = (l + r) >> 1;
            long min = Long.MAX_VALUE;
            if (from <= m) {
                min = Math.min(min, queryMin(from, to, l, m, node.left));
            }
            if (m < to) {
                min = Math.min(min, queryMin(from, to, m + 1, r, node.right));
            }
            return min;
        }

        public static void update(int from, int to, int l, int r, long v, Interval node) {
            if (from <= l && r <= to) {
                node.update(v);
                return;
            }
            node.pushDown();
            int m = (l + r) >> 1;
            long min = Long.MAX_VALUE;
            if (from <= m) {
                update(from, to, l, m, v, node.left);
            }
            if (m < to) {
                update(from, to, m + 1, r, v, node.right);
            }
            node.pushUp();
        }

        public static boolean findMaxIndex(int from, int to, int l, int r, Interval node, int[] position) {
            if (node.max != Long.MAX_VALUE) {
                return false;
            }
            if (l == r) {
                position[0] = l;
                return true;
            }

            node.pushDown();
            boolean find = false;
            int m = (l + r) >> 1;
            if (from <= m && node.left.max == Long.MAX_VALUE) {
                find = findMaxIndex(from, to, l, m, node.left, position);
            }
            if (find == false && to > m && node.right.max == Long.MAX_VALUE) {
                find = findMaxIndex(from, to, m + 1, r, node.right, position);
            }
            return find;
        }

        public void update(int from, int to, int v) {
            update(from, to, left, right, v, root);
        }

        public boolean findMaxIndex(int from, int to, int[] pos) {
            return findMaxIndex(from, to, left, right, root, pos);
        }

        public long queryMin(int from, int to) {
            return queryMin(from, to, left, right, root);
        }

        public void setValue(int from, int to, long val) {
            setValue(from, to, left, right, val, root);
        }

        public static class Interval {
            long min;
            long max;
            long update;
            boolean updateDirty;
            boolean valueDirty;
            Interval left;
            Interval right;

            public void pushDown() {
                if (valueDirty) {
                    left.setValue(min);
                    right.setValue(min);
                    valueDirty = false;
                }

                if (updateDirty) {
                    left.update(update);
                    right.update(update);
                    updateDirty = false;
                    update = 0;
                }
            }

            public void setValue(long val) {
                this.min = this.max = val;
                this.valueDirty = true;
                this.update = 0;
                this.updateDirty = false;
            }

            public void update(long val) {
                if (valueDirty) {
                    min = max = min + val;
                } else {
                    updateDirty = true;
                    update += val;
                    min += val;
                    max += val;
                }
            }

            public void pushUp() {
                this.min = Math.min(left.min, right.min);
                this.max = Math.max(left.max, right.max);
            }
        }
    }

    public static class BlockReader {
        static final int EOF = -1;
        InputStream is;
        byte[] dBuf;
        int dPos, dSize, next;
        StringBuilder builder = new StringBuilder();

        public BlockReader(InputStream is) {
            this(is, 4096);
        }

        public BlockReader(InputStream is, int bufSize) {
            this.is = is;
            dBuf = new byte[bufSize];
            next = nextByte();
        }

        public int nextByte() {
            while (dPos >= dSize) {
                if (dSize == -1) {
                    return EOF;
                }
                dPos = 0;
                try {
                    dSize = is.read(dBuf);
                } catch (Exception e) {
                }
            }
            return dBuf[dPos++];
        }

        public String nextBlock() {
            builder.setLength(0);
            skipBlank();
            while (next != EOF && !Character.isWhitespace(next)) {
                builder.append((char) next);
                next = nextByte();
            }
            return builder.toString();
        }

        public void skipBlank() {
            while (Character.isWhitespace(next)) {
                next = nextByte();
            }
        }

        public int nextInteger() {
            skipBlank();
            int ret = 0;
            boolean rev = false;
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = nextByte();
            }
            while (next >= '0' && next <= '9') {
                ret = (ret << 3) + (ret << 1) + next - '0';
                next = nextByte();
            }
            return rev ? -ret : ret;
        }

        public int nextBlock(char[] data, int offset) {
            skipBlank();
            int index = offset;
            int bound = data.length;
            while (next != EOF && index < bound && !Character.isWhitespace(next)) {
                data[index++] = (char) next;
                next = nextByte();
            }
            return index - offset;
        }

        public boolean hasMore() {
            skipBlank();
            return next != EOF;
        }
    }
}