#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

int n, res, last;
vector<tuple<int, int, int>> mp[200200];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	mp[0].push_back({1, 1, 0});
	cin >> n;
	rep(i, 1, n) {
		int x;
		cin >> x;
		for (int j = 0; j < sz(mp[i - 1]);) {
			int k = j;
			int G = __gcd(x, get<2>(mp[i - 1][j]));
			while (k < sz(mp[i - 1]) && G == __gcd(x, get<2>(mp[i - 1][k])))
				k++;
			mp[i].push_back({get<0>(mp[i - 1][j]), get<1>(mp[i - 1][k - 1]), G});
			j = k;
		}
		if (i > 1) {
			if (get<2>(mp[i].back()) == x) 
				get<1>(mp[i].back())++;
			else 
				mp[i].push_back({i, i, x});
		}
		for (auto [a, b, g] : mp[i]) {
			int c = i - g + 1;
			if (a <= c && c <= b && last < c) {
				last = i;
				res++;
			}
		}
		cout << res << " ";
	}
	cout << endl;

	return 0;
}