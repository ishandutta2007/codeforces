import static java.math.BigInteger.valueOf;

import java.io.*;
import java.util.*;

public class C {

    static final int MOD = 1000000009;

    static int add(int a, int b) {
        a += b;
        if (a >= MOD) {
            a -= MOD;
        }
        return a;
    }

    static int mul(int a, int b) {
        return (int) ((long) a * b % MOD);
    }

    static int inv(int a) {
        return valueOf(a).modInverse(valueOf(MOD)).intValue();
    }

    static void solve() throws IOException {
        int n = nextInt();
        int white = nextInt(), black = nextInt();
        int answer = get(n, white, black);
        out.println(answer);
    }

    private static int get(int n, int white, int black) {
        return mul(choose(white + black - 3, n - 3),
                mul(fact(black), mul(fact(white), white - 1)));
    }

    static int fact(int n) {
        int ret = 1;
        for (int i = 0; i < n; i++) {
            ret = mul(ret, i + 1);
        }
        return ret;
    }

    private static int choose(int n, int k) {
        return mul(fact(n), inv(mul(fact(k), fact(n - k))));
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("c.in");
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