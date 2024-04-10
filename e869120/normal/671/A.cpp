#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
long double ax, ay, bx, by, tx, ty, p[100000], q[100000], s; int n;
vector<pair<long double, int>>E1, E2;
long double dst(long double a1, long double a2, long double a3, long double a4) {
	return sqrtl((a1 - a3)*(a1 - a3) + (a2 - a4)*(a2 - a4));
}
int main() {
	cin >> ax >> ay >> bx >> by >> tx >> ty >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> q[i]; s += dst(p[i], q[i], tx, ty)*2.0L;
		E1.push_back(make_pair(dst(p[i], q[i], ax, ay) - dst(p[i], q[i], tx, ty), i));
		E2.push_back(make_pair(dst(p[i], q[i], bx, by) - dst(p[i], q[i], tx, ty), i));
	}
	if (n == 1) { s += min(E1[0].first, E2[0].first); }
	else {
		sort(E1.begin(), E1.end());
		sort(E2.begin(), E2.end());
		long double P1 = s + E1[0].first;
		long double P2 = s + E2[0].first;
		long double P3 = s + E1[0].first + E2[0].first; if (E1[0].second == E2[0].second)P3 = 1e18;
		long double P4 = s + E1[0].first + E2[1].first; if (E1[0].second == E2[1].second)P4 = 1e18;
		long double P5 = s + E1[1].first + E2[0].first; if (E1[1].second == E2[0].second)P5 = 1e18;
		s = min({ P1,P2,P3,P4,P5 });
	}
	printf("%.12Lf\n", s);
	return 0;
}