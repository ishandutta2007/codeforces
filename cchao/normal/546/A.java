import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    void solve() {
        int k = in.nextInt();
        int n = in.nextInt();
        int w = in.nextInt();
        int t = w * (w + 1) / 2 * k;
        out.println(Math.max(0, t - n));
    }
    Scanner in; PrintWriter out;
    void runFile(String task) {
        try {
            in = new Scanner(new File(task + ".in"));
            out = new PrintWriter(task + ".out");
        } catch(IOException e) {
            e.printStackTrace();
        }
        solve(); out.close();
    }
    void run() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }
    public static void main(String[] args) {
        new Main().run();
    }
}