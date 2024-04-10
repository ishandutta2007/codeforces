/**
 * @author Sergey Kopeliovich (burunduk1@yandex-team.ru)
 */

import java.util.Scanner;

/**
 * @author Sergey Kopeliovich (burunduk1@yandex-team.ru)
 */
public class B {
    public static void main(String[] args) {
        new B().run();
    }

    private void run() {
        Scanner in = new Scanner(System.in);
        int[] a = read(in);
        int[] b = read(in);
        boolean good = false;

        good |= goodAge(a[0], a[1], a[2], b[0], b[1], b[2]);
        good |= goodAge(a[0], a[1], a[2], b[0], b[2], b[1]);
        good |= goodAge(a[0], a[1], a[2], b[1], b[0], b[2]);
        good |= goodAge(a[0], a[1], a[2], b[1], b[2], b[0]);
        good |= goodAge(a[0], a[1], a[2], b[2], b[0], b[1]);
        good |= goodAge(a[0], a[1], a[2], b[2], b[1], b[0]);

        System.out.println(good ? "YES" : "NO");
    }

    private boolean goodAge(int dd, int mm, int yy, int d, int m, int y) {
        if (!correctDate(d, m, y)) {
            return false;
        }
        if (yy != y + 18) {
            return yy > y + 18;
        }
        if (mm != m) {
            return mm > m;
        }
        return dd >= d;
    }

    static int[] dayNum = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    private boolean correctDate( int dd, int mm, int yy ) {
        return (1 <= mm && mm <= 12) && (1 <= dd && dd <= dayNum[mm - 1] + dayAdd(mm, yy)) && (1 <= yy && yy <= 99);
    }

    private int dayAdd(int mm, int yy) {
        return (mm == 2 && yy % 4 == 0) ? 1 : 0;
    }

    private int[] read(Scanner in) {
        String input = in.next();
        String[] s = input.split("[.]");
        int n = s.length;
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = Integer.valueOf(s[i]);
        }
        return res;
    }
}