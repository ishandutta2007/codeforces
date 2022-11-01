import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class buktikan {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    Task solver = new Task();
    solver.solve(1, in, out);
    out.close();
  }
}

class Task { 
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    BigInteger t = new BigInteger(in.next()), w = new BigInteger(in.next()), b = new BigInteger(in.next());
    BigInteger d = w.gcd(b);
    BigInteger lcm = w.divide(d).multiply(b);
    BigInteger k = t.divide(lcm);
    BigInteger ans = w.min(b).multiply(k.add(BigInteger.ONE)).subtract(BigInteger.ONE);
    if(t.mod(lcm).compareTo(b.min(w)) == -1)
      ans = ans.subtract(b.min(w).subtract(t.mod(lcm).add(BigInteger.ONE)));
    BigInteger dd = ans.gcd(t);
    ans = ans.divide(dd);
    t = t.divide(dd);
    out.println(ans+"/"+t);
  }
}

class InputReader {
  public BufferedReader reader;
  public StringTokenizer tokenizer;

  public InputReader(InputStream stream) {
    reader = new BufferedReader(new InputStreamReader(stream), 32768);
    tokenizer = null;
  }

  public String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new StringTokenizer(reader.readLine());
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }

  public int nextInt() {
    return Integer.parseInt(next());
  }

  public long nextLong() {
    return Long.parseLong(next());
  }
	
  public double nextDouble() {
    return Double.parseDouble(next());
  }
}