#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const int ma = 1024 * 1024;


int main() {
	//freopen("a.in", "r", stdin);
	string s;
	cin >> s;
	int k = 0;
	forn (i, sz(s)) {
		k = max(k, s[i] - '0');
	}
	cout << k << "\n";
	//vector<int> ans;
	forn (i, k) {
		string t = "";
		forn (j, sz(s))
		if (s[j] -'0' >= i + 1) {
			t += "1";
		} else {
			if (sz(t))
				t += "0";
		}
		cout << t << " ";
	}
}