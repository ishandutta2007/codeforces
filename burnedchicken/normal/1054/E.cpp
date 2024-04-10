#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=305;
//i_am_noob
//#define wiwihorz  
int n,m,cnt0[maxn][maxn],cnt1[maxn][maxn],cnt2[maxn][maxn],cnt3[maxn][maxn],in0[maxn],in1[maxn],out0[maxn],out1[maxn];
string str1[maxn][maxn],str2[maxn][maxn];
vector<vector<int>> res;

void hhhhauraorz(){
    cin >> n >> m;
    rep(n) rep1(j,m) cin >> str1[i][j];
    rep(n) rep1(j,m) cin >> str2[i][j];
    rep(n) rep1(j,m){
        cnt0[i][j]=count(all(str1[i][j]),'0');
        cnt1[i][j]=sz(str1[i][j])-cnt0[i][j];
        cnt2[i][j]=count(all(str2[i][j]),'0');
        cnt3[i][j]=sz(str2[i][j])-cnt2[i][j];
    }
    rep(n) rep1(j,m){
        if(i==0) in0[(j-1+m)%m]+=cnt0[i][j],out0[(j-1+m)%m]+=cnt2[i][j];
        else in0[j]+=cnt0[i][j],out0[j]+=cnt2[i][j];
        if(i==1) in1[(j-1+m)%m]+=cnt1[i][j],out1[(j-1+m)%m]+=cnt3[i][j];
        else in1[j]+=cnt1[i][j],out1[j]+=cnt3[i][j];
    }
    rep(n) rep1(j,m) rep3(k,sz(str1[i][j])-1,0){
        char c=str1[i][j][k];
        if(c=='0'){
            if(i==0) res.pb({i,j,i,(j-1+m)%m});
            else res.pb({i,j,0,j});
        }
        else{
            if(i==1) res.pb({i,j,i,(j-1+m)%m});
            else res.pb({i,j,1,j});
        }
    }
    rep1(j,m-1) rep(in0[j]) res.pb({0,j,0,m-1});
    rep1(j,m-1) rep(in1[j]) res.pb({1,j,1,m-1});
    rep1(j,m-1) rep(out0[j]) res.pb({0,m-1,0,j});
    rep1(j,m-1) rep(out1[j]) res.pb({1,m-1,1,j});
    rep(n) rep1(j,m) rep3(k,sz(str2[i][j])-1,0){
        char c=str2[i][j][k];
        if(c=='0'){
            if(i==0) res.pb({i,(j-1+m)%m,i,j});
            else res.pb({0,j,i,j});
        }
        else{
            if(i==1) res.pb({i,(j-1+m)%m,i,j});
            else res.pb({1,j,i,j});
        }
    }
    print(sz(res));
    for(auto& vec: res){
        for(auto i: vec) print0(i+1);
        cout << "\n";
    }
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