import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    static boolean[][][] grids;

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = br.readLine().split(" ");

        int n, m;
        n = Integer.parseInt(tmp[0]);
        m = Integer.parseInt(tmp[1]);
        //color, v1, v2;
        grids = new boolean[m][n][n];
        for (int i = 0; i < m; ++i)
        {
            tmp = br.readLine().split(" ");

            int a, b, c;
            a = Integer.parseInt(tmp[0]) - 1;
            b = Integer.parseInt(tmp[1]) - 1;
            c = Integer.parseInt(tmp[2]) - 1;
            grids[c][a][b] = grids[c][b][a] = true;
        }

        //System.out.println(Arrays.deepToString(grids[0]));
        int q = Integer.parseInt(br.readLine());

        for (int i = 0; i < q; ++i)
        {
            tmp = br.readLine().split(" ");

            int u = Integer.parseInt(tmp[0]) - 1;
            int v = Integer.parseInt(tmp[1]) - 1;
            int nums = 0;
            for (int j = 0; j < m; ++j)
            {
                if (dfs(u, v, j, new boolean[n]))
                {
                    ++nums;
                }
            }
            System.out.println(nums);
        }
    }

    static boolean dfs(int a, int b, int c, boolean[] visited)
    {
        if (a == b)
            return true;
        visited[a] = true;
        for (int i = 0; i < grids[0].length; ++i)
        {
            if (grids[c][a][i] && !visited[i])
            {
                if (dfs(i, b, c, visited))
                    return true;
            }
        }
        return false;
    }
}