import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws NumberFormatException, IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] tmp = br.readLine().split(" ");

        int n, m;
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        boolean[][] grid = new boolean[n][m];
        int i = 0, j = 0;
        boolean right = true;
        while (i < n)
        {
            grid[i][j] = true;
            if (right && j == m - 1)
            {
                right = false;
                i += 2;
                if (i < n)
                {
                    grid[i - 1][j] = true;
                    grid[i][j] = true;
                }

            }
            else if (!right && j == 0)
            {
                right = true;
                i += 2;
                if (i < n)
                {
                    grid[i - 1][j] = true;
                    grid[i][j] = true;
                }
            }
            else
            {
                if (right)
                    ++j;
                else
                    --j;
            }
        }
        for (int k = 0; k < grid.length; k++)
        {
            for (int k2 = 0; k2 < grid[0].length; k2++)
            {
                if (grid[k][k2])
                    sb.append('#');
                else
                    sb.append('.');
            }
            sb.append('\n');
        }
        System.out.print(sb);
    }
}