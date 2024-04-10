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
const int maxn=1050005;

//i_am_noob
//#define wiwihorz  
inline char readchar(){
    const int maxn=1000000;
    static char buf[maxn],*p=buf,*q=buf;
    if(p==q&&(q=(p=buf)+fread(buf,1,maxn,stdin))==buf) return EOF;
    else return *p++;
}
inline int readint(){
    int c=readchar(),x=0,neg=0;
    while((c<'0'||c>'9')&&c!='-'&&c!=EOF) c=readchar();
    if(c=='-') neg=1,c=readchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=readchar();
    return neg?-x:x;
}
int n,a[maxn],sum[maxn],res,lst[maxn],curlen[maxn];

void orzck(){
    n=readint();
    rep(n) a[i]=readint();
    rep1(j,20){
        rep(pow2(20-j)) lst[i]=-1,curlen[i]=0;
        int cur=0;
        lst[0]=0;
        rep(n){
            sum[i+1]=sum[i]+(a[i]>>j&1?0:1);
            cur^=a[i]>>j;
            if(lst[cur]!=-1&&sum[i+1]==sum[lst[cur]]) curlen[cur]+=i+1-lst[cur];
            else curlen[cur]=0;
            chkmax(res,curlen[cur]);
            lst[cur]=i+1;
        }
    }
    print(res);
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