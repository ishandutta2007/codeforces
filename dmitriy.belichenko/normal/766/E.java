import java.io.*;
import java.util.*;

public class Template implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    void init() throws FileNotFoundException {
        try {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } catch (Exception e) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }
    }

    String readString() throws IOException {
        while (!tok.hasMoreTokens()) {
            try {
                tok = new StringTokenizer(in.readLine(), " :");
            } catch (Exception e) {
                return null;
            }
        }
        return tok.nextToken();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    int[] readIntArray(int size) throws IOException {
        int[] res = new int[size];
        for (int i = 0; i < size; i++) {
            res[i] = readInt();
        }
        return res;
    }

    long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }

    <T> List<T>[] createGraphList(int size) {
        List<T>[] list = new List[size];
        for (int i = 0; i < size; i++) {
            list[i] = new ArrayList<>();
        }
        return list;
    }

    public static void main(String[] args) {
        new Template().run();
        // new Thread(null, new Template(), "", 1l * 200 * 1024 * 1024).start();
    }

    long timeBegin, timeEnd;

    void time() {
        timeEnd = System.currentTimeMillis();
        System.err.println("Time = " + (timeEnd - timeBegin));
    }

    long memoryTotal, memoryFree;

    void memory() {
        memoryFree = Runtime.getRuntime().freeMemory();
        System.err.println("Memory = " + ((memoryTotal - memoryFree) >> 10)
                + " KB");
    }

    public void run() {
        try {
            timeBegin = System.currentTimeMillis();
            memoryTotal = Runtime.getRuntime().freeMemory();
            init();
            solve();
            out.close();
            if (System.getProperty("ONLINE_JUDGE") == null) {
                time();
                memory();
            }
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    class Graph {
        int[][] graph;

        List<Integer>[] temp;

        Graph(int n) {
            temp = new List[n];
            for (int i = 0; i < n; i++) {
                temp[i] = new ArrayList<>();
            }
        }

        void add(int x, int y) {
            temp[x].add(y);
            temp[y].add(x);
        }

        int[][] build() {
            graph = new int[temp.length][];
            for (int i = 0; i < temp.length; i++) {
                graph[i] = new int[temp[i].size()];
                for (int j = 0; j < temp[i].size(); j++) {
                    graph[i][j] = temp[i].get(j);
                }
            }
            return graph;
        }
    }

    int[][] graph;
    int[] a;

    long sum = 0;

    boolean have(int x, int bit) {
        return (x & bit) != 0;
    }

    int[] cntCbottom;
    int[] cntNbottom;

    void dfs(int x, int parent, int bit, int cntCtop, int cntNtop) {
        boolean have = have(a[x], bit);
        cntCbottom[x] = cntNbottom[x] = 0;
        if (have) {
            sum += bit;
            int t = cntCtop;
            cntCtop = cntNtop;
            cntNtop = t;
        }
        sum += (long) cntNtop * bit;
        for (int y : graph[x]) {
            if (y == parent) continue;
            dfs(y, x, bit, cntCtop + cntCbottom[x], cntNtop + cntNbottom[x]);
            if (have) {
                cntCbottom[x] += cntNbottom[y];
                cntNbottom[x] += cntCbottom[y];
            } else {
                cntCbottom[x] += cntCbottom[y];
                cntNbottom[x] += cntNbottom[y];
            }
        }
        sum += (long) cntNbottom[x] * bit;
        if (have) cntNbottom[x]++; else cntCbottom[x]++;
    }

    void solve() throws IOException {
        int n = readInt();
        cntNbottom = new int[n];
        cntCbottom = new int[n];
        a = readIntArray(n);
        Graph g = new Graph(n);
        for (int i = 0; i < n - 1; i++) {
            int x = readInt() - 1;
            int y = readInt() - 1;
            g.add(x, y);
        }
        graph = g.build();
        for (int bit = 0; bit < 22; bit++) {
            dfs(0, 0, 1 << bit, 0, 0);
        }
        out.println(sum);

    }


}