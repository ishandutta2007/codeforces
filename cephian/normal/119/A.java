import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] data = br.readLine().split(" ");
        int a = Integer.parseInt(data[0]);
        int b = Integer.parseInt(data[1]);
        int n = Integer.parseInt(data[2]);
        boolean bo = false;
        for (;;)
        {
            int gcd;
            if (bo)
                gcd = GCD(b, n);
            else
                gcd = GCD(a, n);
            if (n - gcd < 0)
            {
                if (bo)
                    System.out.println("0");
                else
                    System.out.println("1");
                return;
            }
            n -= gcd;
            bo = !bo;
        }
    }

    public static int GCD(int a, int b)
    {
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }
}