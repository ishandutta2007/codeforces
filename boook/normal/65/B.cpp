/*input
3
7011
9898
9999
9000
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 2020
#define INF 0x3f3f3f3f

int n , x[MAX] , dp[MAX][MAX] , dis[10000][MAX];
int l = 1000 , r = 2011;

vector<int> v[MAX];
int32_t main(){
    IOS;
    cin >> n;
    MEM(dis , INF);
    REP(i , 1000 , 10000) REP(j , l , r + 1){
        int cnt = 0 , v1 = i , v2 = j;
        REP(k , 0 , 4){
            if(v1 % 10 != v2 % 10) cnt ++;
            v1 /= 10 , v2 /= 10;
        }
        dis[i][j] = cnt;
    }
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) REP(j , l , r + 1) if(dis[x[i]][j] <= 1) v[i].pb(j);

    MEM(dp , -1);
    REP(i , 0 , v[1].size()) dp[1][i] = 0;
    REP(i , 2 , n + 1){
        REP(j , 0 , v[i].size()){
            REP(from , 0 , v[i - 1].size()){
                if(v[i][j] >= v[i - 1][from] && dp[i - 1][from] != -1){
                    dp[i][j] = from;
                    // cout << i << " "; DB4(v[i][j] , v[i - 1][from] , " = " , dp[i][j]);
                    break;
                }
            }
        }
    }

    int idx = -1;
    REP(i , 0 , v[n].size()) if(dp[n][i] != -1) idx = i;
    if(idx == -1) cout << "No solution" << endl;
    else {
        stack<int> cc;
        RREP(i , n , 1){
            cc.push(v[i][idx]);
            idx = dp[i][idx];
        }
        while(cc.size()) cout << cc.top() << endl , cc.pop();
    }
    return 0;
}