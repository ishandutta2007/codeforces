import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        Arrays.sort(a);
        int l = 1, r = n;
        while(l < r) {
            boolean ok = true;
            int mid = (l + r) / 2;
            for(int i = 0; i < n; ++i)
                if(i / mid > a[i]) {
                    ok = false;
                    break;
                }
            if(ok) r = mid;
            else l = mid + 1;
        }
        out.println(r);
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