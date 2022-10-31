#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n,k;
	string s;
	cin >> n >> k >> s;
	if(n == 1) {
		if(k >= 1) cout << "0\n";
		else cout << s << "\n";
		return 0;
	}
	if(s[0] != '1' && k > 0) {
		s[0] = '1';
		--k;
	}
	for(int i = 1; i < n; ++i) {
		if(k == 0) break;
		if(s[i] != '0') {
			s[i] = '0';
			--k;
		}
	}
	cout << s << '\n';
}