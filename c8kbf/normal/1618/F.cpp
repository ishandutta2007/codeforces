#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

_ x, y;
str a, b;

bool match(str x, str y);
int main() {
		
	scanf("%lld%lld", &x, &y);
	if(x == y) {
		puts("YES");
		exit(0);
	}
	a = bitset<64>(x).to_string();
	b = bitset<64>(y).to_string();
	for(; a[0] == '0'; ) a.erase(a.begin());
	for(; b[0] == '0'; ) b.erase(b.begin());
	bool ok = false;
	if(a.back() == '1') {
		ok = match(a, b);
		reverse(a.begin(), a.end());
		ok |= match(a, b);
	} else {
		a += '1';
		ok = match(a, b);
		reverse(a.begin(), a.end());
		ok |= match(a, b);
		reverse(a.begin(), a.end());
		a.pop_back();
		for(; a.back() == '0'; ) a.pop_back();
		ok |= match(a, b);
		reverse(a.begin(), a.end());
		ok |= match(a, b);
	}
	puts(ok ? "YES" : "NO");

	return 0;
}

bool match(str x, str y) {
	if(x.length() > y.length()) return false;
	for(_ i = 0; i+x.length() <= y.length(); ++i) if(y.substr(i, x.length()) == x) {
		bool ok = true;
		for(_ j = 0; j < i; ++j) if(y[j] == '0') ok = false;
		for(_ j = i+x.length(); j < y.length(); ++j) if(y[j] == '0') ok = false;
		if(ok) return true;
	}
	return false;
}