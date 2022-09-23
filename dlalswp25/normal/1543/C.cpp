#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-7;

double ans;
double C, M, P, V;

void f(double prob, int cnt) {
	ans += cnt * prob * P;
	double tc = C, tm = M, tp = P;

	if(C > 0) {
		double nxt = prob * C;
		if(C > V) {
			C -= V;
			(M <= eps ? P : M) += V / 2;
			P += V / 2;
			f(nxt, cnt + 1);
			C = tc;
			M = tm;
			P = tp;
		}
		else {
			(M <= eps ? P : M) += C / 2;
			P += C / 2;
			C = 0.0;
			f(nxt, cnt + 1);
			C = tc;
			M = tm;
			P = tp;
		}
	}
	if(M > 0) {
		double nxt = prob * M;
		if(M > V) {
			M -= V;
			(C <= eps ? P : C) += V / 2;
			P += V / 2;
			f(nxt, cnt + 1);
			C = tc;
			M = tm;
			P = tp;
		}
		else {
			(C <= eps ? P : C) += M / 2;
			P += M / 2;
			M = 0.0;
			f(nxt, cnt + 1);
			C = tc;
			M = tm;
			P = tp;
		}
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ans = 0.0;
		scanf("%lf%lf%lf%lf", &C, &M, &P, &V);
		f(1.0, 1);
		printf("%.10f\n", ans);
	}
	return 0;
}