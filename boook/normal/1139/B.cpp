/*input
5
1 2 1 3 6
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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , x[MAX] , sum = 0;
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	x[n + 1] = x[n] + 1;
	RREP(i , n , 1){
		x[i] = max(0LL , min(x[i] , x[i + 1] - 1)) , sum += x[i];
	}
	cout << sum << endl;
    return 0;
}