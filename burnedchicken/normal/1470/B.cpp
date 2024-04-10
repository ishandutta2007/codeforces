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
const int MOD=Mod;
const int maxn=1000005;
//i_am_noob
int t,n,val[maxn],a[maxn],lst,cnt,ans1,ans2,q,x;
vector<int> vec;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    rep2(i,1,10000){
        if(i*i>1000000) break;
        vec.pb(i*i);
    }
    rep2(i,1,1000001) val[i]=i;
    rep2(i,1,1000001){
        if(val[i]==i){
            for(auto j: vec){
                if(i*j>1000000) break;
                val[i*j]=i;
            }
        }
    }
    cin >> t;
    while(t--){
        cin >> n;
        rep(n) cin >> a[i];
        rep(n) a[i]=val[a[i]];
        sort(a,a+n);
        ans1=cnt=1;
        lst=0;
        rep2(i,1,n){
            if(a[i]==a[i-1]) cnt++;
            else{
                cnt=1;
                if((i-lst)%2==0){
                    rep2(j,lst,i) a[j]=1;
                }
                lst=i;
            }
            ans1=max(ans1,cnt);
        }
        if((n-lst)%2==0){
            rep2(j,lst,n) a[j]=1;
        }

        sort(a,a+n);
        ans2=cnt=1;
        rep2(i,1,n){
            if(a[i]==a[i-1]) cnt++;
            else cnt=1;
            ans2=max(ans2,cnt);
        }
        bug(ans1,ans2);
        cin >> q;
        while(q--){
            cin >> x;
            print(x?ans2:ans1);
        }
    }
    return 0;
}