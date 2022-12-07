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

const int xx[] = {1, -1, 0, 0};
const int yy[] = {0, 0, 1, -1};
int n, m;
ll k;
ll res;
int a[1010][1010], b[1010 * 1010], fa[1010 * 1010], size[1010 * 1010];
bool vis[1010][1010];
vector<int> q;

inline int get(int x, int y) { return (x - 1) * m + y; }
inline int getx(int p) { return (p - 1) / m + 1; }
inline int gety(int p) { return p - (getx(p) - 1) * m; }

inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y){
	int xx = find(x), yy = find(y);
	if(xx == yy) return;
	fa[xx] = yy;
	size[yy] += size[xx];
}

void dfs(int x, int y, int v){
	a[x][y] = v;
	vis[x][y] = 1;
	res += v;
	for(int i = 0; i < 4; ++i)
		if(a[x + xx[i]][y + yy[i]] >= v && res < k && !vis[x + xx[i]][y + yy[i]]){
			dfs(x + xx[i], y + yy[i], v);
		}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%I64d", &n, &m, &k);
	//if(k > n * m) { puts("-1"); return 0; }
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			scanf("%d", a[i] + j);
			int p = get(i, j);
			b[p] = a[i][j];
			q.pb(p);
		}
	sort(all(q), [](const int &x, const int &y) { return b[x] > b[y]; });
	for(int u : q){
		int x = getx(u), y = gety(u);
		fa[u] = u; size[u] = 1;
		for(int j = 0; j < 4; ++j)
			if(fa[get(x + xx[j], y + yy[j])] != 0) merge(u, get(x + xx[j], y + yy[j]));
		if((ll)size[find(u)] * b[u] >= k && k % b[u] == 0){ 
			puts("YES");
			dfs(x, y, b[u]); 
			for(int i = 1; i <= n; printf("\n"), ++i)
				for(int j = 1; j <= m; ++j)
					printf("%d ", vis[i][j] ? a[i][j] : 0);
			return 0;
		}
	}
	puts("NO");
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