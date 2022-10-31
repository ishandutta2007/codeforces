import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] s1 = br.readLine().toCharArray();
        char[] s2 = br.readLine().toCharArray();
        char[] s3 = br.readLine().toCharArray();
        l: for (char c : s1)
        {
            for (int i = 0; i < s3.length; ++i)
            {
                if (s3[i] == c)
                {
                    s3[i] = '.';
                    continue l;
                }
            }
            System.out.println("NO");
            return;
        }

        l: for (char c : s2)
        {
            for (int i = 0; i < s3.length; ++i)
            {
                if (s3[i] == c)
                {
                    s3[i] = '.';
                    continue l;
                }
            }
            System.out.println("NO");
            return;
        }

        for (int i = 0; i < s3.length; ++i)
        {
            if (s3[i] != '.')
            {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}