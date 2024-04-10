import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int i = br.readLine().toLowerCase().compareTo(br.readLine().toLowerCase());
        if (i < 0)
            System.out.println("-1");
        else if (i > 0)
            System.out.println("1");
        else
            System.out.println("0");
    }
}