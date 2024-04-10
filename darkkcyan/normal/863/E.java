import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {
  public static void main(String args[]) { new Main().out.flush(); }
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out), false);
  PrintStream err = System.err;
  StringTokenizer st = null;
  String nexttok() {
    try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine()); }
    catch (IOException e) { throw new RuntimeException(e); }
    return st.nextToken();
  }
  int nextint() { return Integer.parseInt(nexttok()); }
  long nextlong() { return Long.parseLong(nexttok()); }
  double nextdouble() { return Double.parseDouble(nexttok()); }
  ///////////////////////////////////////////////////////////////////////////
  
  int maxn = 801010;
  int n;
  int a[], b[], s[] = new int[maxn];
  Integer p[];

  Main() {
    n = nextint();
    a = new int[2 * n];
    for (int i = -1; ++ i < n; ) {
      a[i * 2] = nextint(); a[i * 2 + 1] = nextint();
    }
    p = new Integer[2 * n];
    for (int i = -1; ++ i < 2 * n; ) p[i] = i;
    Arrays.sort(p, (u, v) -> a[u] - a[v]);
    b = new int[2 * n];
    b[p[0]] = 0;
    for (int i = 0; ++i < 2 * n; )
      b[p[i]] = b[p[i - 1]] + Math.min(a[p[i]] - a[p[i - 1]], 2);
    //for (int i = -1; ++ i < n; ) {
      //int l = b[i * 2], r = b[i * 2 + 1];
      //err.println(i + " " + l + " " + r);
    //}
    for (int i = -1; ++ i < n; ) {
      s[b[i * 2]] ++;
      s[b[i * 2 + 1] + 1] --;
    }
    for (int i = 0; ++ i < maxn; ) s[i] += s[i - 1];
    for (int i = -1; ++ i < maxn; ) {
      if (s[i] != 1) s[i] = 0;
      if (i > 0) s[i] += s[i - 1];
    }
    for (int i = -1; ++ i < n; ) {
      int l = b[i * 2], r = b[i * 2 + 1];
      int sum = s[r] - (l > 0 ? s[l - 1] : 0);
      if (sum > 0) continue;
      out.println(i + 1);
      return ;
    }
    out.println(-1);
  }
}