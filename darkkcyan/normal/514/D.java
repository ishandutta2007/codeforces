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
  int a[][];
  
  Deque<Integer> qu[];
  
  boolean ok(int len) {
    for (int i = -1; ++ i < m; ) qu[i].clear();
    for (int r = -1; ++r < n; ) {
      int l = r - len + 1;
      long sum = 0;
      for (int f = -1; ++ f < m; ) {
        while (qu[f].size() > 0 && qu[f].peekFirst() < l) qu[f].removeFirst();
        while (qu[f].size() > 0 && a[qu[f].peekLast()][f] <= a[r][f]) qu[f].removeLast();
        qu[f].add(r);
        sum += (long) a[qu[f].peekFirst()][f];
      }
      if (l < 0) continue;
      if (sum <= k) return true;
    }
    return false;
  }
  
  Main() {
    n = nxtint(); m = nxtint(); k = nxtint();
    a = new int[n][m];
    for (int i = -1; ++ i < n; ) for (int f  = -1; ++ f < m; )
      a[i][f] = nxtint();
    
    qu = new LinkedList[m];
    for (int i = -1; ++ i < m;) qu[i] = new LinkedList();
    int l = 0, r = n;
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (ok(mid)) l = mid;
      else r = mid - 1;
    }
    if (l == 0) {
      for (int i = -1; ++ i < m; ) out.print("0 ");
      return ;
    }
    ok(l);
    for (int i = -1; ++ i < m; ) out.print(a[qu[i].peekFirst()][i] + " ");
  }
}