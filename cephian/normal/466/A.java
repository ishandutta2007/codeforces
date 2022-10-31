import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] data = br.readLine().split(" ");
        int n = Integer.parseInt(data[0]);
        int m = Integer.parseInt(data[1]);
        int a = Integer.parseInt(data[2]);
        int b = Integer.parseInt(data[3]);
        if (a * m <= b)
        {
            System.out.println(a * n);
        }
        else
        {
            int rub = 0;
            while (n >= m)
            {
                rub += b;
                n -= m;
            }
            if (a * n < b)
                System.out.println(rub + a * (n % m));
            else
                System.out.println(rub + b);
        }
    }
}