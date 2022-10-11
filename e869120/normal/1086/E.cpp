#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)
class BIT {
public:
	vector<int>dat; int sz;

	void init(int size_) {
		sz = size_ + 2;
		dat.resize(sz + 2, 0);
	}

	void add(int pos, int x) {
		pos++;
		while (pos <= sz) {
			dat[pos] += x; pos += (pos&-pos);
		}
	}
	int sum(int pos) {
		int s = 0; pos++;
		while (pos >= 1) {
			s += dat[pos]; pos -= (pos&-pos);
		}
		return s;
	}
};


long long N, dp[2009][2009], A[2009][2009], power[2009], fact[2009], mod = 998244353;
vector<long long>R[2009];

void init() {
	dp[0][0] = 1; dp[0][1] = 0;
	for (int i = 2; i <= 2000; i++) {
		dp[i][0] = 1LL * i * dp[i - 1][0];
		if (i % 2 == 0) dp[i][0]++;
		if (i % 2 == 1) dp[i][0]--;
		dp[i][0] += mod * mod; dp[i][0] %= mod;
	}

	for (int i = 0; i <= 2000; i++) {
		dp[i][1] = 1LL * dp[i][0] * (i + 2);
		if (i % 2 == 0) dp[i][1]--;
		if (i % 2 == 1) dp[i][1]++;
		dp[i][1] += mod * mod; dp[i][1] %= mod;
	}

	for (int i = 0; i <= 2000; i++) {
		for (int j = 2; j <= 2000; j++) {
			long long A = (i + j + 1), B = (j - 1);
			dp[i][j] = 1LL * A * dp[i][j - 1] - 1LL * B * dp[i][j - 2];
			dp[i][j] += mod * mod;
			dp[i][j] %= mod;
		}
	}
	
	fact[0] = 1;
	for (int i = 1; i <= 2000; i++) fact[i] = (1LL * fact[i - 1] * i) % mod;
	return;
}

long long getnum(vector<long long>vec) {
	vector<bool>used(vec.size(), false); long long rem = 0;
	for (int i = 0; i < vec.size(); i++) {
		long long cnt1 = 0;
		for (int j = 0; j < vec[i]; j++) { if (used[j] == false) cnt1++; }
		rem += 1LL * cnt1*fact[vec.size() - 1 - i]; rem %= mod;
		used[vec[i]] = true;
	}
	return rem;
}

long long getcor(vector<long long>a, vector<long long>b) {
	BIT Z1, Z2; Z1.init(a.size() + 1); Z2.init(b.size() + 1); vector<bool>used(N, true), used2(N, true);
	for (int i = 0; i < N; i++) Z1.add(i, 1);

	long long rem = 0;
	for (int i = 0; i < b.size(); i++) {
		used[a[i]] = false; if (used2[a[i]] == true) { Z1.add(a[i], -1); Z2.add(a[i], 1); }

		int A = Z1.sum(N), B = Z2.sum(N);
		int L1 = Z1.sum(b[i] - 1), L2 = Z2.sum(b[i] - 1);
		if (a[i] < b[i]) { L1 -= (Z1.sum(a[i]) - Z1.sum(a[i] - 1)); }
		if (a[i] < b[i]) { L2 -= (Z2.sum(a[i]) - Z2.sum(a[i] - 1)); }
		if (A >= 1) rem += 1LL * L1 * dp[A - 1][B];
		if (B >= 1) rem += 1LL * L2 * dp[A][B - 1];
		rem %= mod;

		used2[b[i]] = false;
		if (used[b[i]] == true) { Z1.add(b[i], -1); }
		else { Z2.add(b[i], -1); }
	}
	return rem;
}

int main() {
	init();
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) { scanf("%lld", &A[i][j]); A[i][j]--; R[i].push_back(A[i][j]); }
	}
	power[0] = 1; for (int i = 1; i < N; i++) power[i] = (power[i - 1] * dp[N][0]) % mod;

	long long sum = getnum(R[0]) * power[N - 1]; sum %= mod;
	for (int i = 0; i < N - 1; i++) {
		long long D = getcor(R[i], R[i + 1]);
		sum += D * power[N - i - 2]; sum %= mod;
	}
	cout << sum << endl;
	return 0;
}