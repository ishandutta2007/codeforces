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

  static int maxn = 101010;

  int n, m, q;
  int a[] = new int[maxn], b[] = new int[maxn];

  long getsign(int index) { return index % 2 == 1 ? -1 : 1; }

  Long s[];
  long findans(long as) {
    int pos = Arrays.binarySearch(s, as);
    if (pos < 0) pos = -pos;
    long ans = Long.MAX_VALUE;
    for (int i = Math.max(0, pos - 2); i < Math.min(pos + 3, s.length); ++i) {
      ans = Math.min(ans, Math.abs(as - s[i]));
    }
    return ans;
  }

  Main() {
    n = nxtint(); m = nxtint(); q = nxtint();
    for (int i = -1; ++i < n; ) a[i] = nxtint();
    for (int i = -1; ++i < m; ) b[i] = nxtint();

    long bs = 0;
    for (int i = -1; ++ i < n - 1; ) bs += b[i] * getsign(i);
    s = new Long[m - n + 1];
    for (int i = n - 2, f = 0; ++i < m; ++f) {
      bs += b[i] * getsign(i);
      s[f] = bs * getsign(f);
      bs -= b[f] * getsign(f);
      //System.err.println(f + " " + s[f]);
    }
    Arrays.sort(s);

    long as = 0;
    for (int i = -1; ++i < n; ) as += a[i] * getsign(i);
    out.println(findans(as));
    while (q-- > 0) {
      int u = nxtint() - 1, v = nxtint() - 1, x = nxtint();
      if ((u - v) % 2 == 0) {
        as += x * getsign(u);
      }
      out.println(findans(as));
    }
  }
}