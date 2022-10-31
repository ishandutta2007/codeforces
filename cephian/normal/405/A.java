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
        String[] data = br.readLine().split(" ");
        int[] d2 = new int[data.length];
        for (int i = 0; i < d2.length; ++i)
            d2[i] = Integer.parseInt(data[i]);

        Arrays.sort(d2);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < d2.length; ++i)
        {
            sb.append(d2[i]);
            if (i != d2.length - 1)
                sb.append(" ");
        }
        System.out.println(sb);
    }
}