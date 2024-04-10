import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int x = 0;
        for (int i = 0; i < n; ++i)
        {
            if (br.readLine().contains("+"))
                ++x;
            else
                --x;
        }
        System.out.println(x);
    }
}