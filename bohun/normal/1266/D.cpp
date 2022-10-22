#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

const int mod = 1e9 + 7;
const int nax = 2e5 + 111;

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1)
			c = 1ll * c * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
	}
	return c;
}

int n, m;
int a, b, c;
ll x[100005];

vector <int> X, Y;
vector <pair<pair<int,int>, ll>> ed;

int main () {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		x[a] += c;
		x[b] -= c;
	}

	for(int i = 1; i <= n; ++i) {
		if(x[i] > 0)
			X.pb(i);
		else if(x[i] < 0)
			Y.pb(i);
	}
	int w = 0;
	for(int i = 0; i < ss(X); ++i) {
		int ja = X[i];
		while(x[ja] > 0 && w < ss(Y)) {
			ll cost = min(x[ja], -x[Y[w]]);
			ed.pb(mp(mp(ja, Y[w]), cost));
			x[ja] -= cost;
			x[Y[w]] += cost;
			if(x[Y[w]] == 0)
				w++;
		}
	}

	printf("%d\n", ss(ed));
	for(auto it : ed)
		printf("%d %d %lld\n", it.fi.fi, it.fi.se, it.se);




	return 0;
}