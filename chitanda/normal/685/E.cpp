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

const int maxm = 200100, maxn = 1010;

struct node{
	int l, r, s, t, id;
	void input(int w){
		id = w;
		scanf("%d%d%d%d", &l, &r, &s, &t);
	}
	bool operator < (const node &a) const { return l > a.l; }
}que[maxm];

int n, m, q, u[maxm], v[maxm], dis[maxn][maxn];
bool ans[maxm];

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", u + i , v + i);
	}
	for(int i = 1; i <= q; ++i){
		que[i].input(i);
	}
	sort(que + 1, que + q + 1);
	memset(dis, 127, sizeof(dis));
	for(int i = 1; i <= n; ++i) dis[i][i] = 0;
	for(int i = m, p = 1; i >= 1; --i){
		auto&& U = u[i];
		auto&& V = v[i];
		dis[U][V] = dis[V][U] = i;
		for(int j = 1; j <= n; ++j)
			if(j != U && j != V){
				dis[U][j] = min(dis[U][j], dis[V][j]);
				dis[V][j] = min(dis[V][j], dis[U][j]);
			}
		while(p <= q && que[p].l >= i){
			ans[que[p].id] = dis[que[p].s][que[p].t] <= que[p].r;
			p++;
		}
	}
	for(int i = 1; i <= q; ++i)
		printf("%s\n", ans[i] ? "Yes" : "No");
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