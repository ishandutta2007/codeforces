import java.util.*;
import java.io.*;

public class Main{ //    Main
  public static void main(String[] argv) throws IOException{
    new Main().run();
  }
  PrintWriter pw;
  Scanner sc;
  public void run() throws IOException{
    sc = new Scanner(System.in);
    int l=sc.nextInt(), r=sc.nextInt();
    int ans = 0;
    long cur = 1;
    while (cur <= r) {
        long old_cur = cur;
        while (cur <= r) {
            if (l <= cur) {
                ++ans;
            }
            cur *= 3;
        }
        cur = old_cur * 2;
    }
    pw = new PrintWriter(System.out);
    pw.print(ans);
    pw.close();
  }
}