/*input

*/
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define int long long
#define inf 0x3f3f3f3f
#define mod 1000000007

int n, m;

int ppow(int a, int k) {
	if (k == 0) return 1;
	if (k % 2 == 0) return ppow(a * a % mod, k >> 1);
	if (k % 2 == 1) return ppow(a * a % mod, k >> 1) * a % mod;
}
int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n >> m;
	vector<int> sol;
	for (int i = 2; i * i <= n; ++ i) {
		if (n % i == 0) {
			sol.emplace_back(i);
			while (n % i == 0) n /= i;
		}
	} if (n != 1) sol.emplace_back(n);
	
//	for (auto to : sol) cout << to << " "; cout << "\n";

	int ans = 1;
	for (auto to : sol) {
		int tmp = 1, mm = m;
		vector<PII> now;
		while (mm) now.emplace_back(tmp, mm), mm /= to, tmp *= to;
//		for (auto to : now) cout << to.S << " "; cout << "\n";
		for (int i = 0; i + 1 < now.size(); ++ i)
			now[i].S -= now[i + 1].S;
//		for (auto to : now) cout << to.S << " "; cout << "\n";
		for (auto to : now) {
			int val = ppow(to.F % mod, to.S);
			ans = ans * val % mod;
		}
	}
	cout << ans << "\n";
    return 0;
}