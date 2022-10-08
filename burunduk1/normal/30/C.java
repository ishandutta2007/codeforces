import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Sergey Kopeliovich (burunduk1@yandex-team.ru)
 */
public class C {
    private double res = 0;

    public static void main(String[] args) {
        new C().run();
    }

    private void run() {
        Locale.setDefault(Locale.US);
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        MyTarget t[] = new MyTarget[n];
        for (int i = 0; i < n; i++) {
            t[i] = new MyTarget(in);
        }
        Arrays.sort(t);

        double f[] = new double[n];
        for (int i = 0; i < n; i++) {
            f[i] = 0.0;
            for (int j = 0; j < n; j++) {
                if (t[j].canGoTo(t[i])) {
                    f[i] = Math.max(f[i], f[j]);
                }
            }
            f[i] += t[i].getP();
            res = Math.max(res, f[i]);
        }
        System.out.format("%.10f\n", res);
    }

    private class MyTarget implements Comparable {
        private int x;
        private int y;
        private int t;
        private double p;

        public MyTarget(Scanner in) {
            x = in.nextInt();
            y = in.nextInt();
            t = in.nextInt();
            p = in.nextDouble();
        }

        public int compareTo(Object o) {
            return t - ((MyTarget)o).t;
        }

        public double getP() {
            return p;
        }

        public boolean canGoTo(MyTarget target) {
            return t <= target.t && sqr(x - target.x) + sqr(y - target.y) <= sqr(t - target.t);
        }

        private long sqr(int d) {
            return (long)d * d;
        }
    }
}