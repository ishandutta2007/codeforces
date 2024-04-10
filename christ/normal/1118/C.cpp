#include <bits/stdc++.h>

using namespace std;

int grid[25][25];
int cnt[1005];

void quit(bool chk)
{
    if (!chk)
    {
        printf("NO\n");
        exit(0);
    }
}

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 0; x < n * n; x++)
    {
        int a;
        scanf("%i", &a);
        cnt[a]++;
    }
    deque<int> vals;
    deque<int> valOne, valTwo;
    for (int x = 0; x < 1005; x++)
    {
        while (cnt[x] >= 4)
            vals.push_back(x), cnt[x] -= 4;
        if (cnt[x] == 1)
            valOne.push_back(x);
        else if (cnt[x] == 2)
            valTwo.push_back(x);
        else if (cnt[x] == 3)
            valOne.push_back(x), valTwo.push_back(x);
    }
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (grid[x][y]) continue;
            if (x == n-x-1)
            {
                if (y == n-y-1)
                {
                    quit(!valOne.empty());
                    grid[x][y] = valOne.front();
                    valOne.pop_front();
                }
                else
                {
                    if (valTwo.empty())
                    {
                        quit(!vals.empty());
                        grid[x][n-y-1] = grid[x][y] =  vals.front();
                        valTwo.push_back(vals.front());
                        vals.pop_front();
                    }
                    else
                        grid[x][n-y-1] = grid[x][y] = valTwo.front(), valTwo.pop_front();
                }
            }
            else if (y == n-y-1)
            {
                if (valTwo.empty())
                {
                    quit(!vals.empty());
                    grid[n-x-1][y] = grid[x][y] = vals.front();
                    valTwo.push_back(vals.front());
                    vals.pop_front();
                }
                else
                    grid[n-x-1][y] = grid[x][y] = valTwo.front(), valTwo.pop_front();
            }
            else
            {
                quit(!vals.empty());
                grid[x][y] = grid[n-x-1][y] = grid[x][n-y-1] = grid[n-x-1][n-y-1] = vals.front();
                vals.pop_front();
            }
        }
    }
    printf("YES\n");
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            printf("%i%c", grid[x][y], y == n-1 ? '\n' : ' ');
}