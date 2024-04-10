/*input
4 2
1 2000 2000 2
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
#define MAX 2020
#define INF 0x3f3f3f3f

int n , m , use[MAX] , ans[MAX];
PII x[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i].A , x[i].B = i;
	sort(x + 1 , x + 1 + n , greater<PII>());
	int all = 0;
	REP(i , 1 , m + 1) all += x[i].A , use[x[i].B] = 1;
	REP(i , 1 , n + 1) use[i] += use[i - 1];
	// REP(i , 1 , n + 1) cout << use[i] << " " ; cout << endl;
	REP(i , 1 , n + 1) ans[use[i]] = i;
	RREP(i , m , 2) ans[i] -= ans[i - 1];
	cout << all << endl;
	REP(i , 1 , m + 1) cout << ans[i] << " " ; cout << endl;
    return 0;
}