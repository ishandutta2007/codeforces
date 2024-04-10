import java.util.Arrays;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        var in = new Scanner(System.in);
        for (int tn = in.nextInt(); tn > 0; tn--) {
            int n = in.nextInt();
            var a = new int[n];
            var pos = new int[2 * n + 1];
            for (int i = 0; i < n; i++) a[i] = in.nextInt();
            for (int i = 0; i < n; i++) pos[in.nextInt()] = i;
            int mi = 2 * n, ans = 2 * n;
//            System.out.println(Arrays.toString(pos));
            for (int i = 0; i < n; i++)
                for (; mi > a[i]; mi -= 2)
                    ans = Math.min(ans, i + pos[mi]);
            System.out.println(ans);
        }
    }
}