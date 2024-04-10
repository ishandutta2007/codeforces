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

  int n, q, m;
  int a[];
  int qt[], ql[], qr[];

  int q1(int l, int r, int p) {
    if (p < l || p > r) return p;
    if (p == l) return r;
    return p - 1;
  }

  int q2(int l, int r, int p) {
    if (p < l || p > r) return p;
    int len = r - l + 1;
    p -= l;
    p = len - p - 1;
    return p + l;
  }

  int findpos(int p) {
    for (int i = q; i-- > 0;) {
      if (qt[i] == 1) p = q1(ql[i], qr[i], p);
      else p = q2(ql[i], qr[i], p);
    }
    return p;
  }

  Main() {
    n = nextint(); q = nextint(); m = nextint();
    a = new int[n + 1];
    for (int i = 0; i ++ < n; ) a[i] = nextint();
    qt = new int[q]; ql = new int[q]; qr = new int[q];
    for (int i = 0; i < q; ++i) {
      qt[i] = nextint();
      ql[i] = nextint();
      qr[i] = nextint();
    }
    while (m -- > 0) {
      out.print(a[findpos(nextint())] + " ");
    }
  }
}