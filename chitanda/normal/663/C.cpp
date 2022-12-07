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

int n, m, x, y;
char s[10];
vector<pair<int, bool> > g[100100];
vector<int> cnt, ans, f[2];
bool flag, cl[100100], vis[100100];

void dfs(int t, bool kt, bool k){
	vis[t] = 1; f[kt].pb(t); cl[t] = kt;
	for(auto v : g[t])
		if(!vis[v.fi]) dfs(v.fi, v.se ^ k ^ kt, k);
		else if(cl[v.fi] != (v.se ^ k ^ kt)) flag = 0;
}

void merge(vector<int> &a, const vector<int> b){
	for(auto v : b) a.pb(v);
}

bool work(bool k){
	memset(vis, 0, sizeof(vis));
	cnt.clear(); flag = 1;
	for(int i = 1; i <= n; i++)
		if(!vis[i]){
			f[0].clear(), f[1].clear();
			dfs(i, 0, k);
			if(!flag) return 0;
			if(f[0].size() < f[1].size()) merge(cnt, f[0]);
			else merge(cnt, f[1]);
		}
	if(cnt.size() < ans.size()) ans = cnt;
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		scanf("%d%d%s", &x, &y, s);
		g[x].pb(mkp(y, s[0] == 'B'));
		g[y].pb(mkp(x, s[0] == 'B'));
	}
	ans.resize(n + 1);
	bool t1 = work(0);
	bool t2 = work(1);
	if(!t1 && !t2) { printf("-1\n"); return 0; }
	printf("%d\n", (int)ans.size());
	for(auto v : ans) printf("%d ", v);
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