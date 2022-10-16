#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=5e5+10,ADD=5e5;
int T,n;
int S[MAXN];
char s[MAXN];
struct Edge{
    int u,v,idx;
}edge[MAXN*2];
int fst[MAXN*2],nxt[MAXN*2],tot;
int st[MAXN],top,tag[MAXN];
vector<array<int,2> >e[MAXN*2];
void adde(int u,int v,int w){
    //printf("%d->%d (%d)\n",u-ADD,v-ADD,w);
    edge[++tot]=(Edge){u,v,w};
    nxt[tot]=fst[u];fst[u]=tot;
}
void dfs(int u){
    for(int& j=fst[u];j;j=nxt[j]){
        if(tag[edge[j].idx])continue;
        int v=edge[j].v;tag[edge[j].idx]=1;
        //printf("%d->%d\n",u-ADD,v-ADD);
        dfs(v);
    }
    st[++top]=u;
}
void solve(){
    rep(i,1,tot)edge[i]={0,0,0},nxt[i]=0,tag[i]=0;
    rep(i,-n,n)fst[i+ADD]=0,e[i+ADD].clear();
    tot=0;
    cin>>(s+1);n=strlen(s+1);
    S[0]=0;rep(i,1,n)S[i]=S[i-1]+((s[i]=='1')?(1):(-1));
    rep(i,1,n)e[S[i-1]+ADD].push_back({S[i]+ADD,i}),e[S[i]+ADD].push_back({S[i-1]+ADD,i});
    rep(i,-n,n)sort(e[i+ADD].begin(),e[i+ADD].end(),greater<array<int,2> >());
    rep(i,-n,n)for(auto j:e[i+ADD])adde(i+ADD,j[0],j[1]);
    top=0;
    dfs(0+ADD);
    per(i,top-1,1)if(st[i]<st[i+1])cout<<'0';else cout<<'1';cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}