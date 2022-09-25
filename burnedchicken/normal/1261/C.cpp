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
int n,m,dx[8]={1,0,-1,0,1,1,-1,-1},dy[8]={0,1,0,-1,1,-1,-1,1};
vector<int> val[maxn],dis[maxn];
vector<bool> vec[maxn],vis[maxn];

inline bool ingrid(int x, int y){return x>=0&&x<n&&y>=0&&y<m;}

void orzck(){
    cin >> n >> m;
    rep(n+2) vec[i].resize(m+2),val[i].resize(m+2),dis[i].resize(m+2);
    rep(n){
        string str;
        cin >> str;
        rep1(j,m) if(str[j]=='X') vec[i+1][j+1]=1;
    }
    n+=2,m+=2;
    queue<pii> q;
    rep(n) rep1(j,m) if(!vec[i][j]) q.push({i,j}),val[i][j]=-1;
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        rep(8){
            int nx=x+dx[i],ny=y+dy[i];
            if(ingrid(nx,ny)&&vec[nx][ny]){
                vec[nx][ny]=0;
                q.push({nx,ny});
                val[nx][ny]=val[x][y]+1;
            }
        }
    }
    rep(n) rep1(j,m) bug(i,j,val[i][j]);
    int l=0,r=min(n,m)-1;
    while(l<r){
        int mid=l+r+1>>1;
        rep(n) rep1(j,m) dis[i][j]=inf;
        rep(n) rep1(j,m) if(val[i][j]>=mid) q.push({i,j}),dis[i][j]=0;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(dis[x][y]==mid) continue;
            rep(8){
                int nx=x+dx[i],ny=y+dy[i];
                if(ingrid(nx,ny)&&dis[nx][ny]==inf){
                    q.push({nx,ny});
                    dis[nx][ny]=dis[x][y]+1;
                }
            }
        }
        bool flag=1;
        rep(n) rep1(j,m) if(val[i][j]>=0&&dis[i][j]==inf) flag=0;
        if(flag) l=mid;
        else r=mid-1;
    }
    print(l);
    rep2(i,1,n-1){
        rep2(j,1,m-1) cout << (val[i][j]>=l?'X':'.');
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