#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		ll c, s;
		cin >> c >> s;
		vector<int> v(c, 0);
		for(int i = 0; i < s; ++i)
			++v[i%c];
		ll ans = 0;
		for(int i = 0; i < c; ++i)
			ans += v[i]*v[i];
		cout << ans << '\n';
	}
}