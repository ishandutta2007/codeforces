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
  
  char s[] = {'0', '1'};
  char[] rep(int ch, int n) {
    char[] ans = new char[n];
    while (n-- > 0) ans[n] = s[ch];
    return ans;
  }

  void reverse(char[] x, int l, int r) {
    for (int i = l; i <= r; ++i) {
      x[i] = x[i] == '0' ? '1' : '0';
    }
  }

  int ask(char[] t) {
    System.out.print("? ");
    System.out.println(t);
    System.out.flush();
    return nxtint();
  }

  int n;
  int found;
  int pos[] = new int[2];

  Main() {
    n = nxtint();

    char[] t = rep(0, n);
    int u = ask(t);
    t[n - 1] = '1';
    int v = ask(t);
    if (u < v) {
      found = 0;
    } else {
      found = 1;
    }
    System.err.println("found " + found + " " + n);
    pos[found] = n;

    t[n - 1] = '0';
    int l = 0, r = n - 2, lastans = u;
    while (l < r) {
      int mid = l + (r - l) / 2;
      reverse(t, l, mid);
      int nf = ask(t), f = lastans;
      lastans = nf;
      if (t[l] == s[found ^ 1]) {
        int temp = nf;
        nf = f;
        f = temp;
      }
      System.err.println("nf f " + nf + " " + f);
      if (f - nf == mid - l + 1) {
        // left side dont have it
        System.err.println("no left");
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    pos[found ^ 1] = l + 1;
    System.out.print("! " + pos[0] + " " + pos[1]);
    System.out.flush();
  }
}