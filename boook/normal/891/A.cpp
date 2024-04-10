/*input
3
2 1 1
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
#define MAX 2020
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];

	int tmp = x[1] , cnt = 0;
	REP(i , 1 , n + 1) tmp = __gcd(tmp , x[i]);
	REP(i , 1 , n + 1) if(x[i] == 1) cnt ++;

	if(tmp != 1){
		cout << -1 << endl;
	}
	else if(cnt) cout << n - cnt << endl; 
	else{
		int ans = INF;
		REP(i , 1 , n + 1){
			int now = x[i] , res = 0;
			REP(j , i + 1 , n + 1){
				now = __gcd(now , x[j]);
				res ++;
				if(now == 1){
					ans = min(ans , res + n - 1);
					break;
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}