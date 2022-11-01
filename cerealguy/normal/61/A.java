import java.io.*;
import java.util.*;

public class A {

    private void solve() throws IOException {
        String s1 = nextToken(), s2 = nextToken();
        char[] res = new char[s1.length()];
        for (int i = 0; i < res.length; i++) {
            res[i] = s1.charAt(i) == s2.charAt(i) ? '0' : '1';
        }
        out.println(new String(res));
    }

    public static void main(String[] args) {
        new A().run();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;
    boolean eof = false;

    public void run() {
        Locale.setDefault(Locale.US);
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            st = new StringTokenizer("");
            solve();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            System.exit(239);
        }
    }

    String nextToken() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                eof = true;
                line = "0";
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
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
}