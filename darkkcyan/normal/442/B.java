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
  
  int n;
  double a[];
  Main() {
    n = nxtint();
    a = new double[n];
    for (int i = -1; ++ i < n; ) a[i] = nxtdouble();
    Arrays.sort(a);
    if (a[n - 1] == 1) {
      out.println(1);
      return;
    }
    double ans = 0;
    double u = 0, v = 1;
    for (int i = n; i-- > 0; ) {
      u += a[i] / (1 - a[i]);
      v *= (1 - a[i]);
      ans = Math.max(ans, u * v);
      //err.println(i + " " + u * v);
    }
    out.printf("%.9f", ans);
  }
}