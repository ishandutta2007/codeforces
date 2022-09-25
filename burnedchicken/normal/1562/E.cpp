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
const int maxn=5005;

//i_am_noob
#define wiwihorz  

vector<int> sa(const vector<int>& str){
    int n=sz(str);
    vector<int> res(n),rnk=str,nrnk(n);
    iota(all(res),0);
    for(int k=1; k<n; k<<=1){
        auto comp=[&](int i, int j){
            if(rnk[i]!=rnk[j]) return rnk[i]<rnk[j];
            return (i+k<n?rnk[i+k]:-1)<(j+k<n?rnk[j+k]:-1);
        };
        sort(all(res),comp);
        nrnk[res[0]]=0;
        rep2(i,1,n) nrnk[res[i]]=nrnk[res[i-1]]+comp(res[i-1],res[i]);
        rnk=nrnk;
    }
    return res;
}

vector<int> sa(const string& str){
    vector<int> vec(sz(str));
    rep(sz(str)) vec[i]=str[i];
    return sa(vec);
}

vector<int> lcp(const vector<int>& str, const vector<int>& sa){
    int n=sz(str);
    vector<int> res(n-1),rnk(n);
    rep(n) rnk[sa[i]]=i;
    int cur=0;
    rep(n){
        if(cur) cur--;
        if(!rnk[i]) continue;
        for(int j=sa[rnk[i]-1]; max(i,j)+cur<n; ++cur) if(str[i+cur]!=str[j+cur]) break;
        res[rnk[i]-1]=cur;
    }
    return res;
}

vector<int> lcp(const string& str, const vector<int>& sa){
    vector<int> vec(sz(str));
    rep(sz(str)) vec[i]=str[i];
    return lcp(vec,sa);
}

int n,val[maxn][maxn],dp[maxn];
string str;
vector<int> vec1,rnk,vec2;

void orzck(){
    cin >> n >> str;
    vec1=sa(str);
    vec2=lcp(str,vec1);
    rnk.resize(n);
    bug(vec1);
    rep(n) rnk[vec1[i]]=i;
    bug(rnk);
    rep(n-1){
        int minn=inf;
        rep2(j,i,n-1){
            chkmin(minn,vec2[j]);
            val[vec1[i]][vec1[j+1]]=val[vec1[j+1]][vec1[i]]=minn;
        }
    }
    int res=n;
    dp[0]=n;
    rep2(i,1,n){
        dp[i]=n-i;
        rep1(j,i) if(rnk[j]<rnk[i]) chkmax(dp[i],dp[j]+(n-i)-val[j][i]);
        chkmax(res,dp[i]);
        bug(i,dp[i]);
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