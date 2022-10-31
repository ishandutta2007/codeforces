#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	int n;
	ll x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	vector<char> v;
	for(char c : s) {
		if(v.size() == 0 || v.back() != c)
			v.push_back(c);
	}
	int z  = 0;
	if(v[0] == '0')
		z = (v.size()+1)/2;
	else
		z = v.size()/2;
	ll ans = min(y * z, max(0ll, y + (z-1)*x));
	cout << ans << "\n";
}