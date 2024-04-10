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

typedef vector<LL> VL;
vector<pair<LL, int>> Z;

int check(int g) {
	int run = g, ends = 0;
	LL now = 1;
	for (int i = 0; i < SZ(Z); i++) {
		if (now == Z[i].first) {
			LL f = MIN(run, Z[i].second);
int ff = run -f;

			run = f;
ends-=MIN(ff,ends);
ends+=Z[i].second-f;
			now *= 2;
		}
		else if (Z[i].first < now) {
			ends+= Z[i].second;
		}
		else {
			return 0;
		}
		if (ends > run) return 0;
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	VL V;
	for (int i = 0; i < n; i++) {
		LL s;
		scanf("%lld", &s);
		V.push_back(s);
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			Z.push_back(make_pair(V[i], 1));
		}
		else {
			if (Z.back().first == V[i]) Z.back().second++;
			else Z.push_back(make_pair(V[i], 1));
		}
	}

	if (Z[0].first != 1) {
		printf("-1\n");
		return 0;
	}

	VI ans;
	int lo = (Z[0].second + 1) / 2;
	int hi = Z[0].second;
	for (int g = lo; g <= hi; g++) {
		if (check(g)) {
			ans.push_back(g);
		}
	}

	if (ans.empty()) {
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < SZ(ans); i++) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}