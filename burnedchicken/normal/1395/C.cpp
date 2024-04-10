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
const int maxn=205;
//i_am_noob
int n,m,a[maxn],b[maxn];
bitset<pow2(9)> bs,bs1,bs2;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    rep(n) cin >> a[i];
    rep(m) cin >> b[i];
    bs[0]=1;
    rep(n){
        bs1=bs;
        bs2.reset();
        rep1(j,m) bs2[a[i]&b[j]]=1;
        bs.reset();
        rep1(j,pow2(9)) rep1(k,pow2(9)) bs[j|k]=bs[j|k]||(bs1[j]&&bs2[k]);
    }
    rep(pow2(9)) if(bs[i]){
        print1(i);
        break;
    }
    return 0;
}