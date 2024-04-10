#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MX = 200000;
const ll MOD = 1000000007;

int N, Q;
vector<int> primes;
int sieve[202020];

ll A[202020];
ll D[202020];

vector<pii> I[202020];

struct SegTree {
	int T[525252] = {0, };
	int base = 262144;
	bool chk[525252] = {0, };

	vector<int> v;

	void init() {
		for(int i = base; i < base + N; i++) T[i] = 0;
		for(int i = base + N; i < 525252; i++) T[i] = MOD;
		for(int i = base - 1; i >= 1; i--) T[i] = min(T[i << 1], T[i << 1 | 1]);
	}

	void clr() {
		for(int i : v) { T[i] = 0; chk[i] = false; }
		v.clear();
	}

	void upd(int p) {
		p += base; p--;
		T[p]++;
		v.push_back(p);
		while(p > 1) {
			p >>= 1;
			if(!chk[p]) { chk[p] = true; v.push_back(p); }
			T[p] = min(T[p << 1], T[p << 1 | 1]);
		}
	}

	int get() {
		return T[1];
	}
}seg;

vector<int> f(int n) {
	vector<int> ret;
	vector<int>::iterator it = primes.begin();
	while(n > 1) {
		if(sieve[n] == n) {
			ret.push_back(n);
			break;
		}
		while(it != primes.end() && n % *it) it++;
		if(it == primes.end()) return vector<int>();
		ret.push_back(*it); n /= *it;
	}
	return ret;
}

int main() {
	for(int i = 2; i <= MX; i++) {
		if(!sieve[i]) { sieve[i] = i; primes.push_back(i); }
		for(int j : primes) {
			if(i * j > MX) break;
			sieve[i * j] = j;
			if(i % j == 0) break;
		}
	}

	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		vector<int> v = f(A[i]);
		for(int j : v) I[j].emplace_back(0, i);
	}
	for(int i = 1; i <= Q; i++) {
		int p, x; scanf("%d%d", &p, &x);
		vector<int> v = f(x);
		for(int j : v) I[j].emplace_back(i, p);
	}

	for(int i = 0; i <= Q; i++) D[i] = 1;

	seg.init();
	for(int p : primes) {
		seg.clr();
		int t = 0;
		for(pii i : I[p]) {
			seg.upd(i.second);
			int mn = seg.get();
			while(t < mn) {
				t++; D[i.first] = D[i.first] * p % MOD;
			}
		}
	}

	for(int i = 1; i <= Q; i++) {
		D[i] = D[i] * D[i - 1] % MOD;
		printf("%lld\n", D[i]);
	}

	return 0;
}