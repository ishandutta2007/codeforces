/* 	* In the name of GOD  */

#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1001, M = 1000001;
int a[N];
bool f[M];
vector <int> p;

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	for (int i = 2; i < M; i++)
		f[i] = true;
	for (int i = 2; i < N; i++) {
		if (!f[i])
			continue;
		for (int j = i * i; j < M; j += i) {
			f[j] = false;
		}
	}
	for (int i = 0; i < M; i++)
		if (f[i])
			p.push_back(i);
	int n, k;
	cin >> n >> k;
	bool h = false;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int x = sqrt(a[i]);
		if (x * x == a[i])
			if (is_prime(x)) {
				v.push_back(x);
			}
		if (a[i] <= M * N) {
			if (is_prime(a[i]))
				v.push_back(a[i]);
		}
		for (auto x : p) {
			int y = a[i];
			while (y % x == 0)
				y /= x;
			if (y == 1) {
				v.push_back(x);
			}
		}
	}
	if (k == 1) {
		cout << 0;
		return 0;
	}
	sort (v.begin(), v.end());
	v.erase (unique (v.begin(), v.end()), v.end());
	vector <vector <int>> w;
	vector <int> q, v2 = v;
	vector <int> s;
	v.clear();
	int s1 = 0, s2 = 0;
	for (auto x : v2) {
		w.push_back({});
		for (int i = 0; i < n; i++) {
			int y = a[i];
			while (y % x == 0)
				y /= x;
			if (y == 1) {
				w.back().push_back(a[i]);
			}
		}
		if (w.back().size() >= 2) {
			if (w.back().size() >= 3)
				h = true;
			v.push_back(x);
			s1 += w.back().size();
		} else {
			w.pop_back();
		}
	}
	for (int i = 0; i < n; i++) {
		int y = a[i], cnt = 0;
		for (int j = 0; j < v.size(); j++) {
			if (y % v[j] == 0) {
				cnt++;
				while (y % v[j] == 0)
					y /= v[j];
			}
		}
		if (y == 1 && cnt != 1) {
			q.push_back(a[i]);
			s2++;
			s.push_back(cnt);
		}
	}
	/*
	cout << "p^x:\n";
	for (int i = 0; i < w.size(); i++) {
		cout << v[i] << " : ";
		for (auto x : w[i]) 
			cout << x << ' ';
		cout << '\n';
	}
	cout << "m:\n";
	for (auto x : q)
		cout << x << ' ';
	cout << '\n';
	*/
	if (k > s1 + s2) {
		cout << 0;
		return 0;
	}
	if (k >= s1) {
		for (int i = 0; i < w.size(); i++) {
			for (auto x : w[i])
				cout << x << ' ';
		}
		for (int i = 0; i < k - s1; i++) {
			cout << q[i] << ' ';
		}
		return 0;
	}
	if (!h && k % 2) {
		int mn = INT_MAX, in = -1;
		for (int i = 0; i < s.size(); i++) {
			int x = s[i];
			if (x < mn) {
				mn = x;
				in = i;
			}
		}
		if (1 + 2 * mn > k) {
			cout << 0;
			return 0;
		}
		int x = q[in];
		cout << x << ' ';
		k--;
		vector <int> in2;
		for (int i = 0; i < v.size(); i++) {
			if (x % v[i] == 0) {
				in2.push_back(i);
			}
		}
		for (int i = 0; i < in2.size(); i++) {
			cout << w[in2[i]][0] << ' ' << w[in2[i]][1] << ' ';
			k -= 2;
		}
		for (int i = 0; i < v.size(); i++) {
			if (x % v[i] && k) {
				k -= 2;
				cout << w[i][0] << ' ' << w[i][1] << ' ';
			}
		}
		return 0;
	}
	vector <int> ans;
	for (int i = 0; i < w.size(); i++) {
		if (k >= 2) {
			k -= 2;
			ans.push_back(w[i][0]);
			ans.push_back(w[i][1]);
		} else if (k == 1) {
			for (int j = 0; j < w.size(); j++) {
				if (w[j].size() >= 3) {
					if (j < i) {
						ans.push_back(w[j][2]);
					} else {
						ans.pop_back();
						ans.pop_back();
						ans.push_back(w[j][0]);
						ans.push_back(w[j][1]);
						ans.push_back(w[j][2]);
					}
					break;
				}
			}
			k = 0;
		}
	}
	for (int i = 0; i < w.size(); i++) {
		for (int j = 2; j < w[i].size(); j++) {
			if (k) {
				ans.push_back(w[i][j]);
				k--;
			}
		}
	}
	for (auto x : ans)
		cout << x << ' ';
}