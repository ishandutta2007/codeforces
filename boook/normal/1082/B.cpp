/*input
10
GGGSGGGSGG
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
#define MAX 200000
#define INF 0x3f3f3f3f

string s;
int x[MAX] , p[MAX];
int32_t main(){
	IOS;
	cin >> s >> s;
	int n = s.size();
	int all = 0 , ans = 0;

	REP(i , 1 , n + 1) x[i] = s[i - 1] == 'G' , all += s[i - 1] == 'G';

	REP(i , 1 , n + 1) if(x[i]) p[i] = p[i - 1] + x[i];
	RREP(i , n , 1) if(x[i]) p[i] = max(p[i] , p[i + 1]);
	// REP(i , 1 , n + 1) cout << p[i] << " "; cout << endl;
	REP(i , 1 , n + 1) ans = max(ans , p[i] + 1);
	REP(i , 2 , n + 0) if(x[i] == 0 && x[i - 1] == 1 && x[i + 1] == 1)
		ans = max(ans , p[i - 1] + p[i + 1] + 1);

	ans = min(ans , all);
	cout << ans << endl;
    return 0;
}