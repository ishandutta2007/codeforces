import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws NumberFormatException, IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        System.out.println(get(n-1,n-1));
    }
    
    static int get(int x, int y)
    {
        if(x<0 || y < 0)
            return 0;
        if(x==0 || y==0)
            return 1;
        return get(x-1, y) + get(x, y-1);
    }
}