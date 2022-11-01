#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5010;

double f[N][N];

int n, p[N], last[N], m;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &p[i], &last[i]);
	}

	double answer = 0;
	f[1][0] = 1;
	for(int i = 1; i <= n; i++) {
		double cst =  (100. - p[i]) / 100., sum = 0, s2 = 0, power = 1;
		for(int j = 1; j < last[i]; j++) {
			power = power * cst;
		}
		for(int j = 1; j <= m; j++) {
			if (f[i][j] < 1e-20) {
				f[i][j] = 0;
			}
			sum *= cst;
			if (j) {
				sum += f[i][j - 1];
			}
			if (j >= last[i]) {
				sum -= f[i][j - last[i]] * power;
			}

			f[i + 1][j] = sum * p[i] / 100.;
			if (j >= last[i]) {
				f[i + 1][j] += f[i][j - last[i]] * power;
			}
		}
		double s = 1;
		for(int j = m; j > m - last[i] && j >= 0; j--) {
			answer += s * f[i][j] * (i - 1);
			s *= cst;
		}
	}
/*
	cout << f[2][1] << " " << f[2][2] << " " << f[2][3] << " " << f[2][4] << endl;

	cout << f[3][1] << " " << f[3][2] << " " << f[3][3] << " " << f[3][4] << endl;
	cout << f[4][1] << " " << f[4][2] << " " << f[4][3] << " " << f[4][4] << endl;
*/	for(int i = 0; i <= m; i++) {
		answer += f[n + 1][i] * n;
	}
	printf("%.8f\n", answer);
	return 0;
}