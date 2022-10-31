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


    private void solve() throws IOException {
        int n = nextInt();
        int d = nextInt();
        int h = nextInt();
        if ((2 * h < d) || (h == 1 && d < 2 && n  >2)) {
            out.println("-1");
            return;
        }
        int[] p = new int[n];
        for (int i = 1; i <= h; i++) {
            p[i] = i - 1;
        }
        if (d > h) {
            p[h + 1] = 0;
            for (int i = h + 2; i <= d; i++ ) {
                p[i] = i - 1;
            }
            for (int i = d + 1; i < n; i++) {
                p[i] = 0;
            }
        } else {
            for (int i = h + 1; i < n; i++) {
                p[i] = h - 1;
            }
        }
        for (int i = 1; i < n; i++) {
            out.println((i + 1) + " " + (p[i]+ 1));
        }

    }



    void run() throws IOException {
        // br = new BufferedReader(new FileReader("input.txt"));
        // out = new PrintWriter("output.txt");
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