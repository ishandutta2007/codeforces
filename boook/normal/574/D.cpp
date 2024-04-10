#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200000
#define INF 0x3f3f3f3f

int n , x[MAX] , o[MAX];

int32_t main(){

	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];

	REP(i , 1 , n + 1) o[i] = x[i];

	int tmp = INF;
	REP(i , 1 , n + 1){
		tmp = min(tmp + 1 , x[i - 1] + 1);
		o[i] = min(o[i] , tmp);
	}
	tmp = INF;
	RREP(i , n , 1){
		tmp = min(tmp + 1 , x[i + 1] + 1);
		o[i] = min(o[i] , tmp);
	}
	
	int ans = 0;
	REP(i , 1 , n + 1) ans = max(ans , o[i]);
	cout << ans << endl;
    return 0;
}