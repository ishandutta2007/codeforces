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
int sub[130][10];
int solved[10];
int type[10];
int b[] = { 1, 2, 4, 8, 16, 32 };
int points[] = { 500, 1000, 1500, 2000, 2500, 3000 };
int ans = -1;

int can_beat() {
	int score[2];
	score[0] = score[1] = 0;
	for (int j = 0; j < 2; j++) {
		score[j] = 0;
		for (int i = 0; i < 5; i++) {
			if (sub[j][i] == -1) continue;
			score[j] += points[type[i]] / 250 * (250 - sub[j][i]);
		}
	}
	return score[0] > score[1];
}

int check(int z) {
	for (int i = 0; i < 5; i++) {
		LL hi = z, lo = 0;
		int c = type[i];
		// 1/b[c]*(120 + z) - solved[i] >= x.
		LL now = (n + z) / b[c] - solved[i];
		hi = MIN(hi, now);

		if (c <= 4) {
			// x > 1/b[c + 1] * (120 + z)- solved[i];
			LL k = (n + z) / b[c + 1] + 1;
			k -= solved[i];
			LL now = k;
			lo = MAX(lo, now);
		}
		else {
			// x >= - solved[i];
			LL now = -solved[i];
			lo = MAX(lo, now);
		}

		if (lo > hi) return 0;
		if (sub[0][i] == -1 && lo > 0) return 0;
	}
	return can_beat();
}

void pop(VI& Z, double _t) {
	int t = _t;
	if (t < 0) t = 0;
	for (int i = -5; i <= 5; i++) {
		int c = t + i;
		if (c < 0) continue;
		Z.push_back(c);
	}
}

VI findCandi() {
	VI Z;
	for (int i = 0; i < 5; i++) {
		int c = type[i];
		double t = solved[i] / (1. / b[c]) - n;
		pop(Z, t);
		if (c <= 4) {
			t = n*((1. / b[c + 1]) - solved[i]) / (1. - 1. / b[c + 1]);
			pop(Z, t);
		}
	}
	pop(Z, 0);
	set<int> SS(ALL(Z));
	VI _Z(ALL(SS));
	return _Z;
}

void bktk(int at) {
	if (at == 6) {
//		if (z == 0 && type[4] == 1)
//		if (z == 2 && type[0] == 1 && type[1] == 1 && type[2] == 0 && type[3] == 0 && type[4] == 0)
//		if (z == 1 && type[0] == 0 && type[1] == 2 && type[2] == 0 && type[3] == 1 && type[4] == 2)
			//type[4] = type[4];
		VI Zs = findCandi();
		for (int z : Zs) {
			if (check(z)) {
				if (ans == -1 || ans > z) ans = z;
			}
		}
		return;
	}

	for (int i = 0; i < 6; i++) {
		type[at] = i;
		bktk(at + 1);
	}
}

void possible() {
	bktk(0);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &sub[i][j]);
			if (sub[i][j] != -1) solved[j]++;
		}
	}

	{
		possible();
		if (ans != -1) {
//			for (int i = 0; i < 5; i++) printf("%d ", type[i]);
			printf("%d\n", ans);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}