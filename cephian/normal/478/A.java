import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inp = br.readLine().split(" ");
        int sum = 0;
        for (int i = 0; i < inp.length; ++i)
            sum += Integer.parseInt(inp[i]);
        if (sum != 0 && sum % 5 == 0)
            System.out.println(sum / 5);
        else
            System.out.println("-1");
    }
}