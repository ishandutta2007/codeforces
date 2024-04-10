import java.io.*;
import java.util.*;

public class A {

    static void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[2 * n - 1];
        int negative = 0;
        int sumAbs = 0;
        for (int i = 0; i < 2 * n - 1; i++) {
            a[i] = nextInt();
            if (a[i] < 0) {
                ++negative;
                a[i] = -a[i];
            }
            sumAbs += a[i];
        }
        Arrays.sort(a);
        if (negative % 2 == 0 || n % 2 == 1) {
            out.println(sumAbs);
        } else {
            out.println(sumAbs - 2 * a[0]);
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