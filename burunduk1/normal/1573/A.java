import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        var in = new Scanner(System.in);
        for (int tn = in.nextInt(); tn > 0; tn--) {
            int n = in.nextInt();
            String s = in.next();
            int ans = (s.charAt(s.length() - 1) == '0' ? 0 : -1);
            for (var c : s.toCharArray())
                if (c != '0')
                    ans += (c - '0') + 1;
            System.out.println(ans);
        }
    }
}