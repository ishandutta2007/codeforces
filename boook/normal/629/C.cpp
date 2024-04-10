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
#define MAX 2020
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int dp[MAX + 10][MAX + 10];
void solveinit(){
    dp[0][0] = dp[1][1] = 1;
    REP(i , 2 , MAX) REP(j , 0 , MAX){
        if(j == 0) dp[i][j] = dp[i - 1][j + 1];
        else dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % mod;
    }
}
string s;
int n , m;
int32_t main(){
    solveinit();
    cin >> n >> m >> s;
    int p = 0 , q = 0; // )(
    REP(i , 0 , s.size()){
        if(s[i] == '(') q ++;
        if(s[i] == ')'){
            if(q) q --;
            else p ++;
        }
    }
    int add = n - m , ans = 0;
    REP(i , 0 , add + 1){
        REP(j , 0 , add + 1){
            if(max(p , q) + j > 2000LL) continue;
            assert(i < MAX);
            assert(add - i < 2001);
            assert(j + p < 2001);
            assert(j + q < 2001);
            ans = (ans + dp[i][j + p] * dp[add - i][j + q]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}