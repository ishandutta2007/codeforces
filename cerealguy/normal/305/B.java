import static java.math.BigInteger.ONE;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class B {

    static void solve() throws IOException {
        BigInteger p = new BigInteger(nextToken());
        BigInteger q = new BigInteger(nextToken());

        int n = nextInt();
        BigInteger[] a = new BigInteger[n];
        for (int i = 0; i < n; i++) {
            a[i] = new BigInteger(nextToken());
        }

        BigInteger pp = a[n - 1];
        BigInteger qq = ONE;
        for (int i = n - 2; i >= 0; --i) {
            BigInteger ppp = a[i].multiply(pp).add(qq);
            BigInteger qqq = pp;
            pp = ppp;
            qq = qqq;
        }
        {
            BigInteger gcd = p.gcd(q);
            p = p.divide(gcd);
            q = q.divide(gcd);
        }
        {
            BigInteger gcd = pp.gcd(qq);
            pp = pp.divide(gcd);
            qq = qq.divide(gcd);
        }
        if (pp.equals(p) && qq.equals(q)) {
            out.println("YES");
        } else {
            out.println("NO");
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("b.in");
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