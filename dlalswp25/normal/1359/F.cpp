#include <bits/stdc++.h>

using namespace std;

int N;

int x[25252];
int y[25252];
int dx[25252];
int dy[25252];
int s[25252];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d%d%d%d%d", &x[i], &y[i], &dx[i], &dy[i], &s[i]);

	double ans = 1e18;
	for(int i = 1; i <= N; i++) {
		for(int j = i + 1; j <= N; j++) {
			int det = dx[i] * (-dy[j]) - dy[i] * (-dx[j]);

			double veli = sqrt(dx[i] * dx[i] + dy[i] * dy[i]);
			double velj = sqrt(dx[j] * dx[j] + dy[j] * dy[j]);
			if(det == 0) {
				if((y[j] - y[i]) * dx[i] != (x[j] - x[i]) * dy[i]) continue;

				int tx = x[j] - x[i];
				int ty = y[j] - y[i];

				if(tx) {
					if(dx[i] * tx < 0) {
						if(-dx[j] * tx < 0) {
							continue;
						}
						else ans = min(ans, fabs((double)tx / (s[j] * dx[j] / velj)));
					}
					else {
						ans = min(ans, fabs((double)tx / (s[i] * dx[i] / veli)));
						if(-dx[j] * tx > 0) {
							ans = min(ans, fabs((double)tx / (fabs(s[j] * dx[j] / velj) + fabs(s[i] * dx[i] / veli))));
						}
					}
				}
				else {
					if(dy[i] * ty < 0) {
						if(-dy[j] * ty < 0) {
							continue;
						}
						else ans = min(ans, fabs((double)ty / (s[j] * dx[j] / velj)));
					}
					else {
						ans = min(ans, fabs((double)ty / (s[i] * dx[i] / veli)));
						if(-dy[j] * ty > 0) {
							ans = min(ans, fabs((double)ty / (fabs(s[j] * dy[j] / velj) + fabs(s[i] * dy[i] / veli))));
						}
					}
				}

				continue;
			}

			int tx = x[j] - x[i];
			int ty = y[j] - y[i];

			int iu = -dy[j] * tx + dx[j] * ty;
			int iv = -dy[i] * tx + dx[i] * ty;

			// printf("%d %d %d %d %d %d %d\n", i, j, det, tx, ty, iu, iv);

			if((det > 0 && (iu < 0 || iv < 0)) || (det < 0 && (iu > 0 || iv > 0))) continue;

			// double u = (double)iu / det;
			// double v = (double)iv / det;

			// printf("%d %d %f %f\n", i, j, u, v);

			double t1 = iu * veli / (det * s[i]);
			double t2 = iv * velj / (det * s[j]);

			ans = min(ans, max(t1, t2));

			// printf("%d %d %f\n", i, j, ans);
		}
	}

	if(ans == 1e18) puts("No show :(");
	else printf("%.10f\n", ans);

	return 0;
}