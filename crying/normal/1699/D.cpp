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
const int MAXN=5010,INF=1e9;
int T,n,a[MAXN],ans;
vector<int>occ[MAXN];
int f[MAXN][MAXN],bucket[MAXN];
int g[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n)occ[i].clear();
    rep(i,1,n)cin>>a[i],occ[a[i]].push_back(i);
    rep(i,1,n+1)f[i][i-1]=1;
    ans=0;
    rep(l,1,n){
        rep(i,1,n)bucket[i]=0;
        f[l][l]=0;bucket[a[l]]++;int maxv=a[l];
        rep(r,l+1,n){
            bucket[a[r]]++;
            if(bucket[a[r]]>bucket[maxv])maxv=a[r];
            if(r-l+1-bucket[maxv]>=bucket[maxv])f[l][r]=(even((r-l+1))?(1):(0));
            else f[l][r]=0;
        }
    }
    rep(i,1,n){
        if(f[1][i-1])g[i]=1;
        else g[i]=-INF;
        rep(j,1,i-1)if(f[j+1][i-1] && a[j]==a[i])g[i]=max(g[i],g[j]+1);
        if(f[i+1][n])ans=max(ans,g[i]);
    }
    cout<<ans<<'\n';
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}