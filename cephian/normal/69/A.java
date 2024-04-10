import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; ++i)
        {
            String[] inp = br.readLine().split(" ");
            a += Integer.parseInt(inp[0]);
            b += Integer.parseInt(inp[1]);
            c += Integer.parseInt(inp[2]);
        }
        if (a == 0 && b == 0 && c == 0)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}