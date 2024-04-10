#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
int A[262626];

struct Node {
	ll lmx, rmx, mx, sum;

	Node(ll _lmx = 0, ll _rmx = 0, ll _mx = 0, ll _sum = 0) : lmx(_lmx), rmx(_rmx), mx(_mx), sum(_sum) {}

	Node operator+ (const Node& o) const {
		Node ret;
		ret.lmx = max(lmx, sum + o.lmx);
		ret.rmx = max(o.rmx, o.sum + rmx);
		ret.mx = max({mx, o.mx, rmx + o.lmx});
		ret.sum = sum + o.sum;
		return ret;
	};
};

vector<Node> dnc(int s, int e) {
	if(s == e) {
		vector<Node> ret;
		int t = max(0, A[s]);
		ret.emplace_back(t, t, t, A[s]);
		return ret;
	}

	int m = s + e >> 1;
	auto vl = dnc(s, m);
	auto vr = dnc(m + 1, e);

	int n = vl.size();
	vector<Node> ret(n + n);

	for(int i = 0; i < n; i++) {
		ret[i] = vl[i] + vr[i];
	}
	for(int i = n; i < n + n; i++) {
		ret[i] = vr[i - n] + vl[i - n];
	}
	return ret;
}

int main() {
	scanf("%d", &N); N = 1 << N;
	for(int i = 0; i < N; i++) scanf("%d", &A[i]);
	auto v = dnc(0, N - 1);

	scanf("%d", &Q);
	int x = 0;
	while(Q--) {
		int k; scanf("%d", &k);
		x ^= 1 << k;
		printf("%lld\n", v[x].mx);
	}
	return 0;
}