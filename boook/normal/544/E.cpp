#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 21
#define INF 0x3f3f3f3f

int n , m , val[MAX][MAX] , cost[MAX][MAX] , sset[MAX][MAX];
int dp[1 << MAX];
string s[MAX];

int32_t main(){
    cin >> n >> m;
    REP(i , 0 , n) cin >> s[i];
    REP(i , 0 , n) REP(j , 0 , m) cin >> val[i][j];

    MEM(dp , INF);
    int dpval = 0;
    REP(i , 0 , n){
        int ok = 0;
        REP(j , 0 , m){
            REP(k , 0 , n){
                if(s[i][j] == s[k][j]) sset[i][j] |= (1 << k);
                if(s[i][j] == s[k][j] && i != k)
                    cost[i][j] += val[k][j];
            }
            if(cost[i][j] == 0) ok = 1;
        }
        if(ok == 0) dpval |= (1 << i);
    }
    dp[dpval] = 0;
    for(int id = dpval ; id > 0 ; id = (id - 1) & dpval){
        REP(i , 0 , n){
            if((id & (1 << i)) == 0) continue;
            REP(j , 0 , m){
                dp[id ^ (1 << i)] = min(dp[id ^ (1 << i)] , dp[id] + val[i][j]);
                int tmp = (id | sset[i][j]) ^ sset[i][j];
                dp[tmp] = min(dp[tmp] , dp[id] + cost[i][j]);
            }

        }
    }

    cout << dp[0] << endl;
    return 0;
}