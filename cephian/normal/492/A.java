import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int i = 0;
        for (;;)
        {
            int tmp = ((i + 1) * (i + 2)) / 2;
            if (n - tmp < 0)
                break;
            n -= tmp;
            ++i;
        }
        System.out.println(i);
    }
}