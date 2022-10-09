import java.lang.*;
import java.io.*;
import java.util.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int s = sc.nextInt() * 100;
    int ans = -1;
    for (int t = 0; t < n; ++t) {
      int u = sc.nextInt() * 100 + sc.nextInt();
      if (u > s) continue;
      int x = (s - u) % 100;
      ans = Math.max(ans, x);
    }
    System.out.println(ans);
  }
}