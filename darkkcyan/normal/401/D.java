import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String args[]) throws IOException { new Main().bw.close(); }
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  StringTokenizer st = null;
  String nxttok() {
    try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine()); }
    catch (Exception e) { return ""; }
    return st.nextToken();
  }
  int nxtint() { return Integer.parseInt(nxttok()); }
  long nxtlong() { return Long.parseLong(nxttok()); }

  long n; int m;
  int[] s = new int[10];
  int getKey(int[] c) {
    int ans = 0;
    for (int i = -1; ++ i < 10; ) {
      ans = (ans * (s[i] + 1) + c[i]);
    }
    return ans;
  }

  int maxn = 19;
  int maxm = 101;
  long[][] dp = new long[1 << maxn][maxm];
  int ts[] = new int[10];
  long cal(int mod) {
    int k = getKey(ts);
    if (k == 0) return mod == 0 ? 1 : 0;
    if (dp[k][mod] != -1) return dp[k][mod];
    long ans = 0;
    for (int i = -1; ++ i < 10; ) {
      if (ts[i] == 0) continue;
      ts[i]--;
      ans += cal((mod * 10 + i) % m);
      ts[i]++;
    }
    return dp[k][mod] = ans;
  }

  Main() throws IOException {
    n = nxtlong(); m = nxtint();
    while (n > 0) {
      s[(int)(n % 10)]++;
      n /= 10;
    }
    for (int i = -1; ++i < 10;) {
      ts[i] = s[i];
    }
    int k = getKey(s);
    for (int i = -1; ++i < k; )
      for (int f = -1; ++f < m; )
        dp[i][f] = -1;
    long ans = 0;
    for (int i = 0; ++i < 10; ) {
      if (ts[i] == 0) continue;
      --ts[i];
      ans += cal(i % m);
      ++ts[i];
    }
    bw.write("" + ans);
  }
}