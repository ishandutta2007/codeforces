import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        char[] cha = str.toCharArray();

        for (int i = 1; i < cha.length; ++i)
        {
            if (Character.isLowerCase(cha[i]))
            {
                System.out.println(str);
                return;
            }
        }
        if (Character.isLowerCase(cha[0]))
            System.out.println(Character.toUpperCase(cha[0]) + str.substring(1, str.length()).toLowerCase());
        else
            System.out.println(str.toLowerCase());
    }
}