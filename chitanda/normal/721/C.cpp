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

int n, m, T;
int u, v, w;
int f[5010][5010], from[5010][5010], ru[5010];
vector<pair<int, int> >g[5010];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &T);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d%d", &u, &v, &w);
		g[u].pb(mkp(v, w));
		ru[v]++;
	}

	queue<int> q;
	for(int i = 1; i <= n; ++i)
		if(!ru[i]) q.push(i);
	memset(f, 127, sizeof(f));
	f[1][1] = 0;
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(auto e : g[t]){
			int v = e.fi, w = e.se;
			for(int i = 1; i <= n; ++i)
				if(f[t][i] <= 1e9)
					if(ckmin(f[v][i + 1], f[t][i] + w)) from[v][i + 1] = t;
			ru[v]--;
			if(!ru[v]) q.push(v);
		}
	}
	for(int i = n; i >= 1; --i)
		if(f[n][i] <= T){
			printf("%d\n", i);
			int now = n, x = i;
			vector<int> q; q.pb(n);
			while(from[now][x]) q.pb(from[now][x]), now = from[now][x], x--;
			for(int j = i - 1; j >= 0; --j) printf("%d ", q[j]);
			break;
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