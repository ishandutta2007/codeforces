import java.lang.*;
import java.io.*;
import java.util.*;

public class main {
  BufferedReader br;
  StringTokenizer st;

  String nxtln() { try { return br.readLine(); } catch (Exception e) {return "";} }
  String nxttok() { return st.nextToken(); }
  int toint(String s) { return Integer.parseInt(s); }
  void newst() { st = new StringTokenizer(nxtln()); }

  public static void main(String arg[]) throws IOException { new main(); }

  int maxn = 101010;
  int n;
  int[] a = new int[maxn];
  int[] b = new int[maxn];

  int findfirst(int [] a) {
    for (int i = -1; ++ i < n - 1; ) {
      if (a[i] > a[i + 1]) 
        return i;
    }
    return n - 1;
  }

  public main() throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    n = toint(nxtln());
    newst();
    for (int i = -1; ++ i < n; ) a[i] = toint(nxttok());
    int ans = findfirst(a);
    for (int i = (ans + 1) % n, f = 0; f < n; ++f, i = (i + 1) % n) {
      b[f] = a[i];
    }
    if (findfirst(b) != n - 1) 
      System.out.print(-1);
    else
      System.out.print(n - ans - 1);
  }
}