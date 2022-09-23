#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll P = 898989967;
ll Q[5] = {909092647, 959596819, 998244389, 979798003, 979798019};

const int Z = 3;

int N, M;
ll C[505050];

struct X {
	ll H[5];
	int id;

	bool operator< (const X& o) {
		for(int i = 0; i < Z; i++) {
			if(H[i] != o.H[i]) return H[i] < o.H[i];
		}
		return id < o.id;
	}
}A[505050];

ll pw(ll a, ll b, ll mod) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%lld", &C[i]);
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < Z; j++) A[i].H[j] = 0;
			A[i].id = i;
		}
		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			for(int j = 0; j < Z; j++) {
				A[b].H[j] = (A[b].H[j] + pw(P, a, Q[j])) % Q[j];
			}
		}

		sort(A + 1, A + N + 1);

		ll g = 0;

		ll sum = 0;
		int p = 1;
		while(p <= N) {
			bool ok = false;
			for(int j = 0; j < Z; j++) if(A[p].H[j] != 0) ok = true;
			if(!ok) { p++; continue; }

			sum += C[A[p].id]; p++;
			while(p <= N) {
				ok = true;
				for(int j = 0; j < Z; j++) if(A[p].H[j] != A[p - 1].H[j]) ok = false;
				if(!ok) break;
				sum += C[A[p].id]; p++;
			}
			g = gcd(g, sum);
		}
		printf("%lld\n", g);
	}
	return 0;
}