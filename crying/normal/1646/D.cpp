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
const int MAXN=2e5+10,INF=1e9;
int n,cnt,ans[MAXN],deg[MAXN];
vector<int>e[MAXN];
array<int,2>f[MAXN][2];
void upd(array<int,2>&a ,array<int,2>b){
    if(a[0]<b[0])a=b;
    else if(a[0]==b[0]&&a[1]>b[1])a=b;
}
void dfs(int u,int fa){
    f[u][0]={0,1};
    f[u][1]={1,deg[u]};
    for(auto v:e[u])if(v!=fa){
        dfs(v,u);
        //0->0,0->1
        array<int,2>tmp={f[u][0][0]+f[v][0][0],f[u][0][1]+f[v][0][1]};
        upd(tmp,{f[u][0][0]+f[v][1][0],f[u][0][1]+f[v][1][1]});
        f[u][0]=tmp;
        f[u][1]={f[u][1][0]+f[v][0][0],f[u][1][1]+f[v][0][1]};
    }
}
void dfs2(int u,int fa,int s){
    if(s==1){
        ans[u]=deg[u];
        for(auto v:e[u])if(v!=fa)dfs2(v,u,0);
    }else{
        ans[u]=1;
        for(auto v:e[u])if(v!=fa){
            array<int,2>s=f[v][0];
            upd(s,f[v][1]);
            if(s==f[v][0])dfs2(v,u,0);
            else dfs2(v,u,1);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        e[u].push_back(v);e[v].push_back(u);
    }
    if(n==2){
        cout<<"2 2"<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }   
    rep(i,1,n)deg[i]=e[i].size();
    dfs(1,1);
    int qwq=0;
    array<int,2>s=f[1][0];
    upd(s,f[1][1]);
    cout<<s[0]<<' '<<s[1]<<endl;
    if(s==f[1][1])qwq=1;
    dfs2(1,1,qwq);
    rep(i,1,n)cout<<ans[i]<<' ';

    return 0;
}