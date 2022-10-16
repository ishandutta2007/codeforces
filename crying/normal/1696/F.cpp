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
const int MAXN=210,INF=1e9;
int T,n;
string s,ss[MAXN][MAXN];
vector<array<int,2> >e;
struct DSU{
    int fa[MAXN];
    void Init(){
        rep(i,1,n)fa[i]=i;
    }
    int Find(int x){
        if(fa[x]==x)return x;
        return fa[x]=Find(fa[x]);
    }
    void merge(int x,int y){
        x=Find(x);y=Find(y);if(x==y)return;
        fa[x]=y;
    }
}dsu[MAXN];
queue<int>q;
void output(int tag){
    if(!tag){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
        for(auto p:e)cout<<p[0]<<' '<<p[1]<<'\n';
    }
}
int fa[MAXN];
namespace G{
    vector<int>edge[MAXN];
    int dis[MAXN][MAXN];
    void dfs(int u,int rt,int fa){
        for(auto v:edge[u])if(v!=fa){
            dis[rt][v]=dis[rt][u]+1;
            dfs(v,rt,u);
        }
    }
    int solve(){   
        rep(i,1,n)rep(j,1,n)if(i!=j)dis[i][j]=INF;else dis[i][j]=0;
        rep(i,1,n)dfs(i,i,0);
        rep(i,1,n)rep(j,1,n)if(dis[i][j]==INF)return 0;
        rep(i,1,n){
            rep(j,1,n)rep(k,1,n){
                if(dsu[i].Find(j)==dsu[i].Find(k)){
                    if(dis[i][j]!=dis[i][k])return 0;
                }else{
                    if(dis[i][j]==dis[i][k])return 0;
                }
            }
        }
        return 1;
    }
};
int check(){
    if(e.size()!=n-1)return 0;
    dsu[n+1].Init();
    for(auto p:e){
        if(dsu[n+1].Find(p[0])==dsu[n+1].Find(p[1]))return 0;
        dsu[n+1].merge(p[0],p[1]);
    }
    rep(i,1,n)G::edge[i].clear();
    for(auto p:e){
        G::edge[p[0]].push_back(p[1]);
        G::edge[p[1]].push_back(p[0]);
    }
    return G::solve();
}
void solve(){
    cin>>n;
    rep(i,1,n)dsu[i].Init();
    rep(i,1,n){
        rep(j,1,n-i){
            cin>>s;
            s=" "+s;
            ss[i][j]=s;
            rep(k,1,n){
                if(s[k]=='1'){
                    dsu[k].merge(i,i+j);
                }
            }
        }
    }
    rep(i,1,n)rep(j,1,n-i){
        rep(k,1,n){
            if(ss[i][j][k]=='0'){
                if(dsu[k].Find(i)==dsu[k].Find(i+j)){
                    output(0);return;
                }
            }
        }
    }

    rep(i,2,n){
        e.clear();
        memset(fa,0,sizeof fa);
        fa[1]=0;
        rep(j,2,n)if(dsu[1].Find(i)==dsu[1].Find(j)){
            fa[j]=1;q.push(j);e.push_back({1,j});
        }
        int flag=1;
        while(q.size()){
            int u=q.front();q.pop();
            rep(v,2,n)if(v!=fa[u] && dsu[u].Find(v)==dsu[u].Find(fa[u]) && fa[v]==0){
                fa[v]=u;q.push(v);e.push_back({u,v});
            }
        }
        if(!flag)continue;
        if(check()){
            output(1);
            return;
        }
    }
    output(0);
}
int main(){
    cin>>T;
    while(T--)solve();


    return 0;
}
/*
1
3
001 000
000
*/