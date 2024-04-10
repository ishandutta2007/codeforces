import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int g = 1;
        char last = 'Q';
        for (int i = 0; i < n; ++i)
        {
            String st = br.readLine();
            if (last == st.charAt(0))
                ++g;
            last = st.charAt(1);
        }
        System.out.println(g);
    }
}