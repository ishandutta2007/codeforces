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
#define pi pair<ll,ll>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double db;
using namespace std;
const ll MAXN=2010,mod=1e9+7;
int div2=(mod+1)/2;
ll T,n,m,k;
ll f[MAXN][MAXN];
void solve(){
    cin>>n>>m>>k;
    rep(i,1,n){
        f[i][0]=0;
        f[i][i]=k*i%mod;
        rep(j,1,i-1){
            f[i][j]=(f[i-1][j]+f[i-1][j-1])*div2%mod;
        }
    }
    printf("%lld\n",f[n][m]);
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}