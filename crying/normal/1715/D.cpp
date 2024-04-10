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
int u[MAXN],v[MAXN],x[MAXN];
int ret[MAXN];
int tag[MAXN];
vector<int>e[MAXN];
queue<int>q;
void expand(){
    int u=q.front();q.pop();
    for(auto v:e[u]){
        if(tag[v]>=0)continue;
        if(!tag[u]){
            tag[v]=1;q.push(v);
        }
    }
}
void solve(int idx){
    rep(i,1,n)e[i].clear(),tag[i]=-1;
    rep(i,1,m){
        if(u[i]==v[i]){
            tag[u[i]]=(x[i]>>idx&1);
            continue;
        }
        if(x[i]>>idx&1)e[u[i]].push_back(v[i]),e[v[i]].push_back(u[i]);
        else tag[u[i]]=tag[v[i]]=0;
    }
    rep(i,1,n)if(tag[i]!=-1)q.push(i);
    while(q.size())expand();
    rep(i,1,n)if(tag[i]==-1){
        tag[i]=0;
        q.push(i);
        while(q.size())expand();
    }
    rep(i,1,n)ret[i]+=(tag[i])*(1<<idx);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,m)cin>>u[i]>>v[i]>>x[i];
    rep(i,0,29)solve(i);
    rep(i,1,n)cout<<ret[i]<<" ";
    return 0;
}