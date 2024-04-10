/*input
2 2 2
1 3
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , m , k , x[MAX];
int32_t main(){
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	sort(x + 1 , x + 1 + n);
	vector<int> sol;
	REP(i , 1 , n + 1){
		int sum = upper_bound(ALL(sol) , x[i]) - lower_bound(ALL(sol) , x[i] - m + 1);
		if(sum < k - 1) sol.pb(x[i]);
	}
	cout << n - sol.size() << endl;
    return 0;
}