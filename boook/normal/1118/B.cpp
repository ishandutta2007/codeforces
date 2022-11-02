/*input
9
2 3 4 2 2 3 2 2 4
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 300000
#define INF 0x3f3f3f3f

int n , x[MAX] , sum[MAX][2];

int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1){
		sum[i][0] += sum[i - 1][0] + x[i] * (i % 2 == 0);
		sum[i][1] += sum[i - 1][1] + x[i] * (i % 2 == 1);
	}
	int ans = 0;
	REP(i , 1 , n + 1){
		int val = 0;
		val += sum[i - 1][0] + sum[n][1] - sum[i][1];
		val -= sum[i - 1][1] + sum[n][0] - sum[i][0];
		if(val == 0) ans ++;
	}
	cout << ans << endl;
    return 0;
}