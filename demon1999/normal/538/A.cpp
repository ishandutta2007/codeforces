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
	int n = sz(s);
	for (int i = 0; i < n; i++) {
		for (int j = i; j <= n; j++) {
			string t = "";
			forn(k, i)
				t += s[k];
			for (int p = j; p < n; p++)
				t += s[p];
			if (t == "CODEFORCES") {
				cout << "YES\n";
				re 0;
			}
		}
	}
	cout << "NO\n";
}