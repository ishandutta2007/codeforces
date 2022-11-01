import java.io.*;
import java.util.*;

public class B {

    static boolean isGood(boolean[][] g) {
        int n = g.length;
        int[][] d = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j]) {
                    d[i][j] = 1;
                }
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (d[i][k] == 0 || d[k][j] == 0) {
                        continue;
                    }
                    if (d[i][j] == 0 || d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && (d[i][j] == 0 || d[i][j] > 2)) {
                    return false;
                }
            }
        }
        return true;
    }

    static void stupid(int n) {
        boolean[][] g = new boolean[n][n];
        for (int mask = 0; mask < 1 << (n * (n - 1) / 2); mask++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    g[i][j] = (mask & (1 << cnt)) != 0;
                    g[j][i] = !g[i][j];
                    cnt++;
                }
            }
            if (isGood(g)) {
                System.err.println(Arrays.deepToString(g).replace('[', '{')
                        .replace(']', '}'));
                break;
            }
        }
    }

    static final boolean[][] SIX = { { false, true, true, true, false, false },
            { false, false, true, false, true, false },
            { false, false, false, true, true, true },
            { false, true, false, false, true, true },
            { true, false, false, false, false, true },
            { true, true, false, false, false, false } };

    static final boolean[][] THREE = { { false, true, false },
            { false, false, true }, { true, false, false } };

    static void solve() throws IOException {
        // stupid(3);
        int n = nextInt();
        if (n == 4) {
            out.println(-1);
            return;
        }

        boolean[][] g = new boolean[n][n];

        int start;
        if ((n & 1) == 1) {
            g[0][1] = g[1][2] = g[2][0] = true;
            start = 3;
        } else {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    g[i][j] = SIX[i][j];
                }
            }
            start = 6;
        }
        while (start < n) {
            for (int i = 0; i < start; i++) {
                g[i][start] = true;
            }
            for (int i = 0; i < start; i++) {
                g[start + 1][i] = true;
            }
            g[start][start + 1] = true;
            start += 2;
        }

        char[] buf = new char[2 * n - 1];
        Arrays.fill(buf, ' ');

        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                buf[2 * v] = g[u][v] ? '1' : '0';
            }
            out.println(buf);
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("b.in");
        if (file.exists() && file.canRead()) {
            input = new FileInputStream(file);
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solve();
        out.close();
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }
}