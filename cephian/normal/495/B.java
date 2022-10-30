import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] in = br.readLine().split(" ");
        int a = Integer.parseInt(in[0]);
        int b = Integer.parseInt(in[1]);
        if (b > a)
        {
            System.out.println("0");
            return;
        }
        if (b == a)
        {
            System.out.println("infinity");
            return;
        }
        int n = a - b;
        int max = (int) Math.sqrt(n);
        int sol = 0;
        for (int i = 1; i <= max; ++i)
        {
            if (n % i == 0)
            {
                if (i * i == n)
                {
                    if (i > b)
                        ++sol;
                }
                else
                {
                    if (i > b)
                        ++sol;
                    if (n / i > b)
                        ++sol;
                }
            }
        }
        System.out.println(sol);
    }
}