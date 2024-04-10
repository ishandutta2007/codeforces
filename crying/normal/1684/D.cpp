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
#define int ll
int T,n,k,a[MAXN],b[MAXN];
void solve(){
    cin>>n>>k;
    rep(i,1,n)cin>>a[i],b[i]=-a[i]+(n-i);
    sort(b+1,b+1+n);
    ll ans=0;
    rep(i,1,n)ans+=a[i];
    rep(i,1,k)ans+=b[i]-(k-i);
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();


    return 0;
}