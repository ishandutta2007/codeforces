import java.util.Locale;
import java.util.Scanner;

/**
 * @author Sergey Kopeliovich (burunduk1@yandex-team.ru)
 */
public class B {
    public static void main(String[] args) {
        new B().run();
    }

    private void run() {
        Locale.setDefault(Locale.US);
        Scanner in = new Scanner(System.in);
        int L = in.nextInt();
        int d = in.nextInt();
        int v = in.nextInt();
        int g = in.nextInt();
        int r = in.nextInt();

        double t = (double)d / v;
        int time = (int)(t / (g + r)) * (g + r);
        final double eps = 1e-9;

        if (time + g - eps < t) {
            t = time + (g + r);
        }
        System.out.format("%.10f\n", t + (double)(L - d) / v);
    }
}