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
const ll MAXN=5e3+10,INF=1e16;
ll n,a[MAXN],b[MAXN],f[2][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;rep(i,1,n)cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    rep(i,1,n)f[1][i]=abs(a[1]-b[i]);
    rep(i,2,n){
        ll pre=INF;
        rep(j,1,n)pre=min(pre,f[(i-1)&1][j]),f[i&1][j]=pre+abs(a[i]-b[j]);
    }
    ll ans=INF;rep(i,1,n)ans=min(ans,f[n&1][i]);
    cout<<ans;
    return 0;
}