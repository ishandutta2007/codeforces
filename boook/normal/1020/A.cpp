/*input
3 6 2 3 3
1 2 1 3
1 4 3 4
1 2 2 3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int n , h , a , b , k;
int32_t main(){
	IOS;
	cin >> n >> h >> a >> b >> k;
	REP(tiems , 0 , k){
		int l , r , t , f , ans = 0;
		cin >> l >> r >> t >> f;
		if(l != t){
			if(b <= r) ans += r - b , r = b;
			if(r <= a) ans += a - r , r = a;
			ans += abs(t - l) , l = t;
		}
		ans += abs(r - f);
		cout << ans << endl;
	}
    return 0;
}