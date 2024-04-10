#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <utility>

#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define MOD 1000000007
#define Eps 1e-8
#define INF 1e10
#define MX 1005
#define MN 1000005
#define rep(i, n) for (int i = 0; i < n; i ++)

using namespace std;

typedef long long LL;


bool Equal(double x, double y) {
	return fabs(x - y) < Eps;
}

struct Point {
	double x, y, k;
	int input() {
		double a, b, c, d;
		scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
		x = a / b; y = c / d;
	}
	int circle_transform() {
		double z = x*x + y*y;
		x /= z; y /= z;
	}
	bool operator < (const Point &A) const {
		if (!Equal(x, A.x)) return x < A.x;
		if (!Equal(y, A.y)) return y < A.y;
		return k < A.k;
	}
	
}P[MX], Q[MN];

int N, n;

LL rlt;

int mul(LL &a, LL b) {
	a = a*b % MOD;
}

int sub(LL &a, LL b) {
	a -= b;
	if (a < 0) a += MOD;
}

int add(LL &a, LL b) {
	a += b; a %= MOD;
}

int main() {
	cin >> N;
	rep(i, N) {
		P[i].input();
		P[i].circle_transform();
	}
	
	rep(i, N) rep(j, i) {
		Q[n].x = (P[i].x + P[j].x);
		Q[n].y = (P[i].y + P[j].y);
		Q[n].k = Equal(P[i].x, P[j].x) ? INF: (P[i].y - P[j].y) / (P[i].x - P[j].x);
		n ++;
	}
	
	sort(Q, Q + n);
	
	LL cur, cnt;
	int i, j, k, id;
	
	for (i = 0; i < n;) {
		k = i;
		while (k < n && Equal(Q[k].x, Q[i].x) && Equal(Q[k].y, Q[i].y)) k ++;
		cur = 1LL; cnt = 1LL;
		for (j = i + 1; j < k; j ++) {
			if (Equal(Q[j].k, Q[j - 1].k)) cnt ++;
			else {
				mul(cur, 1 + cnt);
				cnt = 1;
			}
		}
		mul(cur, 1 + cnt);
		add(rlt, cur);
		sub(rlt, k - i + 1);
		i = k;
	}
	
	cout << rlt << endl;
		
	return 0;
}