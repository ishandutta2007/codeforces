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
//typedef long long int LL;
typedef __int64 LL;

VI V[200005];
VI VV[200005];
int n;
LL x, y;

int case1Ok() {
	for (int i = 1; i <= n; i++) {
		if (SZ(V[i]) == n - 1) {
			return 0;
		}
	}
	return 1;
}

int vis[200005];
LL dp0[200005], dp1[200005];
int DP() {
	queue<int> Q;
	VI Z;
	Q.push(1);
	vis[1] = -1;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		Z.push_back(u);
		for (int v : V[u]) {
			if (!vis[v]) {
				VV[u].push_back(v);
				vis[v] = u;
				Q.push(v);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		int v = Z[i];
		if (SZ(VV[v]) == 0) {
			dp0[v] = dp1[v] = 1;
			continue;
		}
		LL sdp0 = 0;
		for (int u : VV[v]) {
			sdp0 += dp0[u];
		}
		dp0[v] = sdp0 + 1;
		dp1[v] = sdp0 + 1;
		for (int u : VV[v]) {
			dp1[v] = MIN(dp1[v], dp1[u] + (sdp0 - dp0[u]));
			dp0[v] = MIN(dp0[v], dp1[u] + (sdp0 - dp0[u]));
		}

		if (SZ(VV[v]) >= 2) {
			LL min0 = MIN(dp1[VV[v][0]] - dp0[VV[v][0]], dp1[VV[v][1]] - dp0[VV[v][1]]);
			LL min1 = MAX(dp1[VV[v][0]] - dp0[VV[v][0]], dp1[VV[v][1]] - dp0[VV[v][1]]);
			for (int j = 2; j < SZ(VV[v]); j++) {
				int u = VV[v][j];
				LL val = dp1[u] - dp0[u];
				if (val < min0) min1 = min0, min0 = val;
				else if (val < min1) min1 = val;
			}
			dp0[v] = MIN(dp0[v], sdp0 + min0 + min1 - 1);
		}
	}
	return MIN(dp0[Z[0]], dp1[Z[0]]);
}

int main()
{
	scanf("%d %I64d %I64d", &n, &x, &y);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		V[u].push_back(v);
		V[v].push_back(u);
	}

	if (n == 2) {
		printf("%I64d\n", x);
		return 0;
	}

	if (n == 3) {
		printf("%I64d\n", x + MIN(x, y));
		return 0;
	}

	LL ans = 1000000000;
	ans *= ans;

	if (case1Ok()) {
		ans = MIN(ans, (n - 1) * y);
	}
	ans = MIN(ans, (n - 2) * y + x);

	int f = DP();
	ans = MIN(ans, (f - 1) * y + (n - 1 - f + 1) * x);
	printf("%I64d\n", ans);

	return 0;
}