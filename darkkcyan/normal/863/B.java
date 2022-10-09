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

  Main() {
    int n = nextint();
    int a[] = new int[n * 2];
    for (int i = -1; ++ i < n * 2; ) a[i] = nextint();
    Arrays.sort(a);
    long ans = Long.MAX_VALUE;
    for (int u = -1; ++ u < n * 2; )
    for (int v = u; ++v < n * 2; ) {
      long tans = 0;
      int f = 0;
      for (int i = -1; ++ i < n - 1; ) {
        while (f == u || f == v) ++f;
        int x = a[f++];
        while (f == u || f == v) ++f;
        tans += Math.abs(x - a[f++]);
      }
      ans = Math.min(ans, tans);
    }
    out.println(ans);
  }
}