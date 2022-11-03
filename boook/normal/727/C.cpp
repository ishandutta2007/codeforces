/*input

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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , x[MAX] , ans[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 2 , n + 1){
		cout << "? 1 " << i << endl;
		fflush(stdout);
		cin >> x[i];
	}
	cout << "? 2 3" << endl;
	int tmp;
	cin >> tmp;
	ans[1] = (tmp + x[2] + x[3]) / 2 - tmp;
	REP(i , 2 , n + 1) ans[i] = x[i] - ans[1];
	cout << "! ";
	REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    return 0;
}