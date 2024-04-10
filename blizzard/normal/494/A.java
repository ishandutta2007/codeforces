import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
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
        String s = nextLine();
        int n = s.length();
        int[] bal = new int[n];
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            bal[i] = (i == 0) ? 0 : bal[i-1];
            if (s.charAt(i) == '(') {
                bal[i]++;
            } else {
                bal[i]--;
            }
            if (bal[i] < 0) {
                out.println(-1);
                return;
            }
            if (s.charAt(i) == '#') {
                ans[i] = 1;
            }
        }
        int balance = bal[n-1];
        int curmin = 1000000;
        for (int i = n - 1; i >= 0; i--) {
            if (bal[i] < curmin) {
                curmin = bal[i];
            }
            if (s.charAt(i) == '#') {
                int x = Math.min(curmin, balance);
                curmin -= x;
                balance -= x;
                ans[i] += x;
            }
        }
        if (balance != 0) {
            out.println(-1);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] != 0) {
                out.println(ans[i]);
            }
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
        new A().run();
    }
}