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
        int[] days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String s = nextLine();
        String[] st = s.split(" ");
        int n = Integer.valueOf(st[0]);

        if (st[2].contains("week")) {
            if (n == 5 || n == 6) {
                out.println(53);
                return;
            } else {
                out.println(52);
                return;
            }
        } else {
            if (n <= 29) {
                out.println(12);
                return;
            }
            if (n == 30) {
                out.println(11);
                return;
            }
            if (n == 31) {
                out.println(7);
                return;
            }
            out.println(0);
            return;
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