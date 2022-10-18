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

int n, m;
int pp[100][100];
map<pair<int, VI>, pair<double, double> > M;

pair<double, double> DP(int id, VI V, int score) {
	auto z = make_pair(id, V);
	if (SZ(V) == 1) {
		return make_pair(1., 0);
	}
	if (M.find(z) != M.end()) {
		return M[z];
	}


	double retP = -100;
	double retE = -100;
	int side[100];

	VI V1, V2;
	int sz = SZ(V);
	for (int i = 0; i < sz; i++) {
		if (i < sz / 2) {
			V1.push_back(V[i]);
			side[V[i]] = 0;
		}
		else {
			V2.push_back(V[i]);
			side[V[i]] = 1;
		}
	}

	vector<pair<double, double> > Z;
	VI V3;
	pair<double, double> sideZ;
	if (side[id] == 0) {
		sideZ = DP(id, V1, score>>1);
		V3 = V2;
	}
	else {
		sideZ = DP(id, V2, score >> 1);
		V3 = V1;
	}

	for (int i : V3) {
		Z.push_back(DP(i, V3, score >> 1));
	}

	retP = 0;
	for (int i = 0; i < SZ(V3); i++) {
		retP += Z[i].first * pp[id][V3[i]];
	}
	retP *= sideZ.first / 100.0;

	retE = sideZ.second;
	retE += score * retP;
	double ff = -100;
	for (int i = 0; i < SZ(V3); i++) {
		ff = MAX(ff, Z[i].second);
	}
	retE += ff;

	auto zz = make_pair(retP, retE);
	return M[z] = zz;
}

int main()
{
	scanf("%d", &n);
	m = 1 << n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &pp[i][j]);
		}
	}

	VI V;
	for (int i = 0; i < m; i++) V.push_back(i);
	double ans = -100;
	for (int i = 0; i < m; i++) {
		auto now = DP(i, V, 1 << (n - 1));
		ans = MAX(ans, now.second);
	}
	printf("%.12lf\n", ans);


	return 0;
}