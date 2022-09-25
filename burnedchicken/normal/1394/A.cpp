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
const int maxn=100005;
//i_am_noob
int n,d,m,a[maxn],sum1[maxn],sum2[maxn],ans=0;
vector<int> vec1,vec2;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> d >> m;
    rep(n) cin >> a[i];
    sort(a,a+n);
    rep(n){
        if(a[i]<=m) vec1.pb(a[i]);
        else vec2.pb(a[i]);
    }
    reverse(all(vec1)),reverse(all(vec2));
    sum1[0]=0,sum2[0]=0;
    rep(sz(vec1)) sum1[i+1]=sum1[i]+vec1[i];
    rep(sz(vec2)) sum2[i+1]=sum2[i]+vec2[i];
    rep(n+1){
        if((i-1)*(d+1)>=n||i>sz(vec2)) break;
        ans=max(ans,sum2[i]+sum1[min(sz(vec1),n-(i-1)*(d+1)-1)]);
    }
    print1(ans);
    return 0;
}