// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
public class Main {
  class pair {
    int xx, yy;
    pair(int x, int y) { xx = x; yy = y; }
    long tolong() { 
      return xx << 31 | yy;
    }
  }
  
  int maxn = 201010;
  long rem = (long)1e9 + 7;
  
  long mpow(long b, long m) {
    long ans = 1;
    for (; m > 0; m >>= 1, b = (b * b) % rem)
      if ((m & 1) == 1) ans = (ans * b) % rem;
    return ans;
  }
  long fac[] = new long[maxn], rfac[] = new long[maxn];
  
  void genfac() {
    fac[0] = 1;
    for (int i = 0; ++i < maxn; ) fac[i] = (fac[i - 1] * i) % rem;
    for (int i = -1; ++ i < maxn; ) rfac[i] = mpow(fac[i], rem - 2);
  }
  
  long comb(int k, int n) {
    return fac[n] * rfac[k] % rem * rfac[n - k] % rem;
  }
  
  int n, m, k;
  pair a[];
  long way[];
  
  Main() {
    genfac();
    n = nxtint(); m = nxtint(); k = nxtint();
    a = new pair[k + 1];
    for (int i = -1; ++ i < k;) {
      a[i] = new pair(nxtint() - 1, nxtint() - 1);
    }
    a[k] = new pair(n - 1, m - 1);
    Arrays.sort(a, (u, v) -> {
      pair a = (pair) u, b = (pair) v;
      if (a.xx == b.xx) return a.yy - b.yy;
      return a.xx - b.xx;
    });
    way = new long[k + 1];
    for (int i = -1; ++i <= k; ) {
      way[i] = comb(a[i].xx, a[i].xx + a[i].yy);
    }
    for (int i = -1; ++ i < k; ) {
      for (int f = i; ++f <= k; ) {
        if (a[f].xx < a[i].xx || a[f].yy < a[i].yy) continue;
        way[f] -= way[i] * comb(a[f].xx - a[i].xx, a[f].xx + a[f].yy - a[i].xx - a[i].yy) % rem;
        if (way[f] < 0) way[f] += rem;
      }
    }
    out.println(way[k]);
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