import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] dat = br.readLine().split(" ");
        int pol = 0;
        int crm = 0;
        for (int i = 0; i < dat.length; ++i)
        {
            if (dat[i].equals("-1"))
            {
                if (pol > 0)
                    --pol;
                else
                    ++crm;
            }
            else
            {
                pol += Integer.parseInt(dat[i]);
            }
        }
        System.out.println(crm);
    }
}