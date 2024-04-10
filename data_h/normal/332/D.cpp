#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 2100;

double num = 0, sum = 0;

double C[MAXN][MAXN];
vector<double> vec[MAXN];

int n, k;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			if (x != -1) {
				vec[i].push_back(x);
				vec[j].push_back(x);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if (vec[i].size() < k)
			continue;
		int size = int(vec[i].size());
		num += C[size][k];
		for(int j = 0; j < vec[i].size(); j++)
			sum += C[size - 1][k - 1] * vec[i][j];
	}
	if (num < 1e-8) {
		printf("-1\n");
	} else {
		printf("%.0f", max(0.0, sum / num - 0.5));
	}
	return 0;
}