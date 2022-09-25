#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
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
const int maxn=50005;

//i_am_noob
//#define wiwihorz  

int n,m;
vector<array<int,3>> events;
vector<int> comps,adj[maxn*4],res;
bool good[maxn*4];

inline int pos(int x){return upper_bound(all(comps),x)-comps.begin()-1;}

template<int maxn>
struct dsu{
    int par[maxn],siz[maxn];
    dsu(){rep(maxn) par[i]=i,siz[i]=1;}
    void init(int n){rep(n) par[i]=i,siz[i]=1;}
    int Find(int x){return x==par[x]?x:par[x]=Find(par[x]);}
    bool Union(int x, int y){
        x=Find(x),y=Find(y);
        if(x==y) return false;
        if(siz[x]<siz[y]) swap(x,y);
        par[y]=x;
        siz[x]+=siz[y];
        return true;
    }
};

dsu<maxn*4> d;

void orzck(){
    cin >> n >> m;
    vector<int> tmp;
    rep(m){
        string str;
        int x,y;
        cin >> str >> x >> y;
        array<int,3> arr;
        if(str[0]=='a') arr[0]=0;
        else arr[0]=1;
        arr[1]=x,arr[2]=y;
        tmp.pb(x),tmp.pb(y+1);
        events.pb(arr);
    }
    tmp.pb(0),tmp.pb(pow2(n));
    sort(all(tmp));
    tmp.resize(unique(all(tmp))-tmp.begin());
    rep(sz(tmp)-1){
        int l=tmp[i],r=tmp[i+1]-1;
        if(l==r){
            comps.pb(l);
            continue;
        }
        int k=__lg(l^r);
        int mid=((l>>k)^1)<<k;
        comps.pb(l),comps.pb(mid);
    }
    comps.pb(pow2(n));
    rep(n){
        int cur=0;
        rep1(j,sz(comps)-1){
            cur=((comps[j+1]-1)>>i+1)<<i+1;
            if(cur<comps[j]) continue;
            int l=j,r=pos(cur+pow2(i)),k=cur+pow2(i);
            while(cur<k){
                adj[l].pb(r),adj[r].pb(l);
                cur=min(comps[l+1],comps[r+1]-pow2(i));
                if(cur>=comps[l+1]) l++;
                if(cur>=comps[r+1]-pow2(i)) r++;
            }
        }
    }
    rep(sz(comps)-1) good[i]=1;
    for(auto& arr: events){
        if(arr[0]){
            int l=pos(arr[1]),r=pos(arr[2]+1);
            rep2(i,l,r) good[i]=0;
        }
    }
    rep(sz(comps)-1) if(good[i]) for(auto j: adj[i]) if(good[j]) d.Union(i,j);
    reverse(all(events));
    for(auto& arr: events){
        if(arr[0]){
            int l=pos(arr[1]),r=pos(arr[2]+1);
            rep2(i,l,r) good[i]=1;
            rep2(i,l,r) for(auto j: adj[i]) if(good[j]) d.Union(i,j);
        }
        else{
            int x=pos(arr[1]),y=pos(arr[2]);
            if(d.Find(x)==d.Find(y)) res.pb(1);
            else res.pb(0);
        }
    }
    reverse(all(res));
    for(auto i: res) print(i);
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