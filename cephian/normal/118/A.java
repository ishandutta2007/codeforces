import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        str = str.toLowerCase().replace("a", "").replace("o", "").replace("y", "").replace("e", "").replace("u", "")
                .replace("i", "");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length(); ++i)
        {
            sb.append(".");
            sb.append(str.charAt(i));
        }
        System.out.println(sb);
    }
}