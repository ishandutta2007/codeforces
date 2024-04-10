import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {

    private void solve() throws IOException {
        int a = nextInt();
        String bb = nextToken();
        BigInteger n = new BigInteger(nextToken(), a);
        if ("R".equals(bb)) {
            out.println(roman(n.intValue()));
        } else {
            out.println(n.toString(Integer.parseInt(bb)).toUpperCase());
        }
    }

    final static String[] names = { "I", "IV", "V", "IX", "X", "XL", "L", "XC",
            "C", "CD", "D", "CM", "M" };
    final static int[] values = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500,
            900, 1000 };

    String roman(int n) {
        String res = "";
        for (int i = values.length - 1; i >= 0; i--) {
            while (n >= values[i]) {
                n -= values[i];
                res += names[i];
            }
        }
        return res;
    }

    public static void main(String[] args) {
        new C().run();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public void run() {
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
                line = "0";
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
}