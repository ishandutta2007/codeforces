#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
//#define int ll
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
const int maxn=1505;

//i_am_noob
//#define wiwihorz  
int n,m;
short a[maxn][maxn],b[maxn][maxn],c[maxn];
bool used[maxn];
vector<int> res;
bitset<maxn> bs[maxn],good;

void hhhhauraorz(){
    n=readint(),m=readint();
    rep(n) rep1(j,m) a[j][i]=readint();
    rep(n) rep1(j,m) b[j][i]=readint();
    good[0]=1;
    rep(n) rep1(j,m) if(i&&b[j][i]>=b[j][i-1]) bs[j][i]=1;
    rep1(_,m){
        bool flag=0;
        rep1(j,m) if(!used[j]){
            if((good|bs[j]).count()==n){
                res.pb(j);
                rep2(i,1,n) if((!good[i])&&b[j][i]>b[j][i-1]) good[i]=1;
                flag=1;
                used[j]=1;
                break;
            }
        }
        if(!flag) break;
    }
    reverse(all(res));
    rep(n) c[i]=i;
    for(auto i: res) stable_sort(c,c+n,[i](int j1, int j2){return a[i][j1]<a[i][j2];});
    rep(n) rep1(j,m) if(a[j][c[i]]!=b[j][i]){
        print(-1);
        return;
    }
    print(sz(res));
    for(auto i: res) print0(i+1);
    cout << "\n";
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