import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String args[]) throws IOException { new Main(); }
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  
  long rem = (long) 1e9 + 7;
  long dpcnt[], dpmax[], dpmin[];
  int orda = ("a").codePointAt(0);
  int n;
  int s[], a[] = new int[26];

  public Main() throws IOException {
    n = Integer.parseInt(br.readLine());
    String str = br.readLine();
    s = new int[n + 1];
    for (int i = 0; i++ < n; ) {
      s[i] = str.codePointAt(i - 1) - orda;
    }

    String t[] = br.readLine().split(" ");
    for (int i = -1; ++ i < 26; ) {
      a[i] = Integer.parseInt(t[i]);
      //System.err.println(i + ":" + a[i]);
    }

    dpcnt = new long[n + 1];
    dpmax = new long[n + 1];
    dpmin = new long[n + 1];

    dpcnt[0] = 1;
    dpmax[0] = 0;
    dpmin[0] = 0;
    for (int i = 1; i <= n; ++i) {
      boolean has[] = new boolean[26];
      has[s[i]] = true;
      dpcnt[i] = dpcnt[i - 1];
      dpmax[i] = Math.max(1, dpmax[i - 1]);
      dpmin[i] = dpmin[i - 1] + 1;
      for (int f = i - 1; f > 0; --f) {
        boolean ok = true;
        has[s[f]] = true;
        for (int g = -1; ++g < 26; ) {
          if (has[g] && i - f + 1 > a[g]) {
            ok = false;
            break;
          }
        }
        if (!ok) {
          //System.err.println(i + " " + f);
          break;
        }
        dpcnt[i] = (dpcnt[i] + dpcnt[f - 1]) % rem;
        dpmax[i] = Math.max(dpmax[i], Math.max(dpmax[f - 1], i - f + 1));
        dpmin[i] = Math.min(dpmin[i], dpmin[f - 1] + 1);
      }
    }
    for (int i = -1; ++i <= n; ) {
      //System.err.println(i + " " + dpcnt[i] + " " + dpmax[i] + " " + dpmin[i]);
    }
    System.out.println(dpcnt[n] + "\n" + dpmax[n] + "\n" + dpmin[n]);
  }
}