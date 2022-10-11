#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int n, a, b, s, cnt; vector<int>X[1 << 18];

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n - 1; i++) {
		scanf("%d%d", &a, &b);
		X[a].push_back(b);
		X[b].push_back(a);
	}
	if (n == 2) {
		cout << s << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < X[i].size(); j++) {
			int pa = i, pb = X[i][j]; if (pa > pb) continue;
			if (X[pa].size() == 1 || X[pb].size() == 1) cnt++;
		}
	}
	long double L = 1.0L * s * 2.0L / cnt;
	printf("%.12Lf\n", L);
	return 0;
}