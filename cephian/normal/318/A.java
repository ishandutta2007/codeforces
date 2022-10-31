import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] dat = br.readLine().split(" ");
        long n = Long.parseLong(dat[0]);
        long k = Long.parseLong(dat[1]);
        long trans;
        if (n % 2 == 1)
            trans = (n + 3) / 2;
        else
            trans = n / 2 + 1;

        if (k < trans)
            System.out.println(2 * k - 1);
        else
            System.out.println((k - trans + 1) * 2);
    }
}