import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int l = 0, u = 0;
        for (char c : str.toCharArray())
        {
            if (Character.isUpperCase(c))
                ++u;
            else
                ++l;
        }
        if (u > l)
            System.out.println(str.toUpperCase());
        else
            System.out.println(str.toLowerCase());
    }
}