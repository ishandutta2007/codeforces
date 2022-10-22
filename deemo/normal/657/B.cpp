#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXX = 2e6 + 15;
const ll INF = 1e16;

ll n, k;
ll p[MAXX], sec[MAXX];
vector<ll>	vec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;	n++;
	vec.resize(n, 0);
	for (ll i = 0; i < n; i++){
		ll x, cur = i;	cin >> x;
		sec[i] = x;
		x += vec[i];
		vec[i] = 0;
		while (x != 0){
			ll y = abs(x);
			if (cur >= vec.size())	vec.push_back(0);
			if (y & 1)
				vec[cur] += x>0?1:-1;
			x /= 2LL;
			cur++;
		}
	}

	ll m = vec.size();
	ll cur = 0;
	for (ll i = m - 1; i >= 0; i--){
		if (abs(cur) < INF){	
			cur += vec[i];
			p[i] = cur;
			cur *= 2LL;
		}
		else p[i] = cur;
	}

	int cnt = 0;
	for (ll i = 0; i < n; i++){
		ll z = p[i];
		z -= sec[i];
		if (z){
			if (abs(z) <= k)	cnt++;
		}
		else if (i != n - 1)	cnt++;
		if (vec[i])	break;
	}
	cout << cnt << "\n";
	return	0;
}