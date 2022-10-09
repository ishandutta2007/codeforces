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

  int n, x;
  boolean m[] = new boolean[111];

  int findmex() {
    for (int i = -1; ++ i < m.length; ) {
      if (!m[i]) return i;
    }
    return -1;
  }

  Main() {
    n = nxtint();
    x = nxtint();
    for (int i = -1; ++ i < n; ) {
      m[nxtint()] = true;
    }
    
    int ans = 0;
    while (findmex() < x) {
      ++ans;
      m[findmex()] = true;
    }
    if (findmex() != x) ++ans;
    out.println(ans);
  }
}