import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int s, n;
        String[] d1 = br.readLine().split(" ");
        s = Integer.parseInt(d1[0]);
        n = Integer.parseInt(d1[1]);
        Dragon[] x = new Dragon[n];
        for (int i = 0; i < n; ++i)
        {
            String[] d2 = br.readLine().split(" ");
            x[i] = new Dragon();
            x[i].x = Integer.parseInt(d2[0]);
            x[i].y = Integer.parseInt(d2[1]);
        }
        Arrays.sort(x);
        for (int i = 0; i < n; ++i)
        {
            if (s > x[i].x)
            {
                s += x[i].y;
            }
            else
            {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}

class Dragon implements Comparable<Dragon>
{
    int x, y;

    @Override
    public int compareTo(Dragon d)
    {
        return x - d.x;
    }
}