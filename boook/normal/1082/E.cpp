/*input
6 6
6 6 9 9 6 6
*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i, j, k)  for(int i = j; i <  k; ++ i)
#define RREP(i, j, k) for(int i = j; i >= k; -- i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int, int>
#define ALL(i) i.begin(), i.end()
#define DBGG(i, j) cout << i << " " << j << endl
#define DB4(i, j, k, l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0), cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 500900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , p[MAX] , b[MAX];
vector<int> v[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) v[x[i]].pb(i);
	
	int ans = 0;
	REP(i , 1 , n + 1) p[i] = p[i - 1] + (x[i] == m);
	RREP(i , n , 1)    b[i] = b[i + 1] + (x[i] == m);
	ans = max(ans , p[n]);

	REP(i , 1 , MAX) if(i != m){
		int big = -INF;
		REP(j , 0 , v[i].size()){
			big = max(big ,  -j + 1 + p[v[i][j]]);
			ans = max(ans , big + j + b[v[i][j]]);
		}
	}

	cout << ans << endl;
    return 0;
}