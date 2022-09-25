#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
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
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=(1<<19)+5;

//i_am_noob
//#define wiwihorz  
int n,k,a[maxn],vall[maxn*2],valr[maxn*2],lc[maxn],rc[maxn],minn[maxn],suf[maxn],res[maxn];

void pull(int x){
    if(vall[lc[x]]==inf&&valr[rc[x]]==inf) vall[x]=inf,valr[x]=inf,minn[x]=inf;
    else if(vall[lc[x]]==inf) vall[x]=vall[rc[x]]+pow2(k-1-__lg(x)),valr[x]=valr[rc[x]],minn[x]=inf;
    else if(valr[rc[x]]==inf) vall[x]=vall[lc[x]],valr[x]=valr[lc[x]]+pow2(k-1-__lg(x)),minn[x]=inf;
    else vall[x]=vall[lc[x]],valr[x]=valr[rc[x]],minn[x]=valr[lc[x]]+vall[rc[x]]+1;
}

void orzck(){
    cin >> n >> k;
    rep(n) cin >> a[i];
    rep2(i,1,pow2(k)) lc[i]=i*2,rc[i]=i*2+1;
    rep2(i,pow2(k),pow2(k+1)) vall[i]=inf,valr[i]=inf;
    rep(n){
        int cur=1;
        rep3(j,k-1,0){
            if(a[i]&pow2(j)) cur=cur*2+1;
            else cur=cur*2;
        }
        vall[cur]=0,valr[cur]=0;
    }
    minn[pow2(k)]=suf[pow2(k)]=inf;
    rep3(i,pow2(k)-1,1) pull(i);//,bug(i,vall[i],valr[i],minn[i]);
    rep3(i,pow2(k)-1,1) suf[i]=min(suf[i+1],minn[i]);
    res[0]=suf[1];
    rep2(mask,1,pow2(k)){
        int tmp=0;
        rep1(j,k) if(mask&pow2(j)) tmp^=pow2(k-1-j);
        int dep=__builtin_ctz(mask);
        rep3(i,pow2(dep+1)-1,1) swap(lc[i],rc[i]);
        rep3(i,pow2(dep+1)-1,1) pull(i);
        //bug(mask);
        //rep3(i,pow2(k)-1,1) bug(i,minn[i]);
        rep3(i,pow2(dep+1)-1,1) suf[i]=min(suf[i+1],minn[i]);
        res[tmp]=suf[1];
    }
    rep(pow2(k)) print0(res[i]);
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}