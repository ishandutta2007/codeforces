//
// Created by calabash_boy on 18-10-18.
//
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LINE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif

#define PB(x) push_back(x)
#define rep(i,l,r) for (int i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (int i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)

typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3fLL;
/************* header ******************/
const int maxn = 2005;
char s[maxn][maxn];
int dp[maxn][maxn];
int rk[maxn][maxn];
pii min_val[maxn][maxn];
pii nxt[maxn][maxn];
int n,k;
string dfs(int x,int y){
    string ans = "";
    while (x !=n || y!= n){
        ans += s[x][y];
        pii Nxt = nxt[x][y];
        int xx = Nxt.first;
        int yy = Nxt.second;
        x = xx;
        y = yy;
    }
    return ans+s[n][n];
}
int main(){
    untie;
    cin>>n>>k;
    REP(i,1,n)cin>>&s[i][1];
    int max_sum = 0;
    REP(i,1,n)REP(j,1,n){
        if (i >= 2){
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
        if (j >= 2){
            dp[i][j] = max(dp[i][j],dp[i][j-1]);
        }
        if (s[i][j] == 'a')dp[i][j] ++;
        int need = i+ j -1 - dp[i][j];
        if (need <= k){
            if (i+j-1 >max_sum){
                max_sum = i+j-1;
            }
        }
    }
//    REP(i,1,n){
//        REP(j,1,n)cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
    REP(i,1,n)REP(j,1,n)min_val[i][j] = {inf,inf};
    rk[n][n] = 1;
    for (int step = 1;step <= 2*n-1;step++){
        vector<pair<pair<int,int>,pair<int,int> > > list;
        int sum = 2*n - step;
        for (int i=1;i<=n;i++){
            int j = sum - i;
            if (j <1 || j > n)continue;
            if (i < n){
                list.push_back({{s[i][j],rk[i+1][j]},{i,j}});
            }
            if (j < n){
                list.push_back({{s[i][j],rk[i][j+1]},{i,j}});
            }
        }
        sort(list.begin(),list.end(),[](pair<pii,pii> a,pair<pii,pii> b){
            if (a.first.first != b.first.first){
                return a.first.first < b.first.first;
            }
            return a.first.second < b.first.second;
        });
        for (auto piiii: list){
            int x = piiii.second.first;
            int y = piiii.second.second;
            min_val[x][y] = min(min_val[x][y],piiii.first);
        }
        vector<pair<pii,pii> > list2(0);
        for (auto piiii:list){
            int x = piiii.second.first;
            int y = piiii.second.second;
            if (min_val[x][y] == piiii.first){
                list2.push_back(piiii);
            }
        }
        pair<int,int> pre = {-1,-1};
        for (auto piiii:list2){
            int x = piiii.second.first;
            int y = piiii.second.second;
            int Nxt = piiii.first.second;
            if (x < n && Nxt == rk[x+1][y]){
                nxt[x][y] = {x+1,y};
            }
            if (y < n && Nxt == rk[x][y+1]){
                nxt[x][y] = {x,y+1};
            }
            if (pre.first == -1){
                rk[x][y] = 1;
                pre = {x,y};
                continue;
            }
            rk[x][y] = rk[pre.first][pre.second];
            if (min_val[x][y] != min_val[pre.first][pre.second])rk[x][y] ++;
            pre = {x,y};
        }
    }
    string ans;
    string pre;
    REP(i,1,n)ans += 'z'+1;
    REP(i,1,max_sum)pre +='a';
    if (max_sum == 0){
        cout<<dfs(1,1)<<endl;
        return 0;
    }
    REP(i,1,n)REP(j,1,n){
        int need = i+ j -1 - dp[i][j];
        if (need <= k){
            if (i+j-1 == max_sum){
                string suf = dfs(i,j);
                string tmp = pre + suf.substr(1,suf.size());
                ans = min(ans,tmp);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}