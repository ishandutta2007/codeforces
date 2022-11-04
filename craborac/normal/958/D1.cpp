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
typedef unsigned long long ull;
const ll ma = 128 * 1024;


ll n;
vector<pair<pair<ll, ll>, ll> > a;
map<pair<ll, ll>, ll> kk;
int main() {
	scanf("%d\n", &n);
	forn (i, n) {
		string s;
		int a1, b1, c1;
		scanf("(%d+%d)/%d\n", &a1, &b1, &c1);
		//cout << a1 << " " << b1 << " " << c1 << "\n";
		a1 += b1;
		int gc = __gcd(a1, c1);
		a1 /= gc;
		c1 /= gc;
		//cout << a1 << " " << c1 << "\n";
		a.push_back(mp(mp(a1, c1), i));
		kk[mp(ll(a1), ll(c1))]++;
	}
	forn (i, n) {
		cout << kk[a[i].fi] << " ";
	}
}