#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n, m, q, go[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector <pair <int, int> > f(int x, int y)
{
    vector <pair <int, int> > re;
    for(int i=0; i<4; i++)
    {
        int nx=x+go[i][0], ny=y+go[i][1];
        if(nx>=0 and nx<n and ny>=0 and ny<m) re.push_back({nx, ny});
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>q;
    char fi[n][m+1];
    for(int a=0; a<n; a++) scanf("%s", fi[a]);
    int d[n][m];
    queue <pair <int, int> > qu;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            vector <pair <int, int> > ne=f(a, b);
            d[a][b]=inf;
            for(int c=0; c<ne.size(); c++)
            {
                if(fi[a][b]==fi[ne[c].first][ne[c].second]) d[a][b]=0;
            }
            if(d[a][b]==0) qu.push({a, b});
        }
    }
    while(qu.size())
    {
        int x=qu.front().first, y=qu.front().second;
        vector <pair <int, int> > ne=f(x, y);
        for(int a=0; a<ne.size(); a++)
        {
            int nx=ne[a].first, ny=ne[a].second;
            if(d[nx][ny]==inf)
            {
                d[nx][ny]=d[x][y]+1;
                qu.push({nx, ny});
            }
        }
        qu.pop();
    }
    for(int a=0; a<q; a++)
    {
        int x, y;
        long long p;
        scanf("%d%d%lld", &x, &y, &p);
        x--, y--;
        int va=fi[x][y]-'0';
        if(d[x][y]!=inf and d[x][y]<p)
        {
            va^=((p-d[x][y])&1);
        }
        printf("%d\n", va);
    }
}