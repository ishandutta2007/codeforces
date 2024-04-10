import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n1 = 0, n2 = 0, n3 = 0;
        int total = 0;
        br.readLine();
        String[] gr = br.readLine().split(" ");
        for (String str : gr)
        {
            if (str.equals("1"))
                ++n1;
            else if (str.equals("2"))
                ++n2;
            else if (str.equals("3"))
                ++n3;
            else
                ++total;
        }
        total += n2 / 2;
        n2 = (n2 % 2 == 0) ? 0 : 1;
        if (n3 >= n1)
        {
            total += n3;
            n1 = 0;
        }
        else
        {
            n1 -= n3;
            total += n3;
        }
        if (n2 == 1)
        {
            ++total;
            n1 = Math.max(n1 - 2, 0);
        }
        if (n1 != 0)
            total += (n1 % 4 == 0) ? n1 / 4 : n1 / 4 + 1;
        System.out.println(total);
    }
}