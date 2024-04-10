import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;

public class Main
{
    public static void main(String[] args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = 0;
        char[] nums = null;
        try
        {
            n = Integer.parseInt(br.readLine());
            nums = br.readLine().toCharArray();
        }
        catch (IOException e)
        {
        }
        TreeSet<String> ops = new TreeSet<String>();
        for (int i = 0; i < n; ++i)
        {
            StringBuilder str = new StringBuilder();
            for (int j = i;; j = (j + 1) % n)
            {
                char c = (char) (nums[j] - (nums[i] % '0'));
                if (c < '0')
                    c += 10;
                str.append(c);
                if (j == (i - 1 + n) % n)
                    break;
            }
            ops.add(str.toString());
        }
        System.out.println(ops.first());
    }
}