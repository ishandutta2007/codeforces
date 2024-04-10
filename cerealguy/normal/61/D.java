import java.io.*;
import java.util.*;

public class D {

    static class Edge {
        int to;
        int w;

        public Edge(int to, int w) {
            this.to = to;
            this.w = w;
        }
    }

    ArrayList<Edge> e[];
    int n;
    long depth;
    long total;
    long maxdepth;

    void dfs(int u, int p) {
        maxdepth = Math.max(maxdepth, depth);
        for (Edge edg : e[u]) {
            if (edg.to != p) {
                depth += edg.w;
                dfs(edg.to, u);
                depth -= edg.w;
            }
        }
    }

    private void solve() throws IOException {
        n = nextInt();
        e = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            e[i] = new ArrayList<D.Edge>(2);
        }
        for (int i = 0; i < n - 1; i++) {
            int u = nextInt() - 1, v = nextInt() - 1, w = nextInt();
            e[u].add(new Edge(v, w));
            e[v].add(new Edge(u, w));
            total += 2 * w;
        }
        dfs(0, -1);
        out.println(total - maxdepth);
    }

    public static void main(String[] args) {
        new D().run();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;
    boolean eof = false;

    public void run() {
        Locale.setDefault(Locale.US);
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            st = new StringTokenizer("");
            solve();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            System.exit(239);
        }
    }

    String nextToken() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                eof = true;
                line = "0";
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}