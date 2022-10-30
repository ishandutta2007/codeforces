import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws NumberFormatException, IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long in = Long.parseLong(br.readLine())+1;
        if (in % 2 == 0)
            in = -in;
        System.out.println(in / 2);
    }
}