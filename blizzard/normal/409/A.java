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
        char[] c1 = nextLine().toCharArray();
        char[] c2 = nextLine().toCharArray();
        int d = 0;
        for (int i = 0; i < c1.length ; i+=2) {
            if (c2[i] == '8' && c1[i] == '[') d++;
            if (c2[i] == '[' && c1[i] == '(') d++;
            if (c2[i] == '(' && c1[i] == '8') d++;
            if (c1[i] == '8' && c2[i] == '[') d--;
            if (c1[i] == '[' && c2[i] == '(') d--;
            if (c1[i] == '(' && c2[i] == '8') d--;

        }
        if (d > 0) {
            out.println("TEAM 2 WINS");
        } else {
            if (d < 0) {
                out.println("TEAM 1 WINS");
            } else {
                out.println("TIE");
            }
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
        new A().run();
    }
}