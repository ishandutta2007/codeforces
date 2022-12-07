#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int N(1111);
int dis[N], idx[N], prv[N], prp[N], ind[N], lim[N];
bool vst[N], inq[N];
int inf(1e9);
struct Edge {
	int y, next, f, para;
	bool tp;
} edges[N];
int l(1);
int cst;
void build(int x, int y, int c, int para) {
	edges[++l].y = y;
	edges[l].para = para;
	edges[l].next = idx[x];
	edges[l].f = c;
	idx[x] = l;
}
void cnnt(int x, int y, int c, int para) {
	//printf("%d %d %d %d %d\n", x, y, c, para, tp);
	build(x, y, c, para);
	build(y, x, 0, -para);
}
int source, target;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(0); i < m; i++) {
		int x, y, c, f;
		scanf("%d%d%d%d", &x, &y, &c, &f);
		cst += max(0, f - c);
		if(f > c) {
			cnnt(x, y, f - c, 0);
			cnnt(x, y, c, 1);
		}else {
			cnnt(x, y, f, 1);
		}
		if(f < c) {
			cnnt(y, x, c - f, 1);
			cnnt(y, x, inf, 2);
		}else {
			cnnt(y, x, inf, 2);
		}
		lim[i] = c;
		ind[y] += f;
		ind[x] -= f;
	}
	source = n + 1;
	target = n + 2;
	for(int i(2); i < n; i++) {
		//printf("ind[%d] = %d\n", i,ind[i]);
		if(ind[i] > 0) {
			cnnt(i, target, ind[i], 0);
		}else if(ind[i] < 0) {
			cnnt(source, i, -ind[i], 0);
		}
	}
	if(ind[1] + ind[n] > 0) {
		cnnt(n, target, ind[1] + ind[n], 0);
	}else if(ind[1] + ind[n] < 0) {
		cnnt(source, 1, -(ind[1] + ind[n]), 0);
	}
	cnnt(1, n, inf, 0);
	cnnt(n, 1, inf, 0);
	for(;;) {
		fill(prv + 1, prv + 3 + n, 0);
		fill(prp + 1, prp + 3 + n, 0);
		fill(dis + 1, dis + 3 + n, inf);
		dis[source] = 0;
		static queue<int> q;
		q.push(source);
		inq[source] = true;
		while(!q.empty()) {
			int v(q.front());
			q.pop();
			inq[v] = false;
			for(int p(idx[v]); p; p = edges[p].next) {
				if(edges[p].f) {
					int delta(edges[p].para);
					int y(edges[p].y);
					if(dis[v] + delta < dis[y]) {
						//printf("v = %d, y = %d, dis[v] = %d, delta = %d, dis[y] = %d, f = %d\n", v, y, dis[v], delta, dis[y], edges[p].f);
						dis[y] = dis[v] + delta;
						prv[y] = v;
						prp[y] = p;
						if(!inq[y]) {
							q.push(y);
							inq[y] = true;
						}
					}
				}
			}
		}

		if(dis[target] < inf) {
			int x(target);
			int res(inf);
			while(prv[x]) {
				res = min(res, edges[prp[x]].f);
				x = prv[x];
			}
			x = target;
			while(prv[x]) {
				cst += edges[prp[x]].para * res;
				edges[prp[x]].f -= res;
				edges[prp[x] ^ 1].f += res;
				x = prv[x];
			}
		}else {
			break;
		}
	}
	printf("%d\n", cst);
}