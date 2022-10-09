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
  
  int n, m;
  ArrayList<Integer> gr[];
  int dp[], d[], tr[];
  long path[];
  Main() {
    n = nxtint(); m = nxtint();
    gr = new ArrayList[n];
    for (int i = -1; ++ i < n; ) gr[i] = new ArrayList<>();
    int ic = 0;
    for (int i = -1; ++ i < m; ) {
      int u = nxtint(), v = nxtint(), z = nxtint();
      --u; --v;
      gr[u].add(v << 1 | z);
      gr[v].add(u << 1 | z);
      ic += z;
    }
    dp = new int[n];
    d = new int[n];
    tr = new int[n];
    Arrays.fill(d, -1);
    Queue<Integer> qu = new LinkedList<>();
    dp[0] = 0;
    d[0] = 0;
    for (qu.add(0); qu.size() > 0; ) {
      int u = qu.remove();
      for (int i: gr[u]) {
        int v = i >> 1, z = (i & 1) == 0 ? 1 : -1;;
        if (d[v] != -1) {
          if (d[v] == d[u] + 1 && dp[v] > dp[u] + z) {
            dp[v] = dp[u] + z;
            tr[v] = u;
          }
          continue;
        }
        d[v] = d[u] + 1;
        dp[v] = dp[u] + z;
        tr[v] = u;
        qu.add(v);
      }
    }
    out.println(dp[n - 1] + ic);
    path = new long[d[n - 1]];
    for (int u = n - 1, i = 0; u > 0; u = tr[u], i ++) {
      int v = tr[u];
      if (u < v) path[i] = ((long)u << 30) + v;
      else path[i] = ((long)v << 30) + u;
      for (int x: gr[v]) {
        if ((x >> 1) != u) continue;
        if ((x & 1) == 0) out.println((u + 1) + " " + (v + 1) + " 1");
        break;
      }
    }
    Arrays.sort(path);
    for (int u = -1; ++ u < n; ) {
      for (int i: gr[u]) {
        int v = i >> 1;
        if (v < u) continue;
        if (Arrays.binarySearch(path, ((long)u << 30) + v) >= 0) continue;
        if ((i & 1) == 1) out.println((u + 1) + " " + (v + 1) + " 0");
      }
    }
  }
}