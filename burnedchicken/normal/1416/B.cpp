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
const int maxn=10005;
//i_am_noob
int t,n,a[maxn],sum,x;
vector<int> vec1,vec2,vec3;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        rep(n) cin >> a[i];
        sum=0;
        rep(n) sum+=a[i];
        if(sum%n){
            print1(-1);
            continue;
        }
        if(n==1){
            print1(0);
            continue;
        }
        vec1.clear(),vec2.clear(),vec3.clear();
        rep2(i,1,n){
            x=ceiling(a[i],i+1);
            vec1.pb(0),vec2.pb(i),vec3.pb(x*(i+1)-a[i]);
            a[0]-=vec3.back(),a[i]+=vec3.back();
            vec1.pb(i),vec2.pb(0),vec3.pb(a[i]/(i+1));
            a[0]+=vec3.back()*(i+1),a[i]-=vec3.back()*(i+1);
        }
        rep2(i,1,n) vec1.pb(0),vec2.pb(i),vec3.pb(sum/n);
        print1(sz(vec1));
        rep(sz(vec1)) print3(vec1[i]+1,vec2[i]+1,vec3[i]);
    }
    return 0;
}