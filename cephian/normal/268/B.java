import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws NumberFormatException, IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int tot = n;
        for (int i = 1; i < n; ++i)
            tot += (n - i) * i;
        System.out.println(tot);
    }
}