#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , m , k , x;
int dp[MAX][15][3] , tmp[15][3];
vector<int> v[MAX];
int p , q , r;
void DFS(int now , int fa){
    if(v[now].size() == 1 && v[now][0] == fa){
        dp[now][0][0] = p;
        dp[now][1][1] = q;
        dp[now][0][2] = r;
        return;
    }
    for(auto to : v[now]){
        if(to == fa) continue;
        DFS(to , now);
    }
    dp[now][0][0] = 1;
    dp[now][1][1] = 1;
    dp[now][0][2] = 1;
    for(auto to : v[now]){
        if(to == fa) continue;
        MEM(tmp , 0);
        RREP(i , x , 0) RREP(j , x , i)
            tmp[j][0] = (tmp[j][0] + dp[now][j - i][0] * dp[to][i][0]) % mod;
        RREP(i , x , 0) RREP(j , x , i)
            tmp[j][0] = (tmp[j][0] + dp[now][j - i][0] * dp[to][i][1]) % mod;
        RREP(i , x , 0) RREP(j , x , i)
            tmp[j][0] = (tmp[j][0] + dp[now][j - i][0] * dp[to][i][2]) % mod;

        RREP(i , x , 0) RREP(j , x , i)
            tmp[j][2] = (tmp[j][2] + dp[now][j - i][2] * dp[to][i][0]) % mod;
        RREP(i , x , 0) RREP(j , x , i)
            tmp[j][2] = (tmp[j][2] + dp[now][j - i][2] * dp[to][i][2]) % mod;

        RREP(i , x , 0) RREP(j , x , i)
            tmp[j][1] = (tmp[j][1] + dp[now][j - i][1] * dp[to][i][0]) % mod;
        RREP(i , x , 0){
            dp[now][i][0] = tmp[i][0];
            dp[now][i][1] = tmp[i][1];
            dp[now][i][2] = tmp[i][2];
        // DB4(now , i , 0 , dp[now][i][0]);
        // DB4(now , i , 1 , dp[now][i][1]);
        // DB4(now , i , 2 , dp[now][i][2]);
        }
    }
    RREP(i , x , 0){
        dp[now][i][0] = (dp[now][i][0] * p) % mod;
        dp[now][i][1] = (dp[now][i][1] * q) % mod;
        dp[now][i][2] = (dp[now][i][2] * r) % mod;
    }
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    cin >> k >> x;
    p = k - 1 , q = 1 , r = m - k;
    if(n == 1) cout << m << endl;
    else{
        DFS(1 , 0);
        int ans = 0;
        RREP(i , x , 0){
            ans = (ans + dp[1][i][0]) % mod;
            ans = (ans + dp[1][i][1]) % mod;
            ans = (ans + dp[1][i][2]) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}