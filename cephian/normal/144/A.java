import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        int max_i = -1, max = 0;
        int min_i = -1, min = 999999;
        String[] sold = br.readLine().split(" ");
        for (int i = 0; i < sold.length; ++i)
        {
            int num = Integer.parseInt(sold[i]);
            if (num > max)
            {
                max_i = i;
                max = num;
            }
            if (num <= min)
            {
                min_i = i;
                min = num;
            }
        }
        int s = max_i + (sold.length - 1 - min_i);
        if (max_i > min_i)
            --s;
        System.out.println(s);
    }
}