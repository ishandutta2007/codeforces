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
//typedef __int64 LL;

int col[200005];
VI V[200005];
int n;
VI ans;

void dfs(int at, int par) {
	int sz = SZ(V[at]);
	int child = -1;
	for (int i = 0; i < sz; i++) {
		int u = V[at][i];
		if (par == u) {
			continue;
		}
		ans.push_back(u);
		col[u] ^= 1;
		dfs(u, at);
		child = u;
	}

	if (at != 1 && col[at] == 0) {
		col[par] ^= 1;
		ans.push_back(par);
		col[at] ^= 1;
		ans.push_back(at);
	}

	if (par == -1) {
		if (col[1] == 0) {
			col[child] ^= 1;
			ans.push_back(child);
			col[1] ^= 1;
			ans.push_back(1);
			col[child] ^= 1;
			ans.push_back(child);
		}
	}
	else {
		col[par] ^= 1;
		ans.push_back(par);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &col[i]);
		if (col[i] == -1) col[i] = 0;
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		V[u].push_back(v);
		V[v].push_back(u);
	}

	int flag = 0;
	for (int i = 1; i <= n; i++) {
		if (col[i] == 0) flag = 1;
	}
	if (flag == 0) {
		printf("1\n");
		return 0;
	}

	ans.push_back(1);
	dfs(1, -1);
	int sz = SZ(ans);
	for (int i = 0; i < sz; i++) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}