import java.io.*;
import java.util.*;

public class D {

    int n;

    int start;
    int[][] matrix;
    int[] path;
    int[] maxEdge;

    int[] stack;
    int stackptr;
    int[] answer;

    int[] lastEdge;
    int[] deg;

    int[][] m;

    boolean[] alreadyHave;
    int sets = 0;
    int[] p;

    int get(int u) {
        if (p[u] != u)
            p[u] = get(p[u]);
        return p[u];
    }

    void union(int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v)
            return;
        sets--;
        p[u] = v;
    }

    boolean findPath(int start, int startV) {
        if (sets != 1)
            return false;
        Arrays.fill(deg, 0);
        for (int i = 0; i < n; i++) {
            Arrays.fill(m[i], 0);
        }
        Arrays.fill(lastEdge, 0);
        for (int i = start; i < path.length - 1; i++) {
            m[path[i]][path[i + 1]]++;
            m[path[i + 1]][path[i]]++;
            deg[path[i]]++;
            deg[path[i + 1]]++;
        }
        deg[startV]--;
        deg[path[start]]--;
        m[startV][path[start]]--;
        m[path[start]][startV]--;
        for (int i = 0; i < n; i++) {
            if (deg[i] % 2 == 1) {
                if ((i != startV && i != this.start) || startV == this.start) {
                    return false;
                }
            } else if ((i == startV || i == this.start) && startV != this.start)
                return false;
        }
        stackptr = 0;
        stack[stackptr] = startV;
        int answercnt = 0;
        while (stackptr >= 0) {
            int u = stack[stackptr];
            if (deg[u] == 0) {
                answer[answercnt++] = u;
                --stackptr;
            } else {
                for (; lastEdge[u] < n; lastEdge[u]++) {
                    if (m[u][lastEdge[u]] > 0) {
                        deg[u]--;
                        deg[lastEdge[u]]--;
                        m[u][lastEdge[u]]--;
                        m[lastEdge[u]][u]--;
                        stack[++stackptr] = lastEdge[u];
                        break;
                    }
                }
            }
        }
        int totalcnt = path.length - start - 1;
        if (totalcnt != answercnt)
            return false;
        for (int i = 0; 2 * i < answercnt; i++) {
            int tmp = answer[i];
            answer[i] = answer[answercnt - 1 - i];
            answer[answercnt - 1 - i] = tmp;
        }
        System.arraycopy(answer, 0, path, start + 1, answercnt);
        return true;
    }

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] path = new int[m + 1];
        for (int i = 0; i < path.length; i++) {
            path[i] = nextInt() - 1;
        }
        int[] res = solve(n, path);
        if (res.length == 0) {
            out.println("No solution");
        } else {
            for (int i : path) {
                out.print((i + 1) + " ");
            }
            out.println();
        }
    }

    int[] solve(int n, int[] path) {
        this.n = n;
        matrix = new int[n][n];
        start = path[0];
        this.path = path;
        for (int i = 1; i < path.length-1; i++) {
            int u = path[i];
            int v = path[i + 1];
            matrix[u][v]++;
            matrix[v][u]++;
        }
        maxEdge = new int[n];
        Arrays.fill(maxEdge, -1);
        this.m = new int[n][n];
        lastEdge = new int[n];
        deg = new int[n];
        alreadyHave = new boolean[n];
        stack = new int[n * n + 1000];
        answer = new int[n * n + 1000];
        int[][] curmatrix = new int[n][n];
        boolean found = false;
        alreadyHave[start] = true;
        sets = 1;
        p = new int[n];
        p[start] = start;
        loop: for (int i = path.length - 2; i >= 0; i--) {
            int u = path[i];
            if (!alreadyHave[u]) {
                sets++;
                p[u] = u;
            }
            alreadyHave[u] = true;
            union(u, path[i + 1]);
            if (maxEdge[u] > path[i + 1]) {
                for (int j = path[i + 1] + 1; j < n; j++) {
                    if (curmatrix[u][j] == 1) {
                        if (findPath(i, j)) {
                            found = true;
                            break loop;
                        }
                    }
                }
            }
            maxEdge[u] = Math.max(maxEdge[u], path[i + 1]);
            maxEdge[path[i + 1]] = Math.max(maxEdge[path[i + 1]], u);
            curmatrix[u][path[i + 1]]++;
            curmatrix[path[i + 1]][u]++;
        }
        if (found)
            return path;
        else
            return new int[0];
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