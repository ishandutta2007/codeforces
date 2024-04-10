import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] word = null;
        try
        {
            word = br.readLine().toCharArray();
        }
        catch (IOException e)
        {
        }
        char[] hello = new char[] { 'h', 'e', 'l', 'l', 'o' };
        int ind = 0;
        int i = 0;
        while (ind != 5 && i < word.length)
        {
            if (word[i] == hello[ind])
                ++ind;
            ++i;
        }
        if (ind == 5)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}