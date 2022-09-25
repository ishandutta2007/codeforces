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
const int maxn=1000005;

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
#define num array<short,8>
set<num> st;
num a[maxn];
vector<num> vec;
map<int,vector<int>> mm;
map<int,int> d[300];
vector<short> d2[300];
int ans[300][300],type[maxn];

inline int dis(vector<short> vec, num x){
    int res=0;
    rep(min(8ll,sz(vec))) res+=abs(vec[i]-x[i]);
    rep2(i,sz(vec),8) res+=x[i];
    rep2(i,8,sz(vec)) res+=vec[i];
    return res;
}

void dfs(vector<short> vec1, int val, int sum){
    rep3(i,vec1.back(),1) if(val*(i+1)<1000000&&sum+i+__lg(val*(i+1)/1000)<=25){
        vec1.pb(i);
        dfs(vec1,val*(i+1),sum+i);
        vec1.pop_back();
    }
    rep(sz(vec)){
        if(d[i].count(val)) chkmin(d[i][val],dis(vec1,vec[i]));
        else d[i][val]=dis(vec1,vec[i]);
    }
}

void orzck(){
    rep2(i,1,maxn){
        int x=i,lst=-1;
        int cur=-1;
        num k;
        rep1(j,8) k[j]=0;
        while(x>1){
            if(nt.lpd[x]!=lst) k[++cur]=1;
            else k[cur]++;
            lst=nt.lpd[x];
            x/=nt.lpd[x];
        }
        sort(all(k),[](int i1, int i2){return i1>i2;});
        a[i]=k;
        if(!st.count(k)) st.insert(k);
    }
    for(auto& k: st) vec.pb(k);
    sort(all(vec));
    rep2(i,1,maxn) type[i]=lower_bound(all(vec),a[i])-vec.begin();
    rep(31) dfs(vector<short>({(short)i}),i+1,i);
    rep(sz(vec)) for(auto [x,y]: d[i]) d2[i].pb(y);
    rep(sz(vec)) rep2(j,i,sz(vec)){
        short de=49;
        #pragma GCC ivdep
        rep1(k,sz(d2[i])) chkmin(de,(short)(d2[i][k]+d2[j][k]));
        ans[i][j]=ans[j][i]=de;
    }
    int q;
    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        bug(type[x],type[y]);
        print(ans[type[x]][type[y]]);
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