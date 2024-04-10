#include <bits/stdc++.h>

using namespace std;

const int maxn = 100500;

int sum1[maxn];
int sum2[maxn];
int cnt1[maxn];
int cnt2[maxn];

int main() {

    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

	string s, t;
	cin >> s >> t;
	
	int n = s.size();
	int m = t.size();
	
	sum1[0] = 0;
	cnt1[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] != 'A') {
			sum1[i] = sum1[i - 1] + 1;
			cnt1[i] = 0;
		} else {
			sum1[i] = sum1[i - 1];
			cnt1[i] = cnt1[i - 1] + 1;
		}
	}

	sum2[0] = 0;
	cnt2[0] = 0;
	for (int i = 1; i <= m; ++i) {
		if (t[i - 1] != 'A') {
			sum2[i] = sum2[i - 1] + 1;
			cnt2[i] = 0;
		} else {
			sum2[i] = sum2[i - 1];
			cnt2[i] = cnt2[i - 1] + 1;
		}
	}

	int q;
	cin >> q;
	for (int z = 0; z < q; ++z) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		int a1, a2, x, y;
		x = sum1[b] - sum1[a - 1];
		y = sum2[d] - sum2[c - 1];
		a1 = min(cnt1[b], b - a + 1);
		a2 = min(cnt2[d], d - c + 1);

		if (x > y) {
			cout << 0;
			continue;
		}
		if (x == y) {
			if (a1 >= a2 && (a1 - a2) % 3 == 0) {
				cout << 1;
			} else {
				cout << 0;
			}
			continue;
		}
		if ((y - x) % 2 != 0) {
			cout << 0;
			continue;
		}
		if (a1 > a2) {
			cout << 1;
			continue;
		}
		if (a1 < a2) {
			cout << 0;
			continue;
		}
		if (x == 0) {
			cout << 0;	
		} else {
			cout << 1;
		}
	}
	

    return 0;
}