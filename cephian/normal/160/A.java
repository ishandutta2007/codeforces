import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        String[] sv = br.readLine().split(" ");
        int tot = 0;
        int[] vals = new int[sv.length];
        for (int i = 0; i < sv.length; ++i)
        {
            int tmp = Integer.parseInt(sv[i]);
            tot += tmp;
            vals[i] = tmp;
        }
        Arrays.sort(vals);
        int bound = tot / 2;
        int take = 0;
        int tnum = 0;
        for (int i = vals.length - 1; i >= 0; --i)
        {
            take += vals[i];
            ++tnum;
            if (take > bound)
                break;
        }
        System.out.println(tnum);
    }
}