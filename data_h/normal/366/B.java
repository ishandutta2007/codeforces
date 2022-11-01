
import java.util.*;

public class B {
    public static void main(String arg[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt(), k = input.nextInt();
        
        int[] a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = input.nextInt();
        }
        int res = -1, pos = 0;
        for(int i = 0; i < k; i++) {
            int cur = 0;
            for(int j = i; j < n; j += k) 
                cur += a[j];
            if (cur < res || res == -1) {
                res = cur;
                pos = i;
            }
        }
        System.out.println(pos + 1);
    }
}