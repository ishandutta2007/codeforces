#include <bits/stdc++.h>
using namespace std;
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
const int maxn=300005;
//i_am_noob
int n,x[maxn],y[maxn],a[4],ans1,ans2;

inline int dist(int a, int b){return abs(x[a]-x[b])+abs(y[a]-y[b]);}

inline int calc(int a, int b, int c){return dist(a,b)+dist(b,c)+dist(c,a);}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> x[i] >> y[i];
    a[0]=max_element(x,x+n)-x;
    a[1]=min_element(x,x+n)-x;
    a[2]=max_element(y,y+n)-y;
    a[3]=min_element(y,y+n)-y;
    ans2=2*(x[a[0]]-x[a[1]]+y[a[2]]-y[a[3]]);
    rep1(ii,4) rep2(jj,ii+1,4){
        if(a[ii]==a[jj]){
            ans1=ans2;
            break;
        }
        rep(n) ans1=max(ans1,calc(a[ii],a[jj],i));
    }
    print0(ans1);
    rep(n-3) print0(ans2);
    cout << "\n";
    return 0;
}