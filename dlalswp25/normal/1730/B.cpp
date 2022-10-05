#include <bits/stdc++.h>

using namespace std;

int N;
int X[101010];
int T[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &X[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &T[i]);
		double l = *max_element(T + 1, T + N + 1);
		double r = 1e18;
		double ans;
		for(int _ = 0; _ < 100; _++) {
			double m = (l + r) / 2;
			double mxl = -1e18, mnr = 1e18;
			for(int i = 1; i <= N; i++) {
				mxl = max(mxl, X[i] - (m - T[i]));
				mnr = min(mnr, X[i] + (m - T[i]));
			}
			if(mxl <= mnr) r = m;
			else l = m;
			ans = mxl;
		}
		printf("%.10f\n", ans);
	}
	return 0;
}