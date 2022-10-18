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

struct Team {
	LL balloon, weight;
	int id;
};
Team team[300005];

bool operator<(Team A, Team B) {
	if (A.balloon != B.balloon)
		return A.balloon > B.balloon;
	return A.id < B.id;
}

priority_queue<LL> PQ;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		team[i].id = i;
		scanf("%I64d %I64d", &team[i].balloon, &team[i].weight);
	}
	LL bb = team[0].balloon;
	sort(team, team + n);

	int pos = 0;
	int best = 1;
	for (int i = 0; i < n; i++) {
		if (team[i].id == 0) pos = i;
		if (team[i].balloon > bb) best++;
	}

	for (int i = 0; i < pos; i++) {
		PQ.push(-(team[i].weight - team[i].balloon));
	}

	LL we_have = team[pos].balloon;
	int cur = best;
	while (!PQ.empty()) {
		LL u = -PQ.top();
		we_have -= u + 1;
		PQ.pop();

		if (we_have < 0) break;
		cur--;
		while (pos + 1 < n && team[pos + 1].balloon > we_have) {
			cur++;
			PQ.push(-(team[pos + 1].weight - team[pos + 1].balloon));
			pos++;
		}
		best = MIN(best, cur);
	}

	printf("%d\n", best);
	return 0;
}