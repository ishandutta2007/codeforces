/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int lst[26] = {};
int a[N], cnt = 0;

int ask(int l, int r) {
	cnt++;
	assert(cnt <= 6000);
	cout << "? 2 " << l << ' ' << r << endl;
	int y;
	cin >> y;
	return y;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < 26; i++)
		lst[i] = N;
	a[1] = 1;
	vector <int> wef = {1};
	for (int i = 2; i <= n; i++) {
		a[i] = ask(1, i);
		if (a[i] > a[i - 1]) {
			wef.push_back(i);
		}
	}
	string s;
	for (int i = 0; i < n; i++)
		s += "?";
	for (int i = 0; i < (int)wef.size(); i++) {
		cout << "? 1 " << wef[i] << endl;
		char c;
		cin >> c;
		lst[c - 'a'] = wef[i];
		s[wef[i] - 1] = c;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			vector <int> v;
			for (int j = 0; j < 26; j++) {
				if (lst[j] < i + 1) {
					v.push_back(lst[j]);
				}
			}
			sort(v.begin(), v.end());
			int l = 0, r = (int)v.size();
			while (r - l > 1) {
				int mid = (l + r) / 2;
				if (ask(v[mid], i + 1) != (int)v.size() - mid + 1) {
					l = mid;
				} else {
					r = mid;
				}
			}
			s[i] = s[v[l] - 1];
			lst[s[i] - 'a'] = i + 1;
		}
	}
	cout << "! " << s << endl;
}