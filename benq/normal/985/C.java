import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(),k = in.nextInt(),l = in.nextInt();
        int[] need = new int[100001];
        Integer[] a = new Integer[n*k];

        for (int i = 0; i < n*k; ++i) a[i] = in.nextInt();
        Arrays.sort(a);
        
        int num = 0;
        for (int x: a) if (x-a[0] <= l) num ++;
        if (num < n) { System.out.println(0); return; }
        for (int i = 0; i < n; ++i) { need[i] ++; num --; }
        for (int i = 0; i < n; ++i) {
            int z = Math.min(k-1,num);
            need[i] += z; num -= z;
        }
        int t = 0; long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long)a[t];
            t += need[i];
        }
        
        System.out.println(ans);
    }
}