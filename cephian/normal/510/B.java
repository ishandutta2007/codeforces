import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    static boolean[][] visited;
    static int[][] grid;
    static int[][] time;
    static int counter = 0;
    static boolean cycle = false;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");
        int pt = 0;
        int n = Integer.parseInt(tmp[0]);
        int m = Integer.parseInt(tmp[1]);

        grid = new int[n][m];
        visited = new boolean[n][m];
        time = new int[n][m];

        while (pt < m * n)
        {
            int c;
            if (!Character.isAlphabetic(c = br.read()))
                continue;
            grid[pt / m][pt % m] = c;
            ++pt;
        }

        for (int i = 0; i < grid.length; i++)
        {
            for (int j = 0; j < grid[0].length; j++)
            {
                if (!visited[i][j])
                    DFSfind(i, j, -15, -15);
                if (cycle)
                {
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");

    }

    public static void DFSfind(int i, int j, int oldx, int oldy)
    {
        //System.out.println(i + ", " + j + " : " + oldx + ", " + oldy);
        visited[i][j] = true;
        time[i][j] = counter;
        ++counter;

        recurse(i + 1, j, i, j, oldx, oldy);
        recurse(i - 1, j, i, j, oldx, oldy);
        recurse(i, j + 1, i, j, oldx, oldy);
        recurse(i, j - 1, i, j, oldx, oldy);
    }

    public static void recurse(int x, int y, int i, int j, int oldx, int oldy)
    {
        if (ok(x, y))
        {
            if (grid[x][y] == grid[i][j])
            {
                if (!visited[x][y])
                    DFSfind(x, y, i, j);
                else if (x != oldx && y != oldy)
                {
                    //System.out.println("--->" + x + ", " + y + " : " + i + ", " + j);
                    cycle = true;
                }
            }
        }
    }

    public static boolean ok(int i, int j)
    {
        return i >= 0 && i < grid.length && j >= 0 && j < grid[0].length;
    }
}