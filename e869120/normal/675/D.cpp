#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

//==============================LIBRARY==================================
int bit[(1 << 18)];

void Set(int a, int b, int x, int k = 0, int l = 0, int r = (1 << 17)) {
	if (b <= l || r <= a)return;
	if (a <= l && r <= b) {
		bit[k] = max(bit[k], x);
		return;
	}
	int m = (l + r) / 2;
	Set(a, b, x, k * 2 + 1, l, m);
	Set(a, b, x, k * 2 + 2, m, r);
}

int Get(int i) {
	i += (1 << 17) - 1;
	int res = bit[i];
	while (i) {
		i = (i - 1) / 2;
		res = max(res, bit[i]);
	}
	return res;
}

vector<int>E; int n, a[100000], b[100000]; map<int, pair<int, int>>M;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; b[i] = a[i]; E.push_back(a[i]); }
	sort(E.begin(), E.end());
	for (int i = 0; i < n; i++) { a[i] = lower_bound(E.begin(), E.end(), a[i]) - E.begin(); }
	for (int i = 0; i < n; i++) {
		if (i == 0) { Set(0, n, i); M[b[i]] = make_pair(0, n - 1); }
		else {
			int P1 = Get(a[i]); int P = b[P1], Q = a[P1]; if (i >= 2)cout << ' '; cout << P;
			if (P > b[i]) {
				Set(M[P].first, (Q - 1) + 1, i);
				M[b[i]] = make_pair(M[P].first, (Q - 1));
				M[P].first = Q;
			}
			else {
				Set((Q + 1), M[P].second + 1, i);
				M[b[i]] = make_pair(Q + 1, M[P].second);
				M[P].second = Q;
			}
		}
	}
	cout << endl;
	return 0;
}