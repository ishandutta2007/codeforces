//vsp
#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	if (n % 4 != 2) {
		cout << (1 - n % 4 + 4) % 4 << " A\n";
	}
	else {
		cout << 1 << " B\n";
	}
	return 0;
}