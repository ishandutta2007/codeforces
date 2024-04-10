#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define re return
#define x first
#define y second
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

int a, b, n, c, d;
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	forn (i, n) {
		cin >> c >> d;
		if (c > d) a++;
		if (c < d) b++;

	}
	if (a > b)
		cout << "Mishka";
	if (a == b)
		cout << "Friendship is magic!^^";
	if (a < b)
		cout << "Chris";
	re 0;
}