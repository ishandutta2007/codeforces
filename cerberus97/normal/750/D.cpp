/*
Author : Cerberus97
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define fast_cin() ios_base::sync_with_stdio(false);

const int N = 40, X = 350, X_2 = X/2, DIR = 8;

int t[N];
bool seen[X][X][N][DIR] = {0};
bool grid[X][X];

void mark(int i, int j, int dist, int dir);
pii getCell(int i, int j, int dist, int dir);

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> t[i];

    t[1] -= 1;

    seen[X_2][X_2][1][0] = true;
    mark(X_2, X_2, t[1],0);

    for (int k = 2; k <= n; ++k)
    {
        for (int i = 0; i < X; ++i)
        {
            for (int j = 0; j < X; ++j)
            {
                for (int dir = 0; dir <= 8; ++dir)
                {
                    pii p1 = getCell(i,j,t[k-1],(dir+5)%8), p2 = getCell(i,j,t[k-1],(dir+3)%8);
                    seen[i][j][k][dir] = seen[p1.first][p1.second][k-1][(dir+1)%8] or seen[p2.first][p2.second][k-1][(dir+7)%8];

                    if (seen[i][j][k][dir])
                        mark(i,j,t[k],dir);
                }
            }
        }
    }

    int ans = 0;

    // for (int i = X_2 - 15; i < X_2 + 15; ++i)
    // {
    //     for (int j = X_2 - 15; j < X_2 + 15; ++j)
    //         cout << ((grid[j][i])?'X':' ');

    //     cout << endl;
    // }

    for (int i = 0; i < X; ++i)
    {
        for (int j = 0; j < X; ++j)
        {
            if (grid[i][j])
                ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}

void mark(int i, int j, int dist, int dir)
{
    grid[i][j] = 1;
    int i_ch = 0, j_ch = 0;

    if (dir >= 1 and dir <= 3)
        i_ch = 1;

    if (dir >= 5 and dir <= 7)
        i_ch = -1;

    if (dir == 0 or dir == 1 or dir == 7)
        j_ch = 1;

    if (dir >= 3 and dir <= 5)
        j_ch = -1;

    for (int k = 0; k < dist; ++k)
    {
        i += i_ch;
        j += j_ch;
        grid[i][j] = 1;
    }
}

pii getCell(int i, int j, int dist, int dir)
{
    int i_ch = 0, j_ch = 0;

    if (dir >= 1 and dir <= 3)
        i_ch = 1;

    if (dir >= 5 and dir <= 7)
        i_ch = -1;

    if (dir == 0 or dir == 1 or dir == 7)
        j_ch = 1;

    if (dir >= 3 and dir <= 5)
        j_ch = -1;

    for (int k = 0; k < dist; ++k)
    {
        i += i_ch;
        j += j_ch;
    }

    if (i < 0 or j < 0 or i >= X or j >= X)
        return {X-1, X-1};

    return {i,j};
}