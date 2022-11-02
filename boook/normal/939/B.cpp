/*input
28 3
5 6 30
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , x[MAX];

int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , m + 1) cin >> x[i];
	int big = 0 , ans1 = 1 , ans2 = 0;
	REP(i , 1 , m + 1){
		int tmp = n / x[i];
		if(tmp * x[i] >= big){
			big = tmp * x[i];
			ans1 = i , ans2 = tmp;
		}
	}
	cout << ans1 << " " << ans2 << endl;
    return 0;
}