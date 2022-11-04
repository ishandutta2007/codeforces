/* by Hyperhydrochloric Acid */
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

const int siz = 20005;

struct MinCostFlow {
	struct Edge {
		int to, cost, rev, id; int cap;
		Edge(int to, int cap, int cost, int rev, int id = 0): to(to), cost(cost), rev(rev), id(id), cap(cap) {}
	};
	vector<Edge> egs[siz + 5];
	ll dis[siz + 5], h[siz + 5];
	int prv[siz + 5], pre[siz + 5];
	bool inq[siz + 5];
	bool foo = 0;
	void inline clear() {
		loop(i, siz + 5) egs[i].clear();
	}
	void inline addedge(int u, int v, int cap = INF, int cost = 0, int id = 0) {
		if(cost < 0) foo = 1;
		egs[u].pub(Edge(v, cap, cost, SZ(egs[v]), id));
		egs[v].pub(Edge(u, 0, -cost, SZ(egs[u]) - 1, -id));
	}
	void inline adduedge(int u, int v, int cap = INF, int cost = 0, int id = 0) {
		if(cost < 0) foo = 1;
		egs[u].pub(Edge(v, cap, cost, SZ(egs[v]), id));
		egs[v].pub(Edge(u, 0, -cost, SZ(egs[u]) - 1, -id));
		egs[v].pub(Edge(u, cap, cost, SZ(egs[u]), id));
		egs[u].pub(Edge(v, 0, -cost, SZ(egs[v]) - 1, -id));
	}
	bool inline spfa(int s, int t) {
		memset(dis, Inf, sizeof(dis));
		deque<int> q;
		dis[s] = 0; q.pub(s);
		while(SZ(q)) {
			int x = q.front(); q.pop_front();
			inq[x] = 0;
			loop(i, SZ(egs[x])) {
				Edge &e = egs[x][i];
				if(e.cap && dis[e.to] > dis[x] + e.cost) {
					dis[e.to] = dis[x] + e.cost;
					prv[e.to] = x; pre[e.to] = i;
					if(!inq[e.to]) {
						if(SZ(q) && dis[e.to] > dis[q.front()]) q.pub(e.to);
						else q.push_front(e.to);
						inq[e.to] = 1;
					}
				}
			}
		}
		memcpy(h, dis, sizeof(dis)); foo = 0;
		return dis[t] < (INF >> 1);
	}
	bool inline dijkstra(int s, int t) {
		memset(dis, Inf, sizeof(dis));
		priority_queue<pair<int, int> > pq;
		dis[s] = 0; pq.push(mak(0, s));
		while(SZ(pq)) {
			pair<int, int> P = pq.top(); pq.pop();
			int x = P.second, dist = -P.first;
			if(dis[x] != dist) continue;
			loop(i, SZ(egs[x])) {
				Edge &e = egs[x][i];
				if(e.cap && dis[e.to] > dist + e.cost + h[x] - h[e.to]) {
					dis[e.to] = dist + e.cost + h[x] - h[e.to];
					prv[e.to] = x; pre[e.to] = i;
					pq.push(mak(-dis[e.to], e.to));
				}
			}
		}
		loop(i, siz + 5) {
			if(dis[i] < (INF >> 1)) h[i] += dis[i];
			else h[i] = INF;
		}
		return dis[t] < (INF >> 1);
	}
	pair<ll, int> inline get(int s, int t, int f = INF) {
		ll res = 0; int F = 0;
		while(f) {
			if(foo ? !spfa(s, t) : !dijkstra(s, t)) break;
			int fl = f;
			for(int i = t; i != s; i = prv[i]) {
				fl = min(fl, egs[prv[i]][pre[i]].cap);
			}
			f -= fl; F += fl; res += 1ll * fl * h[t];
			for(int i = t; i != s; i = prv[i]) {
				Edge &e = egs[prv[i]][pre[i]];
				e.cap -= fl;
				egs[e.to][e.rev].cap += fl;
			}
		}
		return mak(res, F);
	}
} nf;

int n;
int a[3005];
int in[3005], ou[3005], t1[3005], t7[3005], nds;

int main() {
	scanf("%d", &n);
	int s = 0, t;
	cont(i, n) {
		scanf("%d", a + i);
		in[i] = ++nds; ou[i] = ++nds;
		t1[i] = ++nds; t7[i] = ++nds;
		nf.addedge(in[i], ou[i], 1, -1);
	}
	t = ++nds;
	cont(i, n) {
		nf.addedge(s, in[i], 1);
		nf.addedge(ou[i], t, 1);
		nf.addedge(t1[i], in[i], 1);
		nf.addedge(t7[i], in[i], 1);
		circ(j, i + 1, n) if(a[i] % 7 == a[j] % 7) {
			nf.addedge(ou[i], t7[j], 1);
			nf.addedge(t7[i], t7[j]);
			break;
		}
		circ(j, i + 1, n) if(a[i] + 1 == a[j]) {
			nf.addedge(ou[i], t1[j], 1);
			break;
		}
		circ(j, i + 1, n) if(a[i] - 1 == a[j]) {
			nf.addedge(ou[i], t1[j], 1);
			break;
		}
		circ(j, i + 1, n) if(a[i] == a[j]) {
			nf.addedge(t1[i], t1[j]);
			break;
		}
	}
	printf("%lld\n", -nf.get(s, t, 4).first);
	return 0;
}