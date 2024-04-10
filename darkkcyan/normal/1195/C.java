/**
 * @Author Tran Quang Loc (darkkcyan)
 * BEFORE READING CODE:
 * Java is really lengthy (at least for Java 8). So I used the advantage of initialization block.
 * Basically, every initialization block run before the constructor and they run in the declaration order.
 * And as I understand, every properties (or global variables) is also counted as initialization block.
 */
import java.io.*;
import java.lang.*;
import java.util.*;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.*;
import static java.lang.System.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class Main {
    PrintWriter out = new PrintWriter(System.out, false);
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer stok = null;
    String next() {
        while (stok == null || !stok.hasMoreTokens())
            try {
                stok = new StringTokenizer(in.readLine());
            } catch (IOException e) { throw new RuntimeException(e); }
        return stok.nextToken();
    }

    public static void main(String args[]) throws IOException {
        if (args.length > 0) {
            setIn(new FileInputStream(args[0] + ".inp"));
            setOut(new PrintStream(args[0] + ".out"));
        }
        Main solver = new Main();
        solver.out.flush();  //  could be replace with a method, but nah, this is just competitive programming :p
    }

    ///// Actual solution below /////

    int n = parseInt(next());
    long[][] a = new long[2][n];
    long[][] dp = new long[2][n + 1];
    {
        for (int row = 0; row < 2; ++row) 
            for (int i = 0; i < n; ++i)
                a[row][i] = parseLong(next());
        dp[0][0] = dp[1][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int row = 0; row < 2; ++row) {
                dp[row][i + 1] = max(dp[row][i], dp[row ^ 1][i] + a[row][i]);
            }
        }
        out.println(max(dp[0][n], dp[1][n]));
    }
}