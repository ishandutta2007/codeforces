#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool b[50];

bool addl(int l) {
	if(l == 12) return true;
	if(b[l]) {
		b[l] = 0;
		return addl(l+1);
	} else
		b[l] = true;
	return false;
}

bool add(int x) {
	int lg = 0;
	while(x != 0) {
		++lg, x/=2;
	}
	return addl(lg);
}

bool solve() {
	fill(b, b+50, 0);
	int n;
	cin >> n;
	bool ok = false;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		ok |= add(a);
	}
	return ok;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i) {
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}