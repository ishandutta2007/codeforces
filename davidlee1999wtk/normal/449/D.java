import java.util.Scanner;

/**
 * Created by David Lee on 2017/6/22.
 */

public class Main {
    static int P = 1000000007, N = 1<<20 + 5, k = 1<<20;
    static int a[] = new int [N];

    static private int ksm(int a, int b)
    {
        int c = 1, d = a;
        while (b > 0)
        {
            if((b & 1) != 0)
                c = (int)((long)c * d %P);
            d = (int)((long)d * d %P);
            b >>= 1;
        }
        return c;
    }

    static private void FWT(int [] a, int n, int L, int R)
    {
        if(L==R)
            return;
        int i, h = n/2;
        for (i = L; i < L + h; i++)
            a[i] = (a[i] + a[i+h])%P;
        FWT(a, h, L, L + h - 1);
        FWT(a, h, L + h, R);
    }

    static private void IFWT(int [] a, int n, int L, int R)
    {
        if(L==R)
            return;
        int i, h = n/2;
        for (i = L; i < L + h; i++)
            a[i] = (a[i] - a[i+h] + P)%P;
        IFWT(a, h, L, L + h - 1);
        IFWT(a, h, L + h, R);
    }

    static public void main(String args[]) {
        int T;
        Scanner Cin = new Scanner(System.in);
        //T = Cin.nextInt();
        T = 1;
        while (T > 0)
        {
            T--;
            int n, i;
            n = Cin.nextInt();
            for (i = 0; i < k; i++)
                a[i] = 0;
            for (i = 1; i <= n; i++)
                a[Cin.nextInt()]++;
            FWT(a, k, 0, k - 1);
            //for (i = 0; i < 10; i++)
                //System.out.printf("%d ",a[i]);
            //System.out.println();
            for (i = 0; i < k; i++)
                a[i] = ksm(2, a[i]);
            IFWT(a, k, 0, k - 1);
            System.out.printf("%d\n", a[0]);
        }
    }
}