#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>


using namespace std;

int k, n, m;
string s[15][15];
int used[15][15][15];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

bool check(int x, int y, int z)
{
    return ((x >= 0) && (x < n) && (y >= 0) && (y < m) && (z >= 0) && (z < k) && (s[z][x][y] == '.')); 
}

void dfs(int x, int y, int z)
{
    if(used[x][y][z] == 1)
        return;
    used[x][y][z] = 1;
    for(int i = 0; i < 6; i++)
        if(check(x + dx[i], y + dy[i], z + dz[i]))
            dfs(x + dx[i], y + dy[i], z + dz[i]);
}

int main()
{
    cin >> k >> n >> m;
    for(int z = 0; z < k; z++)
        for(int x = 0; x < n; x++)
        {
            cin >> s[z][x];
            for(int y = 0; y < m; y++)
                used[x][y][z] = 0;
        }
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    dfs(x, y, 0);
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int q = 0; q < k; q++)
                ans += used[i][j][q];
    cout << ans;

    return 0;
}