#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> pp;

const ll MOD = 1000000007;

ll S[202020];
ll E[202020];
int A[202020];
int B[202020];

ll M[404040];
ll D[404040];

int N;

vector<ll> v;
vector<ll> adj[404040];
priority_queue<pp, vector<pp>, greater<pp> > pq;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld%lld", &S[i], &E[i]);

	v.push_back(0);

	for(int i = 1; i <= N; i++) v.push_back(S[i]);
	for(int i = 1; i <= N; i++) v.push_back(E[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for(int i = 1; i <= N; i++) {
		A[i] = lower_bound(v.begin(), v.end(), S[i]) - v.begin();
		B[i] = lower_bound(v.begin(), v.end(), E[i]) - v.begin();
	}

	for(int i = 1; i <= N; i++) {
		adj[A[i]].push_back(B[i]);
	}

	pq.push({0, {-1, 1}});
	D[1] = 1;
	M[1] = v[1];

	int z = 987654321;
	for(int i = 1; i <= N; i++) z = min(z, A[i]);

	for(int i = 2; i < v.size(); i++) {
		ll mn = (1LL) << 62;
		ll x = 0;

		for(int j : adj[i]) {
			if(mn > M[j]) {
				mn = M[j];
				x = D[j];
			}
			else if(mn == M[j]) x = (x + D[j]) % MOD;
		}

		//printf("%d %lld %lld\n", i, mn, x);

		if(mn > v[i] + pq.top().first) {
			mn = v[i] + pq.top().first;
			x = pq.top().second.second;
		}
		else if(mn == v[i] + pq.top().first) x = (x + pq.top().second.second) % MOD;

		M[i] = mn;
		D[i] = x;

		pq.push({M[i] - v[i], {-i, D[i]}});
	}

	// for(int i = 1; i < v.size(); i++) printf("%lld ", M[i]); puts("");
	// for(int i = 1; i < v.size(); i++) printf("%lld ", D[i]); puts("");

	int t = 0;
	for(int i = 1; i <= N; i++) {
		t = max(t, B[i]);
	}

	ll minv = (1LL) << 62;
	ll ans = 0;
	for(int i = t + 1; i < v.size(); i++) {
		if(M[i] < minv) {
			minv = M[i];
			ans = D[i];
		}
		else if(M[i] == minv) ans = (ans + D[i]) % MOD;
	}
	printf("%lld\n", ans);

	return 0;
}