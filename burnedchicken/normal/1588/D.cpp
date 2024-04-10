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
const int maxn=11,maxm=115,maxk=7777714;
    
//i_am_noob
#define wiwihorz  
int n,a[maxn][maxm],pos[maxn][maxm],val[maxn][maxm],nxt[maxn][maxm][maxm];
vector<int> vec[maxn][maxm];
string str[maxn];
int dp[maxm][1049];
pii arr[maxm][1049];
bool vis[maxm][1049];

int solve(int c, int mask){
    //bug(c,mask);
    if(vis[c][mask]) return dp[c][mask];
    vis[c][mask]=1;
    dp[c][mask]=1;
    rep(maxm){
        bool flag=1;
        int x=0;
        rep1(j,n){
            if(nxt[j][vec[j][c][mask>>j&1]][i]==sz(str[j])){
                flag=0;
                break;
            }
            if(vec[j][i][0]!=nxt[j][vec[j][c][mask>>j&1]][i]) x+=pow2(j);
        }
        if(!flag) continue;
        if(1+solve(i,x)>dp[c][mask]){
            arr[c][mask]={i,x};
            dp[c][mask]=1+solve(i,x);
        }
    }
    return dp[c][mask];
}

void orzck(){
    bug("de");
    rep(maxn) rep1(j,maxm) pos[i][j]=-1,vec[i][j].clear();
    cin >> n;
    rep(n){
        cin >> str[i];
        rep1(j,sz(str[i])){
            if(str[i][j]>='A'&&str[i][j]<='Z') a[i][j]=str[i][j]-'A';
            else a[i][j]=str[i][j]-'a'+26;
            if(pos[i][a[i][j]]==-1) val[i][j]=1;
            else val[i][j]=2;
            pos[i][a[i][j]]=j;
            vec[i][a[i][j]].pb(j);
        }
    }
    rep(n) rep1(j,maxm) nxt[i][sz(str[i])-1][j]=sz(str[i]);
    rep(n) rep3(j,sz(str[i])-2,0){
        rep1(k,maxm){
            if(a[i][j+1]==k) nxt[i][j][k]=j+1;
            else nxt[i][j][k]=nxt[i][j+1][k];
        }
    }
    rep(maxm) rep1(j,1049) dp[i][j]=0,vis[i][j]=0,arr[i][j]={-inf,-inf};
    int res=0;
    rep(maxm){
        bool flag=1;
        int x=0;
        rep1(j,n){
            if(pos[j][i]==-1){
                flag=0;
                break;
            }
        }
        if(!flag) continue;
        chkmax(res,solve(i,0));
    }
    print(res);
    if(res){
        rep(maxm) rep1(j,1049) if(dp[i][j]==res){
            int x=i,y=j;
            if(x<26) cout << char('A'+x);
            else cout << char('a'+(x-26));
            bug(x,y);
            rep1(_,res-1){
                pii p=arr[x][y];
                x=p.first,y=p.second;
                if(x<26) cout << char('A'+x);
                else cout << char('a'+(x-26));
                bug(x,y);
            }
            cout << "\n";
            return;
        }
    }
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