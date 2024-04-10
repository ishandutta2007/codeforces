#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,tune=native")

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
#define bug(...) 777771449
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

template<typename T, int maxn, int type>
struct sparse{
    vector<T> val[22];
    sparse(){rep(__lg(maxn)+1) val[i].resize(max(0ll,maxn-pow2(i)+1));}
    inline T oper(T i, T j){return type?max(i,j):min(i,j);}
    void init(vector<T>& vec){
        rep(sz(vec)) val[0][i]=vec[i];
        rep2(i,1,__lg(maxn)+1) rep1(j,sz(vec)-pow2(i)+1) val[i][j]=oper(val[i-1][j],val[i-1][j+pow2(i-1)]);
    }
    T query(int l, int r){return oper(val[__lg(r-l+1)][l],val[__lg(r-l+1)][r-pow2(__lg(r-l+1))+1]);}
};
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=300005,maxm=7777714,maxk=7777714;
    
//i_am_noob
#define wiwihorz  
int n,a[maxn];
map<int,vector<int>> mm;

sparse<int,maxn,0> sp0;//min
sparse<int,maxn,1> sp1;//max

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    vector<int> vec0,vec1;
    int sum=0;
    vec0.pb(0),vec1.pb(0);
    mm.clear();
    mm[0].pb(0);
    rep(n){
        if(i%2==0) sum+=a[i];
        else sum-=a[i];
        if(i%2==0){
            vec0.pb(sum);
            vec1.pb(-inf);
        }
        else{
            vec0.pb(inf);
            vec1.pb(sum);
        }
        mm[sum].pb(i+1);
    }
    sp0.init(vec0),sp1.init(vec1);
    int res=0;
    for(auto [x,vv]: mm){
        int cur=0;
        rep(sz(vv)-1){
            int l=vv[i]+1,r=vv[i+1];
            if(sp0.query(l,r)>=x&&sp1.query(l,r)<=x) cur++;
            else cur=0;
            res+=cur;
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