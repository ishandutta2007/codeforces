#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 30; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

long long Div(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

long long N, K;
long long cnt[1 << 18];
vector<int> X[1 << 18];

void calc_cnt() {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) X[j].push_back(i);
	}

	//  1
	int sum = 0;
	for (int i = 1; i <= N - 1; i++) {
		vector<long long> dp(X[i].size(), 0);
		for (int j = X[i].size() - 1; j >= 0; j--) {
			dp[j] = (N - i) / X[i][j];
			for (int k = j + 1; k < X[i].size(); k++) {
				if (X[i][k] % X[i][j] == 0) dp[j] -= dp[k];
			}
		}
		for (int j = 0; j < X[i].size(); j++) {
			cnt[X[i][j]] += dp[j];
			cnt[X[i][j] + 1] -= dp[j];
			sum += dp[j];
		}
	}

	//  2
	for (int i = 1; i <= N - 1; i++) {
		int from = N + 1 - i; vector<int> vec; vec.push_back(N - i);
		for (int j = 0; j < X[i].size(); j++) {
			int mins = ((from + X[i][j] - 1) / X[i][j]) * X[i][j];
			while (mins <= N - 1 && mins + i - N <= X[i][j]) {
				vec.push_back(mins);
				mins += X[i][j];
			}
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());

		for (int j = 1; j < vec.size(); j++) {
			int G = gcd(i, vec[j]);
			cnt[G] += 1;
			cnt[G + 1] -= 1; sum++;
		}
		vec.push_back(N);

		for (int j = 0; j < (int)vec.size() - 1; j++) {
			int cl = vec[j] + 1, cr = vec[j + 1] - 1;
			if (cl <= cr) { cnt[cl - from + 1]++; cnt[cr + 1 - from + 1]--; sum += (cr - cl + 1); }
		}
	}

	for (int i = 1; i <= N; i++) cnt[i] += cnt[i - 1];
	for (int i = 1; i <= N; i++) cnt[i]--;
	for (int i = 1; i <= N; i++) cnt[i] /= 2LL;
}

long long mod = 1000000007;
long long prob[1 << 18];

int main() {
	cin >> N >> K;
	calc_cnt();

	for (int i = 1; i <= N; i++) {
		prob[i] = Div(1, modpow(K, N - i, mod), mod);
	}

	long long ret1 = 0, ret2 = 0;
	for (int i = 1; i <= N - 1; i++) {
		ret1 += prob[i];
		ret1 %= mod;
	}

	for (int i = 1; i <= N - 1; i++) {
		ret2 += 1LL * (cnt[i] % mod) * prob[i];
		ret2 %= mod;
	}

	cout << (2LL * ret2 + ret1) % mod << endl;
	return 0;
}