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
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

int n;
VI V[200005], Vd[200005];
int vis[200005];
const LL MOD = 1000000007;

int bfs(int at, int dir) {
	queue<int> Q;
	Q.push(at);
	vis[at] = 1;
	int sz = 1;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

		{
			for (int v : Vd[u]) {
				if (vis[v]) continue;
				Q.push(v);
				vis[v] = 1;
				sz++;
			}
		}

		if (dir == 0) {
			for (int v : V[u]) {
				if (vis[v]) continue;
				Q.push(v);
				vis[v] = 1;
				sz++;
			}
		}
	}
	return sz;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		V[u].push_back(v);
		Vd[v].push_back(u);
	}

	LL ans = 1;
	for (int i = 1; i <= 2 * n; i++) {
		if (SZ(V[i]) == 0 && SZ(Vd[i]) != 0) {
			int sz = bfs(i, -1);
			ans = (ans * sz) % MOD;
		}

		if (SZ(V[i]) == 1 && V[i][0] == i) {
			int sz = bfs(i, -1);
			ans = (ans * 1) % MOD;
		}
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (vis[i] == 1) continue;
		if (SZ(V[i]) == 0 && SZ(Vd[i]) == 0) continue;
		bfs(i, 0);
		ans = (ans * 2) % MOD;
	}

	printf("%lld\n", ans);



	return 0;
}