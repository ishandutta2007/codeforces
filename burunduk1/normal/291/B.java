/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.13
 */

import java.io.*;
import java.util.*;

public class b {
  public static void main( String[] args ) throws Exception {
    new b().run();
  }

  StringBuilder sb = new StringBuilder();
  PrintWriter out = new PrintWriter(System.out);

  void finish() {
    out.println("<" + sb + ">");
    sb.setLength(0);
  }

  public void run() throws Exception {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    char s[] = in.readLine().toCharArray();
    boolean open = false;
    for (int pos = 0; pos < s.length; pos++)
      if (s[pos] == '"') {
        if (open)
          finish();
        open = !open;
      } else if (s[pos] != ' ' || open) {
        sb.append(s[pos]);
      } else if (sb.length() > 0) {
        finish();
      }
    if (sb.length() > 0)
      finish();
    out.close();
  }
}