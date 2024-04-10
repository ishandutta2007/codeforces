import java.util.Scanner;

public class DominoesICPC {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        long vertical = input.nextInt();
        long horizon = input.nextInt();
        if (horizon == 1)
        {
            System.out.println(vertical - 1);
        }
        else
        {
            System.out.println(vertical * (horizon - 1));
        }
    }
}