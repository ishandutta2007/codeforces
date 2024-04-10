import java.io.*;
import java.util.*;

public class C {

    static void solve() throws IOException {


        for (int i = 0; i < 9; i++) {
            out.println(i + "??<>" + ((i + 1) % 10));
        }
        out.println("9??>>??0");
        
        out.println("??<>1");


        for (int i = 0; i < 10; i++) {
            out.println("?" + i + ">>" + i + "?");
        }
        
        out.println("?>>??");

        for (int i = 0; i < 10; i++) {
            out.println(i + ">>" + i + "?");
        }
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