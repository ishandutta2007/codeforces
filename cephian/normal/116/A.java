import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int max = 0;
        int train = 0;
        for (int i = 0; i < n; ++i)
        {
            String[] tmp = br.readLine().split(" ");
            train = train - Integer.parseInt(tmp[0]) + Integer.parseInt(tmp[1]);
            if (train > max)
                max = train;
        }
        System.out.println(max);
    }
}