#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;

ll tc()
{
	set <ll> S;
	ll n, i, a, s, f, x, t, l, r, _l, _r;
	bool yeah;

	cin >> n;

	auto read = [&](ll x){
		return s + f * x;
	};

	a = 0; s = 0; f = 1; yeah = 0;
	for(i = 1; i <= n; i ++){
		cin >> x; x -= 2;
		s = x - s; f = -f;

		if(yeah){
			tie(_l, _r) = minmax(-f * s, f * (x - s));
			l = max(l, _l); r = min(r, _r);
			if(l > r) yeah = 0;
		}
		for(; !S.empty(); S.erase(S.begin())){
			t = read(*S.begin());
			if(0 <= t && t <= x) break;
		}
		for(; !S.empty(); S.erase(prev(S.end()))){
			t = read(*prev(S.end()));
			if(0 <= t && t <= x) break;
		}

		if(x & 1){
			a ++;
			if(!yeah && S.empty()){
				a ++; yeah = 1;
				tie(l, r) = minmax(-f * s, f * (x - s));
			}
		}
		else{
			t = f * (x / 2 - s);
			if(S.find(t) != S.end() || yeah && ((l <= t && t <= r) || (r <= t && t <= l))){
				S.clear(); yeah = 0; S.insert(t);
			}
			else{
				a ++; S.insert(t);
			}
		}
	}

	return a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int _t; cin >> _t;

	for(; _t --; ){
		cout << tc() << "\n";
	}

	return 0;
}