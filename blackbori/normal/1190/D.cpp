#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

struct fenwick{
	ll T[303030];
	
	void add(ll p, ll v) { for(; p<=3e5; p+=p&-p) T[p] += v; }
	ll getval(ll p) { return p? getval(p - (p & -p)) + T[p] : 0; }
};

fenwick T;
vector <ll> X;
pll P[202020];
bool chk[202020];
ll n, ans, s;

int main()
{
	ll i, j, x, pv;
	
	scanf("%lld", &n);
	
	for(i=0; i<n; i++){
		scanf("%lld%lld", &P[i].first, &P[i].second);
		X.push_back(P[i].first);
	}
	
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	
	for(i=0; i<n; i++){
		P[i].first = lower_bound(X.begin(), X.end(), P[i].first) - X.begin() + 1;
	}
	
	sort(P, P + n, [&](pll &pa, pll &pb){
		if(pa.second != pb.second) return pa.second > pb.second;
		else return pa.first < pb.first;
	});
	
	for(i=0; i<n; i=j){
		for(j=i, pv=0; j<n && P[i].second == P[j].second; j++){
			if(!chk[P[j].first]){
				T.add(P[j].first, 1); s ++;
				chk[P[j].first] = 1;
			}
			x = T.getval(P[j].first - 1) - T.getval(pv);
			ans -= x * (x + 1) / 2; pv = P[j].first;
		}
		x = T.getval(n) - T.getval(pv);
		
		ans -= x * (x + 1) / 2;
		ans = ans + s * (s + 1) / 2;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}