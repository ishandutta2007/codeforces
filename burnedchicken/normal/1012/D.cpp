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
const int maxn=100005;

//i_am_noob
//#define wiwihorz  
string str[2];
vector<int> vec[2];
vector<pii> res;

void op(int x, int y){
    int c[2];
    c[0]=x,c[1]=y;
    vector<int> tmp[2];
    rep1(k,2) rep1(_,c[k]) tmp[k^1].pb(vec[k].back()),vec[k].pop_back();
    res.pb({accumulate(all(tmp[1]),0ll),accumulate(all(tmp[0]),0ll)});
    rep1(k,2) if(sz(tmp[k])&&sz(vec[k])){
        if(sz(vec[k])) vec[k].back()+=tmp[k].back();
        else vec[k].pb(tmp[k].back());
        tmp[k].pop_back();
    }
    rep1(k,2) while(sz(tmp[k])) vec[k].pb(tmp[k].back()),tmp[k].pop_back();
}

void orzck(){
    cin >> str[0] >> str[1];
    rep(2){
        int cur=0;
        rep1(j,sz(str[i])){
            cur++;
            if(j==sz(str[i])-1||str[i][j]!=str[i][j+1]) vec[i].pb(cur),cur=0;
        }
        reverse(all(vec[i]));
    }
    bug(vec[0]);
    bug(vec[1]);
    int c[2];
    if(str[0][0]==str[1][0]){
        c[0]=c[1]=0;
        if((max(sz(vec[0]),sz(vec[1]))-min(sz(vec[0]),sz(vec[1])))%4==3){
            if(sz(vec[0])>=sz(vec[1])) op(2,1);
            else op(1,2);
        }
        if(sz(vec[0])>sz(vec[1])) c[0]+=(sz(vec[0])-sz(vec[1]))/4*2+1;
        else c[1]+=(sz(vec[1])-sz(vec[0]))/4*2+1;
        bug(sz(vec[0]),sz(vec[1]),c[0],c[1]);
    }
    else{
        c[0]=c[1]=1;
        bug(sz(vec[0]),sz(vec[1]));
        if(sz(vec[0])>sz(vec[1])) c[0]+=(sz(vec[0])-sz(vec[1])+1)/4*2;
        else c[1]+=(sz(vec[1])-sz(vec[0])+1)/4*2;
    }
    if(max(sz(vec[0]),sz(vec[1]))>=2) op(c[0],c[1]);
    while(max(sz(vec[0]),sz(vec[1]))>=2) op(1,1);
    print(sz(res));
    for(auto [x,y]: res) print(x,y);
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