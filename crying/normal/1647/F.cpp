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
const int MAXN=5e5+10,INF=2e9;
int n,ans,a[MAXN];
int f1[MAXN],f2[MAXN],g[2][MAXN];
void solve(){
    int maxpos=1;rep(i,2,n)if(a[i]>a[maxpos])maxpos=i;
    f1[0]=-INF;
    rep(i,1,maxpos){
        f1[i]=INF;
        if(a[i-1]<a[i])f1[i]=min(f1[i],f1[i-1]);
        if(f1[i-1]<a[i])f1[i]=min(f1[i],a[i-1]);
    }
    f2[n+1]=-INF;
    per(i,n,maxpos){
        f2[i]=INF;
        if(a[i+1]<a[i])f2[i]=min(f2[i],f2[i+1]);
        if(f2[i+1]<a[i])f2[i]=min(f2[i],a[i+1]);
    }
    g[0][maxpos]=f1[maxpos];
    g[1][maxpos]=-INF;
    rep(i,maxpos+1,n){
        g[0][i]=INF;g[1][i]=-INF;
        if(a[i-1]>a[i])g[0][i]=min(g[0][i],g[0][i-1]);
        if(g[1][i-1]>a[i])g[0][i]=min(g[0][i],a[i-1]);
        if(a[i-1]<a[i])g[1][i]=max(g[1][i],g[1][i-1]);
        if(g[0][i-1]<a[i])g[1][i]=max(g[1][i],a[i-1]);
    }
    rep(i,maxpos+1,n){
        if(g[1][i]>f2[i])ans++;
    }
}
int main(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    solve();
    reverse(a+1,a+1+n);
    solve();
    cout<<ans;
    return 0;
}