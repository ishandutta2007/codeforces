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
const int maxn=pow2(16)+5;
//i_am_noob
int n,a[maxn],val[maxn],x;
vector<int> vec[maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep2(i,1,n){
        print("XOR",1,i+1);
        cout << flush;
        cin >> x;
        val[i]=x;
        vec[x].pb(i);
    }
    rep(n) if(sz(vec[i])>=2){
        print("AND",vec[i][0]+1,vec[i][1]+1);
        cout << flush;
        cin >> x;
        a[0]=x^i;
        rep2(j,1,n) a[j]=a[0]^val[j];
        print0("!");
        rep1(j,n) print0(a[j]);
        cout << endl;
        return 0;
    }
    rep(n/2) if(sz(vec[2*i])&&sz(vec[2*i+1])){
        print("AND",vec[2*i][0]+1,vec[2*i+1][0]+1);
        cout << flush;
        cin >> x;
        a[0]=x^(2*i);
        break;
    }
    if(!((val[1]^val[2])&1)){
        print("AND",2,3);
        cout << flush;
        cin >> x;
        a[0]^=(val[1]^x)&1;
    }
    else{
        rep2(i,1,n) if(!(val[i]&1)){
            print("AND",1,i+1);
            cout << flush;
            cin >> x;
            a[0]^=x&1;
            break;
        }
    }
    rep2(j,1,n) a[j]=a[0]^val[j];
    print0("!");
    rep1(j,n) print0(a[j]);
    cout << endl;
    return 0;
}