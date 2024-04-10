import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char dir = br.readLine().charAt(0);
        char[] seq = br.readLine().toCharArray();
        for (int i = 0; i < seq.length; ++i)
            seq[i] = shift(seq[i], dir);
        System.out.println(new String(seq));
    }

    public static char shift(char c, char dir)
    {
        char[] keys = new char[] { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k',
                'l', ';', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/' };
        for (int i = 0; i < keys.length; ++i)
        {
            if (keys[i] == c)
            {
                if (dir == 'L')
                    return keys[i + 1];
                return keys[i - 1];
            }
        }
        return '0';
    }
}