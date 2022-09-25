#include <bits/stdc++.h>
using namespace std;
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
const int maxn=1005;
//i_am_noob
int t,n,u,v,k1,k2,c,e[maxn][2];
bool a[maxn],b[maxn];

int par[maxn],val[maxn];
void init(int n){rep(n+1) par[i]=i,val[i]=-1;}
int Find(int x){return x==par[x]?x:par[x]=Find(par[x]);}
void Union(int x, int y){
    x=Find(x),y=Find(y);
    if(x==y) return;
    par[y]=x;
    val[x]=max(val[x],val[y]);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        rep(n-1){
            cin >> e[i][0] >> e[i][1];
        }
        cin >> k1;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        rep(k1){
            cin >> u;
            a[u]=1;
        }
        cin >> k2;
        cin >> c;
        b[c]=1;
        rep(k2-1){
            cin >> u;
            b[u]=1;
        }
        init(n);
        rep(n-1){
            if(a[e[i][0]]&&!a[e[i][1]]) val[e[i][1]]=e[i][0];
            if(a[e[i][1]]&&!a[e[i][0]]) val[e[i][0]]=e[i][1];
        }
        rep(n-1) if((!a[e[i][0]])&&(!a[e[i][1]])) Union(e[i][0],e[i][1]);
        print("B",c);
        cout << flush;
        cin >> u;
        if(a[u]){
            print("C",u);
            cout << flush;
            continue;
        }
        print("A",val[Find(u)]);
        cout << flush;
        cin >> v;
        print("C",b[v]?val[Find(u)]:-1);
        cout << flush;
    }
    return 0;
}