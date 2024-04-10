import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {
  static double mpow(double b, int m) {
    double ans = 1;
    for (; m > 0; m >>= 1) {
      if ((m & 1) == 1) ans *= b;
      b *= b;
    }
    return ans;
  }
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int m = sc.nextInt();
    int n = sc.nextInt();

    double ans = 0;
    for (int max = 1; max <= m; ++max) {
      ans += (mpow((double)max / m, n) - mpow((double)(max - 1) / m, n)) * max;
    }
    System.out.println(ans);
  }
}