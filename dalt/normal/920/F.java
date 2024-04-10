

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/2/28.
 */
public class CF920F {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF920F.in"));
        }
        input = new BlockReader(System.in);
        StringBuilder builder = new StringBuilder();

        int n = input.nextInteger();
        int m = input.nextInteger();

        int[] cache = getD(1000000);

        Node[] nodes = new Node[n + 2];
        Node[] buffer = new Node[n + 2];
        Bit bit = new Bit(n);
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
            nodes[i].val = input.nextInteger();
            nodes[i].next = i;
            bit.update(i, nodes[i].val);
        }
        nodes[n + 1] = new Node();
        nodes[n + 1].next = n + 1;


        for (int i = 1; i <= m; i++) {
            int t = input.nextInteger();
            int l = input.nextInteger();
            int r = input.nextInteger();

            //REPLACE l r  for every  replace ai with D(ai);
            if (t == 1) {
                int j = l;
                while ((j = nodes[j].getP(buffer).next) <= r) {
                    int newVal = cache[nodes[j].val];
                    if (newVal == nodes[j].val) {
                        Node.union(nodes[j], nodes[j + 1], buffer);
                    } else {
                        bit.update(j, newVal - nodes[j].val);
                        nodes[j].val = newVal;
                        j++;
                    }
                }
            } else {
                //SUM l r  calculate .
                long s = bit.query(r) - bit.query(l - 1);
                builder.append(s).append('\n');
            }
        }

        System.out.print(builder);
    }

    public static int[] getD(int n) {
        int[] data = new int[n + 1];
        data[1] = 1;
        int[] primes = new int[n + 1];
        int primeCnt = 0;
        boolean[] isComposite = new boolean[n + 1];
        for (int i = 2; i <= n; i++) {
            if (!isComposite[i]) {
                primes[primeCnt++] = i;
                data[i] = 2;
            }
            //p * i <= n -> p <= n / i -> p<= floor(n / i)
            for (int j = 0, bound = n / i; j < primeCnt && primes[j] <= bound; j++) {
                int p = primes[j];
                int pi = p * i;
                isComposite[pi] = true;

                if (i % p == 0) { // the same as gcd(i, p) > 1
                    data[pi] = data[i] * 2 - data[i / p];
                    break;
                }
                data[pi] = data[i] * data[p];
            }
        }

        return data;
    }

    public static class Bit {
        long[] data;

        public Bit(int cap) {
            data = new long[cap + 1];
        }

        public long query(int i) {
            long s = 0;
            for (; i > 0; i -= i & -i) {
                s += data[i];
            }
            return s;
        }

        public void update(int i, int v) {
            for (int bound = data.length; i < bound; i += i & -i) {
                data[i] += v;
            }
        }
    }

    public static class Node {
        int rank;
        int next;
        int val;
        Node p = this;

        public static void union(Node a, Node b, Node[] que) {
            a = a.getP(que);
            b = b.getP(que);
            if (a == b) {
                return;
            }

            if (a.rank == b.rank) {
                a.rank++;
            }
            if (a.rank > b.rank) {
                b.p = a;
                a.next = Math.max(a.next, b.next);
            } else {
                a.p = b;
                b.next = Math.max(a.next, b.next);
            }
        }

        public Node getP(Node[] que) {
            int queTop = 0;
            Node trace;
            for (trace = this; trace.p != trace; trace = trace.p) {
                que[queTop++] = trace;
            }
            while (queTop > 0) {
                que[--queTop].p = trace;
            }
            return trace;
        }

        @Override
        public String toString() {
            return "(" + val + "->" + next + ")";
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