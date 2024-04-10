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
struct point {
	double x, y;
	void scan() {
		scanf("%lf %lf", &x, &y);
	}
};

point rect[2];
point mousePos[100005], mouseVel[100005];

int comp(double a, double b) {
	double d = a - b;
	if (ABS(d) < 1e-7) return 0;
	if (a < b) return -1;
	return 1;
}

int inside(double x, double y) {
	return (comp(x, rect[0].x) >= 0 && comp(y, rect[0].y) >= 0 &&
		comp(x, rect[1].x) <= 0 && comp(y, rect[1].y) <= 0);
}

double solve() {
	vector<pair<double, int>> D;

	for (int i = 0; i < n; i++) {
		if (comp(mouseVel[i].x, 0) == 0 && comp(mouseVel[i].y, 0) == 0) {

			if (comp(mousePos[i].x, rect[0].x) > 0 && comp(mousePos[i].y, rect[0].y) > 0 &&
				comp(mousePos[i].x, rect[1].x) < 0 && comp(mousePos[i].y, rect[1].y) < 0);
			else return -1000.;

			continue;
		}

		if (comp(mousePos[i].x, rect[0].x) == 0 && comp(mouseVel[i].x, 0) == 0) return -1000.0;
		if (comp(mousePos[i].x, rect[1].x) == 0 && comp(mouseVel[i].x, 0) == 0) return -1000.0;
		if (comp(mousePos[i].y, rect[0].y) == 0 && comp(mouseVel[i].y, 0) == 0) return -1000.0;
		if (comp(mousePos[i].y, rect[1].y) == 0 && comp(mouseVel[i].y, 0) == 0) return -1000.0;

		vector<double> V;
		if (comp(mousePos[i].x, rect[0].x) >= 0 && comp(mousePos[i].y, rect[0].y) >= 0 &&
			comp(mousePos[i].x, rect[1].x) <= 0 && comp(mousePos[i].y, rect[1].y) <= 0) {
			V.push_back(0);
		}

		double x, y, t;
		if (comp(mouseVel[i].x, 0) != 0) {
			t = (rect[0].x - mousePos[i].x) / mouseVel[i].x;
			if (comp(t, 0) >= 0) {
				x = mousePos[i].x + t * mouseVel[i].x;
				y = mousePos[i].y + t * mouseVel[i].y;
				if (inside(x, y)) V.push_back(t);
			}
		}
		if (comp(mouseVel[i].x, 0) != 0) {
			t = (rect[1].x - mousePos[i].x) / mouseVel[i].x;
			if (comp(t, 0) >= 0) {
				x = mousePos[i].x + t * mouseVel[i].x;
				y = mousePos[i].y + t * mouseVel[i].y;
				if (inside(x, y)) V.push_back(t);
			}
		}
		if (comp(mouseVel[i].y, 0) != 0) {
			t = (rect[0].y - mousePos[i].y) / mouseVel[i].y;
			if (comp(t, 0) >= 0) {
				x = mousePos[i].x + t * mouseVel[i].x;
				y = mousePos[i].y + t * mouseVel[i].y;
				if (inside(x, y)) V.push_back(t);
			}
		}
		if (comp(mouseVel[i].y, 0) != 0) {
			t = (rect[1].y - mousePos[i].y) / mouseVel[i].y;
			if (comp(t, 0) >= 0) {
				x = mousePos[i].x + t * mouseVel[i].x;
				y = mousePos[i].y + t * mouseVel[i].y;
				if (inside(x, y)) V.push_back(t);
			}
		}

		if (SZ(V) == 0) return -1000.0;
		sort(ALL(V));

		D.push_back(make_pair(V[0], 1));
		D.push_back(make_pair(V.back(), -1));
	}

	sort(ALL(D));
	int n = SZ(D) / 2;
	if (n == 0) return 0.0;
	int run = 0;
	for (int i = 0; i < D.size(); i++) {
		run += D[i].second;
		if (run == n) return D[i].first;
	}
	return -1000.0;
}

int main()
{
	scanf("%d", &n);
	rect[0].scan();
	rect[1].scan();

	for (int i = 0; i < n; i++) {
		mousePos[i].scan();
		mouseVel[i].scan();
	}

	double ans = solve();

	if (ans < -10) printf("-1\n");
	else printf("%.10lf\n", ans);
	return 0;
}