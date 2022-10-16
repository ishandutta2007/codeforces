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
const ll MAXN=110,MAXM=1e4+10,INF=1e14;
ll t,n,a[MAXN],b[MAXN];
ll ans,f[MAXN][MAXM],s[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];rep(i,1,n)cin>>b[i];
    ans=0;
    rep(i,0,n)rep(j,0,1e4)f[i][j]=INF;
    f[0][0]=0;
    rep(i,1,n)s[i]=s[i-1]+a[i]+b[i];
    rep(i,1,n)rep(j,0,Min(s[i],1e4)){
        ll& ret=f[i][j];
        if(j>=a[i] && f[i-1][j-a[i]]!=INF)ret=min(ret,f[i-1][j-a[i]]+a[i]*(j-a[i])+b[i]*(s[i-1]-j+a[i]));
        if(j>=b[i] && f[i-1][j-b[i]]!=INF)ret=min(ret,f[i-1][j-b[i]]+b[i]*(j-b[i])+a[i]*(s[i-1]-j+b[i]));
    }
    ans=INF;
    rep(i,0,Min(s[n],1e4))ans=min(ans,f[n][i]);
    ans*=2;
    rep(i,1,n)ans+=a[i]*a[i]*(n-1)+b[i]*b[i]*(n-1);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)solve();

    return 0;
}