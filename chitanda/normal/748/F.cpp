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

const int maxn = 200100;
int n, k, root;
vector<int> g[maxn];
bool tag[maxn];
int size[maxn];
queue<int> f[maxn];

void getroot(int t, int fa){
	size[t] = tag[t];
	int tmax = 0;
	for(auto v : g[t]){
		if(v == fa) continue;
		getroot(v, t);
		tmax = max(tmax, size[v]);
		size[t] += size[v];
	}
	tmax = max(tmax, 2 * k - size[t]);
	if(tmax <= k) root = t;
}

void dfs(int t, int fa, int c){
	if(tag[t]) f[c].push(t);
	for(auto v : g[t]){
		if(v == fa) continue;
		dfs(v, t, c);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	int a, b;
	for(int i = 1; i < n; ++i){
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	int x;
	for(int i = 1; i <= 2 * k; ++i){
		scanf("%d", &x);
		tag[x] = 1;
	}
	
	getroot(1, 0);

	auto cmp = [](int a, int b) { return f[a].size() < f[b].size(); };
	priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
	
	for(auto v : g[root]){
		dfs(v, root, v);
		q.push(v);
	}
	if(tag[root]){
		f[root].push(root);
		q.push(root);
	}

	printf("1\n%d\n", root);
	while(k--){
		auto t1 = q.top();
		q.pop();
		auto t2 = q.top();
		q.pop();
		a = f[t1].front();
		b = f[t2].front();
		f[t1].pop();
		f[t2].pop();
		if(!f[t1].empty()) q.push(t1);
		if(!f[t2].empty()) q.push(t2);
		printf("%d %d %d\n", a, b, root);
	}
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