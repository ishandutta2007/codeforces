import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }
    static class TaskD {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            Node[] people = new Node[n + 1];
            Node[] cats = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                people[i] = new Node();
                cats[i] = new Node();
                people[i].opposite = cats[i];
                cats[i].opposite = people[i];
            }
            for (int i = 1; i <= m; i++) {
                Node a = people[in.readInt()];
                Node b = cats[in.readInt()];
                a.next.add(b);
                b.next.add(a);
            }

            dfs(people[1], 0);
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (people[i].visited) {
                    cnt++;
                }
            }


            if (cnt < n) {
                out.println("Yes");
                out.append(cnt).append(' ').append(n - cnt).append('\n');
                for (int i = 1; i <= n; i++) {
                    if (people[i].visited) {
                        out.append(i).append(' ');
                    }
                }
                out.println();
                for (int i = 1; i <= n; i++) {
                    if (!people[i].visited) {
                        out.append(i).append(' ');
                    }
                }
                out.println();
                return;
            }

            for (int i = 1; i <= n; i++) {
                people[i].visited = cats[i].visited = false;
            }
            dfs(cats[1], 0);

            cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (cats[i].visited) {
                    cnt++;
                }
            }

            if (cnt == n) {
                out.println("No");
                return;
            }
            out.println("Yes");
            out.append(n - cnt).append(' ').append(cnt).append('\n');
            for (int i = 1; i <= n; i++) {
                if (!cats[i].visited) {
                    out.append(i).append(' ');
                }
            }
            out.println();
            for (int i = 1; i <= n; i++) {
                if (cats[i].visited) {
                    out.append(i).append(' ');
                }
            }
            out.println();
            return;
        }

        public void dfs(Node root, int depth) {
            if (root.visited) {
                return;
            }
            root.visited = true;
            if (depth % 2 == 1) {
                dfs(root.opposite, depth + 1);
                return;
            }

            for (Node node : root.next) {
                dfs(node, depth + 1);
            }
        }

    }
    static class Node {
        List<Node> next = new ArrayList<>();
        Node opposite;
        boolean visited;

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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(String c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
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
    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public String next() {
            return readString();
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

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
        }

    }
}