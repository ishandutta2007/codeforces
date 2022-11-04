#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>


using namespace std;

int mas[8][8][30];
string s[8];
int n = 8;

bool check(int x, int y, int v)
{
    if((x < 0) || (x >= n) || (y < 0) || (y >= n))
        return false;
    if(v <= x)
        if(s[x - v][y] == 'S')
            return false;
    if(v <= x + 1)
        if(s[x - v + 1][y] == 'S')
            return false;
    return true;
}

void dfs(int x, int y, int v)
{
    if(v >= 30)
        return;
    if(mas[x][y][v] == 1)
        return;
    mas[x][y][v] = 1;
    for(int dx = -1; dx < 2; dx++)
        for(int dy = -1; dy < 2; dy++)
            if(check(x + dx, y + dy, v + 1))
                dfs(x + dx, y + dy, v + 1);
}

int main()
{
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int q = 0; q < 30; q++)
                mas[i][j][q] = 0;
    dfs(7, 0, 0);
    string s = "LOSE";
    for(int i = 0; i < 30; i++)
        if(mas[0][7][i] == 1)
            s = "WIN";
    cout << s;

    return 0;
}