import java.lang.*;
import java.util.*;
import java.io.*;

public class main {
  public static void main(String arg[]) { new main(); }

  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  StringTokenizer st;
  String nxtln() { try { return br.readLine(); } catch(Exception e) { return ""; } }
  void newst() { st = new StringTokenizer(nxtln()); }
  String nxttok() { return st.nextToken(); }
  int toint(String s) { return Integer.parseInt(s); }

  int maxn = 101010;
  int[] c = new int[4];
  int n, m;
  int[] a = new int[maxn];
  int[] b = new int[maxn];
  public main() {
    newst(); for (int i = -1; ++ i < 4; ) c[i] = toint(nxttok());
    newst(); n = toint(nxttok()); m = toint(nxttok());
    newst(); for (int i = -1; ++ i < n; ) a[i] = toint(nxttok());
    newst(); for (int i = -1; ++ i < m; ) b[i] = toint(nxttok());

    int s1 = 0, s2 = 0;
    for (int i = -1; ++ i < n; ) {
      a[i] *= c[0];
      if (a[i] > c[1]) a[i] = c[1];
      s1 += a[i];
    }
    for (int i = -1; ++ i < m; ) {
      b[i] *= c[0];
      if (b[i] > c[1]) b[i] = c[1];
      s2 += b[i];
    }
    if (s1 > c[2]) s1 = c[2];
    if (s2 > c[2]) s2 = c[2];
    int ans = Math.min(s1 + s2, c[3]);
    System.out.print(ans);
  }
}