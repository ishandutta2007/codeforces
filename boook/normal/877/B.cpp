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
#define MAX 5050

string s;
int dp[MAX][MAX];
int32_t main(){

    cin >> s;
    REP(i , 0 , s.size()){
        int cnt = 0;
        REP(j , i , s.size()){
            if(s[j] == 'a') cnt++;
            dp[i][j] = cnt;
        }
    }
    int ans = dp[0][s.size() - 1];
    REP(i , 0 , s.size()){
        int cnt = 0;
        REP(j , i , s.size()){
            if(s[j] == 'b') cnt ++;
            int tmp = cnt;
            if(i != 0) tmp += dp[0][i - 1];
            tmp += dp[j + 1][s.size() - 1];
            ans = max(ans , tmp);
        }
    }
    cout << ans << endl;
    return 0;
}