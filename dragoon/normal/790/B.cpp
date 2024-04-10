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

typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;
typedef vector<LL> VL;

int n, k;
VI adj[200005];
VL V[200005];
VL OV[200005];
LL ogota[200005];
LL gota[200005];
LL ans;

void dfs1(int at, int par) {
	VL now;
	now.resize(k);
	V[at].resize(k);
	for (int v : adj[at]) {
		if (v == par) continue;
		dfs1(v, at);
		gota[at] += gota[v];
		for (int i = 0; i < k; i++) now[i] += V[v][i];
	}

	ogota[at] = gota[at];
	OV[at] = now;

	now[0]++;
	gota[at] += now[k - 1];
	for (int i = 0; i < k; i++) {
		V[at][(i + 1) % k] = now[i];
	}
}

void dfs2(int at, int par, VL ohi, LL gotas) {
	//
	LL tt = 0;
	tt += gotas + ogota[at];
	for (int i = 1; i < k; i++) tt += ohi[i] + OV[at][i];
	ans += tt;
	//	printf(">>>>%d %d\n", at, tt);
	//

	gotas += ogota[at];
	for (int i = 0; i < k; i++) ohi[i] += OV[at][i];



	for (int v : adj[at]) {
		if (v == par) continue;
		gotas -= gota[v];
		for (int i = 0; i < k; i++) ohi[i] -= V[v][i];

		VL to_ohi; to_ohi.resize(k);
		LL to_gotas = gotas + ohi[k - 1];
		for (int i = 0; i < k; i++) {
			to_ohi[(i + 1) % k] = ohi[i];
		}
		if (k == 1) to_gotas++, to_ohi[0]++;
		else to_ohi[1]++;
		dfs2(v, at, to_ohi, to_gotas);

		gotas += gota[v];
		for (int i = 0; i < k; i++) ohi[i] += V[v][i];
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i < n; i++) {
		int u, v;
		//u = i, v = i + 1;
				scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1, -1);
	VL ohi(k, 0);
	dfs2(1, -1, ohi, 0);
	ans /= 2;
	printf("%I64d\n", ans);
	return 0;
}