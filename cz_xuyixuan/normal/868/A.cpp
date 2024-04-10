#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
string a[MAXN], b;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin >> b >> n;
	bool solved = false;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == b) solved = true;
	}
	bool f = false, s = false;
	for (int i = 1; i <= n; i++) {
		if (a[i][1] == b[0]) f = true;
		if (a[i][0] == b[1]) s = true;
	}
	if (f && s) solved = true;
	if (solved) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}