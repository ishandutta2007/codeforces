#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;

ll c[10] = {};
bool f[10] = {};
bool taken[10] = {};

int main() {
	fio;	
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		ll p = 1;
		for(int j = 0; j < s.size(); ++j) {
			int k = s[s.size()-1-j]-'a';
			c[k] += p;
			if(j == s.size()-1) f[k] = true;
			p *= 10;
		}
	}
	ll ans = 0;
	for(int k = 0; k < 10; ++k) {
		ll best = -1;
		for(int i = 0; i < 10; ++i) {
			if(taken[i]) continue;
			if(!k && f[i]) continue;
			if(best == -1 || c[i] > c[best])
				best = i;
		}
		ans += c[best] * k;
		// cout << k << " -> " << char(best+'a') << endl;
		taken[best] = true;
	}
	cout << ans << "\n";
}