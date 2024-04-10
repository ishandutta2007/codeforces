import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] as = br.readLine().split(" ");
        String[] bs = br.readLine().split(" ");
        int n = Integer.parseInt(br.readLine());
        int a = Integer.parseInt(as[0]) + Integer.parseInt(as[1]) + Integer.parseInt(as[2]);
        int b = Integer.parseInt(bs[0]) + Integer.parseInt(bs[1]) + Integer.parseInt(bs[2]);
        n -= a / 5 + b / 10 + ((a % 5 == 0) ? 0 : 1) + ((b % 10 == 0) ? 0 : 1);
        if (n < 0)
            System.out.println("NO");
        else
            System.out.println("YES");
    }
}