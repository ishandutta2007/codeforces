/*input
6 3
1 3 5 2 5 4
1 1 0 1 0 0
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , k , x[MAX] , ans;
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1){
		int in; cin >> in;
		if(in) ans += x[i] , x[i] = 0;
	}
	REP(i , 1 , n + 1) x[i] += x[i - 1];
	int good = ans;
	REP(i , 1 , n + 1){
		if(i + k - 1 <= n) good = max(good , ans + x[i + k - 1] - x[i - 1]);
	}
	cout << good << endl;
    return 0;
}