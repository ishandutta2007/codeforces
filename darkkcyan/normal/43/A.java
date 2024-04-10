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
import java.util.stream.*;
import java.util.function.*;
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
    {
        int n = parseInt(next());
        Map<String, Integer> cnt = new HashMap<>();
        for (int i = n; i-->0; ) {
            String name = next();
            cnt.put(name, cnt.getOrDefault(name, 0) + 1);
        }
        cnt.entrySet().stream().max(Map.Entry.comparingByValue()).ifPresent(x -> out.println(x.getKey()));
    }

}