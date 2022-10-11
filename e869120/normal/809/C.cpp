#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const long long mod = 1000000007;

long long product(vector<long long>vec) {
	long long r = 1; for (int i = 0; i < vec.size(); i++) { r *= (vec[i] % mod); r %= mod; }
	return r;
}

pair<long long, long long> solve(long long sizex, long long sizey, long long k, long long rem) {
	if (sizex == 0 || sizey == 0 || rem < 0) return make_pair(0LL, 0LL);

	long long Z1 = (sizex / k);
	long long Z2 = (sizey / k);

	long long sum = 0, ret = 0, B1 = min(k - 1, rem);
	sum += product({ Z1 * Z2 * k, (B1 + 2LL) * (B1 + 1LL) / 2LL });
	ret += product({ Z1 * Z2 * k, B1 + 1LL});

	if (Z1 == 0 || rem >= k) {
		long long B2 = min(k - 1, rem - Z1 * k);
		sum += product({ Z2, sizex - Z1 * k, (B2 + 2LL) * (B2 + 1LL) / 2LL }) + product({ Z2, Z1 * k, sizex - Z1 * k, B2 + 1LL });
		ret += product({ Z2, sizex - Z1 * k, B2 + 1LL });
	}
	if (Z2 == 0 || rem >= k) {
		long long B2 = min(k - 1, rem - Z2 * k);
		sum += product({ Z1, sizey - Z2 * k, (B2 + 2LL) * (B2 + 1LL) / 2LL }) + product({ Z1, Z2 * k, sizey - Z2 * k, B2 + 1LL });
		ret += product({ Z1, sizey - Z2 * k, B2 + 1LL });
	}

	if ((Z1 ^ Z2) == 0) {
		pair<long long, long long> E = solve(sizex - Z1 * k, sizey - Z2 * k, k >> 1, rem);
		sum += E.first;
		ret += E.second;
	}
	if ((Z1 ^ Z2) == 1) {
		pair<long long, long long> E = solve(sizex - Z1 * k, sizey - Z2 * k, k >> 1, rem - k);
		sum += E.first + product({ k, E.second });
		ret += E.second;
	}
	return make_pair(sum % mod, ret % mod);
}

int main() {
	long long Q, ax, ay, bx, by, ca;
	scanf("%lld", &Q);

	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld%lld%lld%lld", &ax, &ay, &bx, &by, &ca); ca--;
		long long V1 = solve(ax - 1, ay - 1, (1LL << 30), ca).first;
		long long V2 = solve(bx - 0, ay - 1, (1LL << 30), ca).first;
		long long V3 = solve(ax - 1, by - 0, (1LL << 30), ca).first;
		long long V4 = solve(bx - 0, by - 0, (1LL << 30), ca).first;
		printf("%lld\n", (V1 + V4 - V2 - V3 + mod * mod) % mod);
	}
	return 0;
}