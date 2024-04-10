#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>
#include<cstdio>

using namespace std;

//asdf

typedef long long ll;

map<ll, ll>	mp;

void upd(ll u, ll v, ll c){
	while (__builtin_clzll(u) < __builtin_clzll(v)){
		mp[u] += c; 
		u >>= 1;
	}

	while (__builtin_clzll(v) < __builtin_clzll(u)){
		mp[v] += c;
		v >>= 1;
	}

	while (u^v){
		mp[u] += c;
		mp[v] += c;
		u >>= 1;
		v >>= 1;
	}
}

ll get(ll u, ll v){
	ll ret = 0;
	while (__builtin_clzll(u) < __builtin_clzll(v)){
		ret += mp[u];
		u >>= 1;
	}

	while (__builtin_clzll(v) < __builtin_clzll(u)){
		ret += mp[v];
		v >>= 1;
	}

	while (u^v){
		ret += mp[u];
		ret += mp[v];
		u >>= 1;
		v >>= 1;
	}
	return ret;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int q;	cin >> q;
	while (q--){
		int type;	cin >> type;
		if (type == 1){
			ll u, v, c;	cin >> u >> v >> c;
			upd(u, v, c);
		}
		else{
			ll u, v;	cin >> u >> v;
			//cout << get(u, v) << "\n";
			printf("%lld\n", get(u, v));
		}
	}
	//asdf
	return 0;
}