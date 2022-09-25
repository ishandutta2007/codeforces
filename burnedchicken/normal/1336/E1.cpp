#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=200005;
//i_am_noob
int n,m,x,a[40],ans[40],dp[pow2(15)][40],k=1;
vector<int> vec;
bool good[40];

struct xorbasis: vector<ull>{
    bool check(ull x){
        for(auto i: *this) if((x^i)<x) x^=i;
        return x;
    }
    bool push(ull x){
        for(auto i: *this) if((x^i)<x) x^=i;
        if(x) return this->pb(x),true;
        else return false;
    }
}basis;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n >> m;
    rep(n){
        cin >> x;
        basis.push(x);
    }
    for(auto i: basis) vec.pb(i);
    sort(all(vec));
    basis.clear();
    for(auto i: vec) basis.push(i);
    rep(n-sz(basis)) k=(k*2)%MOD;
    if(sz(basis)<=20){
        rep1(mask,pow2(sz(basis))){
            x=0;
            rep(sz(basis)) if(mask&pow2(i)) x^=basis[i];
            ans[__builtin_popcountll(x)]++;
        }
        rep(m+1) print0(ans[i]*k%MOD);
        cout << "\n";
        return 0;
    }
    for(auto i: basis) good[__lg(i)]=true;
    vec.clear();
    rep(m) if(!good[i]) vec.pb(i);
    dp[0][0]=1;
    for(auto i: basis){
        x=0;
        rep1(j,sz(vec)) if(i&pow2(vec[j])) x^=pow2(j);
        bug(i,x);
        rep3(j,sz(basis),1) rep1(mask,pow2(sz(vec))) dp[mask][j]+=dp[mask^x][j-1];
    }
    rep1(mask,pow2(sz(vec))) rep1(j,sz(basis)+1) ans[__builtin_popcountll(mask)+j]+=dp[mask][j],bug(mask,j,dp[mask][j]);
    rep(m+1) print0(ans[i]*k%MOD);
    cout << "\n";
    return 0;
}