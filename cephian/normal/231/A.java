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
            String[] tmp = br.readLine().split(" ");
            int num = 0;
            for (int j = 0; j < 3; ++j)
            {
                if (tmp[j].equals("1"))
                    ++num;
                if (num == 2)
                {
                    ++tot;
                    break;
                }
            }

        }
        System.out.println(tot);
    }
}