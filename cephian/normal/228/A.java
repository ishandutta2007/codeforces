import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] hs = br.readLine().split(" ");
        int num = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = i + 1; j < 4; ++j)
                if (hs[i].equals(hs[j]))
                {
                    ++num;
                    break;
                }
        System.out.println(num);
    }
}