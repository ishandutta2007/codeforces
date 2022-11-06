
import java.io.*;
import java.nio.charset.Charset;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class Contest45F {
    public static void main(String[] args) throws FileNotFoundException {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        IOUtil io;
        if (local) {
            io = new IOUtil(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\Contest45F.in"), new FileOutputStream("E:\\DATABASE\\TESTCASE\\codeforces\\Contest45F.out"));
        } else {
            io = new IOUtil(System.in, System.out);
        }

        Task task = new Task(io);
        task.run();
        io.flush();
    }

    public static class Task implements Runnable {
        IOUtil io;

        public Task(IOUtil io) {
            this.io = io;
        }

        @Override
        public void run() {
            int n = io.readInt();
            Node[] nodes = new Node[n + 1];
            int sum = 0;

            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
                nodes[i].differ = -io.readInt();
                sum += nodes[i].differ;
            }

            if (sum != 0) {
                io.write("Impossible");
                return;
            }

            int m = io.readInt();
            Edge[] edges = new Edge[m];
            for (int i = 0; i < m; i++) {
                Node a = nodes[io.readInt()];
                Node b = nodes[io.readInt()];



                Edge edge = new Edge();
                edge.src = a;
                edge.dst = b;
                edges[i] = edge;

                if (a.findSet() == b.findSet()) {
                    continue;
                } else {
                    Node.union(a, b);
                }

                a.children.add(edge);
                b.children.add(edge);
            }

            dfs(nodes[1], new Edge());
            io.write("Possible\n");
            for (int i = 0; i < m; i++) {
                io.write(edges[i].getFlow(edges[i].src));
                io.write('\n');
            }
            return;
        }

        public static void dfs(Node root, Edge father) {
            for (Edge edge : root.children) {
                if (edge == father) {
                    continue;
                }
                Node other = edge.other(root);
                dfs(other, edge);
                root.differ -= edge.getFlow(root);
            }

            father.sendFlow(root, root.differ);
        }
    }

    public static class Node {
        List<Edge> children = new ArrayList<>(1);
        Node p = this;
        int rank;
        int differ; //The flow into minus flow outside
        int id;

        @Override
        public String toString() {
            return "" + id;
        }

        public Node findSet() {
            return p.p == p ? p : (p = p.findSet());
        }

        public static void union(Node a, Node b) {
            a = a.findSet();
            b = b.findSet();
            if (a == b) {
                return;
            }
            if (a.rank == b.rank) {
                a.rank++;
            }
            if (a.rank > b.rank) {
                b.p = a;
            } else {
                a.p = b;
            }
        }
    }

    public static class Edge {
        Node src;
        Node dst;
        int flow; //The number flow from src to dst

        public void sendFlow(Node from, int f) {
            if (dst == from) {
                f = -f;
            }
            flow += f;
        }

        public int getFlow(Node own) {
            return src == own ? flow : -flow;
        }

        public Node other(Node own) {
            return src == own ? dst : src;
        }
    }

    public static class IOUtil {
        private static int BUF_SIZE = 1 << 13;

        private byte[] r_buf = new byte[BUF_SIZE];
        private int r_cur;
        private int r_total;
        private int r_next;
        private final InputStream in;
        private StringBuilder temporary = new StringBuilder();

        StringBuilder w_buf = new StringBuilder();
        private final OutputStream out;

        public IOUtil(InputStream in, OutputStream out) {
            this.in = in;
            this.out = out;
        }

        private void skipBlank() {
            while (r_next <= 32) {
                r_next = read();
            }
        }

        public int readString(char[] data, int offset, int limit) {
            skipBlank();

            int originalLimit = limit;
            while (limit > 0 && r_next > 32) {
                data[offset++] = (char) r_next;
                limit--;
                r_next = read();
            }

            return originalLimit - limit;
        }

        public String readString(StringBuilder builder) {
            skipBlank();

            while (r_next > 32) {
                builder.append((char) r_next);
                r_next = read();
            }

            return builder.toString();
        }

        public String readString() {
            temporary.setLength(0);
            return readString(temporary);
        }

        public long readUnsignedLong() {
            skipBlank();

            long num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 + r_next - '0';
                r_next = read();
            }
            return num;
        }

        public long readLong() {
            skipBlank();

            int sign = 1;
            while (r_next == '+' || r_next == '-') {
                if (r_next == '-') {
                    sign *= -1;
                }
                r_next = read();
            }

            return sign == 1 ? readUnsignedLong() : readNegativeLong();
        }

        public long readNegativeLong() {
            skipBlank();

            long num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 - r_next + '0';
                r_next = read();
            }
            return num;
        }

        public int readUnsignedInt() {
            skipBlank();

            int num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 + r_next - '0';
                r_next = read();
            }
            return num;
        }

        public int readNegativeInt() {
            skipBlank();

            int num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 - r_next + '0';
                r_next = read();
            }
            return num;
        }

        public int readInt() {
            skipBlank();

            int sign = 1;
            while (r_next == '+' || r_next == '-') {
                if (r_next == '-') {
                    sign *= -1;
                }
                r_next = read();
            }

            return sign == 1 ? readUnsignedInt() : readNegativeInt();
        }

        public int read() {
            while (r_total <= r_cur) {
                try {
                    r_total = in.read(r_buf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                r_cur = 0;
                if (r_total == -1) {
                    return -1;
                }
            }
            return r_buf[r_cur++];
        }

        public void write(char c) {
            w_buf.append(c);
        }

        public void write(int n) {
            w_buf.append(n);
        }

        public void write(String s) {
            w_buf.append(s);
        }

        public void write(long s) {
            w_buf.append(s);
        }

        public void write(double s) {
            w_buf.append(s);
        }

        public void write(float s) {
            w_buf.append(s);
        }

        public void write(Object s) {
            w_buf.append(s);
        }

        public void write(char[] data, int offset, int cnt) {
            for (int i = offset, until = offset + cnt; i < until; i++) {
                write(data[i]);
            }
        }

        public void flush() {
            try {
                out.write(w_buf.toString().getBytes(Charset.forName("ascii")));
                w_buf.setLength(0);
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public double readDouble() {
            return Double.parseDouble(readString());
        }
    }
}