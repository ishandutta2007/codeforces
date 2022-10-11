#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M, seed, vmax, ret, a[1 << 17], op[1 << 17], l[1 << 17], r[1 << 17], x[1 << 17], y[1 << 17];
vector<tuple<long long, long long, long long>>tup;

int rnd() {
	ret = seed;
	seed = (seed * 7 + 13) % 1000000007;
	return ret;
}

void random_generate() {
	for (int i = 1; i <= N; i++) a[i] = (rnd() % vmax) + 1;
	for (int i = 1; i <= M; i++) {
		op[i] = (rnd() % 4) + 1;
		l[i] = (rnd() % N) + 1;
		r[i] = (rnd() % N) + 1;
		if (l[i] > r[i]) swap(l[i], r[i]);

		if (op[i] == 3) x[i] = (rnd() % (r[i] - l[i] + 1)) + 1;
		else x[i] = (rnd() % vmax) + 1;

		if (op[i] == 4) y[i] = (rnd() % vmax) + 1;
	}
}

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a % m;
	for (int i = 0; i < 32; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

void refresh() {
	vector<tuple<long long, long long, long long>> tup2;

	long long cx = 1;
	for (int i = 0; i < tup.size(); i++) {
		if (i == tup.size() - 1 || get<2>(tup[i]) != get<2>(tup[i + 1])) {
			tup2.push_back(make_tuple(cx, get<1>(tup[i]), get<2>(tup[i])));
			if (i != tup.size() - 1) cx = get<0>(tup[i + 1]);
		}
	}
	tup = tup2;
}

void add(long long L, long long R, long long X) {
	vector<tuple<long long, long long, long long>>tup2;
	for (tuple<long long, long long, long long> pos : tup) {
		long long A = get<0>(pos), B = get<1>(pos);
		if (L <= A && B <= R) tup2.push_back(make_tuple(A, B, get<2>(pos) + X));
		else if (R < A || B < L) tup2.push_back(make_tuple(A, B, get<2>(pos)));
		else {
			if (A < L) tup2.push_back(make_tuple(A, L - 1, get<2>(pos)));
			tup2.push_back(make_tuple(max(A, L), min(B, R), get<2>(pos) + X));
			if (R < B) tup2.push_back(make_tuple(R + 1, B, get<2>(pos)));
		}
	}

	tup = tup2;
	refresh();
}

void update(long long L, long long R, long long X) {
	vector<tuple<long long, long long, long long>>tup2;
	for (tuple<long long, long long, long long> pos : tup) {
		long long A = get<0>(pos), B = get<1>(pos);
		if (L <= A && B <= R) tup2.push_back(make_tuple(A, B, X));
		else if (R < A || B < L) tup2.push_back(make_tuple(A, B, get<2>(pos)));
		else {
			if (A < L) tup2.push_back(make_tuple(A, L - 1, get<2>(pos)));
			tup2.push_back(make_tuple(max(A, L), min(B, R), X));
			if (R < B) tup2.push_back(make_tuple(R + 1, B, get<2>(pos)));
		}
	}
	tup = tup2;
	refresh();
}

vector<pair<long long, long long>> getval(long long L, long long R) {
	vector<pair<long long, long long>>vec;
	for (int i = 0; i < tup.size(); i++) {
		long long A = get<0>(tup[i]), B = get<1>(tup[i]);
		long long EL = max(A, L), ER = min(B, R);
		if (EL <= ER) vec.push_back(make_pair(get<2>(tup[i]), ER - EL + 1));
	}
	return vec;
}

long long smallest(long long L, long long R, long long X) {
	vector<pair<long long, long long>> V = getval(L, R);
	sort(V.begin(), V.end());

	long long cnt = 0;
	for (int i = 0; i < V.size(); i++) {
		cnt += V[i].second;
		if (cnt >= X) return V[i].first;
	}
	return -1;
}

long long powers(long long L, long long R, long long X, long long Y) {
	vector<pair<long long, long long>> V = getval(L, R);
	long long ans = 0;
	for (int i = 0; i < V.size(); i++) { ans += modpow(V[i].first, X, Y) * V[i].second; ans %= Y; }
	return ans;
}

int main() {
	cin >> N >> M >> seed >> vmax;
	random_generate();

	for (int i = 1; i <= N; i++) tup.push_back(make_tuple(1LL * i, 1LL * i, a[i]));
	for (int i = 1; i <= M; i++) {
		if (op[i] == 1) add(l[i], r[i], x[i]);
		if (op[i] == 2) update(l[i], r[i], x[i]);
		if (op[i] == 3) printf("%lld\n", smallest(l[i], r[i], x[i]));
		if (op[i] == 4) printf("%lld\n", powers(l[i], r[i], x[i], y[i]));
	}
	return 0;
}