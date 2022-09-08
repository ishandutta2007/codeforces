import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {

    private Scanner in = new Scanner(System.in);
    private PrintWriter out = new PrintWriter(System.out);


    private int getCountOfOccurrencesElementOfArray(int x, int n, int[] a, int ai) {
        int res = lowerBound(a, n, x + 1) - lowerBound(a, n, x);
        if (x == ai) {
            --res;
        }
        return res;
    }

    private int lowerBound(int[] a, int n, int x) {
        int l = -1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[mid] >= x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }

    private void solve(int n, int[] a) {
        long answer = 0;

        Arrays.sort(a);

        for (int i = 0; i < n; i++) {
            for (int x = 1; x <= 32; x++) {

                int pow = 2;
                for (int k = 1; k < x; k++)
                    pow *= 2;

                if ((pow > a[i]) & (a[i] + a[n - 1] >= pow))
                    answer += getCountOfOccurrencesElementOfArray(pow - a[i], n, a, a[i]);

            }
        }
        out.println(answer / 2);
    }


    private void run() throws Exception {
        int n = in.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        solve(n, a);
        out.flush();
    }

    public static void main(String[] args) throws Exception {
        new B().run();
    }

}