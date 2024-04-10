#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e3+3,INF=1e9;
int a[N][N],vis[N][N],d[N][N];
int main(){
    int n,m,t; scanf("%d%d%d",&n,&m,&t);
    rep(i,1,n){
        static char s[N]; scanf("%s",s);
        rep(j,1,m) a[i][j]=s[j-1]-'0';
    }
    rep(i,1,n) a[i][0]=2,a[i][m+1]=2;
    rep(i,1,m) a[0][i]=2,a[n+1][i]=2;
    queue< pr > q;
    rep(i,1,n)
        rep(j,1,m)
            if (a[i-1][j]==a[i][j]||a[i][j-1]==a[i][j]||a[i+1][j]==a[i][j]||a[i][j+1]==a[i][j])
                q.push(mp(i,j)),vis[i][j]=1;
    while (!q.empty()){
        pr p=q.front(); q.pop();
        if (p.fi>1&&!vis[p.fi-1][p.se]) vis[p.fi-1][p.se]=1,d[p.fi-1][p.se]=d[p.fi][p.se]+1,q.push(mp(p.fi-1,p.se));
        if (p.se>1&&!vis[p.fi][p.se-1]) vis[p.fi][p.se-1]=1,d[p.fi][p.se-1]=d[p.fi][p.se]+1,q.push(mp(p.fi,p.se-1));
        if (p.fi<n&&!vis[p.fi+1][p.se]) vis[p.fi+1][p.se]=1,d[p.fi+1][p.se]=d[p.fi][p.se]+1,q.push(mp(p.fi+1,p.se));
        if (p.se<m&&!vis[p.fi][p.se+1]) vis[p.fi][p.se+1]=1,d[p.fi][p.se+1]=d[p.fi][p.se]+1,q.push(mp(p.fi,p.se+1));
    }
    while (t--){
        int i,j; ll p; scanf("%d%d%lld",&i,&j,&p);
        if (p<=d[i][j]||!vis[i][j]) printf("%d\n",a[i][j]);
        else printf("%d\n",((p-d[i][j]&1)?(a[i][j]^1):a[i][j]));
    }
    return 0;
}