import java.util.Scanner;

/**
 * @author Sergey Kopeliovich (burunduk1@yandex-team.ru)
 */
public class A {
    public static void main(String[] args) {
        new A().run();
    }

    private void run() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] x = new int[n];
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            d[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (x[i] == x[j] + d[j] && x[j] == x[i] + d[i]) {
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
    }
}