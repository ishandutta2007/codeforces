import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    void solve() {
        char[][] board = new char[8][];
        for(int i = 0; i < 8; ++i)
            board[i] = in.next().toCharArray();
        int sa = 0, sb = 0;
        String chessA = "QRBNPK", chessB = "qrbnpk";
        int[] weight = {9, 5, 3, 3, 1, 0};
        for(char[] row : board) for(char c : row) {
            if(chessA.indexOf(c) != -1)
                sa += weight[chessA.indexOf(c)];
            else if(chessB.indexOf(c) != -1)
                sb += weight[chessB.indexOf(c)];
        }
        if(sa == sb) out.println("Draw");
        else out.println(sa > sb ? "White" : "Black");
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