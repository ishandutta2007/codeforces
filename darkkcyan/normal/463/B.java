import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {
  public static void main(String args[]) throws IOException { new Main(); }
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

  Main() throws IOException {
    int n = Integer.parseInt(br.readLine());
    int ans = 0;
    for (String s: br.readLine().split(" ")) {
      ans = Math.max(ans, Integer.parseInt(s));
    }
    System.out.println(ans);
  }
}