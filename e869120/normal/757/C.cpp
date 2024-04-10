
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>J[1010000], H;
map<long long, long long>M;
long long n, m, g, power[1010000], fact[1010000], mod = 77777777777LL;
int main() {
	cin >> n >> m;
	power[0] = 1; for (int i = 1; i < 1010000; i++)power[i] = power[i - 1] * 1777777LL % mod;
	fact[0] = 1; for (int i = 1; i < 1010000; i++)fact[i] = fact[i - 1] * i % 1000000007LL;
	for (int i = 0; i < n; i++) {
		cin >> g;
		for (int j = 0; j < g; j++) {
			int r; cin >> r; J[r].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++) {
		long long Y = 0; for (int j = 0; j < (int)J[i].size(); j++) { Y += power[J[i][j]]; Y %= mod; }
		M[Y]++; H.push_back(Y);
	}
	sort(H.begin(), H.end()); long long ret = 1, c = 0;
	for (int i = 0; i < (int)H.size(); i++) {
		if (i == 0 || H[i - 1] != H[i])ret *= fact[M[H[i]]];
		ret %= 1000000007;
	}
	cout << ret << endl;
	return 0;
}