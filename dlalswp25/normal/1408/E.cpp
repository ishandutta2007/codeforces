#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
int p[202020];
ll A[101010];
ll B[101010];

vector<pair<ll, pii> > ed;

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

bool unite(int a, int b) {
	a = par(a); b = par(b);
	if(a == b) return false;
	p[a] = b; return true;
}

int main() {
	scanf("%d%d", &M, &N);
	for(int i = 1; i <= M; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%lld", &B[i]);
	ll s = 0;

	for(int i = 1; i <= M; i++) {
		int k; scanf("%d", &k);
		for(int j = 1; j <= k; j++) {
			int x; scanf("%d", &x);
			s += A[i] + B[x];
			ed.emplace_back(A[i] + B[x], pii(i, M + x));
		}
	}

	sort(ed.begin(), ed.end());
	reverse(ed.begin(), ed.end());

	for(int i = 1; i <= N + M; i++) p[i] = i;
	ll ans = 0;
	for(auto i : ed) {
		int a, b, c = i.first;
		tie(a, b) = i.second;
		if(unite(a, b)) ans += c;
	}
	printf("%lld\n", s - ans);
	
	return 0;	
}