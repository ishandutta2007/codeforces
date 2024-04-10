
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Created by dalt on 2018/3/20.
 */
public class CF932D {

    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF932D.in"));
        }
        input = new BlockReader(System.in);

        int q = input.nextInteger();
        int cnt = 1;
        Node[] nodes = new Node[400001];
        nodes[1] = new Node();
        nodes[1].weight = 0;
        nodes[1].id = 1;

        StringBuilder result = new StringBuilder();
        int last = 0;
        for (int i = 0; i < q; i++) {
            int t = input.nextInteger();
            Node node = nodes[input.nextInteger() ^ last];
            long w = input.nextLong() ^ last;
            //Add a new node (index cnt+1) with weight W and add edge between node R and this node.
            if (t == 1) {
                cnt++;
                nodes[cnt] = new Node();
                nodes[cnt].weight = w;
                nodes[cnt].id = cnt;
                nodes[cnt].setFather(node);
            } else {
                last = node.query(w);
                result.append(last).append('\n');
            }
        }

        System.out.print(result);
    }

    public static class Node {
        long weight;
        //assume exists a sequence start with this, and the next guy is the lowest ancestor of this that satisfy next.weight >= this.weight
        //this.ancestor[i] means the 2^i-th element after this, so this.ancestor[i].ancestor[i] = this.ancestor[i + 1]
        //this.totalWeight is the total weight between ancestor[0] and ancestor[i](include) in sequence.
        //obviously this.totalWeight[i + 1] = this.totalWeight[i] + this.ancestor[i].totalWeight[i]
        Node[] ancestor = new Node[20];
        long[] totalWeight = new long[20];
        int id;

        @Override
        public String toString() {
            return id + ":" + weight;
        }

        public void setFather(Node father) {

            Node upper = father;
            int high = 19;
            while (high >= 0) {
                for (; high >= 0 && (upper.ancestor[high] == null || upper.ancestor[high].weight >= weight); high--)
                    ;
                if (high >= 0) {
                    upper = upper.ancestor[high];
                }
            }
            if (upper.weight < weight) {
                upper = upper.ancestor[0];
            }

            if (upper != null) {
                ancestor[0] = upper;
                totalWeight[0] = upper.weight;
                for (int i = 0; i < 19 && ancestor[i] != null; i++) {
                    ancestor[i + 1] = ancestor[i].ancestor[i];
                    totalWeight[i + 1] = ancestor[i].totalWeight[i] + totalWeight[i];
                }
            }
        }

        public int query(long x) {
            if (x < weight) {
                return 0;
            }
            int len = 1;
            x -= weight;


            Node upper = this;
            int high = 19;
            while (high >= 0) {
                for (; high >= 0 && (upper.ancestor[high] == null || upper.totalWeight[high] > x); high--) ;
                if (high >= 0) {
                    x -= upper.totalWeight[high];
                    upper = upper.ancestor[high];
                    len += 1 << high;
                }
            }

            return len;
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

        public long nextLong() {
            skipBlank();
            long ret = 0;
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