#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e4+4,S=1e7+1e6+7,INF=1e9;
int d[N],id[N][1003],dis[S],x[S],y[S],c;
bool vis[S];
deque< pr > q;
void trans(int u,int v,int c){
    if (dis[u]+c<dis[v]){
        dis[v]=dis[u]+c;
        if (c) q.push_back(mp(-dis[v],v));
        if (!c) q.push_front(mp(-dis[v],v));
    }
}
int read(){
    int c=0; char ch=getchar();
    while (ch<'0'||'9'<ch) ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c;
}
int main(){
    int n=read(),m=read();
    rep(i,1,m) d[i]=read(); sort(d+1,d+1+m);
    int g=read(),r=read(),c=0;
    rep(i,1,m) rep(j,0,g) id[i][j]=++c,x[c]=i,y[c]=j;
    q.push_front(mp(0,id[1][g]));
    rep(i,1,c) dis[i]=INF; dis[id[1][g]]=0;
    while (!q.empty()){
        int u=q.front().se; q.pop_front();
        if (vis[u]) continue; vis[u]=true;
        int i=x[u],j=y[u];
        if (!j) trans(u,id[i][g],1);
        else{
            if (i>1&&j>=d[i]-d[i-1]) trans(u,id[i-1][j-(d[i]-d[i-1])],0);
            if (i<m&&j>=d[i+1]-d[i]) trans(u,id[i+1][j-(d[i+1]-d[i])],0);
        }
    }
    ll ans=INF;
    rep(i,0,g) ans=min(ans,(ll)g*(dis[id[m][i]]+1)+(ll)r*dis[id[m][i]]-i);
    cout<<(ans>=INF?-1:ans)<<endl;
    return 0;
}