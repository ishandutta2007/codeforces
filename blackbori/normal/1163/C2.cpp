#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

vector <pll> L;
pll P[1010];
ll n, ans;

ll ccw(pll pa, pll pb, pll pc)
{
	return (pa.first * pb.second + pb.first * pc.second + pc.first * pa.second) -
			(pa.second * pb.first + pb.second * pc.first + pc.second * pa.first);
}

pll get(pll p)
{
	return pll(P[p.first].first - P[p.second].first, P[p.first].second - P[p.second].second);
}

int main()
{
	ll i, j, k, t, x, y;
	
	scanf("%lld", &n);
	
	for(i=0; i<n; i++){
		scanf("%lld%lld", &x, &y);
		P[i] = pll(x, y);
	}
	
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			L.emplace_back(i, j);
		}
	}
	
	sort(L.begin(), L.end(), [&](pll &la, pll &lb){
		ll dx1, dy1, dx2, dy2;
		
		if(get(la) < pll(0, 0)) swap(la.first, la.second);
		tie(dx1, dy1) = get(la);
		
		if(get(lb) < pll(0, 0)) swap(lb.first, lb.second);
		tie(dx2, dy2) = get(lb);
		
		if(dx1 * dy2 == dx2 * dy1) return ccw(P[la.first], P[la.second], P[lb.second]) > 0;
		else return dx1 * dy2 > dx2 * dy1;
	});
	
	n = 0;
	
	for(i=0; i<L.size(); i=j){
		ll dx1, dy1, dx2, dy2;
		
		tie(dx1, dy1) = get(L[i]);
		for(j=i, t=0; j<L.size() && (tie(dx2, dy2) = get(L[j]), dx1 * dy2 == dx2 * dy1); j=k){
			n ++;
			for(k=j; k<L.size() && (tie(dx2, dy2) = get(L[k]), dx1 * dy2 == dx2 * dy1) && ccw(P[L[j].first], P[L[j].second], P[L[k].first]) == 0; k++);
			t ++;
		}
		
		ans -= t * (t - 1) / 2;
	}
	
	ans += n * (n - 1) / 2;
	
	printf("%lld\n", ans);
	
	return 0;
}