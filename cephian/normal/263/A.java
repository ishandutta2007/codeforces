import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int ans = 0;
        for (int i = 0; i < 5; ++i)
        {
            String[] row = br.readLine().split(" ");
            for (int j = 0; j < 5; ++j)
                if (row[j].equals("1"))
                    ans = Math.abs(2 - i) + Math.abs(2 - j);
        }
        System.out.println(ans);
    }
}