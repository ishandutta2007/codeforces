#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 3e5 + 20;

ll n, m;
pair<ll, ll>	vec[MAXN];
map<ll, short>	mp;
ll ans = 1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++){
		cin >> vec[i].first;
		vec[i].second = i;
	}
	for (ll i = 0; i < n; i++){
		cin >> vec[i + n].first;
		vec[i + n].second = i;
	}
	sort(vec, vec + 2 * n);
	cin >> m;
	
	for (ll i = 0; i < 2 * n;){
		ll j = i;
		mp.clear();
		ll cur = vec[i].first, cz = 0;

		while (j < 2 * n && vec[j].first == cur){
			mp[vec[j].second]++;
			if (mp[vec[j].second] == 2)	cz++;
			j++;
		}
		
		ll ret = 1;
		for (ll w = 2; w <= (j - i); w++){
			if (w % 2 == 1)
				ret = (ret * w) % m;
			else{
				if (cz){
					ret = (ret * w/2) % m;
					cz--;
				}
				else	ret = (ret * w) % m;
			}
		}

		ans = (ans * ret) % m;
		i = j;
	}
	cout << ans << endl;
	return 0;
}