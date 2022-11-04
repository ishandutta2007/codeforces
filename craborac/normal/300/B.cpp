#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n, m;
int used[50];
int used2[50];
int ans[50];
int col[50];
int mas[50][50];

int go(int v, int q)
{
    int col = 1;
    used[v] = 1;
    ans[v] = q;
    for(int i = 0; i < n; i++)
    {
        if((mas[v][i] == 1) && (used[i] == 0))
            col += go(i, q);
    }
    return col;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            mas[i][j] = 0;
        col[i] = 0;
        used[i] = 0;
        used2[i] = 0;
        ans[i] = 0;
        col[i] = 0;
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
    int q = 1;
    int col1 = 0;
    int col2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0)
        {
            int coll = go(i, q);
            col[ans[i]] = coll;
            q++;
            if(coll > 3)
            {
                cout << "-1";
                return 0;
            }
            if(coll == 2)
            {
                col2++;
            }
            if(coll == 1)
            {
                col1++;
            }
        }
    }
    if(col2 > col1)
    {
        printf("-1");
        return 0;
    }
    for(int i = 0; i <= n; i++)
    {
        used2[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        if(used2[ans[i]] == 0)
        {
            //used2[ans[i]] = 1;
            if(col[ans[i]] == 3)
            {
                used2[ans[i]] = 1;
                for(int j = 0; j < n; j++)
                    if(ans[j] == ans[i])
                        cout << j + 1 << " ";
                cout << "\n";
            }
            else if(col[ans[i]] == 2)
            {
                used2[ans[i]] = 1;
                for(int j = 0; j < n; j++)
                    if(ans[j] == ans[i])
                        cout << j + 1 << " ";
                for(int j = 0; j < n; j++)
                {
                    if((used2[ans[j]] == 0) && (col[ans[j]] == 1))
                    {
                        used2[ans[j]] = 1;
                        cout << j + 1 << "\n";
                        break;
                    }
                }
            }
        }
    }
    int coll = 0;

    for(int i = 0; i < n; i++)
    {
        if(used2[ans[i]] == 0)
        {
            coll++;
            cout << i + 1;
            if(coll < 3)
                cout << " ";
            else
            {
                cout << "\n";
                coll = 0;
            }
        }
    }

    return 0;
}