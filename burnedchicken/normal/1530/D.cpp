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
const int maxn=200005;

//i_am_noob
#define wiwihorz  
ykh;
int n,a[maxn],cnt[maxn];
vector<int> vec,vec2;
set<int> st;
bool vis[maxn];

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) a[i]--;
    st.clear();
    vec.clear();
    vec2.clear();
    rep(n) vis[i]=0,cnt[i]=0;
    rep(n){
        if(!vis[a[i]]){
            vis[a[i]]=1;
        }
        else vec.pb(i);
        cnt[a[i]]++;
        
    }
    rep(n) if(!vis[i]) vec2.pb(i);
    print(n-sz(vec));
    bug(vec);
    bug(vec2);
    rep(n) bug(i,cnt[i]);
    if(sz(vec)==1&&vec[0]==vec2[0]){
        rep(n) if(cnt[a[i]]==2&&i!=vec[0]) a[i]=vec2[0],bug(i);
        rep(n) print0(a[i]+1);
        cout << "\n";
        return;
    }
    rep1(de,30){
        shuffle(all(vec2),rng);
        bool flag=1;
        rep(sz(vec)) if(vec[i]==vec2[i]) flag=0;
        if(flag){
            rep(sz(vec)) a[vec[i]]=vec2[i];
            rep(n) print0(a[i]+1);
            cout << "\n";
            return;
        }
    }
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