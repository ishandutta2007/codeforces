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
    final long PRES = 100000;
    long intPart(long x) { return x / PRES; }
    long fracPart(long x) { return (x % PRES + PRES) % PRES; }
    long roundUp(long x) {
        if (fracPart(x) == 0) return x;
        if (x < 0) return - roundDown(-x);
        return intPart(x) * PRES + PRES;
    }

    long roundDown(long x) {
        if (fracPart(x) == 0) return x;
        if (x < 0) return - roundUp(-x);
        return intPart(x) * PRES;
    }

    int n = parseInt(next());
    long[] a = new long[n];
    long[] ans = new long[n];

    {
        for (int i = 0; i < n; ++i) {
            a[i] = parseLong(next().replace(".", ""));
        }

        long s = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] = roundUp(a[i]);
            s += ans[i];
        }

        for (int i = 0; i < n && s != 0; ++i) {
            s -= ans[i];
            ans[i] = roundDown(a[i]);
            s += ans[i];
        }
        
        assert(s == 0);
        for (long i: ans)
            out.printf("%d\n", intPart(i));
    }

}