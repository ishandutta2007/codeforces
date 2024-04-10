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
int n,p[MAXN],cnt;
int f[MAXN],g[MAXN];
ll ans;
void upd(int i){ //dp(i)->dp(i+1)
    if(i==n)return;
    int pref=f[i+1],preg=g[i+1];
    cnt-=(f[i+1]!=-INF || g[i+1]!=INF);
    f[i+1]=-INF;g[i+1]=INF;
    if(p[i]<p[i+1])f[i+1]=max(f[i+1],f[i]);
    if(g[i]<p[i+1])f[i+1]=max(f[i+1],p[i]);
    if(p[i]>p[i+1])g[i+1]=min(g[i+1],g[i]);
    if(f[i]>p[i+1])g[i+1]=min(g[i+1],p[i]);
    cnt+=(f[i+1]!=-INF || g[i+1]!=INF);
    if(f[i+1]!=pref || g[i+1]!=preg)upd(i+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)cin>>p[i];
    per(i,n,1){
        f[i]=INF;g[i]=-INF;cnt++;
        upd(i);
        ans+=cnt;
    }
    cout<<ans;


    return 0;
}