#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LB;
LL K;
bool check(const vector<LL> &a) {
	return *max_element(a.begin(), a.end()) >= K;
}
void work(vector<LL> &a) {
	vector<LL> b;
	LL las = 0;
	for (int i = 0; i < (int) a.size(); ++ i) {
		b.push_back(las += a[i]);
	}
	a.swap(b);
}
const int C = 5;
struct mat {
	LB a[C][C];
	mat() {memset(a, 0, sizeof(a));}
	mat(int) {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < C; ++ i) a[i][i] = 1;
	}
};
mat operator * (const mat &a, const mat &b) {
	mat c = mat();
	for (int i = 0; i < C; ++ i) {
		for (int j = 0; j < C; ++ j) {
			for (int k = 0; k < C; ++ k) {
				c.a[i][k] += a.a[i][j] * b.a[j][k];
			}
		}
	}
	return c;
}
mat mpow(mat a, LL n) {
	mat res = mat(1);
	while (n) {
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}
int main() {
	int n, x;
	cin >> n >> K;
	vector<LL> A;
	int cnt = 0;
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &x);
		A.push_back(x);
		cnt += !!x;
	}
	reverse(A.begin(), A.end());
	while (A.back() == 0) A.pop_back();
	int nn = A.size();
	while (A.size() < C) A.push_back(0);
	reverse(A.begin(), A.end());
	n = A.size();
	if (n <= C) {
	//	assert(n == C);
		mat p = mat(), a = mat();
		LL l = 0, r = 1e18;
		for (int i = 0; i < C; ++ i) a.a[i][0] = A[i];
		for (int i = 0; i < C; ++ i) {
			for (int j = 0; j <= i; ++ j) {
				p.a[i][j] = 1;
			}
		}
		LL ans = r + 1;
		while (l <= r) {
			LL mid = (l + r) / 2;
			mat q = mpow(p, mid) * a;
			LB res = 0;
			for (int i = 0; i < C; ++ i) res = max(res, q.a[i][0]);
			if (res >= K) {
				ans = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		cout << ans << endl;
		return 0;
	}
	int ans = 0;
	while (!check(A)) {
		ans ++;
		work(A);
	}
	printf("%d\n", ans);
}