import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {
    BufferedReader br;
    PrintWriter out;
    StringTokenizer stok;

    String nextToken() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = br.readLine();
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
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

    char nextChar() throws IOException {
        return (char) (br.read());
    }

    String nextLine() throws IOException {
        return br.readLine();
    }
    class Point implements Comparable<Point> {
        int x, y;
        int i;

        Point(int x, int y, int i) {
            this.x = x;
            this.y = y;
            this.i = i;
        }

        Point(int x, int y) {
            this.x = x;
            this.y = y;

        }


        @Override
        public int compareTo(Point o) {
            return Double.compare(Math.atan2(y, x), Math.atan2(o.y, o.x));
        }
    }

    int cross(Point a, Point b) {
        return (a.x * b.y - a.y * b.x);
    }

    int dot(Point a, Point b) {
        return (a.x * b.x + a.y * b.y);
    }
    boolean in(int x, int y, int n, int m) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }
    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, 1, 0, -1};
    int[][] color;
    int n, m;char[][] c;
    int cur;
    int[][] p;
    void dfs(int i, int j, int col) {
        color[i][j] = col;
        cur += p[i][j];
        for (int v = 0; v < 4; v++) {
            if (in(i + dx[v], j + dy[v], n, m) && (c[i + dx[v]][j + dy[v]] == '.') && color[i + dx[v]][j + dy[v]] == 0) {
                dfs(i + dx[v], j + dy[v], col);
            }
        }

    }

    private void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        int k = nextInt();

        c = new char[n][m];
        for (int i = 0; i < n; i++) {
                c[i] = nextLine().toCharArray();
        }
         p = new int[n][m];
        color = new int[n][m];
        for (int i = 0; i  <n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '.') {
                    for (int v = 0; v  <4; v++) {
                        if (in(i + dx[v], j + dy[v], n, m) && (c[i + dx[v]][j + dy[v]] == '*')) {
                            p[i][j]++;
                        }
                    }
                }
            }
        }
        int col = 0;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        ans.add(0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j  <m; j++) {
                if (color[i][j] == 0) {
                    cur = 0;
                    dfs(i, j, ++col);
                    ans.add(cur);
                }
            }
        }
        for (int i = 0; i < k; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            out.println(ans.get(color[x][y]));
        }
    }



    void run() throws IOException {
        //br = new BufferedReader(new FileReader("input.txt"));
        //out = new PrintWriter("output.txt");
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        br.close();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        // Locale.setDefault(Locale.US);
        new D().run();
    }
}