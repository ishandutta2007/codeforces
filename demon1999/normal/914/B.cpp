#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

int n, ans = -1000001, a;
vector<int> c;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	c.resize(n);
	forn (i, n) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	int k = 0;
	bool ok = false;
	forn (i, sz(c)) {
		if (i && c[i] > c[i - 1]) {
			if (k % 2) ok = true;
			k = 0;
		}
		k++;
	}
	if (k % 2) ok  =true;
	if (ok) cout << "Conan\n";
	else
		cout << "Agasa"; 
}