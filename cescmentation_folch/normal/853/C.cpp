#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pi;
typedef pair<pi, int> pii;
typedef vector<pi> vpi;

struct squa {
	ll a, b, c, d;
};

squa G[200010];

ll R[200010];

vi F;
int N;

void add(int ind) {
	while (ind < N) {
		F[ind]++;
		ind += ind&(-ind);
	}
}

int que(int ind) {
	int res = 0;
	while (ind > 0) {
		res += F[ind];
		ind -= ind&(-ind);
	}
	return res;
}

int main() {
	ll n, m;
	cin >> n >> m;
	vi S(n + 1);
	for (int i = 1; i <= n; ++i) cin >> S[i];
	vpi R1(m);
	vpi R2(m);
	for (int i = 0; i < m; ++i) {
		ll a, b, c, d;
		cin >> a >> b;
		cin >> c >> d;
		R[i] = n*(n-1) - (a-1)*(a-2) - (b-1)*(b-2) - (n - c)*(n - c - 1) - (n - d)*(n - d - 1);
		R[i] /= 2ll;
		R1[i] = pi(a, i);
		R2[i] = pi(c, i);
		G[i].a = a;
		G[i].b = b;
		G[i].c = c;
		G[i].d = d;
	}
	sort(R1.begin(), R1.end());
	sort(R2.begin(), R2.end());
	N = n + 10;
	F = vi(n + 10, 0);
	int ti = 0;
	for (int i = 1; i <= n; ++i) {
		while(ti < m and R1[ti].first == i) {
			int j = R1[ti].second;
			ll tt1 = que(G[j].b - 1);
			ll tt2 = que(n) - que(G[j].d);
			R[j] += tt1*(tt1 -1)/2 + tt2*(tt2 - 1)/2;
			++ti;
		}
		add(S[i]);
	}
	
	N = n + 10;
	F = vi(n + 10, 0);
	ti = m-1;
	for (int i = n; i >= 1; --i) {
		while(ti >= 0 and R2[ti].first == i) {
			int j = R2[ti].second;
			ll tt1 = que(G[j].b - 1);
			ll tt2 = que(n) - que(G[j].d);
			R[j] += tt1*(tt1 -1)/2 + tt2*(tt2 - 1)/2;
			--ti;
		}
		add(S[i]);
	}
	
	for (int i = 0; i < m; ++i) cout << R[i] << '\n';
}