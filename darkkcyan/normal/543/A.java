import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {
  public static void main(String args[]) { new Main(); }
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  StringTokenizer st = null; 
  String nxttok() {
    try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine()); }
    catch (Exception e) { return ""; }
    return st.nextToken();
  }
  int nxtint() { return Integer.parseInt(nxttok()); }

  int n, m, b, mod;
  int a[];
  long dp[][][];

  Main() {
    n = nxtint(); m = nxtint(); b = nxtint(); mod = nxtint();
    a = new int[n + 1];
    for (int i = 0; i++ < n; ) a[i] = nxtint();
    dp = new long[2][n + 1][b + 1];
    for (int i = 1; i <= n; ++i) dp[1][i][0] = 1;

    int s = 0;
    for (int i = 0; i++ < m; s ^= 1) {
      for (int f = 0; f <= n; ++f)
        Arrays.fill(dp[s][f], 0);
      for (int f = 1; f <= n; ++f) {
        long tdp[] = dp[s][f];
        for (int g = 0; g <= b; ++g) {
          //System.err.print(i + " " + f + " " + g + ": ");
          tdp[g] += dp[s][f - 1][g];
          //System.err.print(i + " " + (f - 1) + " " + g + " " + dp[s][f - 1][g] + "; ");
          int t = g - a[f];
          if (t >= 0) {
            tdp[g] += dp[s ^ 1][f][t];
            //System.err.print((i - 1) + " " + f + " " + t + " " + dp[s ^ 1][f][t] + "; ");
          }
          while (tdp[g] >= mod) tdp[g] -= mod;
          //System.err.println(tdp[g]);
        }
      }
    }
    long ans = 0;
    s ^= 1;
    for (int f = 0; f <= b; ++f) {
      ans += dp[s][n][f];
      if (ans >= mod) ans -= mod;
    }

    System.out.println(ans);
  }
}