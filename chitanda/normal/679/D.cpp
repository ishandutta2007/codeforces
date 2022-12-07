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
#define eps (1e-9)

const int maxn = 410;
int n, m, u, v;
double ans;
int d[maxn][maxn];
double posi[maxn];
double dis_maxp[maxn];
vector<int> g[maxn];

double next_day(int p, int dis){
	double ans = 0;
	memset(posi, 0, sizeof(posi));

	for(int i = 1; i <= n; ++i)
		if(d[p][i] == dis)
			for(auto v : g[i])
				posi[v] += 1. / n / g[i].size();
	
	vector<int> f;
	for(int i = 1; i <= n; ++i)
		if(posi[i] > eps) f.pb(i);
	
	for(int q = 1; q <= n; ++q){
		double res = 0;
		for(auto v : f)
				dis_maxp[d[q][v]] = max(dis_maxp[d[q][v]], posi[v]);
		for(auto v : f){
			res += dis_maxp[d[q][v]];
			dis_maxp[d[q][v]] = 0;
		}
		ans = max(ans, res);
	}
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	memset(d, 127, sizeof(d));
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", &u, &v);
		d[u][v] = d[v][u] = 1;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i = 1; i <= n; ++i) d[i][i] = 0;

	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(d[i][k] < 1e9 && d[k][j] < 1e9)
					d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
	
	for(int p = 1; p <= n; ++p){
		double res = 0;
		for(int dis = 0; dis < n; ++dis){
			int cnt = 0;
			for(int i = 1; i <= n; ++i) if(d[p][i] == dis) cnt++;
			if(!cnt) continue;
			double day1 = 1. / n;
			double day2 = next_day(p, dis);
			res += max(day1, day2);
		}
		ans = max(ans, res);
	}

	printf("%.10f\n", ans);
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