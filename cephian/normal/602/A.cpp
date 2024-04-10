#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get() {
	ll n,b,a=0;
	cin >> n >> b;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a *= b;
		a += x;
	}
	return a;
}

int main() {
	ll a = get(), b = get();
	if(a == b) cout << "=\n";
	else if(a < b) cout << "<\n";
	else cout << ">\n";
}