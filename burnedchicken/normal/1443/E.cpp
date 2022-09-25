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
//#define inf 2000000000
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
const int MOD=Mod;
const int maxn=200005;
//i_am_noob
int n,m,q,cur=0,o,x,l,r,a[15],fact[16]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000},ans;

void build(int x){
    bool vis[15];
    rep(15) vis[i]=false;
    rep(m){
        int cnt=x/fact[m-1-i];
        x%=fact[m-1-i];
        rep1(j,m){
            if(!vis[j]){
                if(cnt==0){
                    a[i]=j;
                    vis[j]=true;
                    break;
                }
                cnt--;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> q;
    m=min(n,15ll);
    build(cur);
    while(q--){
        cin >> o;
        if(o==1){
            cin >> l >> r;
            l--,r--;
            if(r<n-m){
                print((r+1)*(r+2)/2-l*(l+1)/2);
                continue;
            }
            ans=0;
            if(l<n-m) ans+=(n-m)*(n-m+1)/2-l*(l+1)/2,l=n-m;
            rep2(i,l-(n-m),r+1-(n-m)) ans+=a[i]+n-m+1;
            print(ans);
        }
        else{
            cin >> x;
            cur+=x;
            build(cur);
        }
    }
    return 0;
}