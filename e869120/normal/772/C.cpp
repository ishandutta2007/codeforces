#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, p, a, F[1000], t[200009], u[200009]; bool r[200009]; vector<int>E; pair<int, vector<int>>dp[1000];
int extgcd(int a, int b, int &x, int &y) {
	int d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else { x = 1; y = 0; }
	return d;
}
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
int mod_inverse(int a, int m) {
	int x, y;
	extgcd(a, m, x, y);
	return (m + x%m) % m;
}
int main() {
	cin >> n >> p;
	for (int i = 0; i < n; i++) { cin >> a; r[a] = true; }
	for (int i = 1; i <= p; i++) {
		if (p%i == 0)E.push_back(i);
	}
	for (int i = 0; i < p; i++) {
		if (r[i] == true)continue;
		int s = 0;
		for (int j = 0; j < E.size(); j++) {
			if (i%E[j] == 0)s = j;
		}
		t[i] = s; F[s]++;
	}
	dp[0] = make_pair(F[0], vector<int>{ 0 });
	for (int i = 0; i < E.size(); i++) {
		for (int j = i + 1; j < E.size(); j++) {
			if (E[j] % E[i] != 0)continue;
			vector<int>Q = dp[i].second; Q.push_back(j);
			dp[j] = max(dp[j], make_pair(dp[i].first + F[j], Q));
		}
	}
	vector<int>R, S;
	for (int i = 0; i < dp[E.size() - 1].second.size(); i++) {
		for (int j = 0; j < p; j++) { if (t[j] == dp[E.size() - 1].second[i] && r[j] == false)R.push_back(j); }
	}
	cout << R.size() << endl; S.push_back(R[0]);
	for (int i = 1; i < R.size(); i++) {
		long long p1 = R[i - 1], q1 = R[i], r1 = p;
		r1 /= gcd(gcd(p1, q1), p); p1 /= (p / r1); q1 /= (p / r1);
		S.push_back((1LL * mod_inverse(p1, r1)*q1) % r1);
	}
	for (int i = 0; i < S.size(); i++) {
		if (i)cout << ' '; cout << S[i];
	}
	cout << endl;
	return 0;
}