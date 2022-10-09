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

  int maxn = 101010;
  int n;
  ArrayList<Integer> gr[];
  int qu[] = new int[maxn * 2];
  int col[];

  Main() {
    n = nxtint();
    gr = new ArrayList[n];
    for (int i = -1; ++ i < n; ) gr[i] = new ArrayList<Integer>();
    for (int i = 0; ++ i < n; ) {
      int u = nxtint() - 1, v = nxtint() - 1;
      gr[u].add(v);
      gr[v].add(u);
    }

    col = new int[n];
    Arrays.fill(col, -1);
    int cnt[] = new int[2];

    cnt[col[0] = 0] = 1;
    int l, r;
    for (qu[l = r = 0] = 0; l <= r; ) {
      int u = qu[l++];
      for (int v : gr[u]) {
        if (col[v] != -1) continue;
        cnt[col[v] = col[u] ^ 1]++;
        qu[++r] = v;
      }
    }

    long ans = 0;
    for (int i = -1; ++ i < n; ) {
      ans += cnt[col[i] ^ 1] - gr[i].size();
    }
    ans /= 2;
    out.println(ans);
  }
}