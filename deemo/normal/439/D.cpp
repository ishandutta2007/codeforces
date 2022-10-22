#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;

ll n, m, vec[MAXN], sec[MAXN], gec[2 * MAXN];
ll sum;
map<ll, int>	mp[2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 0; i < n; i++){
		cin >> vec[i];
		mp[0][vec[i]]++;
		gec[i] = vec[i];
	}
	for (ll i = 0; i < m; i++){
		cin >> sec[i];
		mp[1][sec[i]]++;
		gec[i + n] = sec[i];
		sum += sec[i];
	}
	sort(vec, vec + n);
	sort(sec, sec + m);
	sort(gec, gec + m + n);
	int sz = unique(gec, gec + m + n) - gec;

	ll ans = sum, c = 0, c2 = m;
	for (ll i = 0; i < sz; i++){
		if (i == 0)
			sum -= gec[i] * c2;
		else
			sum -= c2 * (gec[i] - gec[i - 1]);
			
		if (i == 0)
			sum += gec[i] * c;
		else
			sum += (gec[i] - gec[i - 1]) * c;

		ans = min(ans, sum);
		if (mp[0].count(gec[i]))	c += mp[0][gec[i]];
		if (mp[1].count(gec[i]))	c2 -= mp[1][gec[i]];
	}
	cout << ans << endl;
	return	0;
}