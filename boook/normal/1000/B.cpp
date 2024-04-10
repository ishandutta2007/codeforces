/*input
2 7
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , ba[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	x[0] = 0 , x[n + 1] = m;
	n ++;
	RREP(i , n - 1 , 0){
		ba[i] = ba[i + 2] + (x[i + 1] - x[i]);
	}
	// REP(i , 0 , n + 1) cout << ba[i] << " " ; cout << endl;
	int open = 1 , ans = 0 , base = 0;
	REP(i , 1 , n + 1){
		for(auto to : {x[i - 1] + 1 , x[i] - 1}){
			if(x[i - 1] < to && to < x[i]){
				if(open == 0){
					int tmp = base + x[i] - to;
					ans = max(ans , tmp + ba[i + 1]);
					// DBGG("tmp = " , tmp + ba[i + 1]);
				}
				if(open == 1){
					int tmp = base + to - x[i - 1];
					ans = max(ans , tmp + ba[i]);
					// DBGG("tmp ? " , tmp + ba[i]);
				}
			}
		}
		if(open == 1) base += x[i] - x[i - 1];
		// DBGG("base = " , base);
		open = 1 - open;
	}
	ans = max(ans , base);
	cout << ans << endl;
    return 0;
}