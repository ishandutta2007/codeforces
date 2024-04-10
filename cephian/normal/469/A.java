import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws NumberFormatException, IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[] lvl = new boolean[n];

        String[] X = br.readLine().split(" ");
        String[] Y = br.readLine().split(" ");
        for (int i = 1; i < X.length; ++i)
        {
            int ind = Integer.parseInt(X[i]);
            lvl[ind - 1] = true;
        }
        for (int i = 1; i < Y.length; ++i)
        {
            int ind = Integer.parseInt(Y[i]);
            lvl[ind - 1] = true;
        }
        for (boolean b : lvl)
        {
            if (!b)
            {
                System.out.println("Oh, my keyboard!");
                return;
            }
        }
        System.out.println("I become the guy.");
    }
}