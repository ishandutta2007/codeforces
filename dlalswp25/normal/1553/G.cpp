#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int MX = 1000001;

int N, Q;
vector<int> primes;
vector<int> factors[1010101];
int sieve[1010101];
int p[1010101];
int A[1010101];
set<int> adj[1010101];
map<pii, int> mp;

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	// printf("%d %d\n", a, b);
	a = par(a); b = par(b);
	p[a] = b;
}

int main() {
	for(int i = 2; i <= MX; i++) {
		if(!sieve[i]) {
			primes.push_back(i);
			sieve[i] = i;
		}
		for(int j : primes) {
			if(i * j > MX) break;
			sieve[i * j] = j;
			if(i % j == 0) break;
		}
	}

	for(int i = 1; i <= MX; i++) {
		if(sieve[i] != i) continue;
		p[i] = i;
		for(int j = 1; i * j <= MX; j++) {
			factors[i * j].push_back(i);
		}
	}

	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j < factors[A[i]].size(); j++) {
			unite(factors[A[i]][j - 1], factors[A[i]][j]);
		}
	}

	for(int i = 1; i <= N; i++) {
		int a = par(factors[A[i]][0]);
		for(int j : factors[A[i] + 1]) {
			int t = par(j);
			// printf("%d i %d -> %d\n", i, a, t);
			if(a != t) adj[a].insert(t);
		}
		int sz = factors[A[i] + 1].size();
		for(int j = 0; j < sz; j++) {
			for(int k = j + 1; k < sz; k++) {
				int x = par(factors[A[i] + 1][j]), y = par(factors[A[i] + 1][k]);
				if(x > y) swap(x, y);
				mp[pii(x, y)] = 1;
			}
		}
	}

	while(Q--) {
		int s, t; scanf("%d%d", &s, &t);
		s = par(factors[A[s]][0]);
		t = par(factors[A[t]][0]);
		if(s == t) puts("0");
		else {
			int ans = 2;
			if(adj[s].find(t) != adj[s].end()) ans = 1;
			if(adj[t].find(s) != adj[t].end()) ans = 1;
			if(s > t) swap(s, t);
			if(mp[pii(s, t)]) ans = 1;
			printf("%d\n", ans);
		}
	}

	return 0;
}