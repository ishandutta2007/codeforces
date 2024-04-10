import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
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

    long[] maxt;
    int m = 0;
    void add(int v, long x) {
        if (v >= m) return;
        maxt[v] += x;
        add(v * 2, x);
        add(v * 2 + 1, x);


    }
    private void solve() throws IOException {
        int n = nextInt();
         m = (1 << (n + 1));
        int[] a = new int[(1 << (n + 1))];
        for (int i = 2; i < (1 << (n + 1)); i++) {
            a[i] = nextInt();
        }
        a[1] = 0;
        long[] dp = new long[(1 << (n + 1))];
        for (int i = 2; i < (1 << (n + 1)); i++) {
            dp[i] = dp[i / 2] + a[i];
        }
        long max = -1;
        for (int i = (1 << n); i < (1 << (n + 1)); i++) {
            max = Math.max(max, dp[i]);
        }

        maxt = new long[m];
        for (int i = (1 << n); i < (1 << (n + 1)); i++) {
            maxt[i] = dp[i];
        }
        for (int i = (1 << n) - 1; i > 0; i--) {
            maxt[i] = Math.max(maxt[i * 2], maxt[ i  * 2 + 1] );
        }
        long ans = 0;
        for (int i = 2; i < (1 << (n + 1)); i++) {
            if (maxt[i] < max) {
                ans += max - maxt[i];
                add(i, max - maxt[i]);
            }

        }
        out.println(ans);
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
        new B().run();
    }
}