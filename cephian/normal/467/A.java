import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int tot = 0;
        for (int i = 0; i < n; ++i)
        {
            String[] vals = br.readLine().split(" ");
            if (Integer.parseInt(vals[1]) - Integer.parseInt(vals[0]) >= 2)
                ++tot;
        }
        System.out.println(tot);
    }
}