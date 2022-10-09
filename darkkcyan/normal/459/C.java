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
  
  int n, d;
  long k;
  boolean hasans() {
    long t = 1;
    for (int i = 1; i <= d; ++i) {
      t *= k;
      if (n <= t) return true;
    }
    return false;
  }
  
  
  void add1(int[] a) {
    int i;
    for (i = 0; i < a.length; ++i) {
      if (a[i] < k) break;
    }
    assert(i < a.length);
    ++a[i];
    for (; i-- > 0; ) {
      a[i] = 1;
    }
  }
  
  int ans[][];

  Main() {
    n = nxtint(); k = nxtlong(); d = nxtint();
    if (!hasans()) {
      out.println(-1);
      return;
    }
    ans = new int[n][d];
    Arrays.fill(ans[0], 1);
    for (int i = 0; ++ i < n; ) {
      System.arraycopy(ans[i - 1], 0, ans[i], 0, d);
      add1(ans[i]);
    }
    for (int i = -1; ++ i < d; out.println()) for (int f = -1; ++f < n; ) out.print(ans[f][i] + " ");
  }
}