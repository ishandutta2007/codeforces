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
	for (int i = 0; i <= 2000; i++) c.push_back(i * i);
	forn (i, n) {
		cin >> a;
		if (a < 0) {
			if (ans < a) ans = a;
			continue;
		}
		if (!binary_search(c.begin(), c.end(), a) && ans < a) ans = a;
		//int k = 
	}
	cout << ans;
}