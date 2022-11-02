/*input
4 6
1 2
1 3
1 4
2 3
2 4
3 4
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
#define int long long
#define MAX 20
#define INF 0x3f3f3f3f

int n , m , dp[MAX][1 << MAX] , v[MAX][MAX];
int id[1 << MAX] , one[1 << MAX];
int32_t main(){
	REP(i , 1 , (1 << MAX)){
		if(i % 2 == 0) one[i] = one[i >> 1];
		if(i % 2 == 1) one[i] = one[i >> 1] + 1;
		if(i % 2 == 0)  id[i] =  id[i >> 1] + 1;
	}
	IOS;
	cin >> n >> m;
	REP(i , 0 , m){
		int a , b;
		cin >> a >> b;
		v[a - 1][b - 1] = 1;
		v[b - 1][a - 1] = 1;
	}
	REP(i , 0 , n) dp[i][1 << i] = 1;

	int ans = 0;
	REP(i , 1 , (1 << n)){
		REP(j , id[i] , n){
			if((i & (1 << j)) == 0) continue;
			if(v[j][id[i]] && one[i] >= 3) ans += dp[j][i];
			REP(k , id[i] , n){
				if((i & (1 << k)) != 0) continue;
				if(v[j][k]) dp[k][i + (1 << k)] += dp[j][i];
			}
		}
	}
	cout << ans / 2 << endl;
    return 0;
}