import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] d1 = br.readLine().split(" ");
        int m = Integer.parseInt(d1[0]);
        String[] inp = br.readLine().split(" ");
        int[] data = new int[inp.length];
        for (int i = 0; i < data.length; ++i)
            data[i] = Integer.parseInt(inp[i]);
        Arrays.sort(data);
        int dif = data[inp.length - 1] - data[0];
        for (int i = 0; i < data.length - m + 1; ++i)
        {
            int tmp = data[i + m - 1] - data[i];
            if (tmp < dif)
                dif = tmp;
        }
        System.out.println(dif);
    }
}