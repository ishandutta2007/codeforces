import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());
        int[] ways = new int[] { a + b + c, a + (b * c), (a + b) * c, (a * b) + c, a * (b + c), a * b * c };
        int max = 0;
        for (int i = 0; i < ways.length; ++i)
            if (ways[i] > max)
                max = ways[i];
        System.out.println(max);
    }
}