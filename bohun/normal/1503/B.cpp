#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

int n;
vector<pair<int, int>> v[2];
int main() {
	cin >> n;
	rep(i, 0, n)
		rep(j, 0, n)
			v[(i + j) % 2].push_back({i, j});

	while (!v[0].empty() && !v[1].empty()) {
		int a;
		cin >> a;
		a--;
		int b = (a == 2 ? 0 : a ^ 1);
		auto [x, y] = v[b].back();
		v[b].pop_back();
		cout << b + 1 << " " << x + 1 << " " << y + 1 << endl;
	}

	while (!v[0].empty() || !v[1].empty()) {
		int a;
		cin >> a;
		a--;
		int b = v[0].empty();
		auto [x, y] = v[b].back();
		v[b].pop_back();
		b = (a <= 1 ? 2 : b);
		cout << b + 1 << " " << x + 1 << " " << y + 1 << endl;
	}
	return 0;
}