import java.io.*;
import java.lang.*;
import java.util.*;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;
import static java.lang.System.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class Main {

    Main() throws IOException {
        String a = nextLine();
        String b = nextLine();
        long ans = 0;
        int s = 0;
        for (int i = 0; i < b.length() - a.length(); ++i) {
            s += b.charAt(i) == '1' ? 1 : 0;
        }

        for (int i = 0; i < a.length(); ++i) {
            s += b.charAt(i + b.length() - a.length()) == '1' ? 1 : 0;
            ans += a.charAt(i) == '1' ? b.length() - a.length() + 1 - s : s;
            s -= b.charAt(i) == '1' ? 1 : 0;
        }
        out.println(ans);
    }


    //////////////////////////////
    PrintWriter out = new PrintWriter(System.out, false);
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer stok = null;
    String nextLine() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            stok = new StringTokenizer(in.readLine());
        }
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
}