/*input
10 2
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 700
#define INF 0x3f3f3f3f

int n , k;
double dp[MAX];
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1){
		REP(j , 1 , MAX){
			double trans1 = dp[j + 0] * j / (j + 1) + j / 2.0;
			double trans2 = dp[j + 1] * 1 / (j + 1) + j / (j + 1.0);
			dp[j] = dp[j] * (k - 1.0) / k + (trans1 + trans2) / k;
		}
	}
	printf("%.11f\n", dp[1] * k);
    return 0;
}