import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inp = br.readLine().split(" ");
        int x = Integer.parseInt(inp[0]);
        int y = Integer.parseInt(inp[1]);
        if (y % 2 == 0)
        {
            int tmp = y;
            y = x;
            x = tmp;
        }
        System.out.println((x / 2) * y + ((x % 2 == 1) ? y / 2 : 0));
    }
}