#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int XX = 1e5 + 5;

ll mx1, mx2, w;
ll fen[XX];
vector<ll>	vec[XX];
map<pair<int, int>, vector<int>>	mp;

void add(int v){
	for (; v < XX; v += v &-v)
		fen[v]++;
}

ll gg(int v){
	ll ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

pair<int, int>	get(ll mid){
	memset(fen, 0, sizeof(fen));
	for (ll i = 1; i <= mx1; i++){
		ll b = mid/ i;
		b = min(b, mx2);
		if (b == 0)	break;
	
		for (ll v:vec[i]){
			if (v > b)	break;
			add(v);
		}

		if (gg(b) >= w)
			return {i, b};
	}

	return {-1, -1};
}

ll rev(ll x){
	ll ret = 0;
	while (x){
		ret = ret*10 + x%10;
		x /= 10;
	}
	return ret;
}

int main(){
	for (int i = 1; i < XX; i++){
		int a = i, aa = rev(i);
		int g = __gcd(a, aa);
		a /= g, aa /= g;
		mp[{a, aa}].push_back(i);
	}

	for (int i = 1; i < XX; i++){
		int a = i, aa = rev(i);
		int g = __gcd(a, aa);
		a /= g, aa /= g;
		for (auto v:mp[{aa, a}])
			vec[i].push_back(v);
		sort(vec[i].begin(), vec[i].end());
	}
	cin >> mx1 >> mx2 >> w;
	
	ll b = 1, e = 1e10;
	pair<int, int>	ret(-1, -1);
	while (b <= e){
		ll mid = (b + e)/ 2;
		auto v = get(mid);
		if (v.F == -1)
			b = mid + 1;
		else
			ret = v, e = mid - 1;
	}

	if (ret.F == -1)
		cout << "-1\n";
	else
		cout << ret.F << " " << ret.S << "\n";
	return 0;
}