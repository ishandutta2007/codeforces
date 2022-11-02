/*input
4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
4 1 2 3
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
#define MAX 505
#define INF 0x3f3f3f3f

int n , dis[MAX][MAX] , x[MAX] , ok[MAX] , ans[MAX];
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1){
		REP(j , 1 , n + 1){
			cin >> dis[i][j];
		}
	}
	REP(i , 1 , n + 1) cin >> x[i];
	RREP(k , n , 1){
		int id = x[k];
		ok[id] = 1;
		REP(i , 1 , n + 1){
			REP(j , 1 , n + 1){
				dis[i][j] = min(dis[i][j] , dis[i][id] + dis[id][j]);
			}
		}
		int sum = 0;
		REP(i , 1 , n + 1){
			REP(j , 1 , n + 1){
				if(ok[i] == 0) continue;
				if(ok[j] == 0) continue;
				sum += dis[i][j];
			}
		}
		ans[k] = sum;
	}
	REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    return 0;
}