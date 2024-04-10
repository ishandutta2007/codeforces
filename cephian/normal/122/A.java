import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] luck = new int[] { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777 };
        for (int l : luck)
            if (n % l == 0)
            {
                System.out.println("YES");
                return;
            }
        System.out.println("NO");
    }
}