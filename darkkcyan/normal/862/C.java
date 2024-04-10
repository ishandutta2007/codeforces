import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {
  public static void main(String args[]) { new Main().out.flush(); }
  PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out), false);
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  StringTokenizer st = null;
  String nxttok() {
    try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine()); }
    catch (IOException e) { throw new RuntimeException(e); }
    return st.nextToken();
  }
  int nxtint() { return Integer.parseInt(nxttok()); }
  long nxtlong() { return Long.parseLong(nxttok()); }
  double nxtdouble() { return Double.parseDouble(nxttok()); }

  /////////////////////////////////////////////////////////////

  int n, m;
  Main() {
    n = nxtint(); m = nxtint();
    int u = (n - 1) % 4;
    int v = (n - 1) / 4;
    if (n == 1) {
      out.println("YES");
      out.print(m);
      return ;
    }
    if (m == 0 && n == 2) {
      out.println("NO");
      return ;
    }
    out.println("YES");
    if (m == 0 && u <= 1) {
      u += 4;
      --v;
    }
    int t = m;
    if (Integer.bitCount(m) < 5) t = ~m;
    for (int i = 0; i < u; ++i) {
      int x = t & -t;
      out.print(x + " ");
      m ^= x;
      t ^= x;
    }
    out.print(m + " ");
    for (int i = 900000, f = 0; f < v; i += 4, ++f) {
      out.print(i + " " + (i + 1) + " " + (i + 2) + " " + (i + 3) + " ");
    }
  }
}