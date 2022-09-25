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
#define wiwihorz  
int n,m,a[maxn],res[maxn];
char b[maxn];
vector<int> vec,vec2,stk;

void orzck(){
    cin >> n >> m;
    rep(n) cin >> a[i];
    rep(n) cin >> b[i];
    vec.clear(),vec2.clear();
    rep(n){
        if(a[i]&1) vec2.pb(i);
        else vec.pb(i);
    }
    rep1(_,2){
        stk.clear();
        sort(all(vec),[](int i, int j){return a[i]<a[j];});
        for(auto i: vec){
            if(sz(stk)&&b[i]=='L'&&b[stk.back()]=='R') res[stk.back()]=res[i]=(a[i]-a[stk.back()])/2,stk.pop_back();
            else stk.pb(i);
        }
        while(sz(stk)>=2&&b[stk[sz(stk)-2]]=='R'){
            int x=stk[sz(stk)-2],y=stk.back();
            res[x]=res[y]=(m-a[x]+m-a[y])/2;
            stk.pop_back(),stk.pop_back();
        }
        reverse(all(stk));
        while(sz(stk)>=2&&b[stk[sz(stk)-2]]=='L'){
            int x=stk[sz(stk)-2],y=stk.back();
            res[x]=res[y]=(a[x]+a[y])/2;
            stk.pop_back(),stk.pop_back();
        }
        if(sz(stk)>=2) res[stk[0]]=res[stk[1]]=(m-a[stk[0]]+a[stk[1]]+m)/2;
        else if(sz(stk)==1) res[stk[0]]=-1;
        vec=vec2;
    }
    rep(n) print0(res[i]);
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