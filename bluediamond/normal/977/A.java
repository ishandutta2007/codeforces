import java.util.Scanner;

public class jmek
{

    public static void main(String []args) 
    {
    	Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), k = cin.nextInt();
        for (int i = 1; i <= k; i++)
        {
            if (n % 10 == 0)
            {
                n /= 10;
            }
            else
            {
                n--;
            }
        }
        System.out.println(n);
    }
}