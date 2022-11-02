/*input
5 2
1 -1
1 -5
2 -1
2 -1
1 -10
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
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , x[MAX] , v[MAX];
vector<int> g[MAX];
int cmp(vector<int> a , vector<int> b){
	return a.size() > b.size();
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i] >> v[i];
	REP(i , 1 , n + 1) g[x[i]].pb(v[i]);

	REP(i , 1 , m + 1){
		sort(g[i].begin() , g[i].end() , greater<int>());
		REP(j , 1 , g[i].size()) g[i][j] += g[i][j - 1];
	}
	sort(g + 1 , g + m + 1 , cmp);
	// REP(i , 1 , n + 1) {for(auto to : g[i]) cout << to << " "; cout << endl;}
	int ans = 0;
	REP(i , 1 , n + 1){
		int sum = 0;
		REP(j , 1 , m + 1){
			if(g[j].size() < i) break;
			else sum += max(0LL , g[j][i - 1]);
		}
		// DBGG(i , sum);
		ans = max(ans , sum);
	}
	cout << ans << endl;
    return 0;
}