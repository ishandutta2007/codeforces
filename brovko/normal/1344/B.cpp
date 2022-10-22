#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, f, used[1005][1005];
char a[1005][1005];

void dfs(int i, int j)
{
    if(a[i][j]=='#')
    {
        used[i][j]=1;
        if(i<n-1 && used[i+1][j]==0)
            dfs(i+1, j);
        if(i>0 && used[i-1][j]==0)
            dfs(i-1, j);
        if(j<m-1 && used[i][j+1]==0)
            dfs(i, j+1);
        if(j>0 && used[i][j-1]==0)
            dfs(i, j-1);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    int F=0;

    for(int i=0;i<n;i++)
    {
        f=0;
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='#')
                f=1;
            if(f==1 && a[i][j]=='.' && a[i][j+1]=='#')
            {
                cout << -1;
                return 0;
            }
        }

        if(f==0)
            F|=1;
    }

    for(int j=0;j<m;j++)
    {
        f=0;
        for(int i=0;i<n;i++)
        {
            if(a[i][j]=='#')
                f=1;

            if(f==1 && a[i][j]=='.' && a[i+1][j]=='#')
            {
                cout << -1;
                return 0;
            }
        }

        if(f==0)
            F|=2;
    }

    if(F==1 || F==2)
    {
        cout << -1;
        return 0;
    }

    int k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]=='#' && used[i][j]==0)
    {
        dfs(i, j);
        k++;
    }
    cout << k;
}