import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String args[]) throws IOException { new Main().bw.close(); }
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  StringTokenizer st = null;
  String nxttok() {
    try { while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine()); }
    catch (Exception e) { return ""; }
    return st.nextToken();
  }
  int nxtint() { return Integer.parseInt(nxttok()); }

  int n, a, d;

  Main() throws IOException {
    n = nxtint();
    a = nxtint();
    d = nxtint();
    double lt = 0;
    for (int i = -1; ++ i < n; ) {
      int st = nxtint(), v = nxtint();
      double mst = (double)v / a;
      double td = a * mst * mst / 2;
      double t = mst;
      if (td > d) {
        t = Math.sqrt((double)2 * d / a);
      } else {
        t += (d - td) / v;
      }
      t += st;
      if (t > lt) lt = t;
      bw.write(lt + "\n");
    }
  }
}