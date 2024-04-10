/*input
4 2
2 78 4 10
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
#define MAX 200800
#define INF 0x3f3f3f3f

int n , k , x[MAX] , siz[MAX] , ten[MAX];
map<PII , int> cc;
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1){
		int val = x[i];
		while(val > 0) val /= 10 , siz[i] ++;
	}
	REP(i , 1 , n + 1) x[i] %= k;
	REP(i , 1 , n + 1) cc[mp(siz[i] , x[i])] ++;

	ten[0] = 1;
	REP(i , 1 , 20 + 1) ten[i] = ten[i - 1] * 10 % k;

	int ans = 0;
	REP(i , 1 , n + 1) if((x[i] * ten[siz[i]] + x[i]) % k == 0) ans --;
	// cout << ans << endl;
	REP(i , 1 , n + 1) REP(j , 1 , 11){
		int tmp = x[i] * ten[j] % k;
		ans += cc[mp(j , (k - tmp) % k)];
	}
	cout << ans << endl;
    return 0;
}