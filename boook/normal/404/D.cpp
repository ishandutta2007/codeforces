#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

string s;
int dp[MAX][5] , len;
int M(int now){ return now % mod;}
int32_t main(){
    IOS;
    cin >> s , len = s.size();
    if(s[0] == '?') dp[0][3] = 1 , dp[0][0] = 1 , dp[0][4] = 1;
    if(s[0] == '0') dp[0][0] = 1;
    if(s[0] == '1') dp[0][4] = 1;
    if(s[0] == '2') return puts("0");
    if(s[0] == '*') dp[0][3] = 1;
    REPNM(i , 1 , len){
        if(s[i] == '?'){
            dp[i][0] = M(dp[i - 1][0] + dp[i - 1][1]);
            dp[i][1] = M(dp[i - 1][3]);
            dp[i][4] = M(dp[i - 1][0] + dp[i - 1][1]);
            dp[i][2] = M(dp[i - 1][3]);
            dp[i][3] = M(dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4]);
        }
        if(s[i] == '0'){
            dp[i][0] = M(dp[i - 1][0] + dp[i - 1][1]);
        }
        if(s[i] == '1'){
            dp[i][1] = M(dp[i - 1][3]);
            dp[i][4] = M(dp[i - 1][0] + dp[i - 1][1]);
        }
        if(s[i] == '2'){
            dp[i][2] = M(dp[i - 1][3]);
        }
        if(s[i] == '*'){
            dp[i][3] = M(dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4]);
        }
        // DB4(dp[i][0] , dp[i][1] , dp[i][2] , dp[i][3]);
        // DBGG(dp[i][4] , "-------");
    }
    cout << M(dp[len - 1][0] + dp[len - 1][1] + dp[len - 1][3]) << "\n";
    return 0;
}