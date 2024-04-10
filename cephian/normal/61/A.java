import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine();
        String s2 = br.readLine();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s1.length(); ++i)
        {
            if (s1.charAt(i) == s2.charAt(i))
                sb.append('0');
            else
                sb.append('1');
        }
        System.out.println(sb);
    }
}