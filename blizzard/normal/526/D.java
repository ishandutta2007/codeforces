import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
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

    int[] z(String s) {
        int[] z = new int[s.length()];
        z[0] = s.length();
        int l = 0, r = 0;
        int j;
        for (int i = 1; i < s.length(); i++)
            if (i > r) {
                for (j = 0; ((j + i) < s.length()) && (s.charAt(i + j) == s.charAt(j)); j++) ;
                z[i] = j;
                l = i;
                r = i + j - 1;
            } else if (z[i - l] < r - i + 1)
                z[i] = z[i - l];
            else {
                for (j = 1; ((j + r) < s.length()) && (s.charAt(r + j) == s.charAt(r - i + j)); j++) ;
                z[i] = r - i + j;
                l = i;
                r = r + j - 1;
            }
        return z;
    }

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        String s = nextLine();
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                out.print(1);
            }
            out.println();
            return;
        }
        int[] z = z(s);
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 1; i <= n; i++) {
            if (i * k > n) {
                break;
            }
            if (i + z[i] >= k * i) {
                a[k * i - 1]++;
                b[ Math.min((k + 1) * i - 1, i + z[i] - 1)]++;
            }
        }

        int x = 0;
        boolean[] f = new boolean[n];
        for (int i = 0; i < n; i++) {
            x += a[i];
            f[i] = (x > 0);
            x -= b[i];
        }
        for (boolean c : f) {
            if (c) {
                out.print(1);
            } else {
                out.print(0);
            }
        }
        out.println();
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