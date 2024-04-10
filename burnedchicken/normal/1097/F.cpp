#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
const int maxn=100005;
//i_am_noob
inline char readchar(){
    const int maxn=1000000;
    static char buf[maxn],*p=buf,*q=buf;
    if(p==q&&(q=(p=buf)+fread(buf,1,maxn,stdin))==buf) return EOF;
    else return *p++;
}
template<typename T>
inline void readint(T& x){
    x=0;
    int c=readchar(),neg=0;
    while((c<'0'||c>'9')&&c!='-'&&c!=EOF) c=readchar();
    if(c=='-') neg=1,c=readchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=readchar();
    if(neg) x=-x;
}
int n,q,op,x,y,z,v;
bitset<7001> bs[maxn],bs1[7005],bs2[7005];
bool bad[7005];

signed main(){
    //ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    rep2(i,1,7001) for(int j=i; j<7001; j+=i) bs1[j][i]=1;
    for(int i=2; i*i<7001; i++) bad[i*i]=1;
    rep2(i,1,7001) if(bad[i]) for(int j=i; j<7001; j+=i) bad[j]=1;
    rep2(i,1,7001) for(int j=i; j<7001; j+=i) if(!bad[j/i]) bs2[i][j]=1;
    readint(n),readint(q);
    while(q--){
        readint(op);
        if(op==1){
            readint(x),readint(v);
            bs[x]=bs1[v];
        }
        else if(op==2){
            readint(x),readint(y),readint(z);
            bs[x]=bs[y]^bs[z];
        }
        else if(op==3){
            readint(x),readint(y),readint(z);
            bs[x]=bs[y]&bs[z];
        }
        else{
            readint(x),readint(v);
            putchar('0'+((bs[x]&bs2[v]).count()&1));
        }
    }
    putchar('\n');
    return 0;
}