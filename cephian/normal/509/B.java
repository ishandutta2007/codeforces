import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split("\\s+");
        int n = Integer.parseInt(tmp[0]), m = Integer.parseInt(tmp[1]);
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        tmp = br.readLine().split(" ");
        for (int i = 0; i < n; ++i)
        {
            int j = Integer.parseInt(tmp[i]);
            max = Math.max(max, j);
            min = Math.min(min, j);
        }
        if (max - min <= m)
            System.out.println("YES");
        else
        {
            System.out.println("NO");
            return;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; ++i)
        {
            int k = Integer.parseInt(tmp[i]);
            for (int j = 0; j < k; ++j)
            {
                sb.append(((j % m) + 1));
                if (j != k - 1)
                    sb.append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}