import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] lets = br.readLine().toCharArray();
        int n1 = 0, n2 = 0, n3 = 0;
        for (int i = 0; i < lets.length; i += 2)
        {
            if (lets[i] == '1')
                ++n1;
            else if (lets[i] == '2')
                ++n2;
            else if (lets[i] == '3')
                ++n3;
        }
        StringBuilder sb = new StringBuilder();
        while (n1 > 0)
        {
            sb.append("1+");
            --n1;
        }
        while (n2 > 0)
        {
            sb.append("2+");
            --n2;
        }
        while (n3 > 0)
        {
            sb.append("3+");
            --n3;
        }
        String str = sb.toString();
        System.out.println(str.substring(0, str.length() - 1));
    }
}