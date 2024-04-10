

import java.io.*;
import java.util.*;

/**
 * Created by dalt on 2018/4/1.
 */
public class CF919F {
    static final int LOST = 1;
    static final int UNKNOWN = 0;
    static final int WIN = 2;
    public static BlockReader input;
    public static PrintStream output;
    static int[][][][][] id = new int[9][9][9][9][9];
    static int[][] status = new int[495][5];
    static int idLen = 0;
    static Node[][] nodes = new Node[495][495];
    static int[] tmpStatus = new int[5];
    static int[] improveStatusCnt = new int[4];

    public static void main(String[] args) throws FileNotFoundException {
        init();

        for (int t = input.nextInteger(); t > 0; t--) {
            solve();
        }

        output.flush();
    }

    public static void init() throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF919F.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        initId(8, new int[5], 0);

        for (int i = 0; i < idLen; i++) {
            for (int j = 0; j < idLen; j++) {
                nodes[i][j] = new Node();
                nodes[i][j].id1 = i;
                nodes[i][j].id2 = j;
            }
        }

        int[] endStatus = new int[]{8, 0, 0, 0, 0};
        int endStatusId = getId(endStatus);

        int[] status1 = new int[5];
        int[] status2 = new int[5];
        for (int i = 0; i < idLen; i++) {
            for (int j = 0; j < idLen; j++) {
                getStatus(i, status1);
                getStatus(j, status2);

                for (int k = 1; k < 5; k++) {
                    if (status1[k] == 0) {
                        continue;
                    }
                    for (int t = 1; t < 5; t++) {
                        if (status2[t] == 0) {
                            continue;
                        }
                        int newCard = (k + t) % 5;

                        //Change
                        status1[k]--;
                        status1[newCard]++;


                        int newStatus = getId(status1);
                        nodes[j][newStatus].outEdge.add(nodes[i][j]);
                        nodes[i][j].relyon++;
                        nodes[i][j].inEdge.add(nodes[j][newStatus]);

                        //Restore
                        status1[newCard]--;
                        status1[k]++;
                    }
                }
            }
        }

        //Spfa

        Deque<Node> deque = new ArrayDeque<>(495 * 495);
        for (int i = 0; i < idLen; i++) {
            if (i == endStatusId) {
                continue;
            }
            Node node = nodes[endStatusId][i];
            Node otherSide = nodes[i][endStatusId];

            node.status = WIN;
            otherSide.status = LOST;
            node.instk = true;
            otherSide.instk = true;

            deque.add(node);
            deque.add(otherSide);
        }

        while (!deque.isEmpty()) {
            Node head = deque.removeFirst();
            head.instk = false;
            for (Node node : head.outEdge) {
                if (improve(head, node) && !node.instk) {
                    node.instk = true;
                    deque.addLast(node);
                }
            }
        }
    }

    public static void solve() {

        boolean aliceFirst = input.nextInteger() == 0;

        Arrays.fill(tmpStatus, 0);
        for (int i = 0; i < 8; i++) {
            tmpStatus[input.nextInteger()]++;
        }

        int aliceCard = getId(tmpStatus);

        Arrays.fill(tmpStatus, 0);
        for (int i = 0; i < 8; i++) {
            tmpStatus[input.nextInteger()]++;
        }

        int bobCard = getId(tmpStatus);

        Node node = aliceFirst ? nodes[aliceCard][bobCard] : nodes[bobCard][aliceCard];
        if (node.status == UNKNOWN) {
            output.println("Deal");
            return;
        }
        if (node.status == WIN) {
            output.println(aliceFirst ? "Alice" : "Bob");
            return;
        }
        if (node.status == LOST) {
            output.println(aliceFirst ? "Bob" : "Alice");
            return;
        }
    }

    public static void getStatus(int id, int[] data) {
        for (int i = 0; i < 5; i++) {
            data[i] = status[id][i];
        }
    }

    public static int getId(int[] data) {
        return id[data[0]][data[1]][data[2]][data[3]][data[4]];
    }

    static boolean improve(Node src, Node dst) {
        dst.relyon--;

        if (dst.status != UNKNOWN) {
            return false;
        }

        if (src.status == LOST) {
            dst.status = WIN;
            return true;
        }

        if (dst.relyon == 0) {
            for (Node node : dst.inEdge) {
                if (node.status == UNKNOWN) {
                    return false;
                }
            }
            dst.status = LOST;
            return true;
        }

        return false;
    }


    public static void initId(int remain, int[] data, int i) {
        if (i == 4) {
            data[i] = remain;

            for (int j = 0; j < 5; j++) {
                status[idLen][j] = data[j];
            }
            id[data[0]][data[1]][data[2]][data[3]][data[4]] = idLen;
            idLen++;
            return;
        }

        for (int j = 0; j <= remain; j++) {
            data[i] = j;
            initId(remain - j, data, i + 1);
        }

    }

    public static class Node {
        int status;
        int id1;
        int id2;
        boolean instk;
        int relyon;

        List<Node> outEdge = new ArrayList<>();
        List<Node> inEdge = new ArrayList<>();

        @Override
        public String toString() {
            int[] data = new int[5];
            getStatus(id1, data);
            String s = Arrays.toString(data);
            getStatus(id2, data);
            s = s + "\n" + Arrays.toString(data);
            switch (status) {
                case LOST:
                    s += "LOST";
                    break;
                case WIN:
                    s += "WIN";
                    break;
                case UNKNOWN:
                default:
                    s += "UNKNOWN";
                    break;
            }
            return s;
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