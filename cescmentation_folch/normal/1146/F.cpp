#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef long double ld;

vvi G;

ll mod = 998244353; 
const int N = 200010;

ll D[N][3];

void f(int x) {
	if ((int)G[x].size() == 0) {
		D[x][2] = 1;
		return;
	}
	D[x][0] = D[x][1] = 1;
	ll tot = 1;
	for (auto y : G[x]) {
		f(y);
		D[x][1] = (D[x][0]*(D[y][1] + D[y][2])%mod + D[x][1]*(D[y][0] + D[y][2])%mod)%mod;
		D[x][0] = (D[x][0]*(D[y][0] + D[y][2]))%mod;
		tot = (tot*(D[y][0] + D[y][1] + 2*D[y][2]))%mod;
	}
	D[x][1] = (D[x][1] - D[x][0] + mod)%mod;
	D[x][2] = (tot - D[x][1] - D[x][0] + 2*mod)%mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	G = vvi(n);
	for (int i = 1; i < n; ++i) {
		int x;
		cin >> x;
		G[x-1].push_back(i);
	}
	f(0);
	cout << (D[0][0] + D[0][2])%mod << '\n';
}