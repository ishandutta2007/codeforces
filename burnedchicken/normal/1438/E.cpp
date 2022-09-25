#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

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
int n,a[maxn],sum[maxn],ans=0;
unordered_map<int,vector<int>> mm;

inline bool check(int i, int j){return j-i>=2&&!(a[i]^a[j]^(sum[j]-sum[i+1]));}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> a[i];
    sum[0]=0;
    rep(n) sum[i+1]=sum[i]+a[i];
    rep3(i,29,0){
        mm.clear();
        rep1(j,n) if(a[j]>>i&1) mm[a[j]>>i].pb(j);
        rep1(j,n) if(!(a[j]>>i&1)) if(mm.count(a[j]>>i|1)){
            vector<int>& vec=mm[a[j]>>i|1];
            auto it1=lower_bound(all(vec),j);
            auto it2=it1;
            if(it1!=vec.end()){
                if(check(j,*it1)) ans++;
                it1++;
            }
            if(it1!=vec.end()){
                if(check(j,*it1)) ans++;
                it1++;
            }
            if(it2!=vec.begin()){
                it2--;
                if(check(*it2,j)) ans++;
            }
            if(it2!=vec.begin()){
                it2--;
                if(check(*it2,j)) ans++;
            }
        }
    }
    print(ans);
    return 0;
}