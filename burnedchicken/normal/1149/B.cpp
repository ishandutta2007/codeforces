#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define mp make_pair
#define inf 2000000000
//#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=100005;
//i_am_noob
int n,q,nxt[maxn][26],dp[255][255][255],x;
string str;
char c;
vector<char> vec[3];

void calc(int i, int j, int k){
    dp[i][j][k]=inf;
    if(i>0) if(dp[i-1][j][k]<inf) dp[i][j][k]=min(dp[i][j][k],nxt[dp[i-1][j][k]][vec[0][i-1]-'a']+1);
    if(j>0) if(dp[i][j-1][k]<inf) dp[i][j][k]=min(dp[i][j][k],nxt[dp[i][j-1][k]][vec[1][j-1]-'a']+1);
    if(k>0) if(dp[i][j][k-1]<inf) dp[i][j][k]=min(dp[i][j][k],nxt[dp[i][j][k-1]][vec[2][k-1]-'a']+1);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> q >> str;
    rep(26) nxt[n][i]=inf;
    rep3(i,n-1,0) rep1(j,26){
        if(str[i]-'a'==j) nxt[i][j]=i;
        else nxt[i][j]=nxt[i+1][j];
    }
    dp[0][0][0]=0;
    while(q--){
        cin >> c;
        if(c=='-'){
            cin >> x;
            vec[--x].pop_back();
            print1(dp[sz(vec[0])][sz(vec[1])][sz(vec[2])]>=inf?"NO":"YES");
            continue;
        }
        cin >> x >> c;
        vec[--x].pb(c);
        if(x==0) rep1(j,sz(vec[1])+1) rep1(k,sz(vec[2])+1) calc(sz(vec[0]),j,k);
        else if(x==1) rep(sz(vec[0])+1) rep1(k,sz(vec[2])+1) calc(i,sz(vec[1]),k);
        else rep(sz(vec[0])+1) rep1(j,sz(vec[1])+1) calc(i,j,sz(vec[2]));
        print1(dp[sz(vec[0])][sz(vec[1])][sz(vec[2])]>=inf?"NO":"YES");
    }
    return 0;
}