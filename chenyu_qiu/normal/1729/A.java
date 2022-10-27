import java.util.Scanner;

public class Div3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        for (int i = 0; i < a; i++) {
            int first = input.nextInt();
            int second = input.nextInt();
            int secondgo = input.nextInt();
            if (Math.abs(secondgo - second)  + (secondgo - 1) == first - 1)
            {
                System.out.println("3");
            }
            if (Math.abs(secondgo - second)  + (secondgo - 1) > first - 1)
            {
                System.out.println("1");
            }
            if (Math.abs(secondgo - second)  + (secondgo - 1) < first - 1)
            {
                System.out.println("2");
            }
        }
    }
}