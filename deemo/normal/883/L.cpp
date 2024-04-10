
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int maxn = 200 * 1000 + 5;
const ll INF = 1e9;

set <pll> s[maxn];
set <int> p;
set <pair<ll, pll> > arrival;

int main(){
	int n = in(), k = in(), m = in();
	for (int i = 0; i < k; i++){
		int x = in()-1;
		s[x].insert({0, i});
		p.insert(x);
	}
	p.insert(-INF);
	p.insert(INF);
	for (int i = 0; i < m; i++){
		ll t;
		int a, b;
		scanf("%lld %d %d", &t, &a, &b);
		a--, b--;
		while ((!arrival.empty() && arrival.begin()->F <= t)){
			auto top = *arrival.begin();
			arrival.erase(top);
			ll at = top.F, id = top.S.F, d = top.S.S;
			if (s[d].empty())
				p.insert(d);
			s[d].insert({at, id});
		}

		if (p.size() == 2){
			ll at = arrival.begin()->F;
			while (!arrival.empty() && arrival.begin()->F == at){
				auto top = *arrival.begin();
				arrival.erase(top);
				ll id = top.S.F, d = top.S.S;
				if (s[d].empty())
					p.insert(d);
				s[d].insert({at, id});
			}
		}

		auto lit = p.upper_bound(a);
		lit--;
		int l = *lit;
		int r = *p.upper_bound(a);
		int w;
		if (a-l == r-a){
			auto cl = *s[l].begin();
			auto cr = *s[r].begin();
			w = (cl < cr ? l : r);
		}
		else if (a-l < r-a)
			w = l;
		else
			w = r;
		ll at = s[w].begin()->F, id = s[w].begin()->S;
		s[w].erase(s[w].begin());
		if (s[w].empty())
			p.erase(w);
		arrival.insert({max(at, t) + abs(w-a) + abs(b-a), {id, b}});
		printf("%lld %lld\n", id+1, max(at, t) + abs(w-a) - t);
	}
	return 0;
}