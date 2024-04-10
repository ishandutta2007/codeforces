#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;
const ll INF = LLONG_MAX >> 2;
inline int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

void exgcd(ll a, ll b, ll& x, ll& y) {
	if (b) exgcd(b, a % b, y, x), y -= (a / b) * x; 
	else x = 1, y = 0;
}

int N, M, D, mod; ll inv, ans;
vector<int> B, G, V[MAXN];

inline int id(int x) {
	return 1ll * ((x - x % D) / D) * inv % mod;
}

bool cmp(int x, int y) { return id(x) < id(y); }

int main(){
	scanf("%d%d", &N, &M), D = gcd(N, M);
	int l, x; scanf("%d", &l);
	while (l--) scanf("%d", &x), B.push_back(x);
	scanf("%d", &l);
	while (l--) scanf("%d", &x), G.push_back(x);
	if ((int)(B.size() + G.size()) < D) { puts("-1"); return 0; }
	if (N > M) swap(N, M), swap(B, G);
	mod = M / D;
	sort(B.begin(), B.end()); x = N - 1;
	for (int i = B.size() - 1; i >= 0; --i){
		if (B[i] == x) --x;
		else break;
	}
	ans = max(ans, (ll)x);
	ll tmp;
	exgcd(N / D, M / D, inv, tmp), inv = (inv % mod + mod) % mod;
	for (int i = 0; i < (int)B.size(); ++i) V[B[i] % D].push_back(B[i]);
	for (int i = 0; i < (int)G.size(); ++i) V[G[i] % D].push_back(G[i]);
	for (int i = 0; i < D; ++i) {
		if (V[i].empty()) {
			puts("-1"); return 0;
		} else {
			sort(V[i].begin(), V[i].end(), cmp);
			for (int j = 0; j < (int)V[i].size() - 1; ++j) if (id(V[i][j+1])-id(V[i][j])-1>0) {
				ans = max(ans, V[i][j] + 1ll * N * (id(V[i][j + 1]) - id(V[i][j]) - 1));
			}
			int t = *(--V[i].end());
			if (id(V[i][0]) - id(t) + M / D - 1 > 0) {
				ans = max(ans, t + 1ll * N * (id(V[i][0]) - id(t) + M / D - 1));
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}