#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

//#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define inf 1010000000
//#define inf 4000000000000000000
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
const int MOD=Mod2;
const int maxn=2005;
//i_am_noob
int n,k,cnta[maxn][maxn],dp[maxn][maxn],a[maxn],maxx,curx,cury;
char grid[maxn][maxn];
string str,minn;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cin >> n >> k;
    rep(n) rep1(j,n) cin >> grid[i][j];
    rep(n) rep1(j,n){
        cnta[i][j]=0;
        if(i) cnta[i][j]=max(cnta[i][j],cnta[i-1][j]);
        if(j) cnta[i][j]=max(cnta[i][j],cnta[i][j-1]);
        if(grid[i][j]=='a') cnta[i][j]++;
    }
    rep(n) dp[i][n]=dp[n][i]=inf;
    rep3(i,2*n-2,0){
        if(i>=n-1){
            rep2(j,i-n+1,n) a[j]=j;
            sort(a+i-n+1,a+n,[i](int x, int y){return grid[x][i-x]==grid[y][i-y]?min(dp[x+1][i-x],dp[x][i-x+1])<min(dp[y+1][i-y],dp[y][i-y+1]):grid[x][i-x]<grid[y][i-y];});
            rep2(j,i-n+1,n) dp[a[j]][i-a[j]]=j;
        }
        else{
            rep1(j,i+1) a[j]=j;
            sort(a,a+i+1,[i](int x, int y){return grid[x][i-x]==grid[y][i-y]?min(dp[x+1][i-x],dp[x][i-x+1])<min(dp[y+1][i-y],dp[y][i-y+1]):grid[x][i-x]<grid[y][i-y];});
            rep1(j,i+1) dp[a[j]][i-a[j]]=j;
        }
    }
    rep3(i,2*n-2,0){
        maxx=-inf;
        rep1(j,n) if(i-j>=0&&i-j<n) maxx=max(maxx,cnta[j][i-j]);
        if(maxx+k>=i+1){
            bug(i);
            rep1(j,i+1) cout << 'a';
            rep1(j,2*n-2-i) minn+='z';
            rep1(j,n) if(i-j>=0&&i-j<n&&cnta[j][i-j]==maxx){
                bug(j,i-j);
                curx=j,cury=i-j;
                str.clear();
                rep1(ii,2*n-2-i){
                    if(curx==n-1) cury++;
                    else if(cury==n-1) curx++;
                    else if(dp[curx+1][cury]<dp[curx][cury+1]) curx++;
                    else cury++;
                    str+=grid[curx][cury];
                }
                minn=min(minn,str);
            }
            print(minn);
            return 0;
        }
    }
    curx=0,cury=0;
    cout << grid[0][0];
    rep(2*n-2){
        if(curx==n-1) cury++;
        else if(cury==n-1) curx++;
        else if(dp[curx+1][cury]<dp[curx][cury+1]) curx++;
        else cury++;
        cout << grid[curx][cury];
    }
    cout << "\n";
    return 0;
}