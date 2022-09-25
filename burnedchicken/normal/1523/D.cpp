#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
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
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
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
//#define wiwihorz  
int n,m,p,cnt[maxn],maxx=-inf;
bool a[maxn][61],res[61];
ykh;

void orzck(){
    cin >> n >> m >> p;
    rep(n) rep1(j,m){
        char c;
        cin >> c;
        a[i][j]=c=='1';
    }
    rep1(_,49){
        int x=rng()%n;
        bug(x);
        vector<int> vec;
        rep(m) if(a[x][i]) vec.pb(i);
        memset(cnt,0,sizeof cnt);
        rep(n){
            int val=0;
            rep1(j,sz(vec)) if(a[i][vec[j]]) val^=pow2(j);
            cnt[val]++;
        }
        rep(sz(vec)) rep1(mask,pow2(sz(vec))) if(!(mask&pow2(i))) cnt[mask]+=cnt[mask^pow2(i)];
        rep(pow2(sz(vec))) bug(i,cnt[i]);
        rep(pow2(sz(vec))) if(cnt[i]>=(n+1)/2&&__builtin_popcountll(i)>maxx){
            maxx=__builtin_popcountll(i);
            bug(i);
            memset(res,0,sizeof res);
            rep1(j,sz(vec)) if(i&pow2(j)) res[vec[j]]=1;
        }
    }
    rep(m) cout << res[i];
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}