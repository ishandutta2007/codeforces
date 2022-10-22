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

int n;
int t[nax];
int q;
int a, b, c;

map <pair<int, int>, int> mapa;
int deb[nax];

int main () {
	scanf("%d", &n);
	ll suma = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", t + i);
		suma += t[i];
	}
	ll opt = 0;
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d %d", &a, &b, &c);
		if(mapa[{a, b}] > 0) {
			int on = mapa[mp(a, b)];
			deb[on]--;
			if(deb[on] < t[on])
				opt--;
			mapa[{a, b}] = 0;
		}
		if(c > 0) {
			mapa[{a, b}] = c;
			deb[c]++;
			if(deb[c] <= t[c])
				opt++;
		}
		printf("%lld\n", suma - opt);
	}


	return 0;
}