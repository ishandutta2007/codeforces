import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb1 = new StringBuilder(br.readLine());
        String s2 = br.readLine();
        if (sb1.reverse().toString().equals(s2))
            System.out.println("YES");
        else
            System.out.println("NO");
    }

}