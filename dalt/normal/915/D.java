

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Arrays;

/**
 * Created by dalt on 2018/1/31.
 */
public class CF915D {
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;
    public static int n;
    public static boolean[][] edges;
    public static boolean[] visited;
    public static boolean[] instack;
    public static int timestamp = 0;


    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF915D.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }

    public static void solve() {
        n = input.nextInteger();
        edges = new boolean[n + 2][n + 2];
        visited = new boolean[n + 2];
        instack = new boolean[n + 2];
        IntList stack = new IntList(1000);
        int root = n + 1;
        for (int i = 1; i <= n; i++) {
            edges[root][i] = true;
        }
        int m = input.nextInteger();
        for (int i = 0; i < m; i++) {
            int from = input.nextInteger();
            int to = input.nextInteger();
            edges[from][to] = true;
        }

        if (!findLoop(root, stack)) {
            System.out.println("YES");
            return;
        }

        int begin, end;
        end = stack.size() - 1;
        for (begin = end - 1; stack.data[begin] != stack.data[end]; begin--) ;

        for (int i = begin; i < end; i++) {
            Arrays.fill(visited, false);
            Arrays.fill(instack, false);
            edges[stack.data[i]][stack.data[i + 1]] = false;
            if (!containLoop(root)) {
                System.out.println("YES");
                return;
            }
            edges[stack.data[i]][stack.data[i + 1]] = true;
        }

        System.out.println("NO");
        return;
    }

    public static boolean findLoop(int node, IntList stack) {
        if (visited[node]) {
            //find a loop
            if (instack[node]) {
                stack.push(node);
                return true;
            } else {
                return false;
            }
        }

        visited[node] = true;
        instack[node] = true;
        stack.push(node);


        for (int i = 1; i <= n; i++) {
            if (!edges[node][i]) {
                continue;
            }

            if (findLoop(i, stack)) {
                return true;
            }
        }

        instack[node] = false;
        stack.pop();
        return false;
    }

    public static boolean containLoop(int node) {
        if (visited[node]) {
            return instack[node];
        }

        visited[node] = true;
        instack[node] = true;


        for (int i = 1; i <= n; i++) {
            if (!edges[node][i]) {
                continue;
            }

            if (containLoop(i)) {
                return true;
            }
        }

        instack[node] = false;
        return false;
    }

    public static class IntList {
        int[] data;
        int size;

        public IntList(int cap) {
            data = new int[cap];
        }

        public void push(int v) {
            ensure(size + 1);
            data[size++] = v;
        }

        public void ensure(int cap) {
            if (cap <= data.length) {
                return;
            }
            int newCap = data.length;
            while (newCap < cap) {
                newCap <<= 1;
            }

            int[] tmp = new int[newCap];
            System.arraycopy(data, 0, tmp, 0, size);
            data = tmp;
        }

        public int pop() {
            return data[--size];
        }

        public int peek() {
            return data[size - 1];
        }

        public int size() {
            return size;
        }

        public void clear() {
            size = 0;
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