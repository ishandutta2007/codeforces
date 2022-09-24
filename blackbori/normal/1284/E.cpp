#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct vec{
	ll x, y;
	vec() {}
	vec(ll x, ll y) : x(x), y(y) {}
	
	bool operator < (vec &v) { return x == v.x? y < v.y : x < v.x; }
};

vec P[3030];
vector <ll> V;
ll n, ans;

ll ccw(vec va, vec vb, vec vc)
{
	return (va.x * vb.y + vb.x * vc.y + vc.x * va.y)
		- (va.y * vb.x + vb.y * vc.x + vc.y * va.x);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i, j, k, x, y;
	
	cin >> n;
	
	for(i = 0; i < n; i ++){
		cin >> x >> y;
		P[i] = vec(x, y);
	}
	
	for(i = 0; i < n; i ++){
		V.clear();
		for(j = 0; j < n; j ++){
			if(i != j) V.push_back(j);
		}
		
		sort(V.begin(), V.end(), [&](ll a, ll b){
			bool fa = P[i] < P[a], fb = P[i] < P[b];
			if(fa != fb) return fa;
			else return ccw(P[i], P[a], P[b]) > 0;
		});
		
		x = n - 1;
		ans += x * (x - 1) * (x - 2) * (x - 3) / 24;
		
		for(j = 0, k = 0; j < V.size(); j ++){
			for(; j != k - n + 1 && ccw(P[i], P[V[j]], P[V[k % (n - 1)]]) >= 0; k ++);
			x = k - j - 1;
//			cout << i << " " << j << " " << k % (n - 1) << " " << x << endl;
			ans -= x * (x - 1) * (x - 2) / 6;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}