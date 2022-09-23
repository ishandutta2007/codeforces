#include <bits/stdc++.h>

using namespace std;
typedef pair<double, int> pdi;

int N;
int X[100005];
int Y[100005];
vector<pdi> V;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d%d", &X[i], &Y[i]);
	for(int i = 1; i <= N; i++) {
		if((long long)Y[1] * Y[i] < 0) {
			puts("-1"); return 0;
		}
	}
	if(Y[1] < 0) for(int i = 1; i <= N; i++) Y[i] *= (-1);
	int M = 0; for(int i = 1; i <= N; i++) M = max(M, Y[i]);

	double l = M / 2.0, r = 1.0;
	for(int i = 1; i <= 50; i++) r *= 2;

	for(int k = 0; k < 80; k++) {
		double m = (l + r) / 2.0;

		for(int i = 1; i <= N; i++) {
			double q = sqrt(max(0.0, 2 * m * Y[i] - (double)Y[i] * Y[i]));
			V.push_back(pdi(X[i] - q, 1));
			V.push_back(pdi(X[i] + q, -1));
		}
		sort(V.begin(), V.end());

		int c = 0, I = 0;
		for(auto i : V) {
			c += i.second;
			I = max(I, c);
		}
		//printf("%d\n", I);
		if(I == N) r = m;
		else l = m;
		V.clear();
	}
	printf("%.10f\n", l);
	return 0;
}