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
#define MAX 40000
#define INF 0x3f3f3f3f

string s , now;
PII dp[MAX][30];
int32_t main(){
    cin >> s >> now;
    REP(i , 0 , MAX) REP(j , 0 , 30) dp[i][j] = mp(10 , 0);
    REP(i , 0 , s.size()){
        REP(j , i , s.size()){
            dp[i][s[j] - 'a'] = min(dp[i][s[j] - 'a'] , mp(0 , j));
        }
        REP(j , 0 , i){
            dp[i][s[j] - 'a'] = min(dp[i][s[j] - 'a'] , mp(1 , j));
        }
    }
    PII ans = mp(0 , 0);
    REP(i , 0 , now.size()){
        PII nxt = dp[ans.B][now[i] - 'a'];
        if(nxt.A == 10) { cout << "-1" << endl; return 0; }
        else {
            if(nxt.A == 1) ans.A ++ , ans.B = nxt.B;
            else {
                if(nxt.B < ans.B) ans.A ++ , ans.B = nxt.B;
                else ans.B = nxt.B;
            }
        }
        ans.B ++;
        if(ans.B == s.size()) ans.A ++ , ans.B = 0;
    }
    if(ans.B == 0) cout << ans.A << endl;
    else cout << ans.A + 1 << endl;
    return 0;
}