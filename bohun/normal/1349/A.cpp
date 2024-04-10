#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

const int N = 200005;

ll pt(int a, int b) {
	ll res = 1;
	while (b) {
		res *= a;
		b--;
	}
	return res;
}

int n;
int sito[N];
int a;

map <int, int> p;
vector <int> v[N];

int main() {
	rep(i, 2, N - 1) {
		if (sito[i]) continue;
		for (int j = i; j < N; j += i)
			sito[j] = i;
	}
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", &a);
		p.clear();
		while (a > 1) {
			p[sito[a]]++;
			a /= sito[a];
		}
		for (auto it : p) 
			v[it.fi].pb(it.se);
	}
	ll res = 1;
	rep(i, 2, N - 1) {
		sort(all(v[i]));
		if (ss(v[i]) < n - 1) continue;
		if (ss(v[i]) == n - 1) res = res * pt(i, v[i][0]);
		else res *= pt(i, v[i][1]);
	}
	printf ("%lld\n", res);
		
	
	
	return 0;
}