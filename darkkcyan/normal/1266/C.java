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
    
    public Main() {
        int r = parseInt(next());
        int c = parseInt(next());
        if (r == 1 && c == 1) {
            out.println("0");
            return ;
        }
        if (c == 1) {
            for (int i = 2; i <= r + 1; ++i) out.println(i);
            return ;
        }

        for (int i = 0; i < r; ++i) {
            for (int f = 0; f < c; ++f) {
                out.print(lcm(i + 1, r + f + 1) + " ");
            }
            out.println();
        }
    }

    long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); } 
    long lcm(long a, long b) { return a / gcd(a, b) * b; }

}