#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998244353;
const ll W = 3;
const int MX = 300000;

int N, M, K;
vector<int> A[303030];
vector<pii> where[303030];
int state[303030];
bool vstC[303030];
int B[606060];
int pos[303030];
vector<int> blocks;

ll D[303030];

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll inv(ll x) { return pw(x, MOD - 2); }

void fft(vector<ll>& A, bool invert) {
	int N = A.size();
	int iv = 0;
	for(int i = 1; i < N; i++) {
		for(int t = N >> 1; t; t >>= 1) {
			iv ^= t;
			if(iv & t) break;
		}
		if(i < iv) swap(A[i], A[iv]);
	}
 
	for(int i = 1; i < N; i <<= 1) {
		int jmp = i << 1;
		ll w0 = pw(W, (MOD - 1) / i >> 1);
		if(invert) w0 = inv(w0);
		ll x = 1;
 
		for(int j = 0; j < N; j += jmp) {
			for(int k = 0; k < i; k++) {
				if(k) x = x * w0 % MOD;
				else x = 1;
				ll ev = A[j | k], od = A[j | k | i] * x % MOD;
				A[j | k] = (ev + od) % MOD; A[j | k | i] = (ev + MOD - od) % MOD;
			}
		}
	}
	ll IN = inv(N);
	if(invert) for(int i = 0; i < N; i++) A[i] = A[i] * IN % MOD;
}
 
void multiply(vector<ll>& A, vector<ll>& B) {
	int M = 1;
	while(M < A.size() + B.size()) M <<= 1;
 
	vector<ll> X, Y;
	for(ll i : A) X.emplace_back(i);
	for(ll i : B) Y.emplace_back(i);
	X.resize(M); Y.resize(M);
 
	fft(X, false); fft(Y, false);
	for(int i = 0; i < M; i++) X[i] = (X[i] * Y[i]) % MOD;
	fft(X, true);
	A.resize(M);
	for(int i = 0; i < M; i++) A[i] = X[i];
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= N; i++) {
		int k; scanf("%d", &k);
		for(int j = 0; j < k; j++) {
			int x; scanf("%d", &x);
			A[i].push_back(x);
			where[x].emplace_back(i, j);
		}
	}

	for(int i = 1; i <= N; i++) {
		if(state[i]) continue;
		vector<int> tmp;

		bool ok = true;
		queue<pii> q;

		int l = MX, r = MX;
		pos[A[i][0]] = MX;
		B[MX] = A[i][0];

		auto die = [&]() {
			for(int j : tmp) {
				for(int k : A[j]) vstC[k] = true;
				state[j] = -1;
			}
		};

		if(!ok) { die(); continue; }

		q.emplace(i, 0); state[i] = 1;

		while(q.size()) {
			if(!ok) break;
			int x, y; tie(x, y) = q.front(); q.pop();
			tmp.push_back(x);

			int tl = l, tr = r;

			int p = pos[A[x][y]];
			for(int j = y - 1; j >= 0; j--) {
				p--;
				int v = A[x][j];
				if(p < l) {
					if(l <= pos[v] && pos[v] <= r && B[pos[v]] == v) { ok = false; break; }
					l--;
					B[p] = v;
					pos[v] = p;
				}
				else if(B[p] != v) { ok = false; break; }
			}

			if(!ok) break;

			p = pos[A[x][y]];
			for(int j = y + 1; j < A[x].size(); j++) {
				p++;
				int v = A[x][j];
				if(p > r) {
					if(l <= pos[v] && pos[v] <= r && B[pos[v]] == v) { ok = false; break; }
					r++;
					B[p] = v;
					pos[v] = p;
				}
				else if(B[p] != v) { ok = false; break; }
			}

			for(int j = l; j <= tl; j++) {
				for(pii k : where[B[j]]) {
					if(state[k.first] == -1) ok = false;
					else if(state[k.first] == 1) continue;
					q.emplace(k); state[k.first] = 1;
				}
			}

			for(int j = tr; j <= r; j++) {
				for(pii k : where[B[j]]) {
					if(state[k.first] == -1) ok = false;
					else if(state[k.first] == 1) continue;
					q.emplace(k); state[k.first] = 1;
				}
			}
		}

		while(q.size()) {
			tmp.push_back(q.front().first); q.pop();
		}

		if(!ok) { die(); continue; }
		blocks.push_back(r - l + 1);
		for(int j = l; j <= r; j++) vstC[B[j]] = true;
		for(int j : tmp) state[j] = -1;
	}

	for(int i = 1; i <= K; i++) {
		if(!vstC[i]) blocks.push_back(1);
	}

	// vector<ll> P(M + 1, 0);
	// for(int i : blocks) P[i]++;
	// vector<ll> F = P;
	
	// for(int i = 0; i < 19; i++) {
	// 	vector<ll> G = F;
	// 	multiply(F, P);

	// 	while(F.size() > M + 1) F.pop_back();

	// 	for(int j = 0; j < M + 1; j++) F[j] = (F[j] + G[j]) % MOD;

	// 	G = P;
	// 	multiply(P, G);

	// 	while(P.size() > M + 1) P.pop_back();
	// }

	// printf("%lld\n", F[M]);

	vector<pii> V;
	sort(blocks.begin(), blocks.end());
	for(int i : blocks) {
		if(!V.size() || V.back().first != i) V.emplace_back(i, 1);
		else V.back().second++;
	}

	D[0] = 1;
	for(int i = 1; i <= M; i++) {
		for(pii j : V) {
			if(j.first > i) break;
			D[i] = (D[i] + (ll)D[i - j.first] * j.second) % MOD;
		}
	}
	printf("%lld\n", D[M]);

	return 0;
}