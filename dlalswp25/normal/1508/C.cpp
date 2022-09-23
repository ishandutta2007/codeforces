#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
vector<int> adj[202020];
bool vst[202020];
vector<int> rev[202020];
set<int> S;
int com[202020];
int A[202020];
int B[202020];
int C[202020];
queue<int> q;
int up[202020];

int p[202020];
int p2[202020];
vector<pair<int, pii> > ed;

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = par(a); b = par(b);
	p[a] = b;
}

int par2(int x) {
	if(x == p2[x]) return x;
	return p2[x] = par2(p2[x]);
}

void unite2(int a, int b) {
	a = par2(a); b = par2(b);
	p2[a] = b;
}

bool is_edge(int a, int b) {
	auto it = lower_bound(adj[a].begin(), adj[a].end(), b);
	return it != adj[a].end() && *it == b;
}

int main() {
	int X = 0;
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
		X ^= C[i];
		ed.emplace_back(C[i], pii(A[i], B[i]));
	}

	for(int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());
	for(int i = 1; i <= N; i++) S.insert(i);

	int e = 0;
	for(int i = 1; i <= N; i++) {
		if(vst[i]) continue;
		vst[i] = true;
		q.push(i);
		S.erase(i);
		com[i] = i;

		while(q.size()) {
			int x = q.front(); q.pop();
			vector<int> v;
			for(int j : S) {
				if(is_edge(x, j)) continue;
				v.push_back(j);
			}
			for(int j : v) {
				e++;
				S.erase(j);
				q.push(j);
				up[j] = x;
				com[j] = i;
				vst[j] = true;
			}
		}
	}

	for(int i = 1; i <= N; i++) p[i] = p2[i] = i;
	for(int i = 1; i <= N; i++) if(up[i]) unite(up[i], i);

	sort(ed.begin(), ed.end());
	ll s = 0;
	ll mn = 1LL << 60;
	for(auto i : ed) {
		int a, b, c = i.first;
		tie(a, b) = i.second;
		if(par(a) == par(b)) {
			if(par2(a) == par2(b)) continue;
			unite2(a, b);
			mn = min(mn, (ll)c);
			continue;
		}
		s += c;
		unite(a, b);
		unite2(a, b);
	}

	ll add = ((ll)N * (N - 1) / 2 - M > e ? 0 : X);
	add = min(add, mn);
	printf("%lld\n", s + add);

	return 0;
}