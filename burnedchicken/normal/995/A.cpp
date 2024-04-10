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

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=55,maxm=7777714,maxk=7777714;
    
//i_am_noob
//#define wiwihorz  
int n,k,a[4][maxn];
pii pos[maxn*2];
vector<array<int,3>> res;

void park(int id){
    int x=pos[id].first^1,y=pos[id].second;
    if(a[x][y]!=id) return;
    a[x^1][y]=0;
    res.pb({id,x+1,y+1});
}

void move(int x, int y){
    int nx,ny;
    if(x==1){
        if(y==n-1) nx=2,ny=n-1;
        else nx=1,ny=y+1;
    }
    else{
        if(y==0) nx=1,ny=0;
        else nx=2,ny=y-1;
    }
    if(a[nx][ny]) return;
    a[nx][ny]=a[x][y];
    a[x][y]=0;
    pos[a[nx][ny]]={nx,ny};
    res.pb({a[nx][ny],nx+1,ny+1});
    park(a[nx][ny]);
}

void orzck(){
    cin >> n >> k;
    rep(4) rep1(j,n) cin >> a[i][j];
    rep2(i,1,3) rep1(j,n) if(a[i][j]) pos[a[i][j]]={i,j};
    rep1(de,2*n+2){
        rep3(i,n-1,0) if(a[1][i]) park(a[1][i]);
        rep(n) if(a[2][i]) park(a[2][i]);
        rep3(i,n-1,0) if(a[1][i]) move(1,i);
        rep(n) if(a[2][i]) move(2,i);
    }
    rep2(i,1,3) rep1(j,n) if(a[i][j]){
        print(-1);
        return;
    }
    print(sz(res));
    for(auto arr: res){
        for(auto i: arr) print0(i);
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