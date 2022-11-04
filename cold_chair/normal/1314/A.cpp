#include <bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

int n, x; ll c[N], t[N];
map<int, multiset<int> > a;
map<int, ll> s;

#define S multiset<int>

multiset<int> b;

ll ans;

void bin(S &a, S &b) {
	if(a.size() < b.size()) swap(a, b);
	while(b.size()) a.insert(*b.begin()), b.erase(b.begin());
}

int main() {
	scanf("%d", &n);
	fo(i, 1, n) scanf("%lld", &c[i]);
	fo(i, 1, n) scanf("%lld", &t[i]);
	fo(i, 1, n) a[c[i]].insert(t[i]), s[c[i]] += t[i];
	
	while(a.size()) {
		int x = (*a.begin()).first;
		swap(b, (*a.begin()).second);
		a.erase(x);
		if(b.size() == 1) continue;
		
		s[x] -= *(-- b.end());
		b.erase(-- b.end());
		ans += s[x];
		
		bin(a[x + 1], b);
		s[x + 1] += s[x];
	}
	pp("%lld\n", ans);
}