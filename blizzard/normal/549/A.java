/**
 * Created by  on 06.06.2015.
 */
import java.util.*;
        import java.io.*;

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
        String[] s = new String[100];
        int n = nextInt();
        int m = nextInt();
        char[][] c = new char[n][m];
        for (int i = 0; i < n; i++) {
            s[i] = nextLine();
            c[i] = s[i].toCharArray();
        }
        long ans = 0;
        for (int i = 0 ; i< n- 1; i++) {
            for (int j  = 0; j < m-1; j++) {
                HashSet<Character> set = new HashSet<Character>();
                set.add(c[i][j]);
                set.add(c[i][j+1]);
                set.add(c[i+1][j]);
                set.add(c[i+1][j+1]);
                if (set.contains('f') && set.contains('a') && set.contains('c') &&set.contains('e') ) {
                    ans++;
                }
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
        new A().run();
    }
}