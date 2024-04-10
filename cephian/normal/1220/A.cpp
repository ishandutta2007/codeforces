#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s >> s;
	int z = 0, n = 0;
	for(char c : s) {
		z += c == 'z';
		n += c == 'n';
	}
	while(n--) cout << "1 ";
	while(z--) cout << "0 ";
	cout << '\n';
}