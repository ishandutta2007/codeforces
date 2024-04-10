#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=1005;
//i_am_noob
int n,k,a[maxn],m,b[100005];

template <int mod>
struct Modint{
    int val;
    Modint(int _val=0){val=_val;}
    operator int() const {return (*this).val;}
    Modint operator +(const Modint& o) const {return val+o.val>=mod?Modint(val+o.val-mod):Modint(val+o.val);}
    Modint operator -() const {return val?Modint(mod-val):*this;}
    Modint operator -(const Modint& o) const {return val-o.val<0?Modint(val-o.val+mod):Modint(val-o.val);}
    Modint operator *(const Modint& o) const {return Modint(val*o.val%mod);}
    Modint operator +=(const Modint& o){*this=(*this)+o;return *this;}
    Modint operator -=(const Modint& o){*this=(*this)-o;return *this;}
    Modint operator *=(const Modint& o){*this=(*this)*o;return *this;}
    Modint Pow(int b) const {
        Modint tmp(val),ret(1);
        while(b){
            if(b&1) ret*=tmp;
            b>>=1;tmp*=tmp;
        }
        return ret;
    }
    Modint Pow(const Modint& a, int b) const {return a.Pow(b);}
    inline Modint inv() const {return (*this).Pow(mod-2);}
    Modint operator /(const Modint& o) const {return *this*o.inv();}
    bool operator ==(const Modint& o) const {return val==o.val;}
};
#define modint Modint<MOD>
modint ans,dp[maxn][maxn],sum[maxn][maxn],cnt[100005];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k;
    rep(n) cin >> a[i];
    sort(a,a+n);
    if(k==2){
        rep(n) rep2(j,i+1,n) ans+=a[j]-a[i];
        print1(ans);
        return 0;
    }
    m=(a[n-1]-a[0])/(k-1);
    rep(100005) b[i]=upper_bound(a,a+n,i)-a-1;
    rep2(l,1,m+1){
        rep2(j,2,k+1) sum[0][j]=0;
        rep(n){
            rep2(j,2,k+1){
                if(j>i+1||a[i]<l) dp[i][j]=0;
                else if(j==2) dp[i][j]=modint((b[a[i]-l]+1)%MOD);
                else dp[i][j]=sum[b[a[i]-l]+1][j-1];
                sum[i+1][j]=sum[i][j]+dp[i][j];
            }
        }
        rep(n) cnt[l]+=dp[i][k];
    }
    rep2(l,1,m+1) ans+=modint(l)*(cnt[l]-cnt[l+1]);
    print1(ans);
    return 0;
}