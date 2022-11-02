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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 500000
#define INF 0x3f3f3f3f

int n , m , a[MAX] , b[MAX] , x[MAX] , z[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;

	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , m + 1) cin >> b[i];
	if(m == 1) return cout << n << endl , 0;
	int pos = 0;
	REP(i , 2 , m + 1) x[pos++] = b[i] - b[i - 1];
	x[pos++] = INF;
	REP(i , 2 , n + 1) x[pos++] = a[i] - a[i - 1];

	int l = 0 , r = 0;
	REP(i , 0 , pos){
		z[i] = max(min(z[i - l] , r - i + 1) , 0);
		while(i + z[i] < pos && x[i + z[i]] == x[z[i]]){
			l = i , r = i + z[i] , z[i] ++;
		}
	}
	int ans = -1;
	REP(i , 0 , pos) ans += z[i] >= m - 1;
	cout << ans << endl;
    return 0;
}