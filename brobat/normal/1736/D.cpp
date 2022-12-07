#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) x.begin(), x..end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
const int N = 200100;
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < 2*n; i++) {
		if(s[i] == '1') cnt++;
	}
	if(cnt % 2) {
		cout << -1 << '\n';
		return;
	}
	vector<pair<int, int>> p;
	for(int i = 0; i < 2*n; i += 2) {
		if(s[i] != s[i + 1]) {
			p.push_back({s[i] - '0', i});
		}
	}
	assert(sz(p) % 2 == 0);
	vector <int> rot;
	for(int i = 0; i < sz(p); i += 2) {
		rot.push_back(p[i].second + p[i].first);
		rot.push_back(p[i + 1].second + 1 - p[i + 1].first);
	}
	cout << sz(rot) << '\n';
	sort(rot.begin(), rot.end());
	for(auto i : rot) cout << i + 1 << ' ';
	cout << '\n';
	for(int i = 0; i < 2*n; i += 2) cout << i + 1 << ' ';
	cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}