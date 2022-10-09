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
    String a = nexttok();
    int cnt0 = 0;
    for (int i = a.length(); i-- > 0; ) 
      if (a.charAt(i) == '0') ++cnt0;
      else break;
    for (int i = cnt0; i -- > 0; ) a = "0" + a;
    for (int l = 0, r = a.length() - 1; l <= r; ++l, --r) {
      if (a.charAt(l) != a.charAt(r)) {
        out.println("NO");
        return ;
      }
    }
    out.println("YES");
  }
}