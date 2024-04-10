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
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

typedef pair<int,int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

int a[200005], c[200005];
int in[200005];
int vis[200005];

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) in[a[i]]++;

	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			vis[i] = 1;
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		int v = a[u];
		in[v]--;
		if (in[v] == 0) {
			vis[v] = 1;
			Q.push(v);
		}
	}

	LL ans = 0;
	// vis[i] = 0, means in a cycle.
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		int j = i;
		vis[i] = 1;
		int now = c[i];
		while (true) {
			j = a[j];
			vis[j] = 1;
			now = MIN(now, c[j]);
			if (j == i) break;
		}
		ans += now;
	}
	printf("%lld\n", ans);
	return 0;
}