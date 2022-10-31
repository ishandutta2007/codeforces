import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] names = new String[] { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
        int gone = 5;
        int pow = 1;
        while (gone < n)
        {
            n -= gone;
            pow *= 2;
            gone *= 2;
        }
        System.out.println(names[(n - 1) / pow]);
    }
}