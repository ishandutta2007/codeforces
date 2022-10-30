import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] inp = br.readLine().split(" ");
        int max = Integer.parseInt(inp[0]);
        int min = max;
        int amz = 0;
        for (int i = 1; i < inp.length; ++i)
        {
            int tmp = Integer.parseInt(inp[i]);
            if (tmp > max)
            {
                ++amz;
                max = tmp;
            }
            if (tmp < min)
            {
                ++amz;
                min = tmp;
            }
        }
        System.out.println(amz);
    }
}