
import java.util.*;


public class C {
    public static void main(String arg[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt(), k = input.nextInt();
        
        int[][] f = new int[n + 1][n * 100 * 2];
        int[] a = new int[n], val = new int[n];
        
        int ZERO = n * 100;
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < 2 * 100 * n; j++)
                f[i][j] = -1;
        }
        for(int i = 0; i < n; i++) {
            a[i] += (val[i] = input.nextInt());
        }
        for(int i = 0; i < n; i++) {
            a[i] -= input.nextInt() * k;
        }
        f[0][ZERO] = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 2 * 100 * n; j++) {
                if (f[i][j] == -1)
                    continue;
                f[i + 1][j] = Math.max(f[i + 1][j], f[i][j]);
                if (j + a[i] >= 0 && j + a[i] < 2 * 100 * n)
                    f[i + 1][j + a[i]] = Math.max(f[i][j] + val[i], f[i + 1][j + a[i]]);
            }
        if (f[n][ZERO] <= 0) {
            System.out.println(-1);
        } else {
            System.out.println(f[n][ZERO]);
        }
    }
}