import java.io.*;
import java.lang.*;
import java.util.*;

public class main {
  static int toint(String s) { return Integer.parseInt(s); }
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    int n = toint(br.readLine());
    int[] a = new int[n];
    st = new StringTokenizer(br.readLine());
    for (int i = -1; ++ i < n; ) a[i] = toint(st.nextToken());

    int[] ans = new int[n];
    int m = 0;
    for (int i = n; i-- > 0; ) {
      if (a[i] <= m) ans[i] = (m + 1 - a[i]);
      m = Math.max(m, a[i]);
    }
    for (int i = -1; ++i < n; ) {
      System.out.print(ans[i] + " ");
    }
  }
}