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

VI E[50005];
VI W[50005];
int side[1000006];
int nTeam;
int n;
int sideN[50005][2];
int m;

int divide() {
	for (int i = 1; i <= nTeam; i++) {
		side[i] = rand() % 2;
	}

	for (int i = 1; i <= n; i++) {
		sideN[i][0] = sideN[i][1] = 0;
		for (int j : W[i]) {
			sideN[i][side[j]] = j;
			if (sideN[i][0] && sideN[i][1]) break;
		}
		if (sideN[i][0] == 0 || sideN[i][1] == 0) return 0;
	}
	return 1;
}

int team[50005];
int cost[50005];

void solve() {
	for (int i = 1; i <= n; i++) {
		team[i] = rand() % SZ(W[i]);
		team[i] = W[i][team[i]];
	}

	set<int> culprits;
	int lim = (m + 1) / 2;
	int now = 0;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j : E[i]) {
			temp += (side[team[i]] != side[team[j]]);
		}
		now += temp;
		cost[i] = temp;

		if (temp < (SZ(E[i]) + 1) / 2) {
			culprits.insert(i);
		}
	}
	now /= 2;

	while (now < lim) {
		assert(culprits.size() > 0);
		int g = *culprits.begin();
		culprits.erase(g);

		int prevTeam = team[g];
		int prevSide = side[prevTeam];
		int newSide = 1 ^ prevSide;
		int newTeam = sideN[g][newSide];

		team[g] = newTeam;
		now += (SZ(E[g]) - cost[g]) - cost[g];
		cost[g] = SZ(E[g]) - cost[g];
		for (int e : E[g]) {
			if (side[team[e]] == newSide) {
				cost[e]--;
				if (cost[e] < (SZ(E[e]) + 1) / 2) {
					culprits.insert(e);
				}
			}
			else {
				cost[e]++;
				if (cost[e] >= (SZ(E[e]) + 1) / 2) {
					culprits.erase(e);
				}
			}
		}

	}

}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}

	
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		for (int j = 0; j < t; j++) {
			int k;
			scanf("%d", &k);
			W[i].push_back(k);
			nTeam = MAX(nTeam, k);
		}
	}

	while (!divide());

	solve();

	for (int i = 1; i <= n; i++) {
		if (i > 1) printf(" ");
		printf("%d", team[i]);
	}
	printf("\n");
	for (int i = 1; i <= nTeam; i++) {
		if (i > 1) printf(" ");
		printf("%d", side[i] + 1);
	}
	printf("\n");

	return 0;
}