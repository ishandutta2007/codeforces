import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        char[] let = br.readLine().toCharArray();
        char prev = 'Q';
        int len = 1;
        int tot = 0;
        for (int i = 0; i < let.length; ++i)
        {
            if (let[i] != prev)
            {
                prev = let[i];
                tot += len - 1;
                len = 1;
            }
            else
                ++len;
        }
        tot += len - 1;
        System.out.println(tot);
    }
}