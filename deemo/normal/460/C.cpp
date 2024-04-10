#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;

ll n, m, w, vec[MAXN], sec[MAXN], mark[MAXN];

bool ok(ll x){
	copy(vec, vec + n, sec);
	fill(mark, mark + MAXN, 0);
	
	ll us = 0, p = 0;
	for (ll i = 0; i < n; i++){
		p += mark[i];
		sec[i] += p;
		if (sec[i] >= x)	continue;

		us += x - sec[i];
		p += x - sec[i];
		mark[i + w] -= x - sec[i];
	}
	return	us <= m;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> w;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	
	ll b = 1, e = 2e9, ret = 0;
	while (b <= e){
		ll mid = (b + e)/ 2;
		if (ok(mid)){
			b = mid + 1;
			ret = mid;
		}
		else	e = mid - 1;
	}
	cout << ret << "\n";
	return	0;
}