#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll ret[202020];
int N, Q;

vector<int> v[202020];
vector<pair<int, pii> > ed;

ll ans = 0;
int p[202020];
int sz[202020];

ll f(ll x) { return x * (x - 1) / 2; }

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = par(a); b = par(b);
	if(a == b) return;
	p[b] = a;
	ans -= f(sz[a]); ans -= f(sz[b]);
	sz[a] += sz[b];
	ans += f(sz[a]);
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i < N; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		ed.push_back({c, {a, b}});
	}

	for(int i = 1; i <= Q; i++) {
		int q; scanf("%d", &q);
		v[q].push_back(i);
	}

	sort(ed.begin(), ed.end());
	for(int i = 1; i <= N; i++) p[i] = i;
	for(int i = 1; i <= N; i++) sz[i] = 1;

	int ptr = 0;
	for(int i = 1; i <= 200000; i++) {
		while(ptr < ed.size() && ed[ptr].first <= i) {
			unite(ed[ptr].second.first, ed[ptr].second.second);
			ptr++;
		}
		for(int j : v[i]) ret[j] = ans;
	}

	for(int i = 1; i <= Q; i++) printf("%lld ", ret[i]); puts("");

	return 0;
}