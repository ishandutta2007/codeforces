import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
  static long gcd(long a, long b) {
    return b != 0 ? gcd(b, a % b) : a;
  }
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    long l = sc.nextLong();
    long r = sc.nextLong();

    for (long a = l; a <= r; ++a) {
      for (long b = a + 1; b <= r; ++b) {
        if (gcd(a, b) != 1) continue;
        for (long c = b + 1; c <= r; ++c) {
          if (gcd(b, c) != 1) continue;
          if (gcd(a, c) != 1) {
            System.out.println(a + " " + b + " " + c);
            return ;
          }
        }
      }
    }
    System.out.println("-1");
  }
}