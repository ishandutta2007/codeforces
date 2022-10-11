#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable: 4996)

long long n, a, b, p[1000009];

vector<int>prime_factor(int c) {
	vector<int>Z;
	for (int i = 2; i*i <= c; i++) {
		if (c%i == 0) { Z.push_back(i); while (c%i == 0)c /= i; }
	}
	if (c >= 2)Z.push_back(c);
	return Z;
}
vector<int>check(int d) {
	vector<int>Z;
	for (int i = 1; i <= n; i++) {
		if (p[i] % d == 0)Z.push_back(0);
		else if ((p[i] + 1) % d == 0 || (p[i] - 1) % d == 0)Z.push_back(1);
		else Z.push_back(2);
	}
	return Z;
}
long long check2(vector<int>D) {
	long long C = 0, maxn = 0, ret = 0;
	for (int i = D.size() - 1; i >= 0; i--) {
		if (D[i] == 1)C += (a - b);
		else C += a;
		maxn = max(maxn, C); ret = min(ret, C - maxn);
	}
	for (int i = 0; i < D.size(); i++)ret += D[i] * b;
	return ret;
}
long long solve(int d) {
	vector<int>S = check(d); bool OK = false;
	for (int i = 0; i < S.size(); i++) { if (S[i] == 2)OK = true; }
	if (OK == false) { return check2(S); }
	long long L = n, R = -1, min1 = 0, min2 = 0, s1 = 0, s2 = 0;
	for (int i = 0; i < S.size(); i++) { if (S[i] == 2) { L = i; break; } }
	for (int i = 0; i < S.size(); i++) { if (S[i] == 2) { R = i; } }
	for (int i = L - 1; i >= 0; i--) {
		if (S[i] == 1)s1 += (a - b);
		else s1 += a;
		min1 = min(min1, s1);
	}
	for (int i = R + 1; i < S.size(); i++) {
		if (S[i] == 1)s2 += (a - b);
		else s2 += a;
		min2 = min(min2, s2);
	}
	for (int i = L - 1; i >= 0; i--) { if (S[i] == 1)min1 += b; }
	for (int i = R + 1; i < S.size(); i++) { if (S[i] == 1)min2 += b; }
	return min1 + min2 + (R - L + 1)*a;
}
long long solves(long long e) {
	vector<int> I = prime_factor(e); long long F = (1LL << 60);
	for (int i = 0; i < I.size(); i++)F = min(F, solve(I[i]));
	return F;
}
int main() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) { scanf("%lld", &p[i]); }
	long long ans = (1LL << 60);
	ans = min(ans, solves(p[1]));
	ans = min(ans, solves(p[n]));
	ans = min(ans, solves(p[1] + 1));
	ans = min(ans, solves(p[n] + 1));
	if (p[1] >= 3)ans = min(ans, solves(p[1] - 1));
	if (p[2] >= 3)ans = min(ans, solves(p[n] - 1));
	cout << ans << endl;
	return 0;
}