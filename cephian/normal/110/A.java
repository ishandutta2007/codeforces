import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] ch = br.readLine().toCharArray();
        int ld = 0;
        for(char c:ch)
        if(c=='4'||c=='7')
            ++ld;
        if(isLucky(ld))
            System.out.println("YES");
        else
            System.out.println("NO");
    }

    public static boolean isLucky(int n)
    {
        char[] ch = (n + "").toCharArray();
        for (char c : ch)
            if (c != '4' && c != '7')
                return false;
        return true;
    }
}