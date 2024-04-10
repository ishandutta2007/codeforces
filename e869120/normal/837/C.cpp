#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int n, a, b, x[100], y[100], maxn;
int solve(int p1, int p2, int p3, int p4) {
	if (p1 > p2)swap(p1, p2);
	if (p3 > p4)swap(p3, p4);
	if (p1 <= p3 && p2 <= p4)return p1*p2;
	return -1000000007;
}
int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			int P1 = -1000000007; if (y[i] <= b)P1 = solve(x[j], y[j], a - x[i], b);
			int P2 = -1000000007; if (x[i] <= a)P2 = solve(x[j], y[j], a, b - y[i]);
			int P3 = -1000000007; if (x[i] <= b)P3 = solve(x[j], y[j], a - y[i], b);
			int P4 = -1000000007; if (y[i] <= a)P4 = solve(x[j], y[j], a, b - x[i]);
			maxn = max(maxn, x[i] * y[i] + max({ P1,P2,P3,P4 }));
		}
	}
	cout << maxn << endl;
	return 0;
}