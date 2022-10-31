import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    void solve() {
        int n = in.nextInt();
        char s[] = in.next().toLowerCase().toCharArray();
        boolean[] vis = new boolean[26];
        int remaining = 26;
        for(char c : s) {
            if(!vis[c - 'a']) {
                vis[c - 'a'] = true;
                remaining--;
            }
        }
        out.println(remaining == 0 ? "YES" : "NO");
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