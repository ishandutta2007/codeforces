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
const int maxn=300005;

//i_am_noob
//#define wiwihorz  
template<int N>
struct BIT{
    int val[N];
    void modify(int x, int y){for(int i=++x; i<N; i+=i&-i) val[i]+=y;}
    int query(int x, int y){
        int ret=0;
        for(int i=++y; i; i-=i&-i) ret+=val[i];
        for(int i=x; i; i-=i&-i) ret-=val[i];
        return ret;
    }
};

const int K=1505;
int n,a[maxn],res[maxn],cnt[maxn],val[maxn],lst,sum;
BIT<maxn> bit;

void orzck(){
    ld start=clock();
    cin >> n;
    rep(n) cin >> a[i];
    lst=0;
    rep(n){
        res[i]+=i*a[i]+bit.query(0,a[i]);
        for(int k=a[i]; k<maxn; k+=a[i]) bit.modify(k,-a[i]);
    }
    bug((clock()-start)/CLOCKS_PER_SEC);
    rep(n) bug(res[i]);
    memset(bit.val,0,sizeof bit.val);
    rep(n){
        res[i]+=sum;
        int tmp=0;
        for(int j=0; j+a[i]<maxn; j+=a[i]) tmp+=i-bit.query(0,min(maxn-1,j+a[i])-1);
        res[i]-=tmp*a[i];
        sum+=a[i];
        bit.modify(a[i],1);
    }
    rep2(i,1,n) res[i]+=res[i-1];
    rep(n) print0(res[i]);
    cout << "\n";
    bug((clock()-start)/CLOCKS_PER_SEC);
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