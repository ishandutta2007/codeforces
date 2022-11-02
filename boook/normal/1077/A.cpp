/*input
6
5 2 3
100 1 4
1 10 5
1000000000 1 6
1 1 1000000000
1 1 999999999
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
#define int long long
const int INF = 0x3f3f3f3f;

int t , a , b , c;
int32_t main(){
	IOS;
	cin >> t;
	REP(times , 0 , t){
		cin >> a >> b >> c;
		int now = (a - b) * (c / 2);
		if(c % 2 == 1) now += a;
		cout << now << endl;
	}
    return 0;
}