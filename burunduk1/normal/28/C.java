import java.util.Locale;
import java.util.Scanner;

/**
 * @author Sergey Kopeliovich (burunduk1@yandex-team.ru)
 */
public class c {
    public void run() {
        Locale.setDefault(Locale.US);
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int a[] = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = in.nextInt();
        }

        long[][] C = new long[n + 2][n + 2];
        C[0][0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                C[i + 1][j] += C[i][j];
                C[i + 1][j + 1] += C[i][j];
            }
        }
//        for (int i = 0; i <= n; i++) {
//            for (int j = 0; j <= n; j++) {
//                System.out.print(C[i][j] + " ");
//            }
//            System.out.println("");
//        }

        double[][] pow = new double[m + 1][n + 1];
        double[][] pow2 = new double[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            double x = 1.0 / i;
            pow[i][0] = 1;
            pow2[i][0] = 1;
            for (int j = 0; j < n; j++) {
                pow[i][j + 1] = pow[i][j] * x;
                pow2[i][j + 1] = pow2[i][j] * (1 - x);
            }
        }

        double[][][] way = new double[m + 1][n + 1][n + 1];
        way[0][0][0] = 1.0;
        for (int i = 0; i < m; i++) {
            for (int max = 0; max <= n; max++) {
                for (int k = 0; k <= n; k++) {
                    int restN = n - k;
                    int restM = m - i;
                    for (int x = 0; x <= restN; x++) {
                        way[i + 1][Math.max(max, len(a[i], x))][k + x] +=
                                way[i][max][k] * C[restN][x] * pow[restM][x] * pow2[restM][restN - x];
                    }
                }
            }
        }

        double sum = 0;
        for (int max = 0; max <= n; max++) {
            sum += way[m][max][n] * max;
        }
        System.out.format("%.18f\n", sum);
    }

    public int len( int a, int x ) {
        return (x + a - 1) / a;
    }

    public static void main(String[] args) {
        new c().run();
    }
}