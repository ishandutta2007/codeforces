import java.util.*;
import java.io.*;

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
        String s = nextLine();
        int m = nextInt();
        int[] l = new int[m];
        int[] r = new int[m];
        int[] k = new int[m];
        for (int i = 0; i < m; i++) {
            l[i] = nextInt() - 1;
            r[i] = nextInt() - 1;
            k[i] = nextInt();
        }
        char[] ans = new char[s.length()];
        for (int i = 0; i < s.length(); i++) {
            int cur = i;
            for (int j = 0; j < m; j++) {
                if (cur >= l[j] && cur <= r[j]) {
                    cur = (cur - l[j] + k[j]) % (r[j] - l[j] + 1) + l[j];
                }
            }
            ans[cur] = s.charAt(i);
        }
        String an = new String(ans);
        out.println(an);
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