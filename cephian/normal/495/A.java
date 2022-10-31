import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static int[][] nums = new int[][] { { 1, 1, 1, 0, 1, 1, 1 }, { 0, 0, 1, 0, 0, 1, 0 }, { 1, 0, 1, 1, 1, 0, 1 },
            { 1, 0, 1, 1, 0, 1, 1 }, { 0, 1, 1, 1, 0, 1, 0 }, { 1, 1, 0, 1, 0, 1, 1 }, { 1, 1, 0, 1, 1, 1, 1 },
            { 1, 0, 1, 0, 0, 1, 0 }, { 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 0, 1, 1 } };

    public static void main(String[] args)
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try
        {
            String line = br.readLine();
            System.out.println(count(line.charAt(0) - '0') * count(line.charAt(1) - '0'));

        }
        catch (IOException e)
        {

        }
    }

    public static int count(int a)
    {
        int ct = 0;
        for (int i = 0; i < 10; ++i)
            if (contains(i, a))
                ++ct;
        return ct;
    }

    static boolean contains(int a, int b)
    {
        for (int i = 0; i < 7; ++i)
        {
            if (nums[b][i] == 1 && nums[a][i] == 0)
                return false;
        }
        return true;
    }
}