#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef priority_queue<pl, vector<pl>, greater<pl> > pq;


#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)

#define N 0

ld intersect(ld m1, ld b1, ld m2, ld b2){
	return (ld)(b1-b2)/(m2-m1);
}

ld slope(ld x1, ld y1, ld x2, ld y2){
	return (ld)(y1-y2)/(ld)(x1-x2);
}

ld b(ll x1, ll y1, ld m){
	return y1 - m*x1;
}

ld abs1(ld d){
	return d > 0 ? d : -d;
}

ld dist(ld x1, ld y1, ld x2, ld y2){
	return sqrtl((x1 - x2) * (x1 - x2) + (y1-y2)*(y1-y2));
}


ld ep = 1e-14;

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
	G(n) G(H)
	vector<pl> v;
	F(i, 0, n){
		G(a) G(b)
		v.push_back({a, b});
	}
	pl s = {v[n-1].first, v[n-1].second+H};
	ld res = dist(v[n-1].first, v[n-1].second, v[n-2].first, v[n-2].second);
	for(ll i = n-2; i>= 1;i--){
		ld slope1 = (ld)(v[i].second - s.second) / (v[i].first - s.first);
		ld slope2 = (ld)(v[i].second - v[i-1].second) / (v[i].first - v[i-1].first);
		if(slope1 < slope2 && abs1(slope1 - slope2) > ep){
			ld b2 = b(v[i].first, v[i].second, slope1);
			i--;
			while(i >= 1){
				ld m1 = slope(v[i].first, v[i].second, v[i-1].first, v[i-1].second);
				ld b1 = b(v[i].first, v[i].second, m1);
				if(abs1(m1 - slope1) < ep){
					if(abs1(b2-b1) < ep){ 
						res += dist(v[i-1].first, v[i-1].second, v[i].first, v[i].second);
						break;
					}else{
						i--;
						continue;
					}
				}
				ld ans = intersect(m1, b1, slope1, b2);
				if(ans >= v[i-1].first && ans <= v[i].first){
					res += dist(ans, ans*m1+b1, v[i-1].first, v[i-1].second);			
					break;
				}
				i--;
			}
		}else{
			res += dist(v[i-1].first, v[i-1].second, v[i].first, v[i].second);
		}
	}
	cout << setprecision(18) << res << endl;
}