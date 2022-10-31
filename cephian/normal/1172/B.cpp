#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

const ll M = 998244353;
const int N = 2e5+5;
ll n;
vector<int> T[N];

ll factorial[N];

ll calc(ll v, ll p) {
	int con = T[v].size();
	ll ans = factorial[con-(p != -1)];
	for(int x : T[v]) {
		if(x == p) continue;
		ans = ans * calc(x, v) % M;
	}
	//cout << " from " << v << " is " << ans << " * " << con % M << endl;
	if(p == -1)
		return ans * n % M;
	else
		return ans * con % M;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	factorial[0] = 1;
	for(int i = 1; i <= n; ++i)
		factorial[i] = i * factorial[i-1] % M;

	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	cout << calc(1, -1) << "\n";
}