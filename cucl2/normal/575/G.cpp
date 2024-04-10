/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int n, m;
vector<pair<int, int> > nei[1 << 17];
int dis[1 << 17], fa[1 << 17];
int sid[1 << 17], af[1 << 17];
pair<int, int> pre[1 << 17];

void inline bfs(int now, int dis[1 << 17], int fa[1 << 17], int mode) {
	memset(dis, Inf, sizeof(int) * (1 << 17));
	dis[now] = 0;
	queue<int> q; q.push(now);
	while(SZ(q)) {
		int x = q.front(); q.pop();
		loop(i, SZ(nei[x])) {
			int to = nei[x][i].first;
			if(nei[x][i].second && mode) continue;
			if(dis[to] > dis[x] + 1) {
				dis[to] = dis[x] + 1;
				fa[to] = x;
				q.push(to);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	cont(i, m) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		nei[a].pub(mak(b, c));
		nei[b].pub(mak(a, c));
	}
	bfs(0, dis, fa, 0);
	bfs(n - 1, sid, af, 1);
	loop(i, n) pre[i] = mak(Inf, Inf);
	int wei = Inf;
	loop(i, n) if(sid[i] != Inf) {
		wei = min(wei, dis[i]);
	}
	set<int> c;
	loop(i, n) if(sid[i] != Inf && dis[i] == wei) {
		c.insert(i);
		pre[i] = mak(sid[i], i);
	}
	loop(i, wei) {
		set<int> nc;
		int mn = 10;
		foreach(it, c) {
			int i = *it;
			loop(j, SZ(nei[i])) {
				int to = nei[i][j].first;
				if(dis[to] != dis[i] - 1) continue;
				if(nei[i][j].second < mn) {
					mn = nei[i][j].second;
					nc.clear();
				}
				if(nei[i][j].second == mn) {
					if(nc.count(to)) {
						pre[to] = min(pre[to], mak(pre[i].first, i));
					} else {
						nc.insert(to);
						pre[to] = mak(pre[i].first, i);
					}
				}
			}
		}
		printf("%d", mn);
		c = nc;
	}
	if(!wei) printf("0");
	puts("");
	printf("%d\n", wei + pre[0].first + 1);
	int now = 0;
	loop(i, wei) {
		printf("%d ", now);
		now = pre[now].second;
	}
	loop(i, pre[0].first + 1) {
		printf("%d ", now);
		now = af[now];
	}
	puts("");
	return 0;
}

/**
 * 
 *   0 
 *  
 *  
 */