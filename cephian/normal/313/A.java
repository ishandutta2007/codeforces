import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] num = br.readLine().toCharArray();
        if (num[0] != '-')
            System.out.println(new String(num));
        else
        {
            if (num.length == 2)
                System.out.println("0");
            else
            {
                int i = num.length - 1;
                if (num[num.length - 2] > num[num.length - 1])
                    --i;
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < num.length; ++j)
                    if (j != i)
                        sb.append(num[j]);
                if (sb.toString().equals("-0"))
                    System.out.println("0");
                else
                    System.out.println(sb);
            }

        }

    }
}