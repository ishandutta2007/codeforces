//int!
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))
typedef long long ll;

int n, m;
vector<int> a;

int ksm(int a, int b){
	int res = 1;
	for(; b; b >>= 1, a = (ll)a * a % m)
		if(b & 1) res = (ll)res * a % m;
	return res;
}

pair<int, int> solve(vector<int> &a){
	if(n == 1) return {a[0], 1};
	int diff = a[1] - a[0], cnt = 0;
	for(int i = 0; i < n; ++i){
		int tmp = (a[i] + diff) % m;
		auto it = lower_bound(all(a), tmp);
		if(it != a.end() && *it == tmp) cnt++;
	}
	int k = n - cnt;
	int d = (ll)diff * ksm(k, m - 2) % m;

	int l = -1, r = 1, lt, rt;
	for(rt = (a[0] + d) % m; r - l <= n; rt = (rt + d) % m, ++r){
		auto it = lower_bound(all(a), rt);
		if(it == a.end() || *it != rt) break;
	}
	for(lt = (a[0] + m - d) % m; r - l <= n; lt = (lt + m - d) % m, --l){
		auto it = lower_bound(all(a), lt);
		if(it == a.end() || *it != lt) break;
	}
	if(r - l <= n) return {-1, -1};
	else return {(lt + d) % m, d};
}

pair<int, int> gao(){
	if(n == 1) return {a[0], 0};
	if(n == m) return {0, 1};
	if(2 * n <= m) return solve(a);
	else{
		vector<int> b;
		for(int i = 0, j = 0; i < m; ++i){
			if(j < n && i == a[j]) j++;
			else b.pb(i);
		}
		n = m - n;
		auto res = solve(b);
		res.fi = (res.fi + (ll)res.se * n) % m;
		return res;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		a.pb(x);
	}
	sort(all(a));
	auto ans = gao();
	if(ans.se == -1) printf("-1");
	else printf("%d %d\n", ans.fi, ans.se);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/