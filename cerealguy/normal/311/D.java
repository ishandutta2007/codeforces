/*--------------------------------------------------------------*/
/* ACM ICPC 2009-2010, NEERC                                    */
/* Northern Subregional Contest                                 */
/* St Petersburg, October 17, 2009                              */
/*--------------------------------------------------------------*/
/* Problem E. Enigmatic Device                                  */
/*                                                              */
/* Original idea         Roman Satukov                          */
/* Problem statement     Andrew Lopatin                         */
/* Testset               Andrew Lopatin                         */
/*--------------------------------------------------------------*/
/* Solution                                                     */
/*                                                              */
/* Author                Andrew Lopatin                         */
/*--------------------------------------------------------------*/
 
import java.util.*;
import java.io.*;

public class enigmatic_al {
  static final int MaxN = 100000, MaxM = 100000, MOD = 95542721;
  static final int P1 = 0, P2 = 48, TSize = 1 << 17;
  
  static int rangeInt (String s, int a, int b) {
    int x = Integer.parseInt (s);
    if (x < a || x > b) throw new RuntimeException (x + " is not in " + a + ".." + b);
    return x;
  }

  static int [][] T;
  // F - non-distributed operation
  // L - local distributed shift, in addition to F
  static int [] F, L;
  static int l, r;


  static void push (int k) {
    F[2 * k] += F[k];
    F[2 * k + 1] += F[k];
    L[k] += F[k];
    F[k] = 0;
  }


  static void normalize (int k) {
    int rsh1 = F[k] + L[k];      
    int cnt1 = Math.max (P2, P1 + P2 - rsh1);

    int sh1 = (rsh1 - P1) % P2 + P1;

    int c1 = sh1;
    int c2 = (F[2 * k] + L[2 * k] - P1) % P2 + P1;

    //System.out.println (" --> " + k + " " + c1 + " " + c2);

    for (int i = 0; i < cnt1; i++) {
      T[k][c1] = T[2 * k][c2];
      ++c1;
      ++c2;
      if (c1 == P1 + P2) c1 = P1;
      if (c2 == P1 + P2) c2 = P1;
    }

    c1 = sh1;
    c2 = (F[2 * k + 1] + L[2 * k + 1] - P1) % P2 + P1;

    //System.out.println (" --> " + k + " " + c1 + " " + c2);

    for (int i = 0; i < cnt1; i++) {
      T[k][c1] = add(T[k][c1], T[2 * k + 1][c2]);
      ++c1;
      ++c2;
      if (c1 == P1 + P2) c1 = P1;
      if (c2 == P1 + P2) c2 = P1;
    }
  }


  static void increment (int k, int a, int b) {
    if (r < a || l > b) return;

    if (l <= a && b <= r) {
      F[k]++;
      return;
    }

    push (k);
    int m = (a + b) >> 1;
    
    increment (2 * k, a, m);
    increment (2 * k + 1, m + 1, b);

    normalize (k);
  }


  static int getSum (int k, int a, int b) {
    if (r < a || l > b) return 0;

    if (l <= a && b <= r) {
      int shift = L[k] + F[k];
      return T[k][(shift - P1) % P2 + P1];
    }

    push (k);
    int m = (a + b) >> 1;
    return add(getSum (2 * k, a, m), getSum (2 * k + 1, m + 1, b));
  }
  
  static int cube(int i) {
      return (int) (((long)i * i % MOD * i) % MOD);
  }
  
  static int add(int a, int b) {
      a += b;
      if (a >= MOD) {
          a -= MOD;
      }
      return a;
  }

  public static void main (String args []) throws Exception {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("d.in");
        if (file.exists() && file.canRead()) {
            input = new FileInputStream(file);
        }
    BufferedReader in = new BufferedReader (new InputStreamReader(input));
    PrintWriter out = new PrintWriter (output);

    int n = rangeInt (in.readLine (), 1, MaxN);
    StringTokenizer tok = new StringTokenizer (in.readLine ());
    int [] a = new int [n];

    for (int i = 0; i < n; i++)
      a[i] = rangeInt (tok.nextToken (), 0, 1000000000) % MOD;
    
    if (tok.hasMoreTokens ()) throw new Exception ("EOL required");

    T = new int [TSize * 2][P1 + P2];
    F = new int [TSize * 2];
    L = new int [TSize * 2];

    for (int i = 0; i < n; i++)
      T[TSize + i][0] = a[i];

    for (int j = 0; j < n; j++)
      for (int i = 1; i < P1 + P2; i++)
        T[TSize + j][i] = cube(T[TSize + j][i - 1]);

    for (int j = TSize - 1; j > 0; j--)
      for (int i = P1 + P2 - 1; i >= 0; i--)
        T[j][i] = add(T[2 * j][i], T[2 * j + 1][i]);

    int m = rangeInt (in.readLine (), 1, MaxM);

    for (int i = 0; i < m; i++) {
      tok = new StringTokenizer (in.readLine ());
      int k = rangeInt (tok.nextToken (), 1, 2);
      l = rangeInt (tok.nextToken (), 1, MaxN) - 1;
      r = rangeInt (tok.nextToken (), l, MaxN) - 1;
      if (k == 2) {
        increment (1, 0, TSize - 1); 
      } else {
        out.println (getSum (1, 0, TSize - 1));
      }
      if (tok.hasMoreTokens ()) throw new Exception ("EOL required");

      /*for (int j = 1; j < TSize * 2; j++)
        System.out.println (j + " " + F[j] + " " + L[j] + " " + T[j][0] + " " + T[j][1] + " " + T[j][2] + " " + T[j][3]);
      System.out.println ("---");*/
    }

    if (in.ready ()) throw new RuntimeException ("EOF expected");

    out.close ();
  }
}