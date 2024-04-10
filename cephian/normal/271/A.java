import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int y = Integer.parseInt(br.readLine()) + 1;
        for (; !isdist(y); ++y)
        {

        }
        System.out.println(y);
    }

    public static boolean isdist(int n)
    {
        char[] ch = (n + "").toCharArray();
        for (int i = 0; i < ch.length - 1; ++i)
        {
            for (int j = i + 1; j < ch.length; ++j)
                if (ch[i] == ch[j])
                    return false;
        }
        return true;
    }
}