#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
typedef long long ll;
using namespace std;
int n, m, q, res;
multiset<int> s[200005];
int qq(int x) {
	return !s[x].empty() && *s[x].rbegin() > x;
}
void add(int k) {
	int a, b;
	cin >> a >> b;
	res -= qq(a) + qq(b);
	if (k == 1) {
		s[a].insert(b);
		s[b].insert(a);
	}
	else {
		s[a].erase(b);
		s[b].erase(a);
	}
	res += qq(a) + qq(b);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	while (m--) 
		add(1);
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1)
			add(1);
		if (t == 2)
			add(-1);
		if (t == 3)
			cout << n - res << "\n";
	}
	return 0;
}