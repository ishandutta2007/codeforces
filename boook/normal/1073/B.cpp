/*input
6
6 5 4 3 2 1
6 5 3 4 2 1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++ i)
#define RREP(i , j , k) for(int i = j ; i >= k ; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j) memset(i , j , sizeof i)
#define ALL(i) i.begin() , i.end()
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
const int MAX = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int n , a[MAX] , b[MAX] , u[MAX] , ans[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , n + 1) cin >> b[i];
	int pos = 1;
	REP(i , 1 , n + 1){
		if(u[b[i]] == 1) ans[i] = 0;
		else {
			int cnt = 0;
			while(pos <= n && u[b[i]] == 0){
				u[a[pos]] = 1;
				pos ++;
				cnt ++;
			}
			ans[i] = cnt;
		}
	}
	REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    return 0;
}