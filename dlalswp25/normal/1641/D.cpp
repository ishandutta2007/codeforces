#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<pair<ll, int>, int> pp;

const ll MX = 2000000000;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int N, M;
int A[101010][5];
int W[101010];
vector<pp> V;
vector<int> weights;
map<int, ll> mp;

bool solve(int x) {
	ll tot = 0;
	int l = 0, r = (int)weights.size() - 1;
	while(l < r) {
		while(l < r && weights[l] + weights[r] > x) r--;
		if(l >= r) break;
		tot += r - l;
		l++;
	}

	ll rmv = 0;
	l = 0;
	while(l < V.size()) {
		r = l;
		while(r < V.size() && V[l].first.first == V[r].first.first) r++;
		r--;
		int tl = l, tr = r;
		ll s = 0;
		while(l < r) {
			while(l < r && V[l].second + V[r].second > x) r--;
			if(l >= r) break;
			s += r - l;
			l++;
		}
		swap(tl, l); swap(tr, r);

		if(V[l].first.second & 1) rmv += s;
		else rmv -= s;
		l = r + 1;
	}

	return rmv < tot;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < M; j++) scanf("%d", &A[i][j]);
		scanf("%d", &W[i]);
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j < 1 << M; j++) {
			ll h = 0;
			int b = 0;
			for(int k = 0; k < M; k++) {
				if(~j & 1 << k) continue;
				if(!mp[A[i][k]]) mp[A[i][k]] = rng();
				h ^= mp[A[i][k]];
				b++;
			}
			V.emplace_back(make_pair(h, b), W[i]);
		}
	}
	sort(V.begin(), V.end());
	for(int i = 1; i <= N; i++) weights.push_back(W[i]);
	sort(weights.begin(), weights.end());

	// for(auto& i : V) {
	// 	printf("[");
	// 	for(auto& j : i.first) printf("%d ", j); printf("] %d\n", i.second);
	// }
	
	ll l = 1, r = MX;
	while(l <= r) {
		ll m = l + r >> 1;
		if(solve(m)) r = m - 1;
		else l = m + 1;
	}
	if(l > MX) puts("-1");
	else printf("%lld\n", l);
	return 0;
}