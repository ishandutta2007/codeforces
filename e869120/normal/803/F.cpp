#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
long long n, a[100005], b[100005], c[100005], power[100005], sum, mod = 1000000007; vector<long long>E[100005];
int main() {
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> a[i]; for (long long j = 1; j*j <= a[i]; j++) { if (a[i] % j == 0) { b[j]++; if (j != a[i] / j)b[a[i] / j]++; } }
	}
	sort(a, a + n);
	power[0] = 1; for (long long i = 1; i < 100005; i++) { power[i] = power[i - 1] * 2; power[i] %= mod; }
	for (long long i = 0; i < 100005; i++) { power[i] = (power[i] + mod - 1) % mod; }
	for (long long i = 1; i <= 100000; i++) {
		for (long long j = i; j <= 100000; j += i)E[j].push_back(i);
	}
	c[1] = 0;
	for (int i = 2; i <= 100000; i++) {
		long long V = 1;
		for (int j = 0; j < E[i].size(); j++) {
			V -= c[E[i][j]];
		}
		sum += power[b[i]] * V; c[i] = V; sum %= mod;
	}
	cout << (power[n] + mod - sum) % mod << endl;
	return 0;
}