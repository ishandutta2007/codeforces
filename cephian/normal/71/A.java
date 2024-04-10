import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; ++i)
        {
            String tmp = br.readLine();
            if (tmp.length() > 10)
                sb.append("" + tmp.charAt(0) + (tmp.length() - 2) + tmp.charAt(tmp.length() - 1) + "\n");
            else
                sb.append(tmp + "\n");
        }
        System.out.println(sb);
    }
}