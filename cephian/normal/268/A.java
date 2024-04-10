import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] grid = new int[n][];
        for (int i = 0; i < n; ++i)
        {
            grid[i] = new int[2];
            String[] tmp = br.readLine().split(" ");
            grid[i][0] = Integer.parseInt(tmp[0]);
            grid[i][1] = Integer.parseInt(tmp[1]);
        }
        int count = 0;
        for (int i = 0; i < grid.length - 1; ++i)
        {
            for (int j = i + 1; j < grid.length; ++j)
            {
                if (grid[i][0] == grid[j][1])
                    ++count;
                if (grid[i][1] == grid[j][0])
                    ++count;
            }
        }
        System.out.println(count);
    }
}