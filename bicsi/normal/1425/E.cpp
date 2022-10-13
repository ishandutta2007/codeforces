#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
#include <assert.h>
using namespace std;

typedef long long i64;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector <i64> A(n), D(n);
	for (auto& i : A)
		cin >> i;
	for (auto& i : D)
		cin >> i;
	// need d for exciting eletron

	if (k == 0) {
		i64 best = 0, s_act = 0;
		for (int i = n - 1; i >= 0; i--) {
			s_act += A[i];
			best = max(best, s_act - D[i]);
		}
		cout << best << '\n';
		return 0;
	}
	if (k >= 2) {
		i64 best = max(0LL, A[n - 1] - D[n - 1]);
		i64 s = A[n - 1], dmin = 1e9;
		for (int i = 0; i < n - 1; i++)
			s += A[i], dmin = min(dmin, D[i]);
		best = max(best, s - dmin);
		cout << best << '\n';
		return 0;
	}
	if (k == 1) {
		i64 best = 0, s_act = 0, a_min = 1e9, d_min = 1e9;
		for (int i = n - 1; i > 0; i--) {
			s_act += A[i];
			best = max(best, s_act - D[i]);
			a_min = min(a_min, A[i]);
			if (i != n - 1)
				d_min = min(d_min, D[i]);
		}
		d_min = min(d_min, D[0]);
		s_act += A[0];
		best = max(best, s_act - D[0] - a_min);
		best = max(best, s_act - A[n - 1] - d_min);
		sort(D.begin(), D.end());
		best = max(best, s_act - D[0] - D[1]);
		cout << best << '\n';
	}
	return 0;
}