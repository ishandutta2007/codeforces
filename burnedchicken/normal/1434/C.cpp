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
const int maxn=300005;
//i_am_noob
int t,_a,_b,_c,_d;
__int128 a,b,c,d,e,l,r,mid;
bool flag;

__int128 f(__int128 x){
    if(x<=e){
        return b*d*x*(x-1)/2-x*a;
    }
    else return b*d*e*(e-1)/2+b*c*(x-e)-x*a;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> _a >> _b >> _c >> _d;
        a=_a,b=_b,c=_c,d=_d;
        if(b*c<a){
            print1(-1);
            continue;
        }
        e=ceiling(c,d);
        l=0,r=1e7;
        while(l<r){
            mid=(l+r)/2;
            if(f(mid)<=f(mid+1)) r=mid;
            else l=mid+1;
        }
        print1(-(int)f(l));
    }
    return 0;
}