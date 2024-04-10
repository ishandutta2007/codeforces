#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 6, INF = 1e9;

int l[N], r[N];
int n, state[N];

double answer = 0;

int intersect(int l, int r, int ll, int rr) {
	return max(0, min(rr, r) - max(l, ll) + 1);
}

void dfs(int d, int v, double p) {
	if (d == n) {
		int eq = 0, up = 0;
		for(int j = 0; j < n; j++) {
			if (state[j] == 1) {
				eq++;
			} else if (state[j] == 2) {
				up++;
			}
		}
		if ((up == 1 && eq >= 1) || (up == 0 && eq >= 2)) {
			answer += p * v; 
		}
		return ;
	}
	int len = (r[d] - l[d] + 1);
	state[d] = 0;
	dfs(d + 1, v, p * intersect(l[d], r[d], 0, v - 1) / len);
	state[d] = 1;
	dfs(d + 1, v, p * intersect(l[d], r[d], v, v) / len);
	state[d] = 2;
	dfs(d + 1, v, p * intersect(l[d], r[d], v + 1, INF) / len);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &l[i], &r[i]);
	}
	for(int v = 1; v <= 10000; v++) {
		dfs(0, v, 1);
	}
	printf("%.12f\n", answer);
	return 0;
}