import java.util.Arrays;
import java.util.Scanner;

/**
 * @author Sergey Kopeliovich (burunduk1@yandex-team.ru)
 */

public class a {
    private class Pair implements Comparable {
        public int value;
        public int index;

        Pair( int value, int index) {
            this.value = value;
            this.index = index;
        }

        public int compareTo( Object obj ) {
            return value - ((Pair)obj).value;
        }
    }

    private int x[], y[];

    public int D( int a, int b ) {
        return Math.abs(x[b] - x[a]) + Math.abs(y[b] - y[a]);
    }

    public void run() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();

        x = new int[n];
        y = new int[n];
        Pair len[] = new Pair[m];

        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }
        for (int i = 0; i < m; i++) {
            len[i] = new Pair(in.nextInt(), i + 1);
        }
        Arrays.sort(len);

        int np = n / 2;
        Pair p[] = new Pair[np];
        int res[] = new int[n];

        for (int t = 0; t < 2; t++) {
            Arrays.fill(res, -1);
            for (int i = 0; i < np; i++) {
                int a = (2 * i + t) % n;
                int b = (a + 1) % n;
                int c = (b + 1) % n;
                p[i] = new Pair(D(a, b) + D(b, c), b);
            }
            Arrays.sort(p);
//            System.out.println("p");
//            for (int i = 0; i < np; i++) {
//                System.out.println(p[i].value + " " + p[i].index);
//            }
//            System.out.println("len");
//            for (int i = 0; i < m; i++) {
//                System.out.println(len[i].value + " " + len[i].index);
//            }

            boolean failed = false;
            int pos = 0;
            for (int i = 0; i < np; i++) {
                while (pos < m  && len[pos].value != p[i].value) {
                    pos++;
                }
                if (pos < m) {
                    res[p[i].index] = len[pos++].index;
                } else {
                    failed = true;
                }
            }

            if (!failed) {
                System.out.println("YES");
                for (int i = 0; i < n; i++) {
                    System.out.print(res[i] + " ");
                }
                return;
            }
        }
        System.out.println("NO");
    }

    public static void main(String[] args) {
        new a().run();
    }
}