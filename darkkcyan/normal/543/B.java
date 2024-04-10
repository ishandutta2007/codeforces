// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
public class Main {
  int n, m;
  ArrayList<Integer> gr[];
  int s1, t1, l1, s2, t2, l2;
  
  int[] bfs(int u) {
    Queue<Integer> qu = new LinkedList<>();
    int d[] = new int[n + 1];
    Arrays.fill(d, -1);
    d[u] = 0;
    for (qu.add(u); qu.size() > 0; ) {
      u = qu.remove();
      for (int v: gr[u]) {
        if (d[v] != -1) continue;
        d[v] = d[u] + 1;
        qu.add(v);
      }
    }
    return d;
  }
  
  int ds1[], dt1[], ds2[], dt2[];
  
  Main() {
    n = nxtint(); m = nxtint();
    gr = new ArrayList[n + 1];
    for (int i = -1; ++ i <= n; ) gr[i] = new ArrayList<>();
    for (int i = -1; ++ i < m; ) {
      int u = nxtint();
      int v = nxtint();
      gr[u].add(v);
      gr[v].add(u);
    }
    s1 = nxtint(); t1 = nxtint(); l1 = nxtint();
    s2 = nxtint(); t2 = nxtint(); l2 = nxtint();
    int ans = -1;

    for (int i = 0; i < 2; ++i) {
      ds1 = bfs(s1); ds2 = bfs(s2); dt1 = bfs(t1); dt2 = bfs(t2);
      if (ds1[t1] <= l1 && ds2[t2] <= l2) ans = Math.max(ans, m - ds1[t1] - ds2[t2]);
      for (int u = 0; u ++ < n; ) {
        int d[] = bfs(u);
        int du1 = ds1[u], du2 = ds2[u];
        for (int v = 0; v++ < n; ) {
          int dmid = d[v], dv1 = dt1[v], dv2 = dt2[v];
          // err.println(u + " " + v + " " + du1 + " " + du2 + " " + dv1 + " " + dv2 + " " + dmid);
  
          if (du1 + dmid + dv1 > l1) continue;
          if (du2 + dmid + dv2 > l2) continue;
          ans = Math.max(ans, m - (du1 + du2 + dmid + dv1 + dv2));
        }
      }
      int t = s1; s1 = t1; t1 = t;
    }
    out.println(ans);
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