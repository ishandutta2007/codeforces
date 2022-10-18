#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

#define MAXN 200005
#define LOG2_MAXN 19

struct Centroid_Decomposition
{
	vector<int> V[MAXN];
	int n; //1..n
		   // pri = Primary tree (rooted at 1).
	int priDepth[MAXN], priParent[MAXN];
	// temporary arrays, used to contruct auxiliary tree of centroid decomposition.
	int tmpOrder[MAXN], tmpParent[MAXN], tmpSize[MAXN], tmpUsed[MAXN];
	// Parent and root of auxiliary tree.
	int auxParent[MAXN], auxRoot;

	// Lca parent information of primary tree.
	int lcaParent[LOG2_MAXN][MAXN];
	int step;

	void set(int _n) {
		n = _n;
		for (int i = 1; i <= n; i++) V[i].clear();
	}

	void add_edge(int parent, int child) {
		V[parent].push_back(child);
		V[child].push_back(parent);
	}

	void priLcaPreprocess() {
		for (step = 0; n > (1 << step); step++);
		for (int i = 1; i <= n; i++) lcaParent[0][i] = priParent[i];
		for (int i = 1; i <= step; i++) {
			for (int j = 1; j <= n; j++) {
				lcaParent[i][j] = lcaParent[i - 1][lcaParent[i - 1][j]];
			}
		}
	}

	// Return distance (number of edges) between two nodes in primary tree.
	int priDistance(int u, int v) {
		if (priDepth[u] < priDepth[v]) swap(u, v);

		int ret = 0;
		for (int i = step; i >= 0; i--) {
			if (priDepth[u] - (1 << i) >= priDepth[v]) {
				u = lcaParent[i][u];
				ret += 1 << i;
			}
		}

		for (int i = step; i >= 0; i--) {
			if (lcaParent[i][u] == lcaParent[i][v]) continue;

			ret += 2 * (1 << i);
			u = lcaParent[i][u];
			v = lcaParent[i][v];
		}

		while (u != v) {
			ret += 2;
			u = lcaParent[0][u];
			v = lcaParent[0][v];
		}
		return ret;
	}

	void decompose() {
		CLR(tmpUsed);
		CLR(auxParent);

		bfs();
		auxRoot = centroid_decompose(1);
	}

	int centroid_decompose(int at)
	{
		tmpOrder[0] = at;
		tmpParent[at] = -1;

		// First list all the remaining nodes in tmpOrder
		// and also their parents (not necessarily true parent).
		int r = 1;
		for (int l = 0; l < r; l++)
		{
			int u = tmpOrder[l];
			for (int v : V[u]) {
				if (tmpParent[u] == v || tmpUsed[v]) continue;
				tmpOrder[r++] = v;
				tmpParent[v] = u;
			}
		}

		int center = -1, mxsz = MAXN;
		for (int i = r - 1; i >= 0; i--) {
			int u = tmpOrder[i];
			tmpSize[u] = 1;

			int cursz = 0;
			for (int v : V[u]) {
				if (tmpParent[u] == v || tmpUsed[v]) continue;
				tmpSize[u] += tmpSize[v];
				cursz = MAX(cursz, tmpSize[v]);
			}
			cursz = MAX(cursz, r - tmpSize[u]);
			if (cursz < mxsz) {
				mxsz = cursz;
				center = u;
			}
		}

		tmpUsed[center] = 1;
		for (int v : V[center]) {
			if (!tmpUsed[v]) auxParent[centroid_decompose(v)] = center;
		}
		return center;
	}

	// Does a bfs from 1. Populates priParent and priDepth.
	void bfs() {
		queue<int> Q;

		priParent[1] = -1;
		priDepth[1] = 0;
		Q.push(1);

		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();

			for (int v : V[u]) {
				if (priParent[u] == v) continue;
				priParent[v] = u;
				priDepth[v] = priDepth[u] + 1;
				Q.push(v);
			}
		}
	}

	int closestRed[MAXN];
	void PaintRed(int at) {
		int now = at;
		while (true) {
			int dist = priDistance(at, now);
			closestRed[now] = MIN(closestRed[now], dist);
			if (now == auxRoot) break;
			now = auxParent[now];
		}
	}

	int Query(int at) {
		int now = at;
		int ret = MAXN;
		while (true) {
			int dist = priDistance(at, now);
			ret = MIN(ret, closestRed[now] + dist);
			if (now == auxRoot) break;
			now = auxParent[now];
		}
		return ret;
	}

	void solve(int q) {
		priLcaPreprocess();
		for (int i = 1; i <= n; i++) closestRed[i] = MAXN;
		PaintRed(1);

		while (q--) {
			int t, v;
			scanf("%d %d", &t, &v);
			if (t == 1) PaintRed(v);
			else {
				int ans = Query(v);
				printf("%d\n", ans);
			}
		}
	}
};

int n, m;

Centroid_Decomposition Tree;

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	scanf("%d %d", &n, &m);
	Tree.set(n);

	FORAB(i, 2, n)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		Tree.add_edge(u, v);
	}

	Tree.decompose();
	Tree.solve(m);

	return 0;
}