import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String sb = "";
        int l = Integer.parseInt(br.readLine());
        int n = (l - 1) / 2;
        for (int i = 0; i < n + 1; ++i)
        {
            for (int j = 0; j < l; ++j)
            {
                int num = i - Math.abs(j - n);
                if (num < 0)
                    sb += "*";
                else
                    sb += "D";
            }
            sb += "\n";
        }
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = 0; j < l; ++j)
            {
                int num = i - Math.abs(j - n);
                if (num < 0)
                    sb += "*";
                else
                    sb += "D";
            }
            sb += "\n";
        }
        System.out.println(sb);
    }
}