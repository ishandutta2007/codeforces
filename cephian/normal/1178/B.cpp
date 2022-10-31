#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;


const int N = 1e6+5;
int a[N], b[N];

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	a[0] = 0;
	b[n-1] = 0;
	for(int i = 1; i < n; ++i) {
		a[i] = a[i-1] + (s[i] == s[i-1] && s[i] == 'v');
		int j = n-i-1;
		b[j] = b[j+1] + (s[j] == s[j+1] && s[j] == 'v');
	}
	ll ans = 0;
	for(int i = 1; i < n-1; ++i) {
		if(s[i] == 'o')
			ans += a[i-1] * ll(b[i+1]);
	}
	cout << ans << '\n';
}