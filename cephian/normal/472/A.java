import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws NumberFormatException, IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 2; i <= n / 2; ++i)
        {
            if (isComp(i) && isComp(n - i))
            {
                System.out.println(i + " " + (n - i));
                return;
            }
        }
    }

    public static boolean isComp(int n)
    {
        if (n == 1)
            return false;
        if (n == 2)
            return false;
        if (n % 2 == 0)
            return true;
        int maxit = (int) Math.sqrt(n);
        for (int i = 3; i <= maxit; i += 2)
            if (n % i == 0)
                return true;
        return false;
    }
}