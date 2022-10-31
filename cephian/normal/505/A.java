import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        String s = flipfirst(str);
        if (char1(str, s))
        {
            System.out.println(s);
            return;
        }
        s = flipfirst(reverse(str));
        if (char1(str, s))
        {
            System.out.println(s);
            return;
        }
        System.out.println("NA");
    }

    static String flipfirst(String str)
    {
        return str.substring(0, str.length() / 2 + str.length() % 2)
                + ((str.length() % 2 == 0) ? (str.charAt(str.length() / 2)) : (""))
                + reverse(str.substring(0, str.length() / 2 + str.length() % 2));
    }

    static String reverse(String str)
    {
        return new StringBuilder(str).reverse().toString();
    }

    public static boolean char1(String s1, String s2)
    {
        for (int i = 0; i < s2.length(); ++i)
        {
            if (s1.equals(s2.substring(0, i) + s2.substring(i + 1)))
                return true;
        }
        return false;
    }
}