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
const int MAXN=(1<<17)+10;
int T,p,n,u[MAXN],v[MAXN],cur;
int pv[MAXN],ev[MAXN];
vector<array<int,2> >e[MAXN];
void dfs(int u,int fa,int state){
    for(auto V:e[u])if(V[0]!=fa){
        cur++;
        ev[V[1]]=n+cur;
        pv[V[0]]=cur;
        if(state)swap(ev[V[1]],pv[V[0]]);
        dfs(V[0],u,state^1);
    }
}
void solve(){
    cin>>p;n=(1<<p);
    rep(i,1,n)e[i].clear();
    rep(i,1,n-1){
        cin>>u[i]>>v[i];
        e[u[i]].push_back({v[i],i});e[v[i]].push_back({u[i],i});
    }
    pv[1]=n;cur=0;
    dfs(1,1,0);
    cout<<1<<'\n';
    rep(i,1,n)cout<<pv[i]<<' ';cout<<'\n';
    rep(i,1,n-1)cout<<ev[i]<<' ';cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;while(T--)solve();

    return 0;
}