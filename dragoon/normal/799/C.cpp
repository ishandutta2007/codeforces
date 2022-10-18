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

int n, c, d;

VP V[2];

int solve0() {
	int a = -1, b = -1;
	for (auto& p : V[0]) {
		if (p.second <= c) {
			a = MAX(p.first, a);
		}
	}
	for (auto& p : V[1]) {
		if (p.second <= d) {
			b = MAX(p.first, b);
		}
	}
	if (a == -1 || b == -1) return 0;
	return a + b;
}

bool cmp(PII A, PII B) {
	if (A.second != B.second) return A.second < B.second;
	return A.first < B.first;
}

int solve1(VP& V, int budget) {
	set<PII> S;
	int sz = SZ(V);
	sort(ALL(V), cmp);
	int ret = 0;
	for (int i = 0; i < sz; i++) {
		while (!S.empty()) {
			set<PII>::iterator iS = S.end();
			iS--;

			if (iS->second > budget - V[i].second) {
				S.erase(iS);
				continue;
			}
			ret = MAX(ret, V[i].first + iS->first);
			break;
		}
		S.insert(V[i]);
	}
	return ret;
}

int main()
{
	scanf("%d %d %d", &n, &c, &d);
	for (int i = 0; i < n; i++) {
		int b, p; char s[10];
		scanf("%d %d %s", &b, &p, s);
		int id = (s[0] == 'D');
		V[id].push_back(PII(b, p));
	}

	int ans1 = solve0();
	int ans2 = solve1(V[0], c);
	int ans3 = solve1(V[1], d);
	int ans = MAX(ans1, ans2);
	ans = MAX(ans, ans3);
	printf("%d\n", ans);

	return 0;
}