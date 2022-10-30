import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader b = new BufferedReader(new InputStreamReader(System.in));
        char[] arr = b.readLine().toCharArray();
        for (int i = 0; i < arr.length; ++i)
        {
            if (arr[i] == 'H' || arr[i] == 'Q' || arr[i] == '9')
            {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}