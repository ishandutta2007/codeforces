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
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 110
#define INF 0x3f3f3f3f

bool use[MAX][MAX][MAX][3];
long double dp[MAX][MAX][MAX][3];
int C(int a){ return a * (a - 1) / 2; }
long double DP(int a , int b , int c , int d){
    if(a == 0 && b == 0 && d == 2) return 1;
    if(b == 0 && c == 0 && d == 0) return 1;
    if(a == 0 && c == 0 && d == 1) return 1;
    if(use[a][b][c][d]) return dp[a][b][c][d];
    else {
        use[a][b][c][d] = 1;
        int sum = C(a + b + c) - C(a) - C(b) - C(c);
        if(a > 0 && c > 0)
            dp[a][b][c][d] += (long double)a * (long double)c / (long double)sum * DP(a - 1 , b , c , d);
        if(a > 0 && b > 0)
            dp[a][b][c][d] += (long double)a * (long double)b / (long double)sum * DP(a , b - 1 , c , d);
        if(b > 0 && c > 0)
            dp[a][b][c][d] += (long double)b * (long double)c / (long double)sum * DP(a , b , c - 1 , d);
        return dp[a][b][c][d];
    }
}
int32_t main(){
    int a , b , c;
    cin >> a >> b >> c;
    REP(i , 3) printf("%.011Lf ", DP(a , b , c , i));
    cout << endl;
    return 0;
}