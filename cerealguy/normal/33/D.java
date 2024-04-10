import java.io.*;
import java.util.*;

public class D implements Runnable {

    class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    class Circle {
        int r, x, y;

        public Circle(int r, int x, int y) {
            this.r = r;
            this.x = x;
            this.y = y;
        }

        int compareTo(Circle c) {
            long dx = x - c.x, dy = y - c.y;
            long sqdist = dx * dx + dy * dy;
            long rr = r + c.r;
            rr = rr * rr;
            if (sqdist < rr) {
                if (r > c.r)
                    return 1;
                else
                    return -1;
            } else {
                return 0;
            }
        }

        boolean inside(Point p) {
            long dx = p.x - x, dy = p.y - y;
            return dx * dx + dy * dy < (long)r * r;
        }
    }

    ArrayList<Integer> topsort = new ArrayList<Integer>();
    ArrayList<Integer> e[];
    boolean[] visited;

    void dfs0(int u) {
        for (int v : e[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dfs0(v);
            }
        }
        topsort.add(u);
    }

    public class DisjointSets {
        int[] r;
        int[] p;
        int[] ancestor;

        public DisjointSets(int n) {
            r = new int[n];
            p = new int[n];
            ancestor = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
                ancestor[i] = i;
            }
        }

        public int get(int i) {
            if (p[i] != i)
                p[i] = get(p[i]);
            return p[i];
        }

        int ancestor(int i) {
            return ancestor[get(i)];
        }

        public void union(int i, int j, int anc) {
            i = get(i);
            j = get(j);
            if (i == j)
                return;
            if (r[i] < r[j]) {
                p[i] = j;
                ancestor[j] = anc;
            } else {
                p[j] = i;
                ancestor[i] = anc;
                if (r[i] == r[j])
                    r[i]++;
            }
        }

    }

    DisjointSets ds;
    ArrayList<Integer> q[];

    int[][] answers;

    @SuppressWarnings("unchecked")
    private void solve() throws IOException {
        int n = nextInt(), m = nextInt(), k = nextInt();
        Point[] a = new Point[n];
        Circle[] c = new Circle[m];
        for (int i = 0; i < n; i++) {
            a[i] = new Point(nextInt(), nextInt());
        }
        for (int i = 0; i < m; i++) {
            c[i] = new Circle(nextInt(), nextInt(), nextInt());
        }

        e = new ArrayList[m + 1];
        visited = new boolean[m + 1];
        for (int i = 0; i < e.length; i++) {
            e[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int cmp = c[i].compareTo(c[j]);
                if (cmp == 1) {
                    e[i].add(j);
                }
                if (cmp == -1) {
                    e[j].add(i);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            e[m].add(i);
        }
        topsort = new ArrayList<Integer>();
        visited[m] = true;
        dfs0(m);
        Collections.reverse(topsort);
        int[] sortPosition = new int[m + 1];
        for (int i = 0; i < m + 1; i++) {
            sortPosition[topsort.get(i)] = i;
        }
//      System.out.println(Arrays.toString(sortPosition));
        for (int i = 0; i < e.length; i++) {
            e[i].clear();
        }

        int[] p = new int[m + 1];
        for (int i = 0; i < m; i++) {
            int max = m;
            for (int j = 0; j < m; j++) {
                if (j == i)
                    continue;
                int cmp = c[j].compareTo(c[i]);
                if (cmp == 1 && sortPosition[max] < sortPosition[j]) {
                    max = j;
                }
            }
            e[max].add(i);
            p[i] = max;
        }
//      System.out.println(Arrays.toString(p));

        int[] circle = new int[n];
        for (int i = 0; i < n; i++) {
            int cc = m;
            for (int j = 0; j < m; j++) {
                if (c[j].inside(a[i]) && sortPosition[j] > sortPosition[cc]) {
                    cc = j;
                }
            }
            circle[i] = cc;
        }
        

        ds = new DisjointSets(m + 1);

        q = new ArrayList[m + 1];
        for (int i = 0; i < q.length; i++) {
            q[i] = new ArrayList<Integer>();
        }

        answers = new int[m + 1][m + 1];

        int[] x = new int[k], y = new int[k];
        for (int i = 0; i < k; i++) {
            x[i] = nextInt() - 1;
            y[i] = nextInt() - 1;
            x[i] = circle[x[i]];
            y[i] = circle[y[i]];
            q[x[i]].add(y[i]);
            q[y[i]].add(x[i]);
        }
        Arrays.fill(visited, false);
        dfs(m);

        Arrays.fill(visited, false);
        depth = new int[m + 1];
        visited[m] = true;
        dfs1(m);

        for (int i = 0; i < k; i++) {
            int lca = answers[x[i]][y[i]];
            int res = depth[x[i]] + depth[y[i]] - 2 * depth[lca];
            out.println(res);
        }
    }

    int[] depth;

    void dfs1(int u) {
        for (int v : e[u]) {
            if (!visited[v]) {
                visited[v] = true;
                depth[v] = depth[u] + 1;
                dfs1(v);
            }
        }
    }

    void dfs(int v) {
        visited[v] = true;
        for (int i : e[v])
            if (!visited[i]) {
                dfs(i);
                ds.union(v, i, v);
            }
        for (int i : q[v])
            if (visited[i]) {
                answers[i][v] = answers[v][i] = ds.ancestor(i);
            }
    }

    public static void main(String[] args) {
        new Thread(new D()).start();
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
            solve();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            System.exit(239);
        }
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    long nextLong() {
        return Long.parseLong(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }
}