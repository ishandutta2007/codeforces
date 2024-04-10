#include <bits/stdc++.h>
using namespace std;

#define long long long
#define ve vector
#define ii pair<int, int>
#define ll pair<long, long>
#define sz(v) ((int) (v).size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define xx first
#define yy second
#define pb push_back

map<string, int> db;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	while (n --) {
		string s; cin >> s;
		int t = db[s];
		if (t == 0) cout << "OK";
		else cout << s << t;
		cout << '\n';
		++db[s];
	}
	return 0;
}