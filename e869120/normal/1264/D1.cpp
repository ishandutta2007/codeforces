#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long mod = 998244353;
long long nr[2009][2009], nv[2009][2009];


long long ncr(long long n, long long r) {
	if (r < 0 || n < r) return 0;
	return nr[n - r][r];
}

void init() {
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			if (i == 0 || j == 0) nr[i][j] = 1;
			else nr[i][j] = (nr[i - 1][j] + nr[i][j - 1]) % mod;
		}
	}
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) nv[i][j] = ncr(i, j);
	}
	for (int i = 0; i <= 2000; i++) {
		for (int j = 1999; j >= 0; j--) { nv[i][j] += nv[i][j + 1]; nv[i][j] %= mod; }
	}
}

string S;
int cnt1[2009];
int cnt2[2009];
int cnt3[2009];

int main() {
	cin >> S; int N = S.size(); init();
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') cnt1[i + 1]++;
		if (S[i] == ')') cnt2[i + 1]++;
		if (S[i] == '?') cnt3[i + 1]++;
	}
	for (int i = 1; i <= S.size(); i++) cnt1[i] += cnt1[i - 1];
	for (int i = 1; i <= S.size(); i++) cnt2[i] += cnt2[i - 1];
	for (int i = 1; i <= S.size(); i++) cnt3[i] += cnt3[i - 1];

	// dep >= 1 
	long long ans1 = 0;
	for (int dep = 1; dep <= S.size() / 2; dep++) {
		for (int i = 1; i <= S.size() - 1; i++) {
			if (S[i - 1] == ')') continue;
			long long val1 = ncr(cnt3[i - 1], dep - 1 - cnt1[i - 1]);
			long long val2 = nv[cnt3[N] - cnt3[i]][max(0, dep - (cnt2[N] - cnt2[i]))];
			ans1 += (val1 * val2 % mod);
			ans1 %= mod;
		}
	}

	cout << ans1 << endl;
	return 0;
}