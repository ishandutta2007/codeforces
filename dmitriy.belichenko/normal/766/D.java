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

    class DSU {
        int[] p;
        int[] dist;

        DSU(int n) {
            p = new int[n];
            dist = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
        }

        int find(int x) {
            if (x == p[x]) {
                return x;
            }
            int oldp = p[x];
            p[x] = find(p[x]);
            dist[x] ^= dist[oldp];
            return p[x];
        }

        Random rnd = new Random();

        boolean merge(int x, int y, int d) {
            int px = find(x);
            int py = find(y);
            int realD = dist[x] ^ dist[y];
            if (px == py) {
                if (d != realD) return false;
            } else {
                if (rnd.nextBoolean()) {
                    p[px] = py;
                    dist[px] = realD ^ d;
                } else {
                    p[py] = px;
                    dist[py] = realD ^ d;
                }
            }
            return true;
        }
    }

    void solve() throws IOException {
        int n = readInt();
        int m = readInt();
        int q = readInt();

        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String s = readString();
            map.put(s, map.size());
        }
        DSU dsu = new DSU(map.size());
        for (int i = 0; i < m; i++) {
            int t = readInt() - 1;
            int a = map.get(readString());
            int b = map.get(readString());
            out.println(dsu.merge(a, b, t) ? "YES" : "NO");
        }
        for (int i = 0; i < q; i++) {
            int a = map.get(readString());
            int b = map.get(readString());
            int pa = dsu.find(a);
            int pb = dsu.find(b);
            if (pa != pb) {
                out.println(3);
            } else {
                out.println((dsu.dist[a] ^ dsu.dist[b]) + 1);
            }
        }

    }


}