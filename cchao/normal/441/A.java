import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    void solve() {
        int n = in.nextInt();
        int v = in.nextInt();
        ArrayList<Integer> a = new ArrayList<Integer>();
        for(int i = 0; i < n; ++i) {
            int s = in.nextInt();
            int min = v;
            for(int j = 0; j < s; ++j) {
                min = Math.min(min, in.nextInt());
            }
            if(min < v) 
                a.add(i + 1);
        }
        out.println(a.size());
        for(Integer x: a)
            out.print("" + x + " ");
        out.println("");
    }
    class InputReader {
        StringTokenizer tok; BufferedReader buf;
        InputReader(String file) {
            try {
                buf = new BufferedReader(new FileReader(file));
            } catch(FileNotFoundException e) { e.printStackTrace(); }
        }
        InputReader() {
            buf = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while(tok == null || !tok.hasMoreElements()) {
                try {
                    String s = buf.readLine();
                    if(s == null) {return null; }
                    tok = new StringTokenizer(s);
                } catch(IOException e) {return null; }
            }
            return tok.nextToken();
        }
        boolean hasNext() {
            while(tok == null || !tok.hasMoreElements()) {
                try {
                    String s = buf.readLine();
                    if(s == null) {return false; }
                    tok = new StringTokenizer(s);
                } catch(IOException e) { return false; }
            }
            return true;
        }
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
        BigInteger nextBigInteger() { return (new BigInteger(next())); }
    }
    InputReader in; PrintWriter out;
    void runFile(String task) {
        try {
            in = new InputReader(task + ".in");
            out = new PrintWriter(task + ".out");
        } catch(IOException e) {
            e.printStackTrace();
        }
        solve(); out.close();
    }
    void run() {
        in = new InputReader();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }
    public static void main(String[] args) { new Main().run(); }
}