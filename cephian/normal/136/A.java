import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        String[] vals = br.readLine().split(" ");
        int[] who = new int[vals.length];
        for (int i = 0; i < vals.length; ++i)
            who[Integer.parseInt(vals[i]) - 1] = i + 1;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < who.length; ++i)
        {
            sb.append(who[i]);
            if (i != who.length - 1)
                sb.append(" ");
        }
        System.out.println(sb + "\n");
    }
}