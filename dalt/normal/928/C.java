

import java.io.*;
import java.util.*;

/**
 * Created by dalt on 2018/4/1.
 */
public class CF928C {
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF928C.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        solve();

        output.flush();
    }

    public static void solve() {
        int projectNum = input.nextInteger();

        Map<ID, Node> nodeMap = new HashMap<>(projectNum);
        ID[][] dependencies = new ID[projectNum][];

        Node[] nodes = new Node[projectNum];


        for (int i = 0; i < projectNum; i++) {
            ID id = new ID(input.nextBlock(), input.nextInteger());
            int dependenciesSize = input.nextInteger();

            nodes[i] = new Node(id, dependenciesSize);

            nodeMap.put(id, nodes[i]);
            dependencies[i] = new ID[dependenciesSize];
            for (int j = 0; j < dependenciesSize; j++) {
                dependencies[i][j] = new ID(input.nextBlock(), input.nextInteger());
            }
        }

        for (int i = 0; i < projectNum; i++) {
            Node node = nodes[i];
            for (int j = 0, until = dependencies[i].length; j < until; j++) {
                node.dependencies[j] = nodeMap.get(dependencies[i][j]);
            }
        }

        //bfs
        Deque<Node> deque = new ArrayDeque<>(projectNum);
        deque.addLast(nodes[0]);
        nodes[0].dist = 0;

        Map<String, Node> dependenciesMap = new HashMap<>(projectNum);
        dependenciesMap.put(nodes[0].id.name, nodes[0]);
        Node[] result = new Node[projectNum];
        int resultLen = 0;
        while (!deque.isEmpty()) {
            Node head = deque.removeFirst();
            if (head.invalid) {
                continue;
            }
            result[resultLen++] = head;
            for (Node dependency : head.dependencies) {
                if (dependency.dist != -1) {
                    continue;
                }
                dependency.dist = head.dist + 1;
                Node exist = dependenciesMap.get(dependency.id.name);
                if (exist != null) {
                    if (exist.dist < dependency.dist || exist.id.version > dependency.id.version) {
                        continue;
                    } else {
                        exist.invalid = true;
                    }
                }

                deque.addLast(dependency);
                dependenciesMap.put(dependency.id.name, dependency);
            }
        }

        if (resultLen == 1) {
            output.println(0);
            return;
        }

        Arrays.sort(result, 1, resultLen, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                int cmp = o1.id.name.compareTo(o2.id.name);
                if (cmp == 0) {
                    cmp = o2.id.version - o1.id.version;
                }
                return cmp;
            }
        });

        int resultNewLen = 2;
        for (int i = 2; i < resultLen; i++) {
            if (result[i].id.name.equals(result[i - 1].id.name)) {
                continue;
            }
            result[resultNewLen++] = result[i];
        }

        output.println(resultNewLen - 1);
        for (int i = 1; i < resultNewLen; i++) {
            output.print(result[i].id.name);
            output.print(' ');
            output.println(result[i].id.version);
        }
    }

    private static class ID {
        String name;
        int version;
        int hashCode;


        public ID(String name, int verison) {
            this.name = name;
            this.version = verison;
        }

        @Override
        public int hashCode() {
            if (hashCode == 0) {
                hashCode = name.hashCode();
                hashCode = (hashCode << 5) - hashCode + version;
                if (hashCode == 0) {
                    hashCode = 1;
                }
            }
            return hashCode;
        }

        @Override
        public boolean equals(Object obj) {
            ID other = (ID) obj;
            return version == other.version && name.equals(other.name);
        }

        @Override
        public String toString() {
            return String.format("%s %d", name, version);
        }
    }

    private static class Node {
        Node[] dependencies;
        ID id;
        int dist = -1;
        boolean invalid;

        public Node(ID id, int dependenciesSize) {
            this.id = id;
            this.dependencies = new Node[dependenciesSize];
        }

        @Override
        public String toString() {
            return id.toString();
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