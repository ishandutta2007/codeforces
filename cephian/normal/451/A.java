import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inp = br.readLine().split(" ");
        int n = Integer.parseInt(inp[0]);
        int m = Integer.parseInt(inp[1]);
        int inter = n * m;
        boolean turn = false;
        while (inter != 0)
        {
            if (n > m)
            {
                inter -= n;
                --m;
            }
            else
            {
                inter -= m;
                --n;
            }
            turn = !turn;
        }
        if (!turn)
            System.out.println("Malvika");
        else
            System.out.println("Akshat");
    }
}