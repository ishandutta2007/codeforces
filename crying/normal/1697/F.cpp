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
const int MAXN=5e5+10;
int T,n,m,k,tot;
vector<int>e[MAXN];
void link(int u,int v){e[u].push_back(v);}
int f(int i,int j){return (i-1)*k+j;}
int N(int u){return u+tot;}
namespace G{
    int n,dfntot,sccnum,top;
    int dfn[MAXN],low[MAXN],vis[MAXN],ins[MAXN],st[MAXN],num[MAXN];
    void clear(){
        dfntot=sccnum=top=0;
        rep(i,1,n)vis[i]=ins[i]=0;
    }
    void tarjan(int u){
        dfn[u]=low[u]=++dfntot;st[++top]=u;vis[u]=ins[u]=1;
        for(auto v:e[u]){
            if(!vis[v])tarjan(v),low[u]=min(low[u],low[v]);
            else if(ins[v])low[u]=min(low[u],low[v]);
        }
        if(dfn[u]==low[u]){
            sccnum++;
            while(1){
                int node=st[top--];
                ins[node]=0;num[node]=sccnum;
                if(node==u)break;
            }
        }
    }
    void tarjan(){
        rep(i,1,n)if(!vis[i])tarjan(i);
    }
};
void solve(){
    cin>>n>>m>>k;
    rep(i,1,n*k*2)e[i].clear();
    tot=n*k;
    rep(i,1,n){
        link(N(f(i,1)),f(i,1));
        rep(j,2,k)link(f(i,j),f(i,j-1)),link(N(f(i,j-1)),N(f(i,j)));
        if(i<n)rep(j,1,k)link(f(i,j),f(i+1,j)),link(N(f(i+1,j)),N(f(i,j)));
    }
    rep(i,1,m){
        int op;cin>>op;
        if(op==1){
            int x,val;cin>>x>>val;
            if(val==k)link(f(x,k),N(f(x,k)));
            else link(f(x,val),f(x,val+1)),link(N(f(x,val+1)),N(f(x,val)));
        }else if(op==2){
            int x,y,val;cin>>x>>y>>val;
            rep(a,1,k)rep(b,1,k)if(a+b>val){
                link(f(x,a),N(f(y,b)));link(f(y,b),N(f(x,a)));
            }
        }else{
            int x,y,val;cin>>x>>y>>val;
            rep(a,1,k)if(a<=val){
                if(a+k<=val){
                    link(N(f(x,a)),f(x,a));
                    link(N(f(y,a)),f(y,a));
                }else{
                    link(N(f(x,a)),f(y,val-a+1));link(N(f(y,val-a+1)),f(x,a));
                    link(N(f(y,a)),f(x,val-a+1));link(N(f(x,val-a+1)),f(y,a));
                }
            }
        }
    }
    G::n=tot+tot;
    G::clear();
    G::tarjan();
    rep(i,1,tot)if(G::num[i]==G::num[N(i)]){
        cout<<"-1\n";return;
    }
    rep(i,1,n){
        per(j,k,1){
            if(G::num[f(i,j)]<G::num[N(f(i,j))]){
                cout<<j<<' ';break;
            }
        }
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;while(T--)solve();


    return 0;
}