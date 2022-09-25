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
int n,m,a[maxn][maxn],cnt1[maxn],cnt2[maxn],arr1[maxn][maxn],arr2[maxn][maxn],ans[maxn][maxn];
vector<int> vec;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    rep(n) rep1(j,m) cin >> a[i][j];
    rep(n){
        vec.clear();
        rep1(j,m) vec.pb(a[i][j]);
        sort(all(vec));
        vec.resize(unique(all(vec))-vec.begin());
        cnt1[i]=sz(vec);
        rep1(j,m) arr1[i][j]=lower_bound(all(vec),a[i][j])-vec.begin();
    }
    rep(m){
        vec.clear();
        rep1(j,n) vec.pb(a[j][i]);
        sort(all(vec));
        vec.resize(unique(all(vec))-vec.begin());
        cnt2[i]=sz(vec);
        rep1(j,n) arr2[j][i]=lower_bound(all(vec),a[j][i])-vec.begin();
    }
    rep(n){
        rep1(j,m) print0(max(arr1[i][j],arr2[i][j])+max(cnt1[i]-arr1[i][j],cnt2[j]-arr2[i][j]));
        cout << "\n";
    }
    return 0;
}