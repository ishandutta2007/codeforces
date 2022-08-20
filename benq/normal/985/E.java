import java.util.*;

public class Main {
    static final int MX = 500001;
    static int n,k,d, lo;
    static int[] cum = new int[MX];
    static Integer[] a;
        
    static int getSum(int l, int r) {
        if (l > r) return 0;
        if (l == 0) return cum[r];
        return cum[r]-cum[l-1];
    }
    
    static void solve(int x) {
        while (a[x-1]-a[lo] > d) lo ++;
        int hi = x-k;
        cum[x] = cum[x-1];
        if (getSum(lo,hi) > 0) cum[x] ++;
    }
    
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt(); k = in.nextInt(); d = in.nextInt();
        a = new Integer[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        Arrays.sort(a);
        cum[0] = 1;
        for (int i = 1; i <= n; ++i) solve(i);
        if (cum[n]-cum[n-1] > 0) {
            System.out.println("YES");
            return;
        }
        System.out.println("NO");
    }
}