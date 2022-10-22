//Be Careful what you wish for..

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;

ll n, k, sec[MAXN], vec[MAXN];

bool check(ll mid){
	ll rem = k + 1;
	ll mm = 0;
	memcpy(sec, vec, sizeof(vec));
	for (ll i = n - 1; i >= 0; i--){
		while (sec[i]){
			if (mm <= 0){
				rem--;
				mm = mid - (i + 1);
			}
			if (rem <= 0)	return	false;
			if (mm <= 0)	continue;
			ll g = min(sec[i], mm);
			mm -= g;
			sec[i] -= g;
		}
	}
	return	true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (ll i = 0; i < n; i++)
		cin >> vec[i];

	ll b = 1, e = 1e17, ret = 1e17;
	while (b <= e){
		ll mid = (b + e)/ 2;
		if (check(mid))
			ret = mid, e = mid - 1;
		else
			b = mid + 1;
	}
	cout << ret << "\n";	
	return	0;
}