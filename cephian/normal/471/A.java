import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] dat = br.readLine().split(" ");
        int[] id = new int[6];
        for (int i = 0; i < 6; ++i)
            id[i] = Integer.parseInt(dat[i]);
        int[] sticks = new int[10];
        for (int i : id)
            sticks[i]++;
        boolean bk = false;
        for (int i = 1; i < 10; ++i)
        {
            if (sticks[i] >= 4)
            {
                sticks[i] -= 4;
                bk = true;
                break;
            }
        }
        if (!bk)
        {
            System.out.println("Alien");
            return;
        }
        for (int i = 1; i < 10; ++i)
        {
            if (sticks[i] == 2)
            {
                System.out.println("Elephant");
                return;
            }
        }
        System.out.println("Bear");
    }
}