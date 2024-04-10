/*input
5 5 10
1 2 4 8 16
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
#define MAX 100
#define INF 0x3f3f3f3f

int n , m , k , x[MAX];
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , m + 1) cin >> x[i];

	int ans = 0 , sum = 0;
	sort(x + 1 , x + 1 + m);
	REP(i , 1 , m + 1) sum += x[i];

	REP(i , 0 , n + 1){
		int base = i * sum , las = k - base , nn = n - i , val = i * (m + 1);
		if(las < 0) break;
		REP(j , 1 , m + 1){
			int sml = min(nn , las / x[j]);
			val += sml;
			las -= sml * x[j];
		}
		ans = max(ans , val);
	}
	cout << ans << endl;
    return 0;
}