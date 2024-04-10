#include<bits/stdc++.h>
#define N 1000
using namespace std;
int n,m,a[N+5][N+5],color[N+5][N+5],cnt;
bool vis[N+5][N+5];
int ansx[N*N+5],ansy[N*N+5],ansc[N*N+5];
inline int get(int x,int y)
{
    int ret=0;
    for(int i=x;i<=x+1;++i)
        for(int j=y;j<=y+1;++j) if(!color[i][j])
        {
            if(!ret) ret=a[i][j];
            else if(ret!=a[i][j]) return 0;
        }
    return ret;
}
inline void paint(int x,int y,int col)
{
    for(int i=x;i<=x+1;++i)
        for(int j=y;j<=y+1;++j)
            if(!color[i][j]) color[i][j]=col;
}
inline bool check()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(!color[i][j]) return 0;
    return 1;
}
queue<pair<int,int> > q;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);
    for(int i=1;i<n;++i)
        for(int j=1;j<m;++j)
            if(get(i,j)) q.push({i,j});
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second,col=get(x,y);q.pop();
        if(col) paint(x,y,col),ansx[++cnt]=x,ansy[cnt]=y,ansc[cnt]=col;
        for(int i=x-1;i<=x+1;++i) if(i && i<n)
            for(int j=y-1;j<=y+1;++j) if(j && j<m)
                if(!vis[i][j] && get(i,j)) vis[i][j]=1,q.push({i,j});
    }
    if(!check()) return puts("-1"),0;
    printf("%d\n",cnt);
    for(int i=cnt;i;--i)
        printf("%d %d %d\n",ansx[i],ansy[i],ansc[i]);
    return 0;
}