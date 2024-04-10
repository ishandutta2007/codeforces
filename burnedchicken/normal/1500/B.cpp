#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
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
//#define wiwihorz  
int n,m,k,t,a[maxn>>1],b[maxn>>1],pos1[maxn],pos2[maxn],val[maxn],ans;
bool vis1[maxn],vis2[maxn];
vector<int> vec;

void hhhhauraorz(){
    cin >> n >> m >> k;
    k--;
    rep(n) cin >> a[i];
    rep(m) cin >> b[i];
    rep(n) a[i]--;
    rep(m) b[i]--;
    rep(maxn) pos1[i]=pos2[i]=-1;
    rep(n) pos1[a[i]]=i;
    rep(m) pos2[b[i]]=i;
    t=n*m/__gcd(n,m);
    int cur=0;
    val[0]=0;
    rep(m){
        cur=(cur+n)%m;
        if(cur==0) break;
        val[cur]=n*(i+1);
    }
    rep(maxn) if(pos1[i]!=-1&&pos2[i]!=-1){
        int x=(pos2[i]-pos1[i]+n*m)%m,res=0;
        if(__gcd(m,x)%__gcd(n,m)) continue;
        vec.pb((val[x]+pos1[i])%t);
    }
    sort(all(vec));
    ans+=t*(k/(t-sz(vec)));
    k%=t-sz(vec);
    vec.pb(t);
    rep(sz(vec)){
        int gap=i==0?vec[0]:vec[i]-vec[i-1]-1;
        if(k<gap){
            if(i==0) ans+=k;
            else ans+=vec[i-1]+1+k;
            break;
        }
        k-=gap;
    }
    print(ans+1);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz();
    return 0;
}