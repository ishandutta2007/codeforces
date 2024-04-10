import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class a implements Runnable {
  StringTokenizer tokenizer = new StringTokenizer("");
  BufferedReader in;
  PrintStream out;
  
  public static void main (String[] args) {
    new Thread(new a()).start();
  }
  
  boolean lucky (int n) {
    if (n==0) return false;
    if (n==4 || n==7) return true;
    if (n % 10 != 4 && n % 10 != 7) return false;
    return lucky(n/10);
  }
  
  public void run () {
    try {
      in = new BufferedReader(new InputStreamReader(System.in));
      out = new PrintStream(System.out);
      
      //
      int n = nextInt();
      for (int i = 4; i <= n; ++i) {
        if (lucky(i) && (n % i == 0)) {
          out.println("YES");
          return;
        }
      }
      out.println("NO");
      //
      
      
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
  
  boolean seekForToken () {
    while (!tokenizer.hasMoreTokens()) {
      String s = null;
      try {
        s = in.readLine();
      } catch (Exception e) {
        e.printStackTrace();
      }
      if (s == null) return false;
      tokenizer = new StringTokenizer(s);
    }
    return true;
  }
  String nextToken() {
    return seekForToken() ? tokenizer.nextToken() : null;
  }
  
  int nextInt() {
    return Integer.parseInt(nextToken());
  }
}