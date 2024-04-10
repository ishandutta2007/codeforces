#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 3e5 + 5;

int n, p[N];
multiset<int> s;
ll ans;

int main() {
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%d", &p[i]);
		s.insert(-p[i]);
		if(s.size() && *s.rbegin() + p[i] > 0) {
			int v = *s.rbegin();
			s.erase(s.find(v));
			ans += v + p[i];
			s.insert(-p[i]);
		}
	}
	pp("%lld\n", ans);
}