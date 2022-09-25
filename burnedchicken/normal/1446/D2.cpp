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
const int maxn=200005;
//i_am_noob
int n,a[maxn],cnt[maxn],maxid,maxx=-inf,minn[maxn*2],ans=0,sum[maxn],maxcnt;
const int K=461;
vector<int> vec;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) a[i]--;
    rep(n) cnt[a[i]]++;
    rep(n) if(cnt[i]>maxx) maxx=cnt[i],maxid=i;
    rep(n) if(i!=maxid&&cnt[i]==maxx){
        print(n);
        return 0;
    }
    rep(n){
        if(i==maxid) continue;
        if(cnt[i]<=K) continue;
        sum[0]=0;
        rep1(j,n){
            if(a[j]==maxid) sum[j+1]=sum[j]+1;
            else if(a[j]==i) sum[j+1]=sum[j]-1;
            else sum[j+1]=sum[j];
        }
        memset(minn,-1,sizeof(minn));
        rep1(j,n+1){
             if(minn[sum[j]+maxn]==-1) minn[sum[j]+maxn]=j;
             else ans=max(ans,j-minn[sum[j]+maxn]);
        }
    }
    vec.pb(-1);
    rep(n) if(a[i]==maxid) vec.pb(i);
    vec.pb(n);
    memset(cnt,0,sizeof(cnt));
    rep(sz(vec)){
        maxx=0;
        rep2(j,vec[i]+1,vec[min(sz(vec)-1,i+K+3)]){
            cnt[a[j]]++;
            if(cnt[a[j]]>maxx) maxx++,maxcnt=1;
            else if(cnt[a[j]]==maxx) maxcnt++;
            if(maxcnt>=2) ans=max(ans,j-vec[i]);
        }
        rep2(j,vec[i]+1,vec[min(sz(vec)-1,i+K+3)]) cnt[a[j]]--;
    }
    print(ans);
    return 0;
}