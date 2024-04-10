//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

int n, m, k;
int a[300100], b[300100];
vector<int> g[300100], f[300100], er;
set<int> q;

void imp() { printf("impossible\n"); exit(0); }

bool dfs(int u, int t){
	auto it = lower_bound(g[t].begin(), g[t].end(), u);
	if(it == g[t].end() || *it != u) return 1;
	for(auto v : f[u])
		if(dfs(v, t)) return 1;
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	cin >> n >> m >> k;
	FOR(i, 1, m){
		scanf("%d%d", a + i, b + i);
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
	}
	for(int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
	if(n - (int)g[1].size() - 1 < k) imp();
	for(int i = 2; i <= n; i++){
		er.clear();
		for(auto v : q)
			if(dfs(v, i)) f[i].pb(v), er.pb(v);
		for(auto v : er) q.erase(v);
		q.insert(i);
	}
	if((int)q.size() > k) imp();
	for(auto v : q)
		if(!dfs(v , 1)) imp();
	printf("possible\n");
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