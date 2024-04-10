/*input
9
2 1 3 5 4 1 2 3 1
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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , x[MAX];
int32_t main(){
	IOS , cin >> n;
	int ans = INF , big = INF;
	REP(i , 1 , n + 1) cin >> x[i] , big = min(big , x[i]);
	map<int , int> cc;
	REP(i , 1 , n + 1){
		if(x[i] != big) continue;
		if(cc.find(x[i]) == cc.end()) cc[x[i]] = i;
		else {
			ans = min(ans , i - cc[x[i]]);
			cc[x[i]] = i;
		}
	}
	cout << ans << endl;
    return 0;
}