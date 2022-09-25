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
const int maxn=100005;
//i_am_noob
int t,n,l,a[maxn],k;
ld b[maxn],c[maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    cout << fixed << setprecision(15);
    while(t--){
        cin >> n >> l;
        a[0]=0,a[n+1]=l;
        rep2(i,1,n+1) cin >> a[i];
        b[0]=0;
        rep2(i,1,n+2) b[i]=b[i-1]+(ld)(a[i]-a[i-1])/i;
        c[n+1]=0;
        rep3(i,n,0) c[i]=c[i+1]+(ld)(a[i+1]-a[i])/(n-i+1);
        rep(n+2) if(b[i]>c[i]){
            k=i;
            break;
        }
        /*
        print1(k);
        rep(n+2) print0(b[i]);
        cout << "\n";
        rep(n+2) print0(c[i]);
        cout << "\n";
        */
        print1((b[k-1]*k+c[k-1]*(n+2-k))/(n+2));
    }
    return 0;
}