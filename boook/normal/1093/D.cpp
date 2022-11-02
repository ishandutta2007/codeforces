/*input
2
2 1
1 2
4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define MAX 300900
#define INF 0x3f3f3f3f
#define mod 998244353LL

int t , n , m , u[MAX] , c[MAX];
vector<int> v[MAX];
int v1 = 0 , v2 = 0 , can = 0;
void DFS(int now , int col){
	if(col == 0) v1 ++;
	if(col == 1) v2 ++;

	u[now] = 1 , c[now] = col;
	for(auto to : v[now]){
		if(u[to] == 1){
			if(c[to] == c[now]) can = 0;
		}
		else {
			DFS(to , 1 - col);
		}
	}
}
int ppow(int a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
    if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int32_t main(){
	IOS;
	cin >> t;
	REP(times , 0 , t){
		cin >> n >> m;
		REP(i , 1 , n + 1) v[i].clear();
		REP(i , 1 , n + 1) u[i] = 0 , c[i] = 0;
		REP(i , 1 , m + 1){
			int a , b;
			cin >> a >> b;
			v[a].pb(b);
			v[b].pb(a);
		}
		can = 1;
		int cnt = 1;
		REP(i , 1 , n + 1){
			if(u[i] == 0){
				v1 = 0 , v2 = 0;
				DFS(i , 0);
				int val = 0;
				val = (val + ppow(2 , v1)) % mod;
				val = (val + ppow(2 , v2)) % mod;
				cnt = (cnt * val) % mod;
			}
		}
		if(can == 0) cout << 0 << endl;
		else cout << cnt << endl;
	}
    return 0;
}