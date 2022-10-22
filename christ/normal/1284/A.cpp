#include<bits/stdc++.h>
using namespace std;
const int MN = 1e6+2;
string s[30],t[30];
int main () {
	ios::sync_with_stdio(0); cin.tie();
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < m; i++) cin >> t[i];
	int q;
	cin >> q;
	while (q--) {
		int a;
		cin >> a;
		cout << s[(a-1)%n] + t[(a-1)%m] << '\n';
	}
	return 0;
}