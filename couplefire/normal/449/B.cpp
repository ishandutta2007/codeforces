#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,int>pli;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define N 100005
vector<pii >g[N];
bool vis[N];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,a,b,c;i<=m;++i){
        scanf("%d%d%d",&a,&b,&c);
        g[a].pb(mp(b,c));
        g[b].pb(mp(a,c));
    }
    priority_queue<pli>q;
    for(int i=1,a,b;i<=k;++i){
        scanf("%d%d",&a,&b);
        q.push(mp(-b,-a));
    }
    q.push(mp(0,1));
    int ans=0;
    while(q.size()){
        pli t=q.top();
        q.pop();
        int u=t.Y;
        ll dis=t.X;
        if(u<0 && vis[u=-u])    ++ans;
        if(vis[u])  continue;
        vis[u]=true;
        for(int i=0;i<g[u].size();++i){
            int v=g[u][i].X;
            if(!vis[v]) q.push(mp(dis-g[u][i].Y,v));
        }
    }
    printf("%d\n",ans);
    return 0;
}