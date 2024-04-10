import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] dat = br.readLine().split(" ");
        int n = Integer.parseInt(dat[0]);
        int m = Integer.parseInt(dat[1]);
        int d = 0;
        while (n != 0)
        {
            ++d;
            --n;
            if (d % m == 0)
            {
                //System.out.println(d);
                ++n;
            }
        }
        System.out.println(d);
    }
}