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
const int MAXN=2e5+10;
int n,m;
vector<int>e[MAXN];

int len,res[MAXN];
set<int>S,T,tmpset;
map<int,int>deg;
void solve(){
    res[len]+=T.size();
    for(auto u:T)S.erase(u);
    for(auto u:T){
        for(auto v:e[u]){
            if(S.find(v)==S.end())continue;
            deg[v]++;
            tmpset.insert(v);
        }
    }
    //tmpset
    for(auto u:tmpset){
        if(deg[u]==res[len]){
            S.erase(u);
        }
    }
    T=S;
    S.clear();
    for(auto u:tmpset){
        if(deg[u]==res[len])S.insert(u);
    }
    tmpset.clear();
    if(!T.empty())solve();
    else return;
}
void solve(int u){
    len++;deg.clear();tmpset.clear();
    S.erase(u);
    T.clear();
    T.insert(u);
    solve();
}
int main(){
    //freopen("offices.in","r",stdin);
    //freopen("offices.out","w",stdout);

    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,m){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    rep(i,1,n)S.insert(i);
    while(!S.empty()){
        int u=*S.begin();
        solve(u);
    }

    cout<<len<<"\n";
    sort(res+1,res+1+len);
    rep(i,1,len)cout<<res[i]<<" ";
    return 0;
}