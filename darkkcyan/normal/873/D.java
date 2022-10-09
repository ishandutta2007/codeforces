// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
public class Main {
  class pair {
    int xx, yy;
    pair(int x, int y) {xx = x; yy = y;}
  }
  int n, k;
  ArrayList<pair> pl = new ArrayList<>();
  
  void process(int l, int r) {
    if (l == r - 1) pl.add(new pair(l, r));
    if (l >= r - 1) return;
    int mid = (l + r) / 2;
    
    if (k == 0) {
      pl.add(new pair(l, r));
    } else {
      k -= 2;
      process(l, mid);
      process(mid, r);
    }
  }
  
  int ans[];
  
  Main() {
    n = nxtint(); k = nxtint();
    if (k % 2 == 0 || k > 2 * n - 1) {
      out.println(-1);
      return ;
    }
    --k;
    process(0, n);
    ans = new int[n];
    int cur = n;
    for (pair t: pl) {
      for (int f = t.yy - 1; f >= t.xx; --f) {
        ans[f] = cur --;
      }
    }
    for (int i = -1; ++ i < n; ) out.print(ans[i] + " ");
  }
  
  //////////////////////////////////////////////////////////////////////////////////////
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
  
}