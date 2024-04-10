#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 1010
#define INF 0x3f3f3f3f

int n , x[MAX] , y[MAX] , t[MAX] , sol[MAX];
double dp[MAX] , p[MAX];
int cmp(int a , int b){ return t[a] < t[b]; }
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i] >> y[i] >> t[i] >> p[i];
    REP(i , 1 , n + 1) sol[i] = i;
    sort(sol + 1 , sol + 1 + n , cmp);
    double ans = 0;
    REP(idx , 1 , n + 1){
    	dp[sol[idx]] = max(dp[sol[idx]] , p[sol[idx]]);
    	REP(idy , 1 , idx){
    		int now = sol[idx] , from = sol[idy];
    		int dis = (x[now] - x[from]) * (x[now] - x[from]) + (y[now] - y[from]) * (y[now] - y[from]);
    		if(dis <= (t[now] - t[from]) * (t[now] - t[from])) dp[now] = max(dp[now] , dp[from] + p[now]);
    	}
    	ans = max(ans , dp[sol[idx]]);
    }
    printf("%.11f\n", ans);
    return 0;
}