import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] play = br.readLine().toCharArray();
        int len = 0;
        int prev = 'Q';
        for (int i = 0; i < play.length; ++i)
        {
            if (play[i] != prev)
            {
                len = 1;
                prev = play[i];
            }
            else
            {
                ++len;
                if (len == 7)
                {
                    System.out.println("YES");
                    return;
                }
            }
        }
        if (len == 7)
        {
            System.out.println("YES");
            return;
        }
        System.out.println("NO");
    }
}