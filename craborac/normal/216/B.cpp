#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>


using namespace std;

int mas[110][110];
int used[110];

int col1, col2;
int n;

void dfs(int v)
{
    used[v] = 1;
    col1++;
    int col = 0;
    for(int i = 0; i < n; i++)
    {
        if(mas[v][i] == 1)
        {
            col2++;
            if(used[i] == 0)
                dfs(i);
        }
    }
}

int main()
{
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            mas[i][j] = 0;
        used[i] = 0;
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mas[a][b] = 1;
        mas[b][a] = 1;
    }
    col1 = 0;
    col2 = 0;
    int k = 0;
    int l = 0;
    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0)
        {
            col1 = 0;
            col2 = 0;
            dfs(i);
            col2 /= 2;
            if(col1 % 2 == 1)
            {
                if(col2 == col1)
                    k++;
                else
                    l++;
            }
        }
    }
    cout << (k + (l % 2));

    return 0;
}