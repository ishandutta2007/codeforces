#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, r, c, x, y, used[2005][2005];
char a[2005][2005];
queue <pair <pair <int, int>, pair <int, int> > > q;

void dfs(int i, int j, int X, int Y)
{
    if(X<0 || Y<0 || a[i][j]!='.' || used[i][j]==1)
        return;
    used[i][j]=1;

    if(j-1>=0 && used[i][j-1]==0)
        q.push({{i, j-1}, {X-1, Y}});
    if(j+1<m && used[i][j+1]==0)
        q.push({{i, j+1}, {X, Y-1}});
    if(i-1>=0 && used[i-1][j]==0)
        dfs(i-1, j, X, Y);
    if(i+1>=0 && used[i+1][j]==0)
        dfs(i+1, j, X, Y);
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m >> r >> c >> x >> y;
    r--;
    c--;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];

    q.push({ make_pair(r, c), make_pair(x, y) });
    while(!q.empty())
    {
        pair <pair <int, int>, pair <int, int> > p=q.front();
        dfs(p.first.first, p.first.second, p.second.first, p.second.second);
        q.pop();
    }

    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(used[i][j])
                ans++;
    cout << ans;
}