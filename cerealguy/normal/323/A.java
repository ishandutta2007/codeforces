import java.io.*;
import java.util.*;

public class A {

    static void solve() throws IOException {
        int k = nextInt();
        if ((k&1) == 1) {
            out.println(-1);
            return;
        }
        char[] w = new char[k];
        char[] b = new char[k];
        for (int i = 0; i < k; i++) {
            w[i] = "bw".charAt((i>>1)&1);
            b[i] = "wb".charAt((i>>1)&1);
        }
//      fill(w, 'w');
//      fill(b, 'b');
        char[][] bw = new char[][] { b, w };
        for (int layer = 0; layer < k; layer++) {
            for (int i = 0; i < k; i++) {
                out.println(bw[(layer ^ (i>>1)) & 1]);
            }
            out.println();
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("a.in");
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