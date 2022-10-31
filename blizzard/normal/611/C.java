import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
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

    int[][] h, v;
    int geth(int x, int y) {
        if (x < 0 || y < 0) {
            return 0;
        }
       // System.err.println(x  + " " + y + " h " + h[x][y] );
        return h[x][y];
    }
    int getv(int x, int y) {
        if (x < 0 || y < 0) {
            return 0;
        }
       // System.err.println(x  + " " + y + " v " + v[x][y] );
        return v[x][y];
    }
    int get(int x, int y) {
        if (x < 0 || y < 0) {
            return 0;
        }
       //System.err.println(x  + " " + y + " " + v[x][y] + " " + h[x][y] );
        return h[x][y] + v[x][y];
    }
    private void solve() throws IOException {
        int  n = nextInt();
        int  m = nextInt();
        char[][] c = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = nextLine();
            c[i] = s.toCharArray();
        }
        h = new int[n][m];
        v = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != 0) {
                    h[i][j] += h[i-1][j];
                    v[i][j] += v[i-1][j];
                }
                if (j != 0) {
                    h[i][j] += h[i][j-1];
                    v[i][j] += v[i][j-1];
                }
                if (i != 0 && j != 0){
                    h[i][j] -= h[i-1][j-1];
                    v[i][j] -= v[i-1][j-1];
                }
                if (j != 0 && c[i][j] == '.' && c[i][j - 1] == '.') {
                    h[i][j]++;
                }
                if (i != 0 && c[i][j] == '.' && c[i-1][j] == '.') {
                    v[i][j]++;
                }
            }
        }

        int q = nextInt();
        while (q-- > 0) {
            int x1 = nextInt() - 1;
            int y1 = nextInt() - 1;
            int x2 = nextInt() - 1;
            int y2 = nextInt() - 1;
            out.println(get(x2, y2) - getv(x2, y1 - 1) - geth(x2, y1) - getv(x1, y2) - geth(x1 - 1, y2) + getv(x1, y1 - 1) + geth(x1 - 1, y1));
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
        new C().run();
    }
}