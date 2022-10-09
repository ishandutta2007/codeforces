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
  int n, m, k;
  BitSet a[], b[];
  
  int findcost(BitSet x, BitSet a[], int m) {
    int ans = 0;
    for (int i = -1; ++ i < a.length; ) {
      int tc = 200;
      for (int f = 0; f <= 1; ++f) {
        BitSet t = (BitSet)a[i].clone();
        t.xor(x);
        tc = Math.min(tc, t.cardinality());
        a[i].flip(0, m);
      }
      ans += tc;
    }
    return ans;
  }
  
  Main() {
    n = nxtint();
    m = nxtint();
    k = nxtint();
    a = new BitSet[n];
    b = new BitSet[m];
    for (int i = -1; ++ i < m; ) b[i] = new BitSet(n);
    for (int i = -1; ++ i < n; ) {
      a[i] = new BitSet(m);
      for (int f = -1; ++f < m; ) {
        boolean val = nxtint() > 0;
        a[i].set(f, val);
        b[f].set(i, val);
      }
    }
    int ans = k + 1;
    if (n <= k) {
      for (long i = 0; i < (1L << n); ++i) {
        ans = Math.min(ans, findcost(BitSet.valueOf(new long[]{i}), b, n));
      }
    } else {
      for (int i = -1; ++ i < n; ) {
        ans = Math.min(ans, findcost((BitSet)a[i].clone(), a, m));
      }
    }
    if (ans == k + 1) out.println(-1);
    else out.println(ans);
  }
}