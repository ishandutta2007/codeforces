import java.util.Scanner;

public class GCD {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            int num = input.nextInt();
            System.out.println(num + 2 * (num / 2 + num / 3));
        }
    }
}