import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] vals = br.readLine().split(" ");
        int a = Integer.parseInt(vals[0]);
        int b = Integer.parseInt(vals[1]);
        int tot = 0;
        int used = 0;
        while (a != 0)
        {
            tot += a;
            used += a;
            a = used / b;
            used %= b;
        }
        System.out.println(tot);
    }
}