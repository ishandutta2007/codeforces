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
const int MOD=Mod;
const int maxn=200005;

//i_am_noob
//#define wiwihorz  
template<int maxn>
struct NT{
    vector<int> pr;
    int lpd[maxn];
    NT(){
        pr.clear();
        rep(maxn) lpd[i]=-1;
        rep2(i,2,maxn){
            if(lpd[i]==-1) lpd[i]=i,pr.pb(i);
            for(auto p: pr){
                if(p*i>=maxn) break;
                lpd[p*i]=p;
                if(i%p==0) break;
            }
        }
    }
    inline bool isp(int x){return lpd[x]==x;}
};
NT<maxn> nt;
int nim[maxn];


void orzck(){
    bool good[maxn];
    memset(good,0,maxn);
    int n,f;
    cin >> n >> f;
    rep2(i,2,maxn){
        if(nt.isp(i)||nt.isp(i/nt.lpd[i])) good[i]=1,bug(i);
    }
    good[f]=0;
    vector<int> vec1[100];
    /*
    rep2(i,2,maxn){
        bool vis[100];
        rep1(j,100) vis[j]=0;
        rep1(j,i+1) if(good[i-j]) vis[nim2[j]]=1;
        rep1(j,100) if(!vis[j]){
            nim2[i]=j;
            break;
        }
    }
    */
    vec1[0].pb(0),vec1[0].pb(1);
    rep2(i,2,maxn){
        bool vis[100];
        rep1(j,100) vis[j]=0;
        rep2(j,2,min(i+1,100ll)) if(good[j]) vis[nim[i-j]]=1;
        rep1(j,100) if(!vis[j]){
            bool ok=0;
            for(auto k: vec1[j]) ok|=good[i-k];
            if(!ok){
                nim[i]=j;
                break;
            }
        }
        vec1[nim[i]].pb(i);
    }
    int res=0;
    rep(n){
        int x,y,z;
        cin >> x >> y >> z;
        res^=nim[y-x-1]^nim[z-y-1];
    }
    print(res?"Alice":"Bob");
    print(res?"Bob":"Alice");
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