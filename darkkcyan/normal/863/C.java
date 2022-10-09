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
  
  int beat(int u, int v) {
    if (u == 2 && v == 1) return 1;
    if (u == 1 && v == 0) return 1;
    if (u == 0 && v == 2) return 1;
    return 0;
  }
  
  long ca = 0, cb = 0;
  void getpoint(int t) {
    int a = t / 3, b = t % 3;
    ca += beat(a, b);
    cb += beat(b, a);
  }

  boolean vis[] = new boolean[9];
  long tca[] = new long[9];
  long tcb[] = new long[9];
  long p[] = new long[9];

  Main() {
    long k = nextlong();
    int a = nextint() - 1, b = nextint() - 1;
    int t = a * 3 + b;
    int m[] = new int[9];
    for (int i = -1; ++ i < 9; ) m[i] = nextint() - 1;
    for (int i = -1; ++ i < 9; ) m[i] = m[i] * 3 + nextint() - 1;
    long s = 0;
    for (; s < k && !vis[t]; ++s) {
      tca[t] = ca;
      tcb[t] = cb;
      getpoint(t);
      vis[t] = true;
      p[t] = s;
      t = m[t];
      err.println(s + " " + t);
    }
    err.println("\n" + ca + " " + cb);
    if (s < k) {
      long d = s - p[t];
      long time = (k - s) / d;
      ca += (ca - tca[t]) * time;
      cb += (cb - tcb[t]) * time;
      k = (k - s) % d;
      err.println(d + " " + time + " " + ca + " " + cb);
      while (k -- > 0) {
        getpoint(t);
        t = m[t];
      }
    }
    out.println(ca + " " + cb);
  }
}