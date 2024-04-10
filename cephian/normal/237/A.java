import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main
{
    public static void main(String[] args) throws NumberFormatException, IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        HashMap<String, Integer> hm = new HashMap<String, Integer>();
        int num = 1;
        for (int i = 0; i < n; ++i)
        {
            String tmp = br.readLine();
            if (hm.containsKey(tmp))
                hm.put(tmp, hm.get(tmp) + 1);
            else
                hm.put(tmp, 1);
        }
        int max = 0;
        for (int i : hm.values())
            if (i > max)
                max = i;
        System.out.println(max);
    }
}

class Pers
{

}