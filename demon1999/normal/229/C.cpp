//#include "grader.h"
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
//const int ma = 128 * 1024, mal = 8;
const ll mod = ll(1e9) + 7, bub = 1000;
int n, m;
ll ans, ansk;
ll num[1000000];
vector<int> e[1000000];
vector<bitset<1000000> > qq;
map<pair<int, int>, int> is;

int main() {
	//iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	//cin >> n >> m;
	scanf("%d%d", &n, &m);
	ans = ll(n) * ll(n - 1) * ll(n - 2) / 6LL - ll(n - 2) * ll(m);
	vector<pair<int, int> > rb;
	forn (i, m) {
		int a, b, w;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
		//is[mp(a, b)] = is[mp(b, a)] = 1;
		//rb.push_back(mp(a, b));
	}
	ll ansk = 0;

	forn (i, n) {
		ans += ll(sz(e[i])) * ll(sz(e[i]) - 1) / 2LL;		
	}
	cout << ans;
//	forn (i, )
}