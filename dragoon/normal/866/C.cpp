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

int N, R;
int f[100], s[100];
double p[100];
double G;
double dp[52][5003];
int marker[52][5003];
int mark = 0;

double DP(int at, int now) {
	if (at == N) {
		if (now <= R) {
			return 0;
		}
		else {
			return G;
		}
	}

	if (now > R) {
		return G;
	}

	double &ret = dp[at][now];
	if (marker[at][now] == mark) {
		return ret;
	}
	marker[at][now] = mark;
	ret = G;

	double x = p[at] * (f[at] + DP(at + 1, now + f[at]))
		+ (1 - p[at]) * (s[at] + DP(at + 1, now + s[at]));
	ret = MIN(ret, x);
	return ret;
}

double calc(double g) {
	G = g;
	mark++;

	return DP(0, 0);
}

int main()
{
	scanf("%d %d", &N, &R);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %lf", &f[i], &s[i], &p[i]);
		p[i] /= 100.0;
	}

	double lo = 0;
	double hi = 1e12;
	for (int i = 1; i <= 80; i++) {
		double mid = (lo + hi) / 2;
		double p = calc(mid);
		if (mid > p) hi = mid;
		else lo = mid;
	}

	double ans = (lo + hi) / 2.;
	printf("%.15lf\n", ans);
	return 0;
}