#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=3e5+10,MAXM=MAXN*31;
int n,x,a[MAXN],k,base;
int ch[MAXM][2],tot=1,tag[MAXM];
map<int,vector<int> >f;
map<int,int>vis;
vector<int>ret;
void clr(){
    rep(i,1,tot)ch[i][0]=ch[i][1]=0,tag[i]=0;
    tot=1;
}
void Ins(int u,int x,int idx,int d){
    if(d<0){
        tag[u]=idx;return;
    }
    int v=x>>d&1;
    if(!ch[u][v])ch[u][v]=++tot;
    Ins(ch[u][v],x,idx,d-1);
}
int dfs(int u,int val,int idx,int sum,int d){
    if(d<0){
        if(sum>=x){
            ret.pb(idx);ret.pb(tag[u]);
            return 1;
        }
        else return 0;
    }
    int v=val>>d&1;
    if(ch[u][!v]){
        return dfs(ch[u][!v],val,idx,sum^(1<<d),d-1);
    }else{
        return dfs(ch[u][v],val,idx,sum,d-1);
    }
}
int A(int x){
    return (1<<x)-1;
}
void solve(vector<int> b){
    clr();
    for(auto u:b){
        Ins(1,a[u],u,29);
    }
    for(auto u:b){
        if(dfs(1,a[u],u,0,29))return;
    }
    ret.pb(b[0]);
}
int main(){
    cin>>n>>x;
    rep(i,1,n)cin>>a[i];
    if(x==0){
        printf("%d\n",n);
        rep(i,1,n)printf("%d ",i);
        return 0;
    }
    per(i,29,0){
        if(x>>i&1){
            k=i;break;
        }
    }
    base=A(30)-A(k+1);
    rep(i,1,n){
        f[a[i]&base].pb(i);
    }
    rep(i,1,n){
        if(vis[a[i]&base])continue;
        vis[a[i]&base]=1;
        vector<int>& tmp=f[a[i]&base];
        solve(tmp);
    }
    if(ret.size()<2)return printf("-1"),0;
    printf("%d\n",(int)ret.size());
    for(auto u:ret)printf("%d ",u);

    return 0;
}