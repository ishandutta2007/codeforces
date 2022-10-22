#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi

using namespace std;

int n, m, t, a[1005][1005], used[1005][1005], b[1005][1005];
char c;
queue <pair <int, pair <int, int> > > q;

void dfs(int x, int y, int d)
{
    used[x][y]=1;
    b[x][y]=d;
    q.push({x, {y, d}});

    if(x+1<n && used[x+1][y]==0 && a[x][y]==a[x+1][y])
        dfs(x+1, y, d);
    if(x-1>=0 && used[x-1][y]==0 && a[x][y]==a[x-1][y])
        dfs(x-1, y, d);
    if(y+1<m && used[x][y+1]==0 && a[x][y]==a[x][y+1])
        dfs(x, y+1, d);
    if(y-1>=0 && used[x][y-1]==0 && a[x][y]==a[x][y-1])
        dfs(x, y-1, d);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        cin >> c;
        a[i][j]=c-'0';
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        int f=0;
        if(i!=0 && a[i-1][j]==a[i][j])
            f=1;
        if(i!=n-1 && a[i+1][j]==a[i][j])
            f=1;
        if(j!=0 && a[i][j-1]==a[i][j])
            f=1;
        if(j!=m-1 && a[i][j+1]==a[i][j])
            f=1;
        if(f==1)
        {
            dfs(i, j, 0);
        }
    }

    if(q.empty())
    {
        while(t--)
        {
            int x, y, d;
            cin >> x >> y >> d;
            x--;
            y--;
            cout << a[x][y] << "\n";
        }
        return 0;
    }

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second.first;
        int d=q.front().second.second;

        if(x!=0 && used[x-1][y]==0)
            dfs(x-1, y, d+1);
        if(x!=n-1 && used[x+1][y]==0)
            dfs(x+1, y, d+1);
        if(y!=0 && used[x][y-1]==0)
            dfs(x, y-1, d+1);
        if(y!=m-1 && used[x][y+1]==0)
            dfs(x, y+1, d+1);

        q.pop();
    }

    while(t--)
    {
        int x, y, d;
        cin >> x >> y >> d;
        x--;
        y--;
        if(b[x][y]>=d)
            cout << a[x][y] << "\n";
        else if((d-b[x][y])%2==0)
            cout << a[x][y] << "\n";
        else cout << 1-a[x][y] << "\n";
    }
}