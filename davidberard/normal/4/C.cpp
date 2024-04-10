#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

map<string, int> mp;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;++i) {
		string s;
		cin >> s;
		if(mp.count(s)) {
			cout << s << mp[s]++ << "\n";
		} else {
			cout << "OK\n";
			mp[s] = 1;
		}
	}
	return 0;
}