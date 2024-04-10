import java.util.Scanner;
import static java.lang.Math.*;

/**
 * @author Sergey Kopeliovich (burunduk1@yandex-team.ru)
 */
public class A {
    public static void main(String[] args) {
        new A().run();
    }

    private void run() {
        Scanner in = new Scanner(System.in);

        int A = in.nextInt();
        int B = in.nextInt();
        int n = in.nextInt();
        final int M = 1000;

        for (int x = -M; x <= M; x++) {
            long t = A;
            for (int i = 0; i < n; i++) {
                t *= x;
                if (abs(t) > abs(B)) {
                    break;
                }
            }
            if (t == B) {
                System.out.println(x);
                return;
            }
        }
        System.out.println("No solution");
    }
}