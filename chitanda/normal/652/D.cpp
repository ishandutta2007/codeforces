//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

int n, l[200100], r[200100], ans[200100], w[200100];

bool cmp(int a, int b) { return r[a] < r[b]; }

int c[200100];
void add(int x) { for(; x <= 200000; x += x & -x) c[x]++; }
int ask(int x) { int ans = 0; for(; x; x -= x & -x) ans += c[x]; return ans; }

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	vector<int> value;
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", l + i, r + i);
		value.pb(l[i]);
		w[i] = i;
	}
	sort(all(value));
	sort(w + 1, w + n + 1, cmp);
	set<int> q;
	for(int i = 1; i <= n; ++i){
		int L = lower_bound(all(value), l[w[i]]) - value.begin() + 1;
		ans[w[i]] = i - ask(L) - 1;
		add(L);
	}
	for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
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