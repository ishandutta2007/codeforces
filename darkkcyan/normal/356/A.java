// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
public class Main {
  public static void main(String args[]) { new Main().out.flush(); }
  PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out), false);
  PrintStream err = System.err;
  
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  StringTokenizer st = null;
  String nxttok() {
    try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());}
    catch (IOException e) { throw new RuntimeException(e); }
    return st.nextToken();
  }
  int nxtint() { return Integer.parseInt(nxttok()); }
  long nxtlong() { return Long.parseLong(nxttok()); }
  double nxtdouble() { return Double.parseDouble(nxttok()); }
  
  /////////////////////////////////////////////////////////////////////////////
  
  int n, m;
  int next[], ans[];
  
  int findnext(int u) {
    if (u >= n) return u;
    if (next[u] == u) return u;
    return next[u] = findnext(next[u]);
  }
  
  void joinall(int l, int r, int tans) {
    int t = l;
    while (t <= r && (t = findnext(t)) <= r) {
      next[t] = r + 1;
      ans[t] = tans;
      ++t;
    }
  }
  
  Main() {
    n = nxtint();
    m = nxtint();
    next = new int[n];
    for (int i = -1; ++ i < n; ) next[i] = i;
    ans = new int[n];
    while (m-- > 0) {
      int l = nxtint() - 1, r = nxtint() - 1, x = nxtint() - 1;
      joinall(l, x - 1, x + 1);
      joinall(x + 1, r, x + 1);
    }
    for (int i = -1; ++i < n; ) out.print(ans[i] + " ");
  }
}