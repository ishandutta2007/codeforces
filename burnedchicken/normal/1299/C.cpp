#include <bits/stdc++.h>
#include <bits/extc++.h>

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
const int MOD=Mod;
const int maxn=1000005;
//i_am_noob
int n,a[maxn],curval,curl;
ld ans[maxn];

struct rational{
    int nu,de;
    rational(): nu(0),de(1){}
    rational(int _nu, int _de){
        if(_de<0) _nu*=-1,_de*=-1;
        nu=_nu,de=_de;
    }
    bool operator <(const rational& o) const {return nu*o.de<de*o.nu;}
};
vector<pair<rational,int>> vec;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> a[i];
    rep(n){
        curval=a[i],curl=1;
        while(1){
            if(vec.empty()||vec.back().first<rational(curval,curl)){
                vec.pb({rational(curval,curl),curl});
                break;
            }
            curval+=vec.back().first.nu,curl+=vec.back().second;
            vec.pop_back();
        }
    }
    curl=0;
    cout << fixed << setprecision(15);
    for(auto p: vec){
        rep2(i,curl,curl+p.second) print1((ld)p.first.nu/p.second);
        curl+=p.second;
    }
    return 0;
}