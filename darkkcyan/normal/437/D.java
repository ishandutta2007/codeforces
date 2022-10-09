import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String args[]) { new Main(); }
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  StringTokenizer st = null;
  String nxttok() {
    try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine()); }
    catch (Exception e) { return ""; }
    return st.nextToken();
  }
  int nxtint() { return Integer.parseInt(nxttok()); }

  int n, m;
  int a[];
  Integer p[];
  ArrayList<Integer> gr[];
  boolean check[];

  int dsu[], cnt[];
  int findp(int u) { return dsu[u] = dsu[u] == u ? u : findp(dsu[u]); }
  void join(int u, int v) {
    u = findp(u); v = findp(v);
    if (u == v) return;
    cnt[u] += cnt[v];
    dsu[v] = u;
  }

  Main() {
    n = nxtint(); m = nxtint();
    a = new int[n]; p = new Integer[n];
    gr = new ArrayList[n];
    dsu = new int[n];
    cnt = new int[n];
    for (int i = -1; ++ i < n; ) {
      a[i] = nxtint();
      p[i] = i;
      gr[i] = new ArrayList<Integer>();
      dsu[i] = i;
      cnt[i] = 1;
    }
    while (m-- > 0) {
      int u = nxtint() - 1, v = nxtint() - 1;
      gr[u].add(v);
      gr[v].add(u);
    }

    long ans = 0;

    Arrays.sort(p, (u, v) -> a[v] - a[u]);

    check = new boolean[n];
    for (int i = -1; ++ i < n; ) {
      int u = p[i];
      check[u] = true;
      for (int v: gr[u]) {
        if (!check[v] || findp(u) == findp(v)) continue;
        ans += (long)a[u] * cnt[findp(u)] * cnt[findp(v)];
        join(u, v);
      }
    }
    System.out.println((double) ans * 2 / n / (n - 1));
  }
}