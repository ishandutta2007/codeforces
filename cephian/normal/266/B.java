import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inp = br.readLine().split(" ");
        int n = Integer.parseInt(inp[0]);
        int t = Integer.parseInt(inp[1]);
        char[] arr = br.readLine().toCharArray();
        for (int i = 0; i < t; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                if (arr[j] == 'B' && arr[j + 1] == 'G')
                {
                    arr[j] = 'G';
                    arr[j + 1] = 'B';
                    ++j;
                }
            }
        }
        System.out.println(new String(arr));
    }
}