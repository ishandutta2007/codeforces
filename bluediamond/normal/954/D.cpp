#include <bits/stdc++.h>

using namespace std;

const int N=1000;
int n,m,a,b;
vector<int>v[N+5];
int best[N+5][N+5];
queue<int>q;
bool mu[N+5][N+5];
void bfs(int x)
{
    for(int i=1;i<=n;i++)
        best[x][i]=-1;
    q.push(x);
    best[x][x]=0;
   // cout<<x<<" : ";
    while(!q.empty())
    {
        int nod=q.front();
        q.pop();
        //cout<<nod<<" ";
        for(int i=0;i<v[nod].size();i++)
        {
            int nod_nou=v[nod][i];
            if(best[x][nod_nou]==-1)
            {
                best[x][nod_nou]=best[x][nod]+1;
                q.push(nod_nou);
            }
        }
    }
   // cout<<"\n";
}
int main()
{
    cin>>n>>m>>a>>b;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        mu[x][y]=mu[y][x]=1;
    }
    for(int i=1;i<=n;i++)
    {
        bfs(i);
    }
    int ans=0;
    for(int x=1;x<=n;x++)
    {
        for(int y=x+1;y<=n;y++)
        {
            if(mu[x][y]==1)
                continue;
            ///muchie intre x si y
            int c1;
            int c2;
            c1=best[a][x]+1+best[y][b];
            c2=best[b][x]+1+best[y][a];
            if(min(c1,c2)>=best[a][b])
            {
             //   cout<<"A: "<<x<<" "<<y<<"\n";
                ans++;
            }
        }
    }
        cout<<ans;
    return 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<i<<" "<<j<<" : "<<best[i][j]<<"\n";
        }
     //   cout<<best[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
/**
**/