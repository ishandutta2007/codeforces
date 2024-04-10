import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nk = br.readLine().split(" ");
        int k = Integer.parseInt(nk[1]);
        String[] scores = br.readLine().split(" ");
        int[] sco = new int[scores.length];
        for (int i = 0; i < scores.length; ++i)
            sco[i] = Integer.parseInt(scores[i]);
        int i = 0;
        int tot = 0;
        for (; i < k; ++i)
        {
            if (sco[i] <= 0)
            {
                ++i;
                break;
            }
            ++tot;
        }
        if (sco[i - 1] > 0)
        {
            for (int j = i; j < sco.length; ++j)
            {
                if (sco[j] == sco[i - 1])
                    ++tot;
                else
                    break;
            }
        }
        System.out.println(tot);
    }
}