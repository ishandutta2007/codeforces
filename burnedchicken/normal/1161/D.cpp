#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
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

const int maxn=1005;
//i_am_noob
int n,ans=0,k,cnt0,cnt1,cnt2;
vector<int> adj[maxn];
string str;
bool vis[maxn];

void dfs(int u){
    vis[u]=true;
    if(str[u]=='1') cnt1++;
    else if(str[u]=='0') cnt0++;
    else cnt2++;
    for(auto v: adj[u]) if(!vis[v]) dfs(v);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> str;
    n=sz(str);
    if(str.back()=='1'){
        print1(0);
        return 0;
    }
    if(str.back()=='?') str.back()='0';
    reverse(all(str));
    rep2(i,1,n){
        rep1(j,n) adj[j].clear();
        rep1(j,n) if(n-1-j!=j) adj[j].pb(n-1-j);
        rep1(j,i) if(i-1-j!=j) adj[j].pb(i-1-j);
        k=1;
        memset(vis,0,n);
        if(n%2){
            cnt0=cnt1=cnt2=0;
            dfs(n/2);
            k=k*Pow(2,cnt2)%MOD;
        }
        if(i%2){
            cnt0=cnt1=cnt2=0;
            dfs(i/2);
            k=k*Pow(2,cnt2)%MOD;
        }
        rep1(j,n) if(!vis[j]){
            cnt0=cnt1=cnt2=0;
            dfs(j);
            if(cnt2) k=k*Pow(2,cnt2-1)%MOD;
            else if(cnt1%2) k=0;
        }
        ans=add(ans,k);
    }
    print1(ans);
    return 0;
}