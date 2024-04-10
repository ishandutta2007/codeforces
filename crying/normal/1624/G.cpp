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
const int MAXN=2e5+10;
int t,n,m,x[MAXN],y[MAXN],w[MAXN],tag[MAXN];
int ans,fa[MAXN];
int Find(int x){
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
int solve(int lim){
    rep(i,1,n)fa[i]=i;
    rep(i,1,m){
        if(tag[i] || (w[i]>>lim&1))continue;
        if(Find(x[i])!=Find(y[i]))fa[Find(x[i])]=Find(y[i]);
    }
    rep(i,1,n)if(Find(i)!=Find(1))return 0;
    return 1;
}
void solve(){
    scanf("%d%d",&n,&m);
    rep(i,1,m)tag[i]=0;
    rep(i,1,m){
        scanf("%d%d%d",&x[i],&y[i],&w[i]);
    }
    ans=0;
    per(x,29,0){
        if(!solve(x)){
            ans^=(1<<x);
        }else{
            rep(i,1,m){
                if(w[i]>>x&1)tag[i]=1;
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&t);
    while(t--){
        solve();
    }

    return 0;
}