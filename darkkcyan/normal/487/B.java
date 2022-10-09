// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
public class Main {
  int n, s, l;
  int a[];
  
  class it {
    int val = 0, l, r;
    it cl, cr;
    public it (int l, int r) {
      this.l = l; this.r = r;
      if (l >= r) return ;
      int mid = (l + r) / 2;
      cl = new it(l, mid);
      cr = new it(mid + 1, r);
    }
    
    public void upd(int i, int val) {
      if (l > r || i > r || i < l) return;
      if (l == r) {
        this.val = val;
        return;
      }
      cl.upd(i, val);
      cr.upd(i, val);
      this.val = Math.min(cl.val, cr.val);
    }
    
    public int get(int ql, int qr) {
      if (l > r || l > qr || ql > r) return Integer.MAX_VALUE;
      if (ql <= l && r <= qr) return val;
      return Math.min(cl.get(ql, qr), cr.get(ql, qr));
    }
  }
  
  it ma, mi, dp;
  
  boolean ok(int l, int r) {
    if (r - l + 1 < this.l) return false;
    if (- ma.get(l, r) - mi.get(l, r) > s) return false;
    return true;
  }
  
  Main() {
    n = nxtint();
    s = nxtint();
    l = nxtint();
    a = new int[n];
    for (int i = -1; ++ i < n ; ) a[i] = nxtint();
    ma = new it(0, n - 1);
    mi = new it(0, n - 1);
    dp = new it(0, n - 1);
    for (int i = -1; ++ i < n; ) {
      ma.upd(i, -a[i]);
      mi.upd(i, a[i]);
      int l = 0, r = i - this.l + 1;
      while (l < r) {
        int mid = l + (r - l) / 2;
        if (ok(mid, i)) r = mid;
        else l = mid + 1;
      }
      if (!ok(l, i)) {
        dp.upd(i, Integer.MAX_VALUE);
      } else {
        int t = l > 0 ? dp.get(l - 1, i - this.l) : 0;
        if (t != Integer.MAX_VALUE) ++t;
        // err.println(i + " " + l + " " + t + " " + ma.get(l, i) + " " + mi.get(l, i));
        dp.upd(i, t);
      }
    }
    int ans = dp.get(n - 1, n - 1);
    if (ans == Integer.MAX_VALUE) out.println(-1);
    else out.println(ans);
  }
  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
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